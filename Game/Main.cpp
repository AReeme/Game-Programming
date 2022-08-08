#include "Engine.h"

int main()
{
	defender::InitializeMemory();
	defender::SetFilePath("../Assets");

	// Initialize Engine
	defender::g_renderer.Initialize();
	defender::g_inputSystem.Initialize();
	defender::g_audiosystem.Initialize();

	//Create Window
	defender::g_renderer.CreateWindow("Neumont", 800, 600);
	defender::g_renderer.SetClearColor(defender::Color{ 50, 50, 50, 255 });

	//Create Game
	std::shared_ptr<defender::Texture> texture = std::make_shared<defender::Texture>();
	texture->Create(defender::g_renderer, "sf2.png");

	//Create Actors
	defender::Scene scene;

	defender::Transform transform{ defender::Vector2{ 100, 100 }, 90, { 3, 3 } };
	std::unique_ptr<defender::Actor> actor = std::make_unique<defender::Actor>();
	std::unique_ptr<defender::PlayerComponent> pcomponent = std::make_unique<defender::PlayerComponent>();
	actor->AddComponent(std::move(pcomponent));
	std::unique_ptr<defender::SpriteComponent> scomponent = std::make_unique<defender::SpriteComponent>();
	scomponent->m_texture = texture;
	actor->AddComponent(std::move(scomponent));

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
		defender::g_renderer.Draw(texture, { 400, 300 }, angle, { 2, 2 }, {0.5f, 0.5f});
		defender::g_renderer.EndFrame();
	}

	defender::g_renderer.ShutDown();
	defender::g_audiosystem.Shutdown();
}