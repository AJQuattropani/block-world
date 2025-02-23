#pragma once

#include "BlockMesh.hpp"
#include "ChunkData.hpp"

namespace bwrenderer {

	class ChunkModel
	{
	public:
		
		ChunkModel() {
			GL_INFO("ChunkModel generated.");
		}

		~ChunkModel() {
			GL_INFO("ChunkModel destroyed.");
		}

		ChunkModel(const ChunkModel& other) = default;
		ChunkModel& operator=(const ChunkModel& other) = default;

		ChunkModel(ChunkModel&& other) = default;
		ChunkModel& operator=(ChunkModel&& other) = default;

		void render(Shader& shader) const;

		inline void updateRenderData(std::vector<BlockVertex>&& blockVertices)
		{
			mesh.setVertexBuffer(std::move(blockVertices));
		}

		inline void setModelMatrix(bwgame::ChunkCoords coords)
		{
			setModelMatrix(glm::vec3(coords.x,0,coords.z));
		}

		inline void setModelMatrix(glm::vec3 position)
		{
			model = modelMatrixInit(glm::translate(glm::mat4(1.0), position * (float)bwgame::CHUNK_WIDTH_BLOCKS));
		}

		inline const glm::mat4& getModelMatrix()
		{
			return model;
		}

	private:
		BlockMesh mesh;
		glm::mat4 model = modelMatrixInit(glm::mat4(1.0));
	private:

		inline static const glm::mat4 modelMatrixInit(const glm::mat4& premodel)
		{
			return glm::scale(premodel, glm::vec3(1.0));
		}
	};

}