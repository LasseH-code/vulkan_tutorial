#include "vulkan_base.h"
#ifdef VULKAN_SUPPORT_SDL
namespace lh_vulkan
{
    VulkanBase::VulkanBase(VulkanBaseCreationStruct* cs, SDL_Window* window)
    {
        DWORD* flags = &cs->creationFlags;
        
        if (IS_FLAG_SET(*flags, CREATE_WINDOW_SDL) && !createSDLWindow(cs->sdlWindowCS, &window))
        {
            *cs->returnVal = 1;
            lhg::LOG_ERROR("An error occured whilst creating a SDL window (code ",*cs->returnVal,"). aborting");
            return;
        }
#ifdef VULKAN_INFO_OUTPUT
        if (IS_FLAG_SET(*flags, CREATE_WINDOW_SDL)) lhg::LOG_INFO("SDL Window created successfully!");
#endif // VULKAN_INFO_OUTPUT
        
        if (IS_FLAG_SET(*flags, QUERY_INSTANCE_EXTENSIONS_SDL) && !querySDLInstanceExtensions(cs, &window))
        {
            *cs->returnVal = 2;
            lhg::LOG_ERROR("An error occured whilst querying for instance Extensions (code ",*cs->returnVal,"). aborting");
            return;
        }
#ifdef VULKAN_INFO_OUTPUT
        if (IS_FLAG_SET(*flags, QUERY_INSTANCE_EXTENSIONS_SDL)) lhg::LOG_INFO("Query for InstanceExtensions successful!");
#endif // VULKAN_INFO_OUTPUT
        
        *cs->returnVal = createVulkanInstance(cs);
        
        
        if (IS_FLAG_SET(*flags, CREATE_SURFACE_KHR_SDL) && !createSurfaceSDL(&window))
        {
            lhg::LOG_ERROR("Couldn't create VkSurfaceKHR via SDL. aborting swapchain creation...");
            deleteSwapchain();
            return;
        }
#ifdef VULKAN_INFO_OUTPUT
        if (IS_FLAG_SET(*flags, CREATE_SURFACE_KHR_SDL)) lhg::LOG_INFO("Surface created successfully!");
#endif // VULKAN_INFO_OUTPUT
        
        if (IS_FLAG_SET(*flags, CREATE_SWAPCHAIN_KHR) && !createSwapchain(cs->usageFlags))
        {
            lhg::LOG_ERROR("Couldn't establish swapchain. aborting swapchain creation");
            deleteSwapchain();
            return;
        }
#ifdef VULKAN_INFO_OUTPUT
        if (IS_FLAG_SET(*flags, CREATE_SWAPCHAIN_KHR)) lhg::LOG_INFO("Swapchain created successfully!");
        lhg::LOG_INFO("Initialization done");
#endif // VULKAN_INFO_OUTPUT
    }
    
    bool VulkanBase::createSDLWindow(VulkanBaseSDLWindowCreationStruct* cs, SDL_Window** window)
    {
        *window = SDL_CreateWindow(cs->title, cs->x, cs->y, cs->w, cs->h, SDL_WINDOW_VULKAN | cs->windowFlags);
        if (!*window)
        {
            lhg::LOG_CRIT("Error creating SDL window: ", SDL_GetError());
            return 1;
        }
        //lhg::LOG_DEBUG("window: ", *window);
        return(*window);
    }
    
    bool VulkanBase::createSurfaceSDL(SDL_Window** window)
    {
        if (!SDL_Vulkan_CreateSurface(*window, context->instance, &swapchain->surface))
        {
            lhg::LOG_ERROR("Error creating Vulkan Surface via SDL");
            return false;
        }
        return true;
    }
    
    bool VulkanBase::querySDLInstanceExtensions(VulkanBaseCreationStruct* cs, SDL_Window** window)
    {
        if (!cs)
        {
            lhg::LOG_ERROR("Error whilst querying for Instance Extensions. continuing");
            return false;
        }
        return (querySDLInstanceExtensions(&cs->instanceExtensionCount, &cs->instanceExtensions, window));
    }
    
    bool VulkanBase::querySDLInstanceExtensions(uint32_t* instanceExtensionCount, const char*** instanceExtensions,  SDL_Window** window)
    {
        if (!window)
        {
            lhg::LOG_ERROR("Error whilst querying for Instance Extensions. continuing");
            return false;
        }
        SDL_Vulkan_GetInstanceExtensions(*window, instanceExtensionCount, 0);
        //if (instanceExtensions) delete[] *instanceExtensions;
        *instanceExtensions = new const char* [*instanceExtensionCount];
        SDL_Vulkan_GetInstanceExtensions(*window, instanceExtensionCount, *instanceExtensions);
        return true;
    }
}
#endif