#include <stdio.h>
#include "logger.h"
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <SDL_vulkan.h>
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
    //lhg::LOG_CRIT("Test");
    
    std::chrono::time_point<std::chrono::system_clock> start, end;
    std::chrono::duration<double> elapsed_seconds;
    
    start = std::chrono::system_clock::now(); 
    lhg::LOG_WARN("Initializing...");
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        lhg::LOG_CRIT("Error initializing SDL: ", SDL_GetError());
        return 1;
    }
    
    SDL_Window* window = 0;/* = SDL_CreateWindow("Vulkan Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1240, 720, SDL_WINDOW_VULKAN);
    if (!window)
    {
        lhg::LOG_CRIT("Error creating SDL window");
        return 1;
    } 
    
    uint32_t instanceExtensionCount;
    SDL_Vulkan_GetInstanceExtensions(window, &instanceExtensionCount, 0);
    const char** enabledInstanceExtensions = new const char* [instanceExtensionCount];
    SDL_Vulkan_GetInstanceExtensions(window, &instanceExtensionCount, enabledInstanceExtensions);*/
    
    
    int retV; 
    
    lh_vulkan::VulkanBaseSDLWindowCreationStruct windowCS = {"Vulkan Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1240, 720, SDL_WINDOW_VULKAN};
    
    const char* enabledDeviceExtensions[] {VK_KHR_SWAPCHAIN_EXTENSION_NAME};
    lh_vulkan::VulkanBaseCreationStruct vulkanBaseCS = {};
    vulkanBaseCS.creationFlags = lh_vulkan::GENERATE_VULKAN_CONTEXT | lh_vulkan::SETUP_VIA_SDL;
    vulkanBaseCS.usageFlags = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
    vulkanBaseCS.returnVal = &retV;
    vulkanBaseCS.deviceExtensionCount = ARRAY_COUNT(enabledDeviceExtensions);
    vulkanBaseCS.deviceExtensions = enabledDeviceExtensions;
    vulkanBaseCS.sdlWindowCS = &windowCS;
    
    lh_vulkan::VulkanBase* vulkan_base = new lh_vulkan::VulkanBase(&vulkanBaseCS, window);
    
    end = std::chrono::system_clock::now(); 
    elapsed_seconds = end-start;
    lhg::LOG_WARN("Initialization successful - elapsed time: ", elapsed_seconds.count(), 's');
    
    
    while (handle_message())
    {
        
    }
    
    
    start = std::chrono::system_clock::now(); 
    delete vulkan_base;
    lhg::LOG_WARN("Destroying window...");
    SDL_DestroyWindow(window);
    SDL_Quit();
    end = std::chrono::system_clock::now(); 
    elapsed_seconds = end-start;
    lhg::LOG_WARN("Destruction successful - elapsed time: ", elapsed_seconds.count(), 's');
    
    return 0;
}