#pragma once
#include "Resource.h"
#include <map>
#include <string>
#include <memory>
#include <cstdarg>

namespace defender
{
	class ResourceManager
	{
	public:
		ResourceManager() = default;
		~ResourceManager() = default;

		void Initialize();
		void ShutDown();

		template <typename T>
		std::shared_ptr<T> GetA(const std::string& name, void* data = nullptr);
		template <typename T, typename ... TArgs>
		std::shared_ptr<T> Get(const std::string& name, TArgs... args);

	private:
		std::map<std::string, std::shared_ptr<Resource>> m_resources;
	};

	template<typename T>
	inline std::shared_ptr<T> ResourceManager::GetA(const std::string& name, void* data)
	{
		if (m_resources.find(name) != m_resources.end())
		{
			// Found
			return std::dynamic_pointer_cast<T>(m_resources[name]);
		}
		else
		{
			// Wasn't Found, Create Resource and Entered Into Resources
			std::shared_ptr<T> resource = std::make_shared<T>();
			resource->Create(name, data);
			m_resources[name] = resource;

			return resource;
		}
	}

	template<typename T, typename ... TArgs>
	inline std::shared_ptr<T> ResourceManager::Get(const std::string& name, TArgs... args)
	{
		if (m_resources.find(name) != m_resources.end())
		{
			// found 
			return std::dynamic_pointer_cast<T>(m_resources[name]);
		}
		else
		{
			// not found, create resource and enter into resources 
			std::shared_ptr<T> resource = std::make_shared<T>();
			resource->Create(name, args...);
			m_resources[name] = resource;

			return resource;
		}
	}
}
