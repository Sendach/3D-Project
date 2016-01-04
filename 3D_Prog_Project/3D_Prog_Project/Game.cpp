#include "Game.h"
#include <iostream>

void Game::Initialize(int width, int height)
{
	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.majorVersion = 4;
	settings.minorVersion = 3;
	
	window.create(sf::VideoMode(screenWidth, screenHeight), "Project", sf::Style::Default, settings);
	window.setMouseCursorVisible(false);
	window.setFramerateLimit(0);
	glewExperimental = GL_TRUE;
	glewInit();
	glViewport(0, 0, width, height);
	glEnable(GL_DEPTH_TEST);
	gameState = GameState::PLAY;
}

Game::Game() : camera(glm::vec3(0.0f, 0.0f, 300.0f))
{
	
}

void Game::run()
{
	
	Initialize(this->screenWidth, this->screenHeight);
	world->initialize();
	gameLoop();
}

void Game::gameLoop()
{
	
	sf::Clock gameTime;
	sf::Event event;
	while (gameState == GameState::PLAY)
	{
		
		while (window.pollEvent(event))
		{
			
			if (event.type == sf::Event::Closed)
			{
				gameState = GameState::EXIT;
			}
			else if (event.type == sf::Event::Resized)
			{
				glViewport(0, 0, event.size.width, event.size.height);
			}
			else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				gameState = GameState::EXIT;
			}
			
		}
		//FPS
		sf::Time time = gameTime.getElapsedTime();
		//std::cout << 1.0f / time.asSeconds() << std::endl;
		/* Use the enum GameState to decide whether the game should be activated/called or not. If GameState equals Game, call the game functions
		   Otherwise don't.*/
		Update(gameTime.restart().asSeconds(), window, screenWidth, screenHeight);
		//input(gameTime.restart().asSeconds(), camera);
		draw();
		window.display();
	}
}

void Game::input(float delta, Camera& camera)
{

}

void Game::Update(float delta, sf::RenderWindow& window, int screenWidth, int screenHeight)
{
	if (camera.cameraPosition.z >= -325.0 || camera.cameraPosition.z <= -729.0f)
	{
		this->camera.updateCameraKeyboardMovement(delta);
	}
	//this->camera.updateCameraKeyboardMovement(delta);
	this->camera.updateCameraMouseMovement(delta, window, screenWidth, screenHeight);

	world->update(camera);
}

void Game::draw()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	world->render(camera);
}