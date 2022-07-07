/* date = June 23rd 2022 7:23 pm */

#ifndef VULKAN_BASE_H
#define VULKAN_BASE_H

#include "../logger.h"
#include <vulkan/vulkan.h>
#include <cassert>

#ifdef VULKAN_SUPPORT_SDL
#include <SDL.h>
#endif // VULKAN_SUPPORT_SDL

#define ASSERT_VULKAN(val) if(val != VK_SUCCESS) {lhg::LOG_CRIT("An error occured"); assert(false);}
#ifndef VK
#define VK(f) f
#endif // VK
#ifndef VKA
#define VKA(f) ASSERT_VULKAN(VK(f))
#endif // VKA

#define ARRAY_COUNT(array) (sizeof(array) / sizeof((array)[0]))
#define IS_FLAG_SET(flag, val) ((val & flag) == val)

//#define VULKAN_INFO_OUTPUT

namespace lh_vulkan
{
        static const DWORD CREATE_VULKAN_INSTANCE =   0b1; // Replace everywhere possible with 0b1<<x
        static const DWORD FIND_PHYSICAL_DEVICE =     0b10;
        static const DWORD GENERATE_LOGICAL_DEVICE =  0b100;
        static const DWORD SAVE_GRAPHICS_QUEUE =      0b1000; 
        static const DWORD GENERATE_VULKAN_CONTEXT =  0b1111;
        
        static const DWORD CREATE_WINDOW_SDL =        0b10000;
        static const DWORD CREATE_SWAPCHAIN_KHR =     0b100000;
        static const DWORD CREATE_SURFACE_KHR_SDL =   0b1000000;
        
        struct VulkanBaseSDLWindowCreationStruct
        {
                char* title;
                int x;
                int y;
                int w;
                int h;
                uint32_t windowFlags;
        };
        
        struct VulkanBaseCreationStruct
        {
                DWORD creationFlags;
                int* returnVal;
                
                uint32_t instanceExtensionCount;
                const char** instanceExtensions; 
                
                uint32_t deviceExtensionCount; 
                const char** deviceExtensions;
                
                //void* createSurface; 
                VulkanBaseSDLWindowCreationStruct* sdlWindowCS;
        };
        
        struct VulkanQueue
        {
                VkQueue queue;
                uint32_t familyIndex;
        };
        
        struct VulkanSwapchain {
                VkSwapchainKHR swapchain;
                VkSurfaceKHR surface;
        };
        
        struct VulkanContext 
        {
                VkInstance instance;
                VkPhysicalDevice physicalDevice;
                VkPhysicalDeviceProperties physicalDeviceProperties;
                VkDevice logicalDevice;
                VulkanQueue graphicsQueue;
        };
        
        class VulkanBase
        {
                public:
                VulkanContext* context = 0;
#ifndef VULKAN_HEADLESS
                VulkanSwapchain* swapchain = 0;
#endif //VULKAN_HEADLESS
                
                private: 
                bool initVulkanInstance(uint32_t instanceExtensionCount, const char** instanceExtensions);
                bool selectPhysicalDevice();
                bool createLogicalDevice(uint32_t deviceExtensionCount, const char** deviceExtensions);
#ifndef VULKAN_HEADLESS
                bool createSwapchain();
                void deleteSwapchain();
#endif // VULKAN_HEADLESS
                
                public:
                VulkanBase(VulkanBaseCreationStruct* creationStruct);
                ~VulkanBase();
                
#ifndef VULKAN_HEADLESS
#ifdef VULKAN_SUPPORT_SDL
                VulkanBase(VulkanBaseCreationStruct* creationStruct, SDL_Window* window);
                bool createSDLWindow(VulkanBaseSDLWindowCreationStruct* creationStruct, const SDL_Window* window);
                bool createSurfaceSDL(SDL_Window* window);
#endif // VULKAN_SUPPORT_SDL
#endif // VULKAN_HEADLESS
                
                int createVulkanInstance(VulkanBaseCreationStruct* creationStruct);
                void destroyVulkanInstance();
        };
}

#endif //VULKAN_BASE_H
