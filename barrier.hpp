#ifndef __BARRIER__HPP
#define __BARRIER__HPP

#include "capp.hpp"
#include <vector>

class Player;

class Barrier{
private:
	SDL_Rect* m_rect_up, *m_rect_down;
	CApp* m_app;
	float _x, _y;
public:
	enum {
		SPEED = 300,
		WIDTH = 20,
		HEIGHT = 200
	};
	Barrier(CApp*);
	Barrier(CApp*, SDL_Rect*, SDL_Rect*);
	void render();
	void update(int);

	int x() const;
	int y() const;
	void set_x(float);
	void set_y(float);
	const SDL_Rect** get_rect() const;
	bool collides(SDL_Rect*) const;

	static Barrier* generate_new(CApp*);
};

class BarrierManager{
private:
	std::vector<Barrier> m_barriers;
	CApp* m_app;
public:
	BarrierManager(CApp*);
	void generate();
	void update(int);
	void render() const;
	bool collision(Player*);
};

#endif
