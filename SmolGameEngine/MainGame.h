#pragma once
#include <SDL/SDL.h>
#include <GL/glew.h>

enum class GameState { PLAY, EXIT };

class MainGame
{
public:
	MainGame();
	virtual ~MainGame();

	void run();

protected:

private:
	SDL_Window* _window;
	int _screen_width;
	int _screen_height;
	GameState _game_state;

	void init_systems();
	void game_loop();
	void process_input();
};

