cmake_minimum_required(VERSION 3.7)
project(Watery)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -framework OpenGL -framework OpenAL")

set(SOURCE_FILES
		main.cpp
		Game/Sources/game.cpp
		Game/Sources/game.h
		Watery/Data/Size/size.cpp
		Watery/Data/Size/size.h
		Watery/Data/Color/color.cpp
		Watery/Data/Color/color.h
		Watery/Data/Vector/vector.cpp
		Watery/Data/Vector/vector.h
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
		Watery/Engine/Resource/resource.cpp
		Watery/Engine/Resource/resource.h
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
		Watery/Engine/Sound/sound.cpp
		Watery/Engine/Sound/sound.h
		Watery/Engine/Object/animation.cpp
		Watery/Engine/Object/animation.h
		Watery/Engine/System/communication.cpp
		Watery/Engine/System/communication.h
		Watery/Engine/Message/keyboard_message.cpp
		Watery/Engine/Message/keyboard_message.h
		Watery/Engine/Timer/timer.cpp
		Watery/Engine/Timer/timer.h
		Watery/Engine/Object/camera.cpp
		Watery/Engine/Object/camera.h
		Watery/Engine/Resource/resource_manager.cpp
		Watery/Engine/Resource/resource_manager.h
		Watery/Framework/Network/network.cpp
		Watery/Framework/Network/network.h
		Watery/Framework/Clock/clock.cpp
		Watery/Framework/Clock/clock.h
		Watery/Engine/Physics/physics.cpp
		Watery/Engine/Physics/physics.h
		Watery/Framework/Image/lodepng.cpp
		Watery/Framework/Image/lodepng.h
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
		Watery/Framework/Audio/al_initializer.h Watery/Data/Matrix/matrix.cpp Watery/Data/Matrix/matrix.h Watery/Engine/Mathematics/mathematics.cpp Watery/Engine/Mathematics/mathematics.h Watery/Data/Quaternion/quaternion.cpp Watery/Data/Quaternion/quaternion.h)

add_executable(Watery ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} glfw glew alut)