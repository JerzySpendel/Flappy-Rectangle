#ifndef __CAPP__HPP
#define __CAPP__HPP

#include <SDL2/SDL.h>
#include "cplayer.hpp"

class BarrierManager;

class CApp{
private:
	bool running;
	SDL_Surface* m_surface;
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;
	BarrierManager* m_bmanager;
	Player* m_player;
	Uint32 dt;
public:
	enum {
		WIDTH = 640,
		HEIGHT = 480
	};
	CApp();
	int OnExecute();
	bool OnInit();
	void OnEvent(SDL_Event*);
	void OnLoop();
	void OnRender();
	void OnCleanup();

	SDL_Renderer* get_renderer() const;
	SDL_Window* get_window() const;
};

#endif
