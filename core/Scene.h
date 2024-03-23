#pragma once

#include <memory>
#include <iostream>

class Scene
{
public:
	///Scene object
	//Creating the instance
	Scene(const std::string& name);
	virtual ~Scene() = default;

	//Instance
	Scene(const Scene&) = delete; 
	Scene& operator = (const Scene&) = delete;

	//"Move" instance
	Scene(Scene&&) = delete;
	Scene& operator = (Scene&&) = delete;  

	///Content associated with the scene instance
	//Loading the associated content
	virtual void LoadContent();

	//Unloading the associated content
	virtual void UnloadContent();

	///Input Controller
	//Updates the input controller with deltaTime
	void UpdateInputController(float dt);

	///Scene Graph
	//void UpdateSceneGraph(Actor* actor, float dt, Transform globalParentTransform = Transform{});

	//void RenderSceneGraph(Actor* actor, float dt, Transform globalParentTransform = Transform{});

	//SceneGraph mSceneGraph; 

	///Scene Update
	//Updates the scene with deltaTime
	void SceneUpdate(float dt);

	///Collision
	//Handles the collision function with the respective objects
	void CollisionHandle();

	///Lighting
	//Binds the directional Lighting in the scene instance
	void BindDirectionalLight();

	//Binds the points lighting int the scene instance
	void BindPointsLights();

	///Camera
	//Binds the camera 
	void BindCamera();

	//CameraActor mSceneCamera{ "SceneCamera" };

	///UserInterface
	//Rendering the userinterface
	void RenderUI();

	///SceneRendering
	//Renders the scene instance with deltaTime
	void RenderUpdate(float dt);

	///Callback Funtions for window events
	void FramebufferSizeCallback(class Window* window, int width, int height); 
	void MouseMoveCallback(class Window* window, double xpos, double ypos);
	void MouseButtonCallback(class Window* window, int button, int action, int mods);
	void MouseScrollCallback(class Window* window, double xoffset, double yoffset);
	void KeyCallback(class Window* window, int key, int scancode, int action, int mods);

	///Activate Controller
	//void SetController(const std::shared_ptr<IController>& controller) { mActiveController = controller; };

	//std::shared_ptr<IController> GetController() const { return mActiveController; }; 

private:
	//MeshActor* mCubeActor0{ nullptr }; 
	//StaticMeshActor* mStaticMeshActor0{ nullptr }; 

	class Skybox* mSkybox{ nullptr }; 
	class Shader* mShader{ nullptr }; 

	/*PointLightActor* mPointLightActor{ nullptr }; 
	DirectionalLightActor* mDirectionalLightActor{ nullptr }; 

	std::shared_ptr<ActorController> mActorController; 
	std::shared_ptr<CameraController> mCameraController; */

protected:
	//std::shared_ptr<IController> mActiveController{ nullptr };



};