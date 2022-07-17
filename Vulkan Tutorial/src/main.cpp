#include "memory/memory.h"
#include "pch.h"
//#include <stdio.h>
//#include "logger.h"
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_vulkan.h>
//#include <chrono>
#include "ezv_base.h"

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
    //LOG_INFO("info test");
    //LOG_DEBUG("debug test");
    //LOG_WARN("warning test");
    //LOG_ERROR("error test");
    //LOG_CRIT("critical test");
    
    //printMemoryUsage();
    
    std::chrono::time_point<std::chrono::system_clock> start, end;
    std::chrono::duration<double> elapsed_seconds;
    
    start = std::chrono::system_clock::now(); 
    LOG_WARN("Initializing...");
    
    SDL_Window* window = 0;
    
    int retV; 
    
    ezv::EzVSDLWindowCreateInfo windowCI = {"Vulkan Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1240, 720, SDL_WINDOW_VULKAN};
    
    const char* enabledDeviceExtensions[] {VK_KHR_SWAPCHAIN_EXTENSION_NAME};
    ezv::EzVCreateInfo ezVCI = {};
    ezVCI.creationFlags = ezv::GENERATE_VULKAN_CONTEXT | ezv::SETUP_VIA_SDL;
    ezVCI.usageFlags = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
    ezVCI.returnVal = &retV;
    ezVCI.deviceExtensionCount = ARRAY_COUNT(enabledDeviceExtensions);
    ezVCI.deviceExtensions = enabledDeviceExtensions;
    ezVCI.sdlWindowCS = &windowCI;
    
    ezv::EzV* ezv = new ezv::EzV(&ezVCI, window);
    
    end = std::chrono::system_clock::now(); 
    elapsed_seconds = end-start;
    LOG_WARN("Initialization successful - elapsed time: ", elapsed_seconds.count(), 's');
    
    //printMemoryUsage();
    
    while (handle_message())
    {
        
    }
    
    
    start = std::chrono::system_clock::now(); 
    delete ezv;
    LOG_WARN("Destroying window...");
    SDL_DestroyWindow(window);
    SDL_Quit();
    end = std::chrono::system_clock::now(); 
    elapsed_seconds = end-start;
    LOG_WARN("Destruction successful - elapsed time: ", elapsed_seconds.count(), 's');
    
    //printMemoryUsage();
    
    return 0;
}