# Install script for directory: P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/Tutorial")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/Debug/SDL2d.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/Release/SDL2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/MinSizeRel/SDL2.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY OPTIONAL FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/RelWithDebInfo/SDL2.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/bin/Debug/SDL2d.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/bin/Release/SDL2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/bin/MinSizeRel/SDL2.dll")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE SHARED_LIBRARY FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/bin/RelWithDebInfo/SDL2.dll")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/Debug/SDL2maind.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/Release/SDL2main.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/MinSizeRel/SDL2main.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/RelWithDebInfo/SDL2main.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/Debug/SDL2-staticd.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/Release/SDL2-static.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/MinSizeRel/SDL2-static.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/RelWithDebInfo/SDL2-static.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/Debug/SDL2_test.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/Release/SDL2_test.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/MinSizeRel/SDL2_test.lib")
  elseif("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/RelWithDebInfo/SDL2_test.lib")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2Targets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2Targets.cmake"
         "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/CMakeFiles/Export/cmake/SDL2Targets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2Targets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2Targets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/CMakeFiles/Export/cmake/SDL2Targets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/CMakeFiles/Export/cmake/SDL2Targets-debug.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/CMakeFiles/Export/cmake/SDL2Targets-minsizerel.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/CMakeFiles/Export/cmake/SDL2Targets-relwithdebinfo.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/CMakeFiles/Export/cmake/SDL2Targets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2mainTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2mainTargets.cmake"
         "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/CMakeFiles/Export/cmake/SDL2mainTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2mainTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2mainTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/CMakeFiles/Export/cmake/SDL2mainTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/CMakeFiles/Export/cmake/SDL2mainTargets-debug.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/CMakeFiles/Export/cmake/SDL2mainTargets-minsizerel.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/CMakeFiles/Export/cmake/SDL2mainTargets-relwithdebinfo.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/CMakeFiles/Export/cmake/SDL2mainTargets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2staticTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2staticTargets.cmake"
         "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/CMakeFiles/Export/cmake/SDL2staticTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2staticTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2staticTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/CMakeFiles/Export/cmake/SDL2staticTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/CMakeFiles/Export/cmake/SDL2staticTargets-debug.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/CMakeFiles/Export/cmake/SDL2staticTargets-minsizerel.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/CMakeFiles/Export/cmake/SDL2staticTargets-relwithdebinfo.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/CMakeFiles/Export/cmake/SDL2staticTargets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2testTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2testTargets.cmake"
         "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/CMakeFiles/Export/cmake/SDL2testTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2testTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/cmake/SDL2testTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/CMakeFiles/Export/cmake/SDL2testTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/CMakeFiles/Export/cmake/SDL2testTargets-debug.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/CMakeFiles/Export/cmake/SDL2testTargets-minsizerel.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/CMakeFiles/Export/cmake/SDL2testTargets-relwithdebinfo.cmake")
  endif()
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/CMakeFiles/Export/cmake/SDL2testTargets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake" TYPE FILE FILES
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/SDL2Config.cmake"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/SDL2ConfigVersion.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/SDL2" TYPE FILE FILES
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_assert.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_atomic.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_audio.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_bits.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_blendmode.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_clipboard.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_config.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_config_android.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_config_emscripten.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_config_iphoneos.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_config_macosx.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_config_minimal.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_config_ngage.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_config_os2.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_config_pandora.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_config_windows.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_config_winrt.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_copying.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_cpuinfo.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_egl.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_endian.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_error.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_events.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_filesystem.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_gamecontroller.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_gesture.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_guid.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_haptic.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_hidapi.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_hints.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_joystick.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_keyboard.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_keycode.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_loadso.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_locale.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_log.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_main.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_messagebox.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_metal.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_misc.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_mouse.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_mutex.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_name.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_opengl.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_opengl_glext.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_opengles.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_opengles2.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_opengles2_gl2.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_opengles2_gl2ext.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_opengles2_gl2platform.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_opengles2_khrplatform.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_pixels.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_platform.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_power.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_quit.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_rect.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_render.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_rwops.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_scancode.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_sensor.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_shape.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_stdinc.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_surface.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_system.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_syswm.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_test.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_test_assert.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_test_common.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_test_compare.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_test_crc32.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_test_font.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_test_fuzzer.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_test_harness.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_test_images.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_test_log.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_test_md5.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_test_memory.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_test_random.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_thread.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_timer.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_touch.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_types.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_version.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_video.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/SDL_vulkan.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/begin_code.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/libs/SDL/include/close_code.h"
    "P:/Resources/4Coder/4coder/projects/vulkan_tutorial/build/libs/SDL/include/SDL_revision.h"
    )
endif()

