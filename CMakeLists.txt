#https://github.com/meemknight/SDL2OpenglCMakeSetup
#Version 1.0.0

cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

#! ! ! ! ! ! !
#set this to true to ship the game!
#basically this will change the RESOURCES_PATH to be the local path
#! ! ! ! ! ! !
#DELETE THE OUT FOLDER AFTER CHANGING THIS BECAUSE VISUAL STUDIO DOESN'T SEEM TO RECOGNIZE THIS CHANGE AND REBUILD!
option(PRODUCTION_BUILD "Make this a production build" OFF)
#DELETE THE OUT FOLDER AFTER CHANGING THIS BECAUSE VISUAL STUDIO DOESN'T SEEM TO RECOGNIZE THIS CHANGE AND REBUILD!


set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:Release>")
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE) #link time optimization

if(MSVC) 
add_compile_options(/arch:AVX2) #make sure SIMD optimizations take place
endif()

project(mygame)



set(SDL_STATIC ON)

add_subdirectory(thirdparty/SDL-release-2.30.5)		#window opener
add_subdirectory(thirdparty/glad)			#opengl loader
add_subdirectory(thirdparty/stb_image)			#loading images
add_subdirectory(thirdparty/stb_truetype)		#loading ttf files
#add_subdirectory(thirdparty/enet-1.3.17)		#networking
add_subdirectory(thirdparty/glm)			#math
add_subdirectory(thirdparty/imgui-docking)		#ui
add_subdirectory(thirdparty/gl2d)			#rendering
add_subdirectory(thirdparty/freetype)  #font loading

add_executable("${CMAKE_PROJECT_NAME}")

# Set paths explicitly
set(SDL2_MIXER_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/thirdparty/SDL2_mixer/include")
set(SDL2_MIXER_LIB "${CMAKE_SOURCE_DIR}/thirdparty/SDL2_mixer/lib/SDL2_mixer.lib") # Windows
#set(SDL2_MIXER_LIB "${CMAKE_SOURCE_DIR}/thirdparty/SDL2_mixer/lib/libSDL2_mixer.a") # Linux/macOS

# Debugging output
message(STATUS "SDL2_mixer include: ${SDL2_MIXER_INCLUDE_DIR}")
message(STATUS "SDL2_mixer lib: ${SDL2_MIXER_LIB}")

# Check if library exists
if(NOT EXISTS "${SDL2_MIXER_LIB}")
    message(FATAL_ERROR "SDL2_mixer library not found at ${SDL2_MIXER_LIB}")
endif()

# Define SDL2_mixer as an imported library
add_library(SDL2_mixer STATIC IMPORTED)
set_target_properties(SDL2_mixer PROPERTIES
    IMPORTED_LOCATION "${SDL2_MIXER_LIB}"
    INTERFACE_INCLUDE_DIRECTORIES "${SDL2_MIXER_INCLUDE_DIR}"
)

# Add SDL2_mixer to the executable
target_link_libraries("${CMAKE_PROJECT_NAME}" PRIVATE SDL2_mixer)



# MY_SOURCES is defined to be a list of all the source files for my game 
# DON'T ADD THE SOURCES BY HAND, they are already added with this macro
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")




set_property(TARGET "${CMAKE_PROJECT_NAME}" PROPERTY CXX_STANDARD 17)


target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC GLFW_INCLUDE_NONE=1) 

if(PRODUCTION_BUILD)
	# setup the ASSETS_PATH macro to be in the root folder of your exe
	target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC RESOURCES_PATH="./resources/") 
 
	target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC PRODUCTION_BUILD=1) 

else()
	# This is useful to get an ASSETS_PATH in your IDE during development
	target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC RESOURCES_PATH="${CMAKE_CURRENT_SOURCE_DIR}/resources/")
	target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC PRODUCTION_BUILD=0) 

endif()

target_sources("${CMAKE_PROJECT_NAME}" PRIVATE ${MY_SOURCES}  "include/SetupHelper.h"   "src/Object.cpp" "include/Object.h" "include/Shader.h" "src/Shader.cpp" "include/Texture.h" "src/Texture.cpp" "include/stb_image.h" "include/GameData.h" "include/Camera.h" "src/Camera.cpp" "include/GameState.h"  "include/MainMenuState.h" "src/MainMenuState.cpp" "src/Transform.cpp" "include/Transform.h" "src/PlayState.cpp" "include/World.h" "src/World.cpp" "include/StartState.h"    "include/Target.h" "src/Target.cpp" "include/AABB.h" "include/vec3.h" "src/vec3.cpp" "src/AABB.cpp" "include/AABB_test.h" "src/AABB_test.cpp" "src/StartState.cpp" "include/GameOverState.h" "src/GameOverState.cpp" "include/StateManager.h" "src/StateManager.cpp" "include/LTimer.h" "src/LTimer.cpp" "include/Observer.h" "include/ScoreManager.h" "src/ScoreManager.cpp" "include/Subject.h" "src/Subject.cpp" "include/Crosshair.h" "src/Crosshair.cpp" "include/HelperFunctions.h" "src/HelperFunctions.cpp" "include/FontManager.h" "src/FontManager.cpp" "src/Text.cpp" "include/Text.h" "include/Canvas.h" "src/Canvas.cpp" "include/UI.h" "src/UI.cpp" "include/SoundManager.h" "include/ButtonObserver.h" "include/ButtonEvent.h" "src/ButtonEvent.cpp" "include/BoxCollider2D.h" "src/BoxCollider2D.cpp"   "include/MMButtonManager.h" "src/MMButtonManager.cpp" "src/ButtonObserver.cpp" "include/Cursor.h" "src/Cursor.cpp" "include/BoxCollider2D_test.h" "src/BoxCollider2D_test.cpp" "include/GOButtonManager.h" "src/GOButtonManager.cpp" "src/GameData.cpp")


if(MSVC) # If using the VS compiler...

	target_compile_definitions("${CMAKE_PROJECT_NAME}" PUBLIC _CRT_SECURE_NO_WARNINGS)

	#add this line if you want to remove the console!
	#set_target_properties("${CMAKE_PROJECT_NAME}" PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup") #no console
	
	#set_property(TARGET "${CMAKE_PROJECT_NAME}" PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreadedDebug<$<CONFIG:Debug>:Debug>")
	#set_property(TARGET "${CMAKE_PROJECT_NAME}" PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Release>:Release>")

endif()

target_include_directories("${CMAKE_PROJECT_NAME}" PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/")



#target_link_libraries("${CMAKE_PROJECT_NAME}" PRIVATE glm 
#	glad stb_image stb_truetype gl2d imgui enet)

#enet not working yet on linux for some reason
target_link_libraries("${CMAKE_PROJECT_NAME}" PRIVATE glm 
	glad stb_image stb_truetype gl2d freetype imgui SDL2-static)