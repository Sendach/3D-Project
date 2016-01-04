#ifndef GAME_H
#define GAME_H
#include <functional>

//Glew
#define GLEW_STATIC
#include <gl\glew.h>
//SFML
#include <SFML/Graphics.hpp>
//Class Includes
#include "World.h"
#include "Main_Building.h"

class Game
{

public:
	Game();
	~Game() {};
	
	// Runs the game
	void run();

	// Loops through all of it
	void gameLoop();

	// Initializes the system
	void Initialize(int width, int height);

	void input(float delta, Camera& camera);
	// Updates all logic
	void Update(float delta, sf::RenderWindow& window, int screenWidth, int screenHeight);

	// Draws Everything
	void draw();

	Camera camera; // The camera
	std::shared_ptr<ResourceManager> resource = std::make_shared<ResourceManager>(); // Our Resource Manager
	std::shared_ptr<World> world = std::make_shared<World>(resource); // Loads All World Stuff

	// The game window
	sf::RenderWindow window;

	// State of the game
	enum class GameState {PLAY, EXIT};
	// Screen Dimension
	int screenWidth = 1600, screenHeight = 900;
	GameState gameState;
	// The Clock

};
#endif

