cmake_minimum_required(VERSION 3.7)
project(Watery)

set(CMAKE_CXX_STANDARD 14)
add_definitions(-DASIO_STANDALONE)

if (WIN32)
	add_definitions(-DGLEW_STATIC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -O3 -mwindows")
elseif (APPLE)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -framework OpenGL -framework OpenAL -O3")
endif ()

find_package(OpenCV REQUIRED)
include_directories(Watery/ThirdParty/ASIO)

set(SOURCE_FILES
		Demo/Mac/Sources/logic.cpp
		Demo/Mac/Sources/logic.h
		Demo/Mac/Sources/main.cpp
		Watery/Engine/Component/random_move_animation.cpp
		Watery/Engine/Component/random_move_animation.h
		Watery/Engine/Component/angular_velocity.h
        Watery/Engine/Component/animation.h
        Watery/Engine/Component/audio.h
        Watery/Engine/Component/bounding_shape.h
        Watery/Engine/Component/component.h
        Watery/Engine/Component/component_factory.cpp
        Watery/Engine/Component/component_factory.h
        Watery/Engine/Component/constraint.h
        Watery/Engine/Component/health.h
		Watery/Engine/Component/helix_move_animation.cpp
		Watery/Engine/Component/helix_move_animation.h
        Watery/Engine/Component/lifetime.h
        Watery/Engine/Component/position.h
        Watery/Engine/Component/rotation.h
		Watery/Engine/Component/scale.h
        Watery/Engine/Component/shader.h
		Watery/Engine/Component/shrink_animation.cpp
		Watery/Engine/Component/shrink_animation.h
		Watery/Engine/Component/texture.h
        Watery/Engine/Component/velocity.h
        Watery/Engine/Component/vertex_array.h
		Watery/Engine/Component/weapon.cpp
		Watery/Engine/Component/weapon.h
        Watery/Engine/Configuration/default.h
        Watery/Engine/Game/game.cpp
        Watery/Engine/Game/game.h
        Watery/Engine/Loader/loader.cpp
        Watery/Engine/Loader/loader.h
        Watery/Engine/Message/message.h
        Watery/Engine/Message/message_bus.cpp
        Watery/Engine/Message/message_bus.h
        Watery/Engine/Message/messenger.cpp
        Watery/Engine/Message/messenger.h
		Watery/Framework/Mathematics/mathematics.cpp
		Watery/Framework/Mathematics/mathematics.h
		Watery/Framework/Mathematics/matrix.cpp
		Watery/Framework/Mathematics/matrix.h
		Watery/Framework/Mathematics/quaternion.cpp
		Watery/Framework/Mathematics/quaternion.h
		Watery/Framework/Mathematics/vector.cpp
		Watery/Framework/Mathematics/vector.h
        Watery/Engine/Message/collision_event.h
        Watery/Engine/Message/dying_event.h
        Watery/Engine/Message/keyboard_event.h
		Watery/Engine/Message/mouse_event.h
		Watery/Framework/Physics/circle.cpp
		Watery/Framework/Physics/circle.h
		Watery/Framework/Physics/physics.cpp
		Watery/Framework/Physics/physics.h
		Watery/Framework/Physics/rectangle.cpp
		Watery/Framework/Physics/rectangle.h
		Watery/Framework/Physics/shape.h
        Watery/Engine/Resource/al_audio_wrapper.cpp
        Watery/Engine/Resource/al_audio_wrapper.h
        Watery/Engine/Resource/gl_shader_wrapper.cpp
        Watery/Engine/Resource/gl_shader_wrapper.h
        Watery/Engine/Resource/gl_texture_wrapper.cpp
        Watery/Engine/Resource/gl_texture_wrapper.h
        Watery/Engine/Resource/gl_vertex_array_wrapper.cpp
        Watery/Engine/Resource/gl_vertex_array_wrapper.h
        Watery/Engine/Resource/resource_manager.cpp
        Watery/Engine/Resource/resource_manager.h
        Watery/Engine/Resource/resource_wrapper.cpp
        Watery/Engine/Resource/resource_wrapper.h
        Watery/Engine/Resource/shape_wrapper.cpp
        Watery/Engine/Resource/shape_wrapper.h
        Watery/Engine/Scene/object.cpp
        Watery/Engine/Scene/object.h
        Watery/Engine/Scene/world.cpp
        Watery/Engine/Scene/world.h
        Watery/Engine/System/communication.cpp
        Watery/Engine/System/communication.h
        Watery/Engine/System/input.cpp
        Watery/Engine/System/input.h
        Watery/Engine/System/render.cpp
        Watery/Engine/System/render.h
        Watery/Engine/System/scene.cpp
        Watery/Engine/System/scene.h
        Watery/Engine/System/sound.cpp
        Watery/Engine/System/sound.h
        Watery/Engine/System/system.cpp
        Watery/Engine/System/system.h
        Watery/Engine/Timer/timer.h
        Watery/Framework/Audio/al_audio.cpp
        Watery/Framework/Audio/al_audio.h
        Watery/Framework/Audio/al_initializer.cpp
        Watery/Framework/Audio/al_initializer.h
        Watery/Framework/Clock/clock.cpp
        Watery/Framework/Clock/clock.h
        Watery/Framework/Graphics/gl_graphics.cpp
        Watery/Framework/Graphics/gl_graphics.h
        Watery/Framework/Graphics/gl_shader.cpp
        Watery/Framework/Graphics/gl_shader.h
        Watery/Framework/Graphics/gl_text.cpp
        Watery/Framework/Graphics/gl_text.h
        Watery/Framework/Graphics/gl_texture.cpp
        Watery/Framework/Graphics/gl_texture.h
        Watery/Framework/Graphics/gl_vertex_array.cpp
        Watery/Framework/Graphics/gl_vertex_array.h
        Watery/Framework/HID/keyboard.cpp
        Watery/Framework/HID/keyboard.h
		Watery/Framework/HID/mouse.cpp
		Watery/Framework/HID/mouse.h
		Watery/Framework/Network/client.cpp
		Watery/Framework/Network/client.h
		Watery/Framework/Network/server.cpp
		Watery/Framework/Network/server.h
		Watery/Framework/Network/network.cpp
		Watery/Framework/Network/network.h
		Watery/Framework/Window/window.cpp
        Watery/Framework/Window/window.h
        Watery/Framework/XML/xml_document.cpp
        Watery/Framework/XML/xml_document.h
        Watery/Framework/XML/xml_element.cpp
		Watery/Framework/XML/xml_element.h
		Watery/ThirdParty/LodePNG/lodepng.cpp
		Watery/ThirdParty/LodePNG/lodepng.h)

add_executable(Watery ${SOURCE_FILES})

if (APPLE)
	target_link_libraries(${PROJECT_NAME} glfw glew alut ${OpenCV_LIBS})
elseif (WIN32)
    target_link_libraries(${PROJECT_NAME} glew32 glfw3 opengl32)
endif ()