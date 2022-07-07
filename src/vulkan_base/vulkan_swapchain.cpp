#include "vulkan_base.h"

#ifndef VULKAN_HEADLESS
namespace lh_vulkan
{
        bool VulkanBase::createSwapchain()
        {
                VkBool32 supportsPresent = 0;
                VKA(vkGetPhysicalDeviceSurfaceSupportKHR(context->physicalDevice, context->graphicsQueue.familyIndex, swapchain->surface, &supportsPresent));
                if (!supportsPresent)
                {
                        lhg::LOG_ERROR("Graphics Queue dies not support present");
                        *swapchain = {}; 
                        return false;
                }
                return true;
        }
        
        void VulkanBase::deleteSwapchain()
        {
                if(swapchain)
                {
                        if(swapchain->swapchain)vkDestroySwapchainKHR(context->logicalDevice, swapchain->swapchain, 0);
                        if(swapchain->surface)vkDestroySurfaceKHR(context->instance, swapchain->surface, 0);
                        delete swapchain;
                        swapchain = 0;
                }
        }
}
#endif // VULKAN_HEADLESS