#pragma once
#include <string>

namespace defender
{
	class Resource
	{
	public:
		virtual bool Create(const std::string& name, void* data = nullptr) = 0;
	};
}