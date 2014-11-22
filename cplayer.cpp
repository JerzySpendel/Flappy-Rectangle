#include "cplayer.hpp"
#include <iostream>

Player::Player(SDL_Renderer* ren){
	_x = 0.0;
	_y = 0;
	_start_y = 250.0;
	_size = 20;
	_speed = 250;
	_time = 0.0;

	m_renderer = ren;
	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, size(), size());
	_draw_me();
}

void Player::_draw_me(){
	SDL_SetRenderTarget(m_renderer, m_texture);
	SDL_SetRenderDrawColor(m_renderer, 0xff, 0xff, 0xff, 0xff);
	SDL_RenderClear(m_renderer);
	SDL_SetRenderDrawColor(m_renderer, 0xff, 0x00, 0x00, 0xff);
	SDL_Rect r{0,0,size(), size()};
	SDL_RenderDrawRect(m_renderer, &r);
	SDL_SetRenderTarget(m_renderer, NULL);
}

void Player::render() const{
	SDL_Rect r{x(), y(), size(), size()};
	SDL_RenderCopy(m_renderer, m_texture, NULL, &r);
}

void Player::handle_event(SDL_Event* e){
	if(e->type == SDL_KEYDOWN){
		if(e->key.keysym.sym == SDLK_SPACE){
			this->jump();
		}
	}
}

int Player::x() const{
	return (int)_x;
}

int Player::y() const{
	return (int)_y;
}

int Player::size() const{
	return _size;
}

void Player::set_x(float x){
	_x = x;
}

void Player::set_y(float y){
	_y = y;
}

void Player::set_size(int size){
	_size = size;
}

void Player::jump(){
	_time = 0.0;
	_start_y = _y;
}

void Player::update(int dt){
	_time += dt/(float)(1000);
	_y = _start_y-_speed*_time + 500*_time*_time/2;

}

SDL_Rect Player::get_rect() const{
	return SDL_Rect{x(), y(), size(), size()};
}
