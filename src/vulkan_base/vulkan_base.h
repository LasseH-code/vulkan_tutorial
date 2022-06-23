/* date = June 23rd 2022 7:23 pm */

#ifndef VULKAN_BASE_H
#define VULKAN_BASE_H

#include "../logger.h"
#include <vulkan/vulkan.h>

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
