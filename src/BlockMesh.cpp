#include "BlockMesh.hpp"

using namespace bwrenderer;

bwrenderer::BlockMesh::BlockMesh() : vbo(setupVertexBuffer()), vao(setupVertexArray())
{
	//BW_INFO("BlockMesh without buffer initialized.");
}

bwrenderer::BlockMesh::BlockMesh(const vertex_vector& vertices)
	: vertices(vertices), vbo(setupVertexBuffer()), vao(setupVertexArray())
{
	//BW_INFO("BlockMesh initialized in place.");
}

void BlockMesh::draw() const
{
	vao.bind();
	glDrawArrays(GL_POINTS, 0, (GLsizei)vertices.size());
	vao.unbind();
}

vertex_buffer BlockMesh::setupVertexBuffer()
{
	//BW_INFO("New vertex buffer created.");
	return vertex_buffer(vertices.data()->data, vertices.size() * sizeof(BlockVertex));
}

vertex_array BlockMesh::setupVertexArray()
{
	//BW_INFO("New vertex array created.");
	vertex_layout layout_object;
	layout_object.push(GL_FLOAT, sizeof(decltype(BlockInfo::position)) / alignof(decltype(BlockInfo::position)));
	layout_object.push(GL_FLOAT, sizeof(decltype(BlockInfo::normal)) / alignof(decltype(BlockInfo::normal)));
	layout_object.push(GL_FLOAT, sizeof(decltype(BlockInfo::tex_coords)) / alignof(decltype(BlockInfo::tex_coords)));
	
	return vertex_array(vbo, layout_object);
}
