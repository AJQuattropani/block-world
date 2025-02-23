#pragma once

#include "BlockUtils.hpp"
#include <bitset>
#include <bit>

namespace bwgame {
	using chunk_coord_t = int32_t;
	using chunk_diff_t = int32_t;

	static constexpr uint16_t CHUNK_WIDTH_BLOCKS = 15;
	static constexpr float CHUNK_WIDTH_BLOCKS_FLOAT = CHUNK_WIDTH_BLOCKS;
	static constexpr uint16_t CHUNK_HEIGHT_BLOCKS = 256;
	static constexpr uint32_t CHUNK_VOLUME = CHUNK_WIDTH_BLOCKS * CHUNK_WIDTH_BLOCKS * CHUNK_HEIGHT_BLOCKS;

	union ChunkCoords
	{
		struct { chunk_coord_t x, z; };
		chunk_coord_t data[2];
		uint64_t seed;

		ChunkCoords() = default;
		ChunkCoords(chunk_coord_t x, chunk_coord_t z) : x(x), z(z) {}
		ChunkCoords(ChunkCoords&&) = default;
		ChunkCoords(const ChunkCoords&) = default;
		ChunkCoords& operator=(ChunkCoords&&) = default;
		ChunkCoords& operator=(const ChunkCoords&) = default;
	};

	enum CHUNK_FLAGS
	{
		MODEL_UPDATE_FLAG = 0,
		SIZE
	};

	using ChunkFlags = std::bitset<CHUNK_FLAGS::SIZE>;

}

namespace std {
	template<>
	struct hash<bwgame::BlockCoords>
	{
		size_t operator()(const bwgame::BlockCoords& key) const
		{
			return key.index;
		}
	};

	template<>
	struct equal_to<bwgame::BlockCoords>
	{
		bool operator()(const bwgame::BlockCoords& key1, const bwgame::BlockCoords& key2) const
		{
			return key1.index == key2.index;
		}
	};

	template<>
	struct hash<bwgame::ChunkCoords>
	{
		size_t operator()(const bwgame::ChunkCoords& key) const
		{
			return key.seed;
		}
	};

	template<>
	struct equal_to<bwgame::ChunkCoords>
	{
		bool operator()(const bwgame::ChunkCoords& key1, const bwgame::ChunkCoords& key2) const
		{
			return key1.seed == key2.seed;
		}
	};
}