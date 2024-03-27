#pragma once

#include <Actor.h>

///Function of class:
///Represent the root-node of the scene hierarcy. 
class SceneGraph : public Actor
{
public:
	SceneGraph(const std::string& name) : Actor(name) { };
};