#include "vulkan_base.h"

namespace lh_vulkan
{
        bool VulkanBase::createSwapchain(VkSurfaceKHR surface, VulkanSwapchain* swapchain)
        {
                VkBool32 supportsPresent = 0;
                VKA(vkGetPhysicalDeviceSurfaceSupportKHR(context->physicalDevice, context->graphicsQueue.familyIndex, surface, &supportsPresent));
                if (!supportsPresent)
                {
                        lhg::LOG_ERROR("Graphics Queue dies not support present");
                        *swapchain = {}; 
                        return false;
                }
                return true;
        }
}