#include <stdio.h>
#include "logger.h"
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <chrono>
#include "vulkan_base/vulkan_base.h"

bool handle_message()
{
        SDL_Event event; 
        while(SDL_PollEvent(&event))
        {
                switch (event.type)
                {
                        case SDL_QUIT:
                        return false;
                }
        }
        return true; 
}

int main()
{
        std::chrono::time_point<std::chrono::system_clock> start, end;
        std::chrono::duration<double> elapsed_seconds;
        
        start = std::chrono::system_clock::now(); 
        lhg::LOG_WARN("Initializing...");
        if(SDL_Init(SDL_INIT_VIDEO) != 0)
        {
                lhg::LOG_CRIT("Error initializing SDL: ", SDL_GetError());
                return 1;
        }
        
        SDL_Window* window = SDL_CreateWindow("Vulkan Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1240, 720, SDL_WINDOW_VULKAN);
        if (!window)
        {
                lhg::LOG_CRIT("Error creating SDl window");
                return 1;
        }
        
        lh_vulkan::VulkanBase* vulkan_base = new lh_vulkan::VulkanBase();
        
        end = std::chrono::system_clock::now(); 
        elapsed_seconds = end-start;
        lhg::LOG_WARN("Initialization successful - elapsed time: ", elapsed_seconds.count(), 's');
        
        
        while (handle_message())
        {
                
        }
        
        
        start = std::chrono::system_clock::now(); 
        lhg::LOG_WARN("Destroying window...");
        SDL_DestroyWindow(window);
        SDL_Quit();
        end = std::chrono::system_clock::now(); 
        elapsed_seconds = end-start;
        lhg::LOG_WARN("Destruction successful - elapsed time: ", elapsed_seconds.count(), 's');
        
        return 0;
}