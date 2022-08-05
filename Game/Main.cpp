#include "Engine.h"
#include <iostream>

using namespace std;

int add(int a, int b)
{
	return a + b;
}

constexpr int add_c(int a, int b)
{
	return a + b;
}

int main()
{
	constexpr int i1 = 5;
	int i2 = add(6, 7);
	constexpr int i3 = add_c(6, 7);
	constexpr float degrees = math::RadToDeg(math::PI);

	std::cout << __FILE__ << std::endl;
	std::cout << __LINE__ << std::endl;
	std::cout << __FUNCTION__ << std::endl;

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
		std::shared_ptr<defender::Texture> texture = std::make_shared<defender::Texture>();
		texture->Create(defender::g_renderer, "sf2.png");

		float angle = 0;

		bool quit = false;
		while (!quit)
		{
			// Update (Engine)
			defender::g_time.Tick();
			defender::g_inputSystem.Update();
			defender::g_audiosystem.Update();

			if (defender::g_inputSystem.GetKeyDown(defender::key_escape)) quit = true;

			angle += 360.0f * defender::g_time.deltaTime;

			//Render Model
			defender::g_renderer.BeginFrame();

			defender::g_renderer.Draw(texture, { 400, 300 }, angle, { 2, 2 }, {0.5f, 0.5f});

			defender::g_renderer.EndFrame();
		}
	}

	defender::g_renderer.ShutDown();
	defender::g_audiosystem.Shutdown();
}