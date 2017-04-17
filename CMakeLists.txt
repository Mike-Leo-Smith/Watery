cmake_minimum_required(VERSION 3.7)
project(Watery)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

set(SOURCE_FILES
		main.cpp
		Engine/Component/component.cpp
		Engine/Component/component.h
		Engine/Component/position.cpp
		Engine/Component/position.h
		Engine/Component/coord.cpp
		Engine/Component/coord.h
		Engine/Resource/resource_manager.cpp
		Engine/Resource/resource_manager.h
		Engine/Object/entity.cpp
		Engine/Object/entity.h
		Engine/Component/component_node.h
		Engine/Message/messenger.cpp
		Engine/Message/messenger.h
		Engine/Message/message_bus.cpp
		Engine/Message/message_bus.h
		Engine/Message/message.cpp
		Engine/Message/message.h
		Engine/System/system.cpp
		Engine/System/system.h
		Middleware/HID/keyboard.cpp
		Middleware/HID/keyboard.h
		Middleware/HID/mouse.cpp
		Middleware/HID/mouse.h
		Middleware/Graphics/graphics.cpp
		Middleware/Graphics/graphics.h
		Middleware/Audio/audio.cpp
		Middleware/Audio/audio.h
		Engine/Scene/scene.cpp
		Engine/Scene/scene.h
		Middleware/Physics/physics.cpp
		Middleware/Physics/physics.h
		Engine/Input/input.cpp
		Engine/Input/input.h
		Engine/Renderer/renderer.cpp
		Engine/Renderer/renderer.h
		Engine/Sound/sound.cpp
		Engine/Sound/sound.h
		Engine/Animation/animation.cpp
		Engine/Animation/animation.h Middleware/Network/network.cpp Middleware/Network/network.h Engine/Commuication/communication.cpp Engine/Commuication/communication.h)

add_executable(Watery ${SOURCE_FILES})