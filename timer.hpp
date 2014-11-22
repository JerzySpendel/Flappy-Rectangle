#ifndef _TIMER_HPP
#define _TIMER_HPP

#include <SDL2/SDL.h>

class Timer{
	Uint32 m_dt;
	Uint32 m_last;
public:
	Timer();
	Uint32 tick();
};

#endif
