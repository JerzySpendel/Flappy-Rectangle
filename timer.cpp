#include "timer.hpp"
Timer::Timer(){
	m_last = SDL_GetTicks();
}

Uint32 Timer::tick(){
	Uint32 last = m_last;
	m_last = SDL_GetTicks();
	return m_last - last;
}
