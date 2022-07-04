/* date = June 23rd 2022 7:23 pm */

#ifndef VULKAN_BASE_H
#define VULKAN_BASE_H

#include "../logger.h"
#include <vulkan/vulkan.h>
#include <cassert>

#define ASSERT_VULKAN(val) if(val != VK_SUCCESS) {lhg::LOG_CRIT("An error occured"); assert(false);}
#ifndef VK
#define VK(f) f
#endif // VK
#ifndef VKA
#define VKA(f) ASSERT_VULKAN(VK(f))
#endif // VKA

#define ARRAY_COUNT(array) (sizeof(array) / sizeof((array)[0]))

//#define VULKAN_INFO_OUTPUT

namespace lh_vulkan
{
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
                VulkanContext* context;
                VulkanSwapchain* swapchain;
                
                private: 
                bool initVulkanInstance(uint32_t instanceExtensionCount, const char** instanceExtensions);
                bool selectPhysicalDevice();
                bool createLogicalDevice(uint32_t deviceExtensionCount, const char** deviceExtensions);
                bool createSwapchain(VkSurfaceKHR surface, VulkanSwapchain* swapchain);
                
                public:
                VulkanBase(uint32_t instanceExtensionCount, const char** instanceExtensions, uint32_t deviceExtensionCount, const char** deviceExtensions, void* createSurface);
                ~VulkanBase();
                
                int createVulkanInstance(uint32_t instanceExtensionCount, const char** instanceExtensions, uint32_t deviceExtensionCount, const char** deviceExtensions, void* createSurface);
                void destroyVulkanInstance();
        };
}

#endif //VULKAN_BASE_H
