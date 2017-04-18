cmake_minimum_required(VERSION 3.7)
project(Watery)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

set(SOURCE_FILES
		main.cpp
		Watery/Engine/Component/component.cpp
		Watery/Engine/Component/component.h
		Watery/Engine/Component/position.cpp
		Watery/Engine/Component/position.h
		Watery/Data/Coord/coord.cpp
		Watery/Data/Coord/coord.h
		Watery/Engine/Resource/resource_manager.cpp
		Watery/Engine/Resource/resource_manager.h
		Watery/Engine/Object/entity.cpp
		Watery/Engine/Object/entity.h
		Watery/Engine/Component/component_node.h
		Watery/Engine/Message/messenger.cpp
		Watery/Engine/Message/messenger.h
		Watery/Framework/MessageBus/message_bus.cpp
		Watery/Framework/MessageBus/message_bus.h
		Watery/Engine/Message/message.cpp
		Watery/Engine/Message/message.h
		Watery/Engine/System/system.cpp
		Watery/Engine/System/system.h
		Watery/Framework/HID/keyboard.cpp
		Watery/Framework/HID/keyboard.h
		Watery/Framework/HID/mouse.cpp
		Watery/Framework/HID/mouse.h
		Watery/Framework/Graphics/graphics.cpp
		Watery/Framework/Graphics/graphics.h
		Watery/Framework/Audio/audio.cpp
		Watery/Framework/Audio/audio.h
		Watery/Engine/Scene/scene.cpp
		Watery/Engine/Scene/scene.h
		Watery/Framework/Physics/physics.cpp
		Watery/Framework/Physics/physics.h
		Watery/Engine/Input/input.cpp
		Watery/Engine/Input/input.h
		Watery/Engine/Renderer/renderer.cpp
		Watery/Engine/Renderer/renderer.h
		Watery/Engine/Sound/sound.cpp
		Watery/Engine/Sound/sound.h
		Watery/Engine/Animation/animation.cpp
		Watery/Engine/Animation/animation.h
		Watery/Framework/Network/network.cpp
		Watery/Framework/Network/network.h
		Watery/Engine/Commuication/communication.cpp
		Watery/Engine/Commuication/communication.h
		Watery/Engine/Message/keyboard_message.cpp
		Watery/Engine/Message/keyboard_message.h
		Watery/Framework/Clock/clock.cpp
		Watery/Framework/Clock/clock.h
		Watery/Engine/Timer/timer.cpp
		Watery/Engine/Timer/timer.h
		Watery/Framework/Context/context.cpp
		Watery/Framework/Context/context.h)

add_executable(Watery ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} glfw)