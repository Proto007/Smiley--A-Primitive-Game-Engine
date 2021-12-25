set(SOURCE_FILES 
	SmileyApp.cpp 
	GameWindow.cpp 
	GLFWimpl/GlfwImplementation.cpp 
	Renderer.cpp 
	Shader.cpp 
	Sprite.cpp 
	Events.cpp
	OpenGLimpl/OpenGLRenderer.cpp 
	OpenGLimpl/OpenGLSprite.cpp 
	OpenGLimpl/OpenGLShader.cpp
)

set(HEADER_FILES 
	Smiley.h 
	SmileyApp.h 
	SmileyUtils.h 
	WindowImplementation.h 
	GameWindow.h 
	GLFWimpl/GlfwImplementation.h
	Renderer.h 
	RendererImplementation.h
	Shader.h 
	ShaderImplementation.h
	Sprite.h 
	SpriteImplementation.h
	Events.h
	KeyCodes.h
	OpenGLimpl/OpenGLRenderer.h 
	OpenGLimpl/OpenGLSprite.h 
	OpenGLimpl/OpenGLShader.h
)

add_library(smiley_lib SHARED ${SOURCE_FILES} ${HEADER_FILES})

target_precompile_headers(smiley_lib PRIVATE pch.h)

add_definitions(-DSMILEY_LIB)
target_link_libraries(smiley_lib glfw glad stbi)

include_directories(../glfw/include)
include_directories(../Smiley)
include_directories(../glad/include)
include_directories(../stbi)