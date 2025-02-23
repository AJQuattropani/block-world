#pragma once

#include <glad/glad.h>

#include "Debug.hpp"
#include "Input.hpp"
#include "Shader.hpp"
#include "Context.hpp"
#include "Chunk.hpp"
#include "World.hpp"
#include "WorldRenderer.hpp"
#include "Player.hpp"

#include <memory>
#include <string>

class Application
{
public:
	Application(unsigned int screen_width = 1080, unsigned int screen_height = 720, float fps = 60.0f / 2.0f, float ups = 60.0f / 2.0f);
	int run();
	~Application();
private:
	GLFWwindow* window;
	// REMOVE
	InputContext input_context;
	std::shared_ptr<bwgame::Context> context;

	std::shared_ptr<bwgame::BlockRegister> blocks;
	std::shared_ptr<bwgame::World> world;
	std::shared_ptr<bwgame::Player> player;

	std::unique_ptr<bwrenderer::WorldRenderer> world_renderer;
private:
	GLFWwindow* glfwWindowInit(const std::string& name);
private:
	void update();

	void render();

	void handleInput();

	void handleContext();
private:
	static void loadCallbacks(GLFWwindow* window);
	static void updateTime(double& lastTimeSeconds, double& deltaTimeSeconds);


};