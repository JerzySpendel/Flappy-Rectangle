#include "cplayer.hpp"
#include "barrier.hpp"
#include "capp.hpp"
#include <iostream>
#include <cstdlib>

Barrier::Barrier(CApp* app){
	m_app = app;
}

Barrier::Barrier(CApp* app, SDL_Rect* up, SDL_Rect* down){
	m_app = app;
	m_rect_up = up;
	m_rect_down = down;
}

void Barrier::render(){
	SDL_Renderer* ren = m_app->get_renderer();
	SDL_SetRenderDrawColor(ren, 0x00, 0xaa, 0x00, 0xff);
	SDL_RenderFillRect(ren, m_rect_up);
	SDL_SetRenderDrawColor(ren, 0x00, 0xFF, 0x00, 0xff);
	SDL_RenderDrawRect(ren, m_rect_up);
	SDL_SetRenderDrawColor(ren, 0x00, 0xaa, 0x00, 0xff);
	SDL_RenderFillRect(ren, m_rect_down);
	SDL_SetRenderDrawColor(ren, 0x00, 0xff, 0x00, 0xff);
}

void Barrier::update(int dt){
	float dx = (dt/1000.0)*Barrier::SPEED;
	m_rect_up->x -= dx;
	m_rect_down->x -= dx;
}

int Barrier::x() const{
	return (int)m_rect_up->x;
}

int Barrier::y() const{
	return (int)m_rect_up->y;
}

void Barrier::set_x(float x){
	_x = x;
}

void Barrier::set_y(float y){
	_y = y;
}

const SDL_Rect** Barrier::get_rect() const{
	return new const SDL_Rect*[2]{m_rect_up, m_rect_down};
}

bool Barrier::collides(SDL_Rect* r) const{
	if(SDL_HasIntersection(r, get_rect()[0]) == SDL_TRUE ||
			SDL_HasIntersection(r, get_rect()[1]) == SDL_TRUE){
		return true;
	}
	return false;
}

Barrier* Barrier::generate_new(CApp* m_app){
	int min_h = CApp::HEIGHT*20/100;
	int max_h = CApp::HEIGHT*80/100;
	int diff = 80;
	int upper = rand()%(max_h-min_h) + min_h;
	SDL_Rect* up = new SDL_Rect{CApp::WIDTH, 0, Barrier::WIDTH, upper};
	SDL_Rect* down = new SDL_Rect{CApp::WIDTH, upper+diff, Barrier::WIDTH, CApp::HEIGHT - (upper+diff)};
	return new Barrier(m_app, up, down);
}

BarrierManager::BarrierManager(CApp* app){
	m_app = app;
}

void BarrierManager::generate(){
	if(m_barriers.size() == 0){
		Barrier* b = Barrier::generate_new(m_app);
		m_barriers.push_back(*b);
		delete b;
	}
}

void BarrierManager::update(int dt){
	std::vector<Barrier> next;
	std::vector<Barrier>::iterator i;
	for(i=m_barriers.begin(); i != m_barriers.end(); i++){
		if(i->x() + Barrier::WIDTH > 0){
			next.push_back(*i);
		}
	}
	m_barriers = next;
	this->generate();
	for(i=m_barriers.begin(); i != m_barriers.end(); i++){
		i->update(dt);
	}
}

void BarrierManager::render() const{
	for(int i=0;i < m_barriers.size();i++){
		Barrier b = m_barriers.at(i);
		b.render();
	}
}

bool BarrierManager::collision(Player* p){
	std::vector<Barrier>::iterator i;
	SDL_Rect r = p->get_rect();
	for(i=m_barriers.begin(); i!=m_barriers.end(); i++){
		if(i->collides(&r)){
			std::cout << "KOLIZJA" << std::endl;
		}
	}
}
