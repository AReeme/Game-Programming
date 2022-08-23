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
	defender::g_physicsSystem.Initialize();

	defender::Engine::Instance().Register();

	//Create Window
	defender::g_renderer.CreateWindow("Neumont", 800, 600);
	defender::g_renderer.SetClearColor(defender::Color{ 50, 50, 50, 255 });

	//Create Scene
	defender::Scene scene;

	rapidjson::Document document;
	bool success = defender::json::Load("level.txt", document);

	scene.Read(document);
	scene.Initialize();

	bool quit = false;
	while (!quit)
	{
		// Update (Engine)
		defender::g_time.Tick();
		defender::g_inputSystem.Update();
		defender::g_audiosystem.Update();
		defender::g_physicsSystem.Update();

		if (defender::g_inputSystem.GetKeyDown(defender::key_escape)) quit = true;

		//Update Scene
		scene.Update();

		//Render Model
		defender::g_renderer.BeginFrame();

		scene.Draw(defender::g_renderer);
		//defender::g_renderer.Draw(texture, { 400, 300 }, angle, { 2, 2 }, {0.5f, 0.5f});
		defender::g_renderer.EndFrame();
	}

	defender::g_renderer.ShutDown();
	defender::g_audiosystem.Shutdown();
	defender::g_physicsSystem.Shutdown();
	defender::g_inputSystem.ShutDown();
	defender::g_resources.ShutDown();
}