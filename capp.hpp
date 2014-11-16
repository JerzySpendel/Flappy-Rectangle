#ifndef __CAPP__HPP
#define __CAPP__HPP

#include <SDL2/SDL.h>
#include "cplayer.hpp"

class CApp{
private:
	bool running;
	SDL_Surface* m_surface;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;
	Player* m_player;
public:
	CApp();
	int OnExecute();
	bool OnInit();
	void OnEvent(SDL_Event*);
	void OnLoop();
	void OnRender();
	void OnCleanup();
};

#endif
