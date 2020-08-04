#include "MainGame.h"

#include <iostream>
#include <string>
#include <GL/glew.h>

void fatal_error(std::string error_string)
{
	std::cout << error_string << std::endl;
	std::cout << "Enter any key to quit...";
	int tmp;
	std::cin >> tmp;
	SDL_Quit();
}

MainGame::MainGame()
{
	_window = nullptr;
	_screen_width = 500;
	_screen_height = 300;
	GameState _game_state = GameState::PLAY;
}

MainGame::~MainGame()
{
	//dtor
}

void MainGame::run()
{
	init_systems();

	game_loop();
}

void MainGame::init_systems()
{
	//Initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	_window = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		_screen_width, _screen_height, SDL_WINDOW_OPENGL);

	if (_window == nullptr) {
		fatal_error("SDL Window could not be created!");
	}

	SDL_GLContext gl_context = SDL_GL_CreateContext(_window);
	if (gl_context == nullptr) {
		fatal_error("SDL_GL context could not be created!");
	}

}

void MainGame::game_loop()
{
	while (_game_state != GameState::EXIT) {
		process_input();
	}
}

void MainGame::process_input()
{
	SDL_Event evnt;
	while (SDL_PollEvent(&evnt)) {
		switch (evnt.type) {
		case SDL_QUIT:
			_game_state = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			std::cout << evnt.motion.x << " " << evnt.motion.y << std::endl;
			break;
		}
	}
}
