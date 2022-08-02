#include "Engine.h"

using namespace std;

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

	{
		//Create Game

		bool quit = false;
		while (!quit)
		{
			// Update (Engine)
			defender::g_time.Tick();
			defender::g_inputSystem.Update();
			defender::g_audiosystem.Update();

			if (defender::g_inputSystem.GetKeyDown(defender::key_escape)) quit = true;

			//Render Model
			defender::g_renderer.BeginFrame();

			defender::g_renderer.EndFrame();
		}
	}

	defender::g_renderer.ShutDown();
	defender::g_audiosystem.Shutdown();
}