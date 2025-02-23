#pragma once

#include "Debug.hpp"
#include "ChunkData.hpp"
#include "ChunkModel.hpp"
#include "ExtendLong.hpp"
#include "BinaryChunk.hpp"
#include "Blocks.hpp"
#include "ThreadList.hpp"
#include "Timer.hpp"

#include <bit>
#include <bitset>
#include <ranges>
#include <unordered_set>
#include <future>
#include <execution>

namespace bwgame
{
	class Chunk
	{
	public:
		Chunk(ChunkCoords chunk_coords, std::unordered_map<ChunkCoords, Chunk> const* chunk_map);
		

		Chunk(const Chunk&) = delete;
		Chunk(Chunk&& other) noexcept;

		Chunk& operator=(const Chunk&) = delete;
		Chunk& operator=(Chunk&&) = delete;

		~Chunk();

		void update();

		void render(bwrenderer::Shader& shader) const;

		inline const ChunkCoords& getChunkCoords() const { return chunk_coords; }

		inline const Block& getBlockConst(block_coord_t x, block_coord_t y, block_coord_t z) const 
		{	return getBlockConst({ x,y,z });	}

		inline void reserve(uint16_t amount) {
			if (block_map.size() >= CHUNK_VOLUME)
			{
				BW_WARN("Reserve failed - Chunk is already at full capacity.");
				return;
			}
			{
				std::scoped_lock<std::mutex> transferModelDataLock(chunk_data_mutex);
				if (block_map.size() + amount > CHUNK_VOLUME)
				{
					BW_WARN("Reserve attempted - Chunk has been set to maximum capacity.");
					block_map.reserve(CHUNK_VOLUME - block_map.size());
					return;
				}
				block_map.reserve(amount);
			}

		}

		inline bool checkBlock(const BlockCoords& coords) const
		{
			const auto& block_it = block_map.find(coords);
			return block_it != block_map.end();
		}

		void deleteBlock(const BlockCoords& coords);

		void setBlock(const BlockCoords& coords, const Block& block);

	private:
		const ChunkCoords chunk_coords;
		ChunkFlags flags;
		// TODO find better data structure for holding onto blocks and chunks
		std::unordered_map<BlockCoords, Block> block_map;
		std::unique_ptr<bwrenderer::ChunkModel> model;
		// TODO make shared_ptr
		std::unordered_map<ChunkCoords, Chunk> const* chunk_map;

		std::unique_ptr<utils::ThreadList> async_chunk_operations;
		mutable std::mutex chunk_data_mutex;

	private:
		inline const Block& getBlockConst(const BlockCoords& coords) const
		{
			const auto& block_pair = block_map.find(coords);
			BW_ASSERT(block_pair != block_map.end(), "Block not found");
			return block_pair->second;
		}


		inline void reloadModelData() const {
			auto data = packageRenderData();
			{
				std::scoped_lock<std::mutex> transferModelDataLock(chunk_data_mutex);
				model->updateRenderData(std::move(data));
			}
		}
		std::vector<bwrenderer::BlockVertex> packageRenderData() const;
		void bc_vertex_helper_ikj(uint8_t u, utils::data_IKJ& n_xzy, utils::data_IKJ& p_xzy, utils::data_IKJ& n_zxy, utils::data_IKJ& p_zxy,
			std::vector<bwrenderer::BlockVertex>& vertices) const;
		void bc_vertex_helper_jik(uint8_t i, uint8_t k, utils::data_JIK& n_yxz, utils::data_JIK& p_yxz,
			std::vector<bwrenderer::BlockVertex>& vertices) const;
		inline bwrenderer::BlockVertex packageBlockRenderData(bwgame::BlockCoords pos, BlockDirection dir) const
		{
			return { .info = {glm::vec3(pos.x, pos.y, pos.z), utils::blockDirectionToNormal(dir), getBlockConst(pos).getTexture(dir)} };
		}



	};

}