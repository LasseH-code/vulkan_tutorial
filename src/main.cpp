#include <stdio.h>
#include "logger.h"
#define SDL_MAIN_HANDLED
#include <SDL.h>

int main()
{
        if(SDL_Init(SDL_INIT_VIDEO) != 0)
        {
                lhg::LOG_ERROR("Error initializing SDL: ");
        }
        
        return 0;
}