//
// Created by Mike Smith on 2017/5/16.
//

#include "loader.h"

namespace watery
{
	void Loader::clear(void)
	{
		_world.destroy_all();
		_manager.destroy_all();
		_factory.destroy_all();
	}
	
	void Loader::configure(const std::string &file_name)
	{
		if (_config.empty())
		{
			_config.load(file_name);
			
			int width = atoi(_config.root()->child("window")[0]->attribute("width").c_str());
			int height = atoi(_config.root()->child("window")[0]->attribute("height").c_str());
			std::string name = _config.root()->child("window")[0]->attribute("title");
			
			_window.setup(name.c_str(), width, height);
		}
	}
	
	Loader &Loader::instance(void)
	{
		static Loader loader;
		return loader;
	}
	
	void Loader::load_level(const std::string &id)
	{
		clear();    // Clear old level data.
		
		if (!_config.empty())
		{
			XMLElement *level_info = nullptr;
			auto &levels = _config.root()->child("level");
			
			// Find the required level information.
			for (auto &level : levels)
			{
				if (level->attribute("id") == id)
				{
					level_info = level;
					break;
				}
			}
			
			// Load the level if it is found.
			if (level_info != nullptr)
			{
				// Load assets.
				for (auto asset : level_info->child("asset"))
				{
					for (auto shader : asset->child("gl_shader"))
					{
						_manager.get_shader(shader->attribute("name"), shader->attribute("path"));
					}
					
					for (auto vertex_array : asset->child("gl_vertex_array"))
					{
						_manager.get_vertex_array(vertex_array->attribute("name"), vertex_array->attribute("path"));
					}
					
					for (auto texture : asset->child("gl_texture"))
					{
						_manager.get_texture(texture->attribute("name"), texture->attribute("path"));
					}
					
					for (auto audio : asset->child(("al_audio")))
					{
						_manager.get_audio(audio->attribute("name"), audio->attribute("path"));
					}
				}
				
				// Configure the camera.
				for (auto world : level_info->child("world"))
				{
					for (auto camera : world->child("camera"))
					{
						float x = (float)atof(camera->attribute("x").c_str());
						float y = (float)atof(camera->attribute("y").c_str());
						float z = (float)atof(camera->attribute("z").c_str());
						
						_world.camera().set_position(Vector(x, y, z));
					}
				}
				
				// Create the objects.
				for (auto world : level_info->child("world"))
				{
					for (auto object : world->child("object"))
					{
						Object *obj = _world.create_object(object->attribute("name"));
						
						// Create the components.
						for (auto shader : object->child("shader"))
						{
							obj->bind_component(_factory.create_shader(_manager.get_shader(shader->attribute("res"))));
						}
						
						for (auto vertex_array : object->child("vertex_array"))
						{
							obj->bind_component(_factory.create_vertex_array(_manager.get_vertex_array(vertex_array->attribute("res"))));
						}
						
						for (auto texture : object->child("texture"))
						{
							obj->bind_component(_factory.create_texture(_manager.get_texture(texture->attribute("res"))));
						}
						
						for (auto audio : object->child("audio"))
						{
							obj->bind_component(_factory.create_audio(_manager.get_audio(audio->attribute("res"))));
						}
						
						for (auto position : object->child("position"))
						{
							float x = (float)atof(position->attribute("x").c_str());
							float y = (float)atof(position->attribute("y").c_str());
							float z = (float)atof(position->attribute("z").c_str());
							
							obj->bind_component(_factory.create_position(Vector(x, y, z)));
						}
						
						for (auto velocity : object->child("velocity"))
						{
							float vx = (float)atof(velocity->attribute("vx").c_str());
							float vy = (float)atof(velocity->attribute("vy").c_str());
							float vz = (float)atof(velocity->attribute("vz").c_str());
							
							obj->bind_component(_factory.create_velocity(Vector(vx, vy, vz)));
						}
						
						for (auto audio : object->child("audio"))
						{
							obj->bind_component(_factory.create_audio(_manager.get_audio(audio->attribute("res"))));
						}
					}
				}
			}
		}
	}
	
	void Loader::load_assets(const std::string &type, const std::string &name, const std::string &path)
	{
		if (type == "gl_shader") { _manager.get_shader(name, path); }
		else if (type == "gl_texture") { _manager.get_texture(name, path); }
		else if (type == "gl_vertex_array") { _manager.get_vertex_array(name, path); }
		else if (type == "al_audio") { _manager.get_audio(name, path); }
	}
}