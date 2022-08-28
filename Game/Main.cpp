#include "Engine.h"
#include "ReemeGame.h"

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

	//Create Game
	std::unique_ptr<ReemeGame> game = std::make_unique<ReemeGame>();
	game->Initialize();

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
		game->Update();

		//Render Model
		defender::g_renderer.BeginFrame();

		game->Draw(defender::g_renderer);
		//defender::g_renderer.Draw(texture, { 400, 300 }, angle, { 2, 2 }, {0.5f, 0.5f});
		defender::g_renderer.EndFrame();
	}

	game->Shutdown();
	defender::Factory::Instance().Shutdown();

	defender::g_renderer.ShutDown();
	defender::g_audiosystem.Shutdown();
	defender::g_physicsSystem.Shutdown();
	defender::g_inputSystem.ShutDown();
	defender::g_resources.ShutDown();
}