#include "vulkan_base.h"

namespace lh_vulkan
{
        bool VulkanBase::initVulkanInstance()
        {
                uint32_t layerPropertyCount = 0; 
                VKA(vkEnumerateInstanceLayerProperties(&layerPropertyCount,0));
                VkLayerProperties* layerProperties = new VkLayerProperties[layerPropertyCount];
                VKA(vkEnumerateInstanceLayerProperties(&layerPropertyCount, layerProperties));
                lhg::LOG_INFO("Available Layers: ");
                for (uint32_t i = 0; i < layerPropertyCount; i++)
                {
                        lhg::LOG_INFO(layerProperties[i].layerName, ": ", layerProperties[i].description);
                }
                
                const char* enabledLayers[] = {
                        "VK_LAYER_KHRONOS_validation"
                };
                
                VkApplicationInfo applicationInfo = {VK_STRUCTURE_TYPE_APPLICATION_INFO};
                applicationInfo.pApplicationName = "Vulkan Tutorial";
                applicationInfo.applicationVersion = VK_MAKE_VERSION(0, 0, 1);
                applicationInfo.apiVersion = VK_VERSION_1_2;
                
                VkInstanceCreateInfo createInfo = {VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO};
                createInfo.pApplicationInfo = &applicationInfo;
                createInfo.enabledLayerCount = ARRAY_COUNT(enabledLayers);
                createInfo.ppEnabledLayerNames = enabledLayers;
                
                lhg::LOG_INFO("Active Layers: ");
                for (uint32_t i = 0; i < createInfo.enabledLayerCount; i++)
                {
                        lhg::LOG_INFO(createInfo.ppEnabledLayerNames[i]);
                }
                
                if (VK(vkCreateInstance(&createInfo, 0, &context->instance) != VK_SUCCESS))
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