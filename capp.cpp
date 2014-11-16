#include "capp.hpp"
#include <SDL2/SDL.h>
#include <iostream>
#include "cplayer.hpp"

CApp::CApp(){
	m_surface = NULL;
	m_window = NULL;
	m_renderer = NULL;
	m_texture = NULL;
	m_player = nullptr;
	running = true;
}

int CApp::OnExecute(){
	if(OnInit() == false){
		std::cout << "nici z tego" << std::endl;
		return -1;
	}
	Player p(m_renderer);

	SDL_Event event;
	while(running){
		while(SDL_PollEvent(&event)){
			OnEvent(&event);
		}
		OnLoop();
		OnRender();
		SDL_Delay(20);
	}

	OnCleanup();
	return 0;
}

bool CApp::OnInit(){
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0){
		std::cout << "Inicjalizacja nie podzialala" << std::endl;
		return false;
	}
	m_window = SDL_CreateWindow("Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
	if( m_window == NULL){
		std::cout << "Stworzenie okna nie zadzialalo" << std::endl;
		return 0;
	}
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	if(m_renderer == NULL){
		std::cout << "Stworzenie renderera nie" << std::endl;
		std::cout << SDL_GetError() << std::endl;
		return 0;
	}
	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 640, 480);
	if(m_texture == NULL){
		std::cout << "Stworzenie tekstury nie" << std::endl;
		return 0;
	}
	m_player = new Player(m_renderer);
	return true;
}

void CApp::OnLoop(){
	m_player->update(20);
	std::cout << m_player->y() << std::endl;
}

void CApp::OnRender(){
	SDL_SetRenderTarget(m_renderer, NULL);
	SDL_SetRenderDrawColor(m_renderer, 155, 180, 222, 0xff);
	SDL_RenderClear(m_renderer);
	m_player->render();
	SDL_RenderPresent(m_renderer);
}

void CApp::OnEvent(SDL_Event* e){
	if(e->type == SDL_QUIT){
		running = false;
		std::cout << "Tak niekiedy bywa" << std::endl;
	}
	m_player->handle_event(e);
}

void CApp::OnCleanup(){
	SDL_FreeSurface(m_surface);
	SDL_DestroyTexture(m_texture);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}
