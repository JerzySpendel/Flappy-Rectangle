#ifndef __CPLAYER__HPP
#define __CPLAYER__HPP

#include <SDL2/SDL.h>

class Player{
private:
	SDL_Texture* m_texture;
	SDL_Renderer* m_renderer;
	void _draw_me();
	float _x,_y,_start_y;
	int _size;
	float _time;
	float _speed;
public:
	Player(SDL_Renderer*);
	void handle_event(SDL_Event*);

	int x() const;
	int y() const;
	int size() const;
	void set_x(float);
	void set_y(float);
	void set_size(int);

	SDL_Rect get_rect() const;

	void update(int);
	void render() const;
	void jump();

};

#endif
