#include "Scene.h"

///Includes 
#include <Actor.h>
#include <imgui.h>
#include <GLFW/glfw3.h>

Scene::Scene(const std::string& name): mSceneGraph(name) {} //Initialization list must be used when init an object

void Scene::LoadContent()
{
	//LOG_INFO("Scene::LoadContent");

	//Texture* diffuseTex = Texture::Load(SOURCE_DIRECTORY("assets/textures/container2.jpg"));
	//Texture* specularTex = Texture::Load(SOURCE_DIRECTORY("assets/textures/container2_specular.jpg"));
	//Material* mat = Material::Load("Default", { diffuseTex, specularTex }, {});

	//mCubeActor0 = new MeshActor("Cube0", Mesh::LoadCube(mat));

	//mPointLightActor = new PointLightActor("PointLight0");
	//mDirectionalLightActor = new DirectionalLightActor("DirectionalLight0");

	//mStaticMeshActor0 = new StaticMeshActor("StaticMeshActor0");
	//AssimpLoader::Load(SOURCE_DIRECTORY("assets/models/sponza/sponza.fbx"), mStaticMeshActor0);

	//mSkybox = new Skybox({
	//	SOURCE_DIRECTORY("assets/textures/starfield_And_Haze/Starfield_And_Haze_left.png"),
	//	SOURCE_DIRECTORY("assets/textures/starfield_And_Haze/Starfield_And_Haze_right.png"),
	//	SOURCE_DIRECTORY("assets/textures/starfield_And_Haze/Starfield_And_Haze_up.png"),
	//	SOURCE_DIRECTORY("assets/textures/starfield_And_Haze/Starfield_And_Haze_down.png"),
	//	SOURCE_DIRECTORY("assets/textures/starfield_And_Haze/Starfield_And_Haze_front.png"),
	//	SOURCE_DIRECTORY("assets/textures/starfield_And_Haze/Starfield_And_Haze_back.png"),
	//	});

	//mShader = new Shader(SOURCE_DIRECTORY("assets/shaders/shader.vs"), SOURCE_DIRECTORY("assets/shaders/shader.fs"));

	//mSceneGraph.AddChild(&mSceneCamera);
	//mSceneGraph.AddChild(mCubeActor0);
	//mSceneGraph.AddChild(mStaticMeshActor0);
	////mSceneGraph.AddChild(mPointLightActor);
	////mSceneGraph.AddChild(mDirectionalLightActor);

	//mCubeActor0->AddComponent<PhysicsComponent>("Cube0PhysicsComponent");
	//mCubeActor0->mCollisionProperties.mType = CollisionType::DYNAMIC;
	//mCubeActor0->SetWorldPosition({ 0.f, 10.f, 0.f });

	//mSceneCamera.SetWorldPosition({ 0.f, 2.f, 3.f });
	//mSceneCamera.SetPitch(-30.f);

	//mDirectionalLightActor->SetWorldRotation(glm::angleAxis(glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f)));
	////mPointLightActor->SetPosition({ 0.f, 2.0f, 0.f });

	//mActorController = std::shared_ptr<ActorController>(new ActorController(mCubeActor0));
	//mCameraController = std::shared_ptr<CameraController>(new CameraController(&mSceneCamera));

	//mActiveController = mCameraController
}

void Scene::UnloadContent()
{
	/*delete mShader;
	mShader = nullptr;
	delete mCubeActor0; 
	mCubeActor0 = nullptr;
	delete mStaticMeshActor0; 
	mStaticMeshActor0 = nullptr;
	delete mPointLightActor; 
	mPointLightActor = nullptr;
	delete mDirectionalLightActor; 
	mDirectionalLightActor = nullptr;
	delete mSkybox;
	mSkybox = nullptr;*/
}

void Scene::UpdateInputController(float dt)
{
	//if (mActiveController) mActiveController->Update(dt);
}

void Scene::UpdateSceneGraph(Actor* actor, float dt, Transform globalParentTransform)
{
	if (!actor) return;

	actor->Update(dt);
	actor->UpdateComponents(dt);

	globalParentTransform.SetTransformMatrix(globalParentTransform.GetTransformMatrix() * actor->GetLocalTransformMatrix());

	const auto& children = actor->GetChildren();
	for (Actor* child : children)
	{
		UpdateSceneGraph(child, dt, globalParentTransform);
	}
}

void Scene::RenderSceneGraph(Actor* actor, float dt, Transform globalParentTransform)
{
	if (!actor) return;

	globalParentTransform.SetTransformMatrix(globalParentTransform.GetTransformMatrix() * actor->GetLocalTransformMatrix());

	/*if (auto iRender = dynamic_cast<IRender*>(actor))
	{
		mShader->setMat4("model", globalParentTransform.GetTransformMatrix());
		iRender->Draw(mShader);
	}*/

	const auto& children = actor->GetChildren();
	for (Actor* child : children)
	{
		RenderSceneGraph(child, dt, globalParentTransform);
	}
}

void Scene::SceneUpdate(float dt)
{
}

void Scene::CollisionHandle()
{
}

void Scene::BindDirectionalLight()
{
}

void Scene::BindPointsLights()
{
}

void Scene::BindCamera()
{
}

void Scene::RenderUI()
{
}

void Scene::RenderUpdate(float dt)
{
}

void Scene::FramebufferSizeCallback(Window* window, int width, int height)
{
}

void Scene::MouseMoveCallback(Window* window, double xpos, double ypos)
{
}

void Scene::MouseButtonCallback(Window* window, int button, int action, int mods)
{
}

void Scene::MouseScrollCallback(Window* window, double xoffset, double yoffset)
{
}

void Scene::KeyCallback(Window* window, int key, int scancode, int action, int mods)
{
}
