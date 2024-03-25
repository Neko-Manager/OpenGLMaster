#pragma once

///Includes from glm-library
#define GLM_ENABLE_EXPERIMENTAL 

#include <glm/glm.hpp>
#include <glm/gtc/quaternion.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/matrix_decompose.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <algorithm>

///Public class
struct Transform
{
	///Constructor for object instance
	Transform()
	{
		glm::vec3 mPosition = glm::vec3(0.0f);
		glm::quat mRotation = glm::quat(glm::identity<glm::quat>());
		glm::vec3 mScale = glm::vec3(1.0f);
	}

	///Adders
	

};