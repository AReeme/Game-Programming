#include "Engine.h"

int main()
{
	defender::InitializeMemory();
	defender::SetFilePath("../Assets");

	// Initialize Engine
	defender::g_renderer.Initialize();
	defender::g_inputSystem.Initialize();
	defender::g_audiosystem.Initialize();
	defender::g_resources.Initialize();

	//Create Window
	defender::g_renderer.CreateWindow("Neumont", 800, 600);
	defender::g_renderer.SetClearColor(defender::Color{ 50, 50, 50, 255 });

	//Load Assets
	//std::shared_ptr<defender::Texture> texture = std::make_shared<defender::Texture>();
	//texture->Create(defender::g_renderer, "Textures/SpaceShip.png");
	std::shared_ptr<defender::Texture> texture = defender::g_resources.Get<defender::Texture>("Textures/SpaceShip.png", &defender::g_renderer);

	//std::shared_ptr<defender::Model> model = std::make_shared<defender::Model>();
	//model->Create("Model/Player.txt");
	defender::g_audiosystem.AddAudio("Laser", "Laser.wav");

	//Create Actors
	defender::Scene scene;

	// Main Actor
	defender::Transform transform{ defender::Vector2{ 400, 300 }, 90, { 3, 3 } };
	std::unique_ptr<defender::Actor> actor = std::make_unique<defender::Actor>();
	actor.get()->GetTransform() = transform;

	std::unique_ptr<defender::PlayerComponent> pcomponent = std::make_unique<defender::PlayerComponent>();
	actor->AddComponent(std::move(pcomponent));

	std::unique_ptr<defender::ModelComponent> mcomponent = std::make_unique<defender::ModelComponent>();
	mcomponent->m_model = defender::g_resources.Get<defender::Model>("Model/Player.txt");
	actor->AddComponent(std::move(mcomponent));

	//std::unique_ptr<defender::SpriteComponent> scomponent = std::make_unique<defender::SpriteComponent>();
	//scomponent->m_texture = texture;
	//actor->AddComponent(std::move(scomponent));

	std::unique_ptr<defender::AudioComponent> acomponent = std::make_unique<defender::AudioComponent>();
	acomponent->m_soundName = "Laser";
	actor->AddComponent(std::move(acomponent));

	std::unique_ptr<defender::PhysicsComponent> phcomponent = std::make_unique<defender::PhysicsComponent>();
	actor->AddComponent(std::move(phcomponent));

	// Child Actor
	defender::Transform transformC{ defender::Vector2{ 10, 11 }, 0, { 1, 1 } };
	std::unique_ptr<defender::Actor> child = std::make_unique<defender::Actor>(transformC);

	std::unique_ptr<defender::ModelComponent> mcomponentC = std::make_unique<defender::ModelComponent>();
	mcomponentC->m_model = defender::g_resources.Get<defender::Model>("Model/Player.txt");
	child->AddComponent(std::move(mcomponentC));

	actor->AddChild(std::move(child));

	scene.Add(std::move(actor));

	float angle = 0;

	bool quit = false;
	while (!quit)
	{
		// Update (Engine)
		defender::g_time.Tick();
		defender::g_inputSystem.Update();
		defender::g_audiosystem.Update();

		if (defender::g_inputSystem.GetKeyDown(defender::key_escape)) quit = true;

		//Update Scene
		angle += 360.0f * defender::g_time.deltaTime;
		scene.Update();

		//Render Model
		defender::g_renderer.BeginFrame();

		scene.Draw(defender::g_renderer);
		//defender::g_renderer.Draw(texture, { 400, 300 }, angle, { 2, 2 }, {0.5f, 0.5f});
		defender::g_renderer.EndFrame();
	}

	defender::g_renderer.ShutDown();
	defender::g_audiosystem.Shutdown();
}