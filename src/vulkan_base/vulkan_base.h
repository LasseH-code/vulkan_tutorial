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

namespace lh_vulkan
{
        
        struct VulkanContext {
                VkInstance instance;
        };
        
        class VulkanBase
        {
                private: 
                VulkanContext* context;
                
                bool initVulkanInstance();
                
                public:
                VulkanBase();
        };
}

#endif //VULKAN_BASE_H
