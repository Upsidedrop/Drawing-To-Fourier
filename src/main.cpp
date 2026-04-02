#include <iostream>
#include <SDL2/SDL.h>
#include <list>
#include <vector>

#include "Math.hpp"
#include "DrawnEq.hpp"

SDL_Renderer* renderer;
int main(){

    bool gameRunning = true;
    SDL_Event event;
    SDL_Window* window;

    SDL_SetHint(SDL_HINT_RENDER_LINE_METHOD, "2");
    window = SDL_CreateWindow("Hello", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 800, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
    std::list<SDL_Point> points;
    float distanceTravelled = 0;

    bool drawing = false;
    while(gameRunning){
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 180);

        while(SDL_PollEvent(&event)){
            switch (event.type){
                case SDL_QUIT:
                {                
                    gameRunning = false;
                }
                break;
                case SDL_MOUSEBUTTONDOWN:
                {
                    if(event.button.button != SDL_BUTTON_LEFT){
                        break;
                    }
                    if(drawing){
                        drawing = false;
                        
                        DrawnEq eq(points, distanceTravelled);
                        eq.printDesmosSyntax();

                        break;
                    }
                    drawing = true;
                }
                break;
                case SDL_MOUSEMOTION:
                {
                    if(!drawing){
                        break;
                    }
                    int x, y;
                    SDL_GetMouseState( &x, &y );
                    if(points.size() != 0){
                        auto lastPoint = points.back();
                        distanceTravelled += Math::distanceBetween(lastPoint, {x, y});
                    }
                    points.push_back({x, y});
                }
            }
        }
        {
            std::vector<SDL_Point> vec(points.begin(), points.end());
            SDL_RenderDrawLines(renderer, vec.data(), vec.size());
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

        SDL_RenderPresent(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    }
    SDL_DestroyWindow(window);
}