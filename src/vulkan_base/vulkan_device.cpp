#include "vulkan_base.h"

namespace lh_vulkan
{
        bool VulkanBase::initVulkanInstance(uint32_t instanceExtensionCount, const char** instanceExtensions)
        {
                uint32_t layerPropertyCount = 0; 
                VKA(vkEnumerateInstanceLayerProperties(&layerPropertyCount,0));
                VkLayerProperties* layerProperties = new VkLayerProperties[layerPropertyCount];
                VKA(vkEnumerateInstanceLayerProperties(&layerPropertyCount, layerProperties));
#ifdef VULKAN_INFO_OUTPUT
                lhg::LOG_INFO("-----AVAILABLE LAYERS-----");
                for (uint32_t i = 0; i < layerPropertyCount; i++)
                {
                        lhg::LOG_INFO(layerProperties[i].layerName, ": ", layerProperties[i].description);
                }
                //lhg::LOG_INFO("--------------------------");
#endif // VULKAN_INFO_OUTPUT
                delete[] layerProperties;
                
                const char* enabledLayers[] = {
                        "VK_LAYER_KHRONOS_validation"
                };
                
                /*uint32_t availableInstanceExtensionCount;
                VKA(vkEnumerateInstanceExtensionProperties(0, &availableInstanceExtensionCount, 0));
                VkExtensionProperties* instanceExtensionProperties = new VkExtensionProperties[availableInstanceExtensionCount];
                VKA(vkEnumerateInstanceExtensionProperties(0, &availableInstanceExtensionCount, instanceExtensionProperties));
                lhg::LOG_INFO("Vulkan Extensions: ");
                for (uint32_t i = 0; i < availableInstanceExtensionCount; i++)
                {
                        lhg::LOG_INFO(instanceExtensionProperties[i].extensionName);
                }
                lhg::LOG_EMPTY();
                delete[] instanceExtensionProperties;*/
                
                VkApplicationInfo applicationInfo = {VK_STRUCTURE_TYPE_APPLICATION_INFO};
                applicationInfo.pApplicationName = "Vulkan Tutorial";
                applicationInfo.applicationVersion = VK_MAKE_VERSION(0, 0, 1);
                applicationInfo.apiVersion = VK_API_VERSION_1_2;
                
                VkInstanceCreateInfo createInfo = {VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO};
                createInfo.pApplicationInfo = &applicationInfo;
                createInfo.enabledLayerCount = ARRAY_COUNT(enabledLayers);
                createInfo.ppEnabledLayerNames = enabledLayers;
                createInfo.enabledExtensionCount = instanceExtensionCount;
                createInfo.ppEnabledExtensionNames = instanceExtensions;
                
#ifdef VULKAN_INFO_OUTPUT
                lhg::LOG_INFO("-------ACTIVE LAYERS------");
                for (uint32_t i = 0; i < createInfo.enabledLayerCount; i++)
                {
                        lhg::LOG_INFO(createInfo.ppEnabledLayerNames[i]);
                }
                lhg::LOG_INFO("--------------------------");
#endif // VULKAN_INFO_OUTPUT
                
                if (VK(vkCreateInstance(&createInfo, 0, &context->instance) != VK_SUCCESS))
                {
                        lhg::LOG_ERROR("Error creating vulkan instance");
                        return false;
                }
                
                return true;
        }
        
        bool VulkanBase::selectPhysicalDevice()
        {
                uint32_t numDevices = 0;
                VKA(vkEnumeratePhysicalDevices(context->instance, &numDevices, 0));
                if(numDevices == 0)
                {
                        lhg::LOG_CRIT("Failed to find GPU's with Vulkan Support!");
                        context->physicalDevice = 0;
                }
                VkPhysicalDevice* physicalDevices = new VkPhysicalDevice[numDevices];
                
                VKA(vkEnumeratePhysicalDevices(context->instance, &numDevices, physicalDevices));
                lhg::LOG_INFO("Found ", numDevices, " GPU(s): ");
                for (uint32_t i = 0; i < numDevices; i++)
                {
                        VkPhysicalDeviceProperties properties = {};
                        VK(vkGetPhysicalDeviceProperties(physicalDevices[i], &properties));
                        lhg::LOG_INFO("GPU ", i, ": ", properties.deviceName);
                }
                context->physicalDevice = physicalDevices[0];
                VK(vkGetPhysicalDeviceProperties(context->physicalDevice, &context->physicalDeviceProperties));
                lhg::LOG_INFO("Selected GPU: ", context->physicalDeviceProperties.deviceName);
                
                delete[] physicalDevices;
                return true;
        }
        
        
        VulkanBase::VulkanBase(uint32_t instanceExtensionCount, const char** instanceExtensions)
        {
                createVulkanInstance(instanceExtensionCount, instanceExtensions);
        }
        
        VulkanBase::~VulkanBase()
        {
                destroyVulkanInstance();
        }
        
        int VulkanBase::createVulkanInstance(uint32_t instanceExtensionCount, const char** instanceExtensions)
        {
                context = new VulkanContext;
                
                if (!initVulkanInstance(instanceExtensionCount, instanceExtensions))
                {
                        return 1;
                }
                
                if (!selectPhysicalDevice())
                {
                        return 2;
                }
#ifdef VULKAN_INFO_OUTPUT
                lhg::LOG_INFO("Vulkan instance created successfully");
#endif // VULKAN_INFO_OUTPUT
                return 0;
        }
        
        void VulkanBase::destroyVulkanInstance()
        {
                delete context;
#ifdef VULKAN_INFO_OUTPUT
                lhg::LOG_WARN("Vulkan instance destroyed");
#endif // VULKAN_INFO_OUTPUT
        }
}
