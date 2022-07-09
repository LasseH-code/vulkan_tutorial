/* date = June 23rd 2022 7:23 pm */

#ifndef VULKAN_BASE_H
#define VULKAN_BASE_H

#include "../logger.h"
#include <vulkan/vulkan.h>
#include <cassert>
#include <vector>

#ifdef VULKAN_SUPPORT_SDL
#include <SDL.h>
#include <SDL_vulkan.h>
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
    static const DWORD CREATE_VULKAN_INSTANCE =        0b1<<0; // Replace everywhere possible with 0b1<<x
    static const DWORD FIND_PHYSICAL_DEVICE =          0b1<<1;
    static const DWORD GENERATE_LOGICAL_DEVICE =       0b1<<2;
    static const DWORD SAVE_GRAPHICS_QUEUE =           0b1<<3; 
    static const DWORD GENERATE_VULKAN_CONTEXT = CREATE_VULKAN_INSTANCE | FIND_PHYSICAL_DEVICE | GENERATE_LOGICAL_DEVICE | SAVE_GRAPHICS_QUEUE;
    
    static const DWORD CREATE_WINDOW_SDL =             0b1<<4;
    static const DWORD CREATE_SWAPCHAIN_KHR =          0b1<<5;
    static const DWORD CREATE_SURFACE_KHR_SDL =        0b1<<6;
    static const DWORD QUERY_INSTANCE_EXTENSIONS_SDL = 0b1<<7;
    static const DWORD SETUP_VIA_SDL = CREATE_WINDOW_SDL | CREATE_SWAPCHAIN_KHR | CREATE_SURFACE_KHR_SDL | QUERY_INSTANCE_EXTENSIONS_SDL;
    
    struct VulkanBaseSDLWindowCreationStruct
    {
        const char* title;
        int x;
        int y;
        int w;
        int h;
        uint32_t windowFlags;
    };
    
    struct VulkanBaseCreationStruct
    {
        DWORD creationFlags;
        VkImageUsageFlags usageFlags;
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
        uint32_t width;
        uint32_t height;
        VkFormat format;
        std::vector<VkImage> images;
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
        bool createSwapchain(VkImageUsageFlags usage);
        void deleteSwapchain();
#endif // VULKAN_HEADLESS
        
        public:
        VulkanBase(VulkanBaseCreationStruct* creationStruct);
        ~VulkanBase();
        
#ifndef VULKAN_HEADLESS
#ifdef VULKAN_SUPPORT_SDL
        VulkanBase(VulkanBaseCreationStruct* cs, SDL_Window* window);
        bool createSDLWindow(VulkanBaseSDLWindowCreationStruct* creationStruct, SDL_Window** window);
        bool createSurfaceSDL(SDL_Window** window);
        bool querySDLInstanceExtensions(VulkanBaseCreationStruct* cs, SDL_Window** window);
        bool querySDLInstanceExtensions(uint32_t* instanceExtensionCount, const char*** instanceExtensions, SDL_Window** window);
#endif // VULKAN_SUPPORT_SDL
#endif // VULKAN_HEADLESS
        
        int createVulkanInstance(VulkanBaseCreationStruct* creationStruct);
        void destroyVulkanInstance();
    };
}

#endif //VULKAN_BASE_H
