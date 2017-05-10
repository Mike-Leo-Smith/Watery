cmake_minimum_required(VERSION 3.7)
project(Watery)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -framework OpenGL -framework OpenAL -O3")

set(SOURCE_FILES
		main.cpp
		Watery/Engine/Mathematics/vector.cpp
		Watery/Engine/Mathematics/vector.h
		Watery/Engine/Configure/configure.h
		Watery/Engine/Component/position.cpp
		Watery/Engine/Component/position.h
		Watery/Engine/Component/velocity.cpp
		Watery/Engine/Component/velocity.h
		Watery/Engine/Component/shader.cpp
		Watery/Engine/Component/shader.h
		Watery/Engine/Component/texture.cpp
		Watery/Engine/Component/texture.h
		Watery/Engine/Component/audio.cpp
		Watery/Engine/Component/audio.h
		Watery/Engine/Component/component.cpp
		Watery/Engine/Component/component.h
		Watery/Engine/Component/component_node.h
		Watery/Engine/Component/component_factory.cpp
		Watery/Engine/Component/component_factory.h
		Watery/Engine/Resource/resource_manager.cpp
		Watery/Engine/Resource/resource_manager.h
		Watery/Engine/Object/object.cpp
		Watery/Engine/Object/object.h
		Watery/Engine/Message/messenger.cpp
		Watery/Engine/Message/messenger.h
		Watery/Engine/Message/message_bus.cpp
		Watery/Engine/Message/message_bus.h
		Watery/Engine/Message/message.cpp
		Watery/Engine/Message/message.h
		Watery/Engine/System/system.cpp
		Watery/Engine/System/system.h
		Watery/Engine/System/input.cpp
		Watery/Engine/System/input.h
		Watery/Engine/System/renderer.cpp
		Watery/Engine/System/renderer.h
		Watery/Engine/System/communication.cpp
		Watery/Engine/System/communication.h
		Watery/Engine/Message/keyboard_message.cpp
		Watery/Engine/Message/keyboard_message.h
		Watery/Engine/Timer/timer.cpp
		Watery/Engine/Timer/timer.h
		Watery/Engine/Object/camera.cpp
		Watery/Engine/Object/camera.h
		Watery/Framework/Network/network.cpp
		Watery/Framework/Network/network.h
		Watery/Framework/Clock/clock.cpp
		Watery/Framework/Clock/clock.h
		Watery/Engine/Physics/physics.cpp
		Watery/Engine/Physics/physics.h
		Watery/Framework/ThirdParty/lodepng.cpp
		Watery/Framework/ThirdParty/lodepng.h
		Watery/Framework/Audio/al_audio.cpp
		Watery/Framework/Audio/al_audio.h
		Watery/Framework/Graphics/gl_texture.cpp
		Watery/Framework/Graphics/gl_texture.h
		Watery/Framework/Graphics/gl_shader.cpp
		Watery/Framework/Graphics/gl_shader.h
		Watery/Framework/Graphics/gl_vertex_array.cpp
		Watery/Framework/Graphics/gl_vertex_array.h
		Watery/Framework/Window/window.cpp
		Watery/Framework/Window/window.h
		Watery/Framework/Audio/al_initializer.cpp
		Watery/Framework/Audio/al_initializer.h
		Watery/Engine/Mathematics/matrix.cpp
		Watery/Engine/Mathematics/matrix.h
		Watery/Engine/Mathematics/mathematics.cpp
		Watery/Engine/Mathematics/mathematics.h
		Watery/Engine/Mathematics/quaternion.cpp
		Watery/Engine/Mathematics/quaternion.h
		Watery/Engine/World/world.cpp
		Watery/Engine/World/world.h
		Watery/Engine/Component/component_manager.cpp
		Watery/Engine/Component/component_manager.h
		Watery/Engine/Component/vertex_array.cpp
		Watery/Engine/Component/vertex_array.h
		Watery/Framework/Graphics/gl_graphics.cpp
		Watery/Framework/Graphics/gl_graphics.h
		Watery/Engine/System/logic.cpp
		Watery/Engine/System/logic.h
		Watery/Engine/Message/mouse_message.cpp
		Watery/Engine/Message/mouse_message.h
		Watery/Engine/System/controller.cpp
		Watery/Engine/System/controller.h
		Watery/Engine/System/sound.cpp
		Watery/Engine/System/sound.h
		Watery/Framework/XML/xml_parser.cpp
		Watery/Framework/XML/xml_parser.h Watery/Engine/Component/frame_animation.cpp Watery/Engine/Component/frame_animation.h Watery/Engine/Component/health.cpp Watery/Engine/Component/health.h Watery/Engine/Component/position_animation.cpp Watery/Engine/Component/position_animation.h Watery/Engine/Physics/shape.cpp Watery/Engine/Physics/shape.h Watery/Engine/Physics/rectangle.cpp Watery/Engine/Physics/rectangle.h)

add_executable(Watery ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} glfw glew alut)