#include "board.h"
#include <iostream>


Board::Board(CApp* app){
    TTF_Init();
    m_app = app;
    m_board_texture = SDL_CreateTexture(m_app->get_renderer(), SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 200, 50);
    m_font = TTF_OpenFont("./res/OpenSans-Regular.ttf", 35);
    if (!m_font)
    {
        std::cout << "Nie załadowany czcionki" << std::endl;
        std::cout << TTF_GetError() << std::endl;
    }
    m_time = 0;
}

SDL_Texture* Board::get_board_texture() {
    return m_board_texture;
}

void Board::update(int dt) {
    SDL_Renderer* renderer = m_app->get_renderer();
    m_time += std::round(dt/10.0)/100.0;
    SDL_Texture *temp = SDL_GetRenderTarget(renderer);
    SDL_SetRenderTarget(renderer, m_board_texture);
    SDL_SetRenderDrawColor(renderer, 0, 0, 100, 255);
    SDL_RenderClear(renderer);

    SDL_Surface* text = TTF_RenderText_Solid(m_font, std::to_string(m_time).c_str(), SDL_Color{255, 255, 255, 255});
    if(m_board_texture != nullptr){
        SDL_DestroyTexture(m_board_texture);
    }
    m_board_texture = SDL_CreateTextureFromSurface(renderer, text);
    SDL_FreeSurface(text);
    SDL_SetRenderTarget(m_app->get_renderer(), temp);
}

void Board::render() {
    int w, h;
    SDL_QueryTexture(m_board_texture, NULL, NULL, &w, &h);
    SDL_Rect dest_r{0, 0, w, h};
    SDL_RenderCopy(m_app->get_renderer(), m_board_texture, NULL, &dest_r);
}
