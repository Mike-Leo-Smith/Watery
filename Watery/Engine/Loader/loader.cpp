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
			XMLElement *expected_level_tag = nullptr;
			auto &level_tags = _config.root()->child("level");
			
			// Find the required level information.
			for (auto &level_tag : level_tags)
			{
				if (level_tag->attribute("id") == id)
				{
					expected_level_tag = level_tag;
					break;
				}
			}
			
			// Load the level if it is found.
			if (expected_level_tag != nullptr)
			{
				// Load assets.
				for (auto asset_tag : expected_level_tag->child("asset"))
				{
					for (auto child_tags : asset_tag->children())
					{
						for (auto child_tag : child_tags.second)
						{
							_manager.get_resource(child_tag->tag(), child_tag->attribute("name"), child_tag->attribute("path"));
						}
					}
				}
				
				// Create the objects.
				for (auto world_tag : expected_level_tag->child("world"))       // Traverse all world tags.
				{
					for (auto object_tags : world_tag->child("object"))      // Traverse all object tags in a world tag.
					{
						Object *object = _world.create_object(object_tags->attribute("name"));
						
						// Create the components and bind it to the object.
						for (auto component_tags : object_tags->children())   // Traverse all component tags in a object tag.
						{
							for (auto component_tag : component_tags.second)
							{
								object->create_component(component_tag->tag(), component_tag->attribute("res"));
							}
						}
					}
				}
			}
		}
	}
}