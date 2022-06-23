#include "vulkan_base.h"

namespace lh_vulkan
{
        bool VulkanBase::initVulkanInstance()
        {
                VkApplicationInfo applicationInfo = {VK_STRUCTURE_TYPE_APPLICATION_INFO};
                applicationInfo.pApplicationName = "Vulkan Tutorial";
                applicationInfo.applicationVersion = VK_MAKE_VERSION(0, 0, 1);
                applicationInfo.apiVersion = VK_VERSION_1_2;
                
                VkInstanceCreateInfo createInfo = {VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO};
                createInfo.pApplicationInfo = &applicationInfo;
                
                if (vkCreateInstance(&createInfo, 0, &context->instance) != VK_SUCCESS)
                {
                        lhg::LOG_ERROR("Error creating vulkan instance");
                        return false;
                }
                
                return true;
        }
        
        VulkanBase::VulkanBase()
        {
                context = new VulkanContext;
                
                if (!initVulkanInstance())
                {
                        return;
                }
                lhg::LOG_INFO("Vulkan instance created successfully");
        }
}