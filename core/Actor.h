#pragma once

///Libraries
#include <iostream>
#include <vector>
#include <Transform.h>
#include <Component.h> 

class Actor
{
public:
	///Actor object
	//Creating the object
	Actor(const std::string& name)
	{
		/*mTag(name); 
		mParent(nullptr);*/
	}

	//Deleting object
	Actor(const Actor&) = delete;
	Actor& operator = (const Actor&) = delete;

	//Deleting memory allocation "move"
	Actor(const Actor&&) = delete;
	Actor& operator = (const Actor&&) = delete;

	//Free Up Memory Space Actor uses
	~Actor();

	///Actor update
	//Update actor object
	virtual void Update(float dt) {}; //Member function which can be ovveridden by derived classes

	//Update actor components
	void UpdateComponents(float dt); //Updates the components of the object

    ///SceneGraph
	void SetParent(Actor* parent); //Sets parent to an Actor object
	void AddChild(Actor* child); //Adds child to Actor object Parent
	void RemoveChild(Actor* child); //Removes the child from the current Actor object of choice

	///Adders
	template <typename T> //template to create new actor component initializing it and add it directly into the mComponent array
	void AddComponent(const std::string& componentName)
	{
		static_assert(std::is_base_of<Component, T>::value, "T must be derived from Component");

		auto component = new T(componentName, this);
		component->Init();
		mComponents.emplace_back(component);
	}

	/// Setters
	//Set all values for where and how the object will be placed int the world or localy, as well as scale
	void SetTransform(const Transform& transform); 
	void SetLocalTransformMatrix(const glm::mat4& transformMatrix);
	void SetLocalPosition(const glm::vec3& position);
	void SetLocalRotation(const glm::quat& rotation);
	void SetLocalScale(const glm::vec3& scale);
	void SetWorldPosition(const glm::vec3& position);
	void SetWorldRotation(const glm::quat& rotation);
	void SetWorldScale(const glm::vec3& scale);

	/// Getters
	//Get all all information for the objects linear algebraL: where it is, what vector properties it has, scale etc
	//const glm::vec3& GetLocalPosition() const;
	glm::vec3 GetWorldPosition() const;
	//const glm::quat& GetLocalRotation() const;
	glm::quat GetWorldRotation() const;
	//const glm::vec3& GetLocalScale() const;
	glm::vec3 GetWorldScale() const;
	//const glm::mat4 GetLocalTransformMatrix() const;
	glm::mat4 GetWorldTransformMatrix() const;
	//const Transform& GetLocalTransform() const;
	//std::vector<Actor*>& GetChildren();
	glm::vec3 GetRight() const;

	///Adds actors of type T to a vector if they match the current object type
	template <typename T>
	void Query(std::vector<Actor*>& actors)
	{
		if (dynamic_cast<T*>(this))
			actors.emplace_back(this);

		for (auto child : this->mChildren)
			child->Query<T>(actors);
	}

protected:
	///Protected Scene graph
	Actor* mParent{ nullptr };
	std::vector<Actor*> mChildren;

	///Protected Components
	std::vector<Component*> mComponents;

private:
	/*TagUnique mTag;
	Transform mTransform{};*/
};