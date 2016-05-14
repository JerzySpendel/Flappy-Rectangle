//
// Created by jerzy on 14.05.16.
//

#ifndef FLAPPYRECTANGLE_BOARD_H
#define FLAPPYRECTANGLE_BOARD_H
#include "capp.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class Board{
    CApp* m_app;
    SDL_Texture* m_board_texture;
    TTF_Font* m_font;
    float m_time;
public:
    Board(CApp*);
    void update(int);
    void render();
    SDL_Texture* get_board_texture();
};

#endif //FLAPPYRECTANGLE_BOARD_H
