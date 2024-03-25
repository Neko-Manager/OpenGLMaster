#include "Actor.h"

Actor::~Actor()
{
}

void Actor::UpdateComponents(float dt)
{
}

void Actor::SetParent(Actor* parent)
{
}

void Actor::AddChild(Actor* child)
{
}

void Actor::RemoveChild(Actor* child)
{
}

void Actor::SetTransform(const Transform& transform)
{
}

void Actor::SetLocalTransformMatrix(const glm::mat4& transformMatrix)
{
}

void Actor::SetLocalPosition(const glm::vec3& position)
{
}

void Actor::SetLocalRotation(const glm::quat& rotation)
{
}

void Actor::SetLocalScale(const glm::vec3& scale)
{
}

void Actor::SetWorldPosition(const glm::vec3& position)
{
}

void Actor::SetWorldRotation(const glm::quat& rotation)
{
}

void Actor::SetWorldScale(const glm::vec3& scale)
{
}

//const glm::vec3& Actor::GetLocalPosition() const
//{
//	// TODO: insert return statement here
//}

glm::vec3 Actor::GetWorldPosition() const
{
	return glm::vec3();
}

//const glm::quat& Actor::GetLocalRotation() const
//{
//	// TODO: insert return statement here
//}

glm::quat Actor::GetWorldRotation() const
{
	return glm::quat();
}

//const glm::vec3& Actor::GetLocalScale() const
//{
//	// TODO: insert return statement here
//}

glm::vec3 Actor::GetWorldScale() const
{
	return glm::vec3();
}

//const glm::mat4 Actor::GetLocalTransformMatrix() const
//{
//	return glm::mat4();
//}

glm::mat4 Actor::GetWorldTransformMatrix() const
{
	return glm::mat4();
}

//const Transform& Actor::GetLocalTransform() const
//{
//	// TODO: insert return statement here
//}

//std::vector<Actor*>& Actor::GetChildren()
//{
//	// TODO: insert return statement here
//}

glm::vec3 Actor::GetRight() const
{
	return glm::vec3();
}
