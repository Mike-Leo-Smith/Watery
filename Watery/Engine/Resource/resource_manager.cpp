//
// Created by Mike Smith on 2017/4/17.
//

#include <gl/glew.h>
#include <string>
#include <fstream>
#include <sstream>
#include "resource_manager.h"
#include "gl_texture_wrapper.h"
#include "gl_shader_wrapper.h"
#include "gl_vertex_array_wrapper.h"
#include "al_audio_wrapper.h"
#include "shape_wrapper.h"

namespace watery
{
	ResourceManager::~ResourceManager(void)
	{
		destroy_all();
	}
	
	void ResourceManager::destroy_all(void)
	{
		for (auto resource : _resources)
		{
			delete resource.second;
		}
		_resources.clear();
	}
	
	ResourceManager &ResourceManager::instance(void)
	{
		static ResourceManager manager;
		return manager;
	}
	
	ResourceWrapper *ResourceManager::get_resource(const std::string &type, const std::string &name, const std::string &file_name)
	{
		ResourceWrapper *resource = nullptr;
		
		// Return the resource directly if it has been loaded.
		if (_resources.count(name) != 0)
		{
			resource = _resources.at(name);
		}
		else
		{
			if (type == "gl_texture") { resource = new GLTextureWrapper(file_name); }
			else if (type == "gl_shader") { resource = new GLShaderWrapper(file_name); }
			else if (type == "gl_vertex_array") { resource = new GLVertexArrayWrapper(file_name); }
			else if (type == "al_audio") { resource = new ALAudioWrapper(file_name); }
			else if (type == "shape") { resource = new ShapeWrapper(file_name); }
			
			if (resource != nullptr)
			{
				_resources.emplace(name, resource);
			}
		}
		
		return resource;
	}
	
	void ResourceManager::destroy_resource(const std::string &name)
	{
		if (_resources.count(name) != 0)
		{
			delete _resources.at(name);
			_resources.erase(name);
		}
	}
}