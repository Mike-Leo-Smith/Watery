//
// Created by Mike Smith on 2017/4/17.
//

#include "scene.h"
#include "../Message/keyboard_message.h"

namespace watery
{
	void Scene::_handle_keyboard_message(Message *message)
	{
		KeyboardMessage *cast_message = static_cast<KeyboardMessage *>(message);
		
		switch (cast_message->code())
		{
		case KEY_UP:
			_camera.move_y(5);
			break;
		
		case KEY_DOWN:
			_camera.move_y(-5);
			break;
		
		case KEY_LEFT:
			_camera.move_x(-5);
			break;
		
		case KEY_RIGHT:
			_camera.move_x(5);
			break;
		
		default:
			break;
		}
	}
}