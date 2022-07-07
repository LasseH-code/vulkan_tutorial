cmake_minimum_required(VERSION 3.10)

# Project name
project(Tutorial)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")

set(COMPILE_DEFINITIONS /*VULKAN_INFO_OUTPUT*/ LHG_VERBOSE VULKAN_SUPPORT_SDL)

set(SOURCE_FILES src/main.cpp src/logger.cpp src/vulkan_base/vulkan_device.cpp src/vulkan_base/vulkan_swapchain.cpp src/vulkan_base/vulkan_SDL_support.cpp)

# Find SDL2
add_subdirectory(libs/SDL)

# Find Vulkan
find_package(Vulkan REQUIRED)

# Tutorial executable
add_compile_definitions(${COMPILE_DEFINITIONS})
add_executable(Tutorial ${SOURCE_FILES})
target_include_directories(Tutorial PUBLIC libs/SDL/include)
target_link_libraries(Tutorial PUBLIC SDL2-static)
target_include_directories(Tutorial PUBLIC ${Vulkan_INCLUDE_DIRS})
target_link_libraries(Tutorial PUBLIC ${Vulkan_LIBRARIES})