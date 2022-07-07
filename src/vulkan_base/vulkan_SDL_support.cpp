#include "vulkan_base.h"
#ifdef vulkan_SDL_SUPPORT
namespace lh_vulkan
{
        VulkanBase::VulkanBase(VulkanBaseCreationStruct* creationStruct, SDL_window* window)
        {
                *returnVal = createVulkanInstance(instanceExtensionCount, instanceExtensions, deviceExtensionCount, deviceExtensions, 0);
                
                if (IS_FLAG_SET(flags, CREATE_WINDOW_SDL) && !createSDLWindow(window, windowTitle, windowX, windowY, windowW, windowH, windowFlags))
                {
                        lhg::LOG_ERROR("An error occured whilst creating a SDL window. aborting swapchain creation...");
                        deleteSwapchain();
                        window = 0;
                        return;
                }
                
                
                if (IS_FLAG_SET(flags, CREATE_SWAPCHAIN_KHR) && !createSwapchain())
                {
                        lhg::LOG_ERROR("Couldn't establish swapchain. aborting swapchain creation...");
                        deleteSwapchain();
                        return;
                }
                
                if (IS_FLAG_SET(flags, CRATE_SURFACE_KHR_SDL) && !createSurfaceSDL(window))
                {
                        lhg::LOG_ERROR("Couldn't create VkSurfaceKHR via SDL. aborting swapchain creation...");
                        deleteSwapchain();
                        return;
                }
        }
        
        bool VulkanBase::createSDLWindow(const SDL_Window* window, char* windowTitle, int windowX, int windowY, int windowW, int windowH, uint32_t flags)
        {
                window = SDL_CreateWindow(windowTitle, windowX, windowY, windowW, windowH, SDL_WINDOW_VULKAN | flags);
                return(window);
        }
        
        bool VulkanBase::createSurfaceSDL(SDL_Window* window)
        {
                return SDL_Vulkan_CreateSurface(window, context->instance, swapchain->surface);
        }
}
#endif