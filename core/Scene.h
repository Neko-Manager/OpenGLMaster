#pragma once

#include <memory>
#include <iostream>

class Scene
{
public:
	explicit Scene(const std::string& name);
	virtual ~Scene() = default;
};