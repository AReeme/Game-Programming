#include "Engine.h"

int main()
{
	defender::InitializeMemory();
	defender::SetFilePath("../Assets");

	rapidjson::Document document;
	bool success = defender::json::Load("json.txt", document);
	assert(success);

	std::string str;
	defender::json::Get(document, "string", str);
	std::cout << str << std::endl;

	bool b;
	defender::json::Get(document, "boolean", b);
	std::cout << b << std::endl;

	int i1;
	defender::json::Get(document, "integer1", i1);
	std::cout << i1 << std::endl;

	int i2;
	defender::json::Get(document, "integer2", i2);
	std::cout << i2 << std::endl;

	float f;
	defender::json::Get(document, "float", f);
	std::cout << f << std::endl;

	defender::Vector2 v2;
	defender::json::Get(document, "vector2", v2);
	std::cout << v2 << std::endl;

	defender::Color color;
	defender::json::Get(document, "color", color);
	std::cout << color << std::endl;

	// Initialize Engine
	defender::g_renderer.Initialize();
	defender::g_inputSystem.Initialize();
	defender::g_audiosystem.Initialize();
	defender::g_resources.Initialize();

	defender::Engine::Instance().Register();

	//Create Window
	defender::g_renderer.CreateWindow("Neumont", 800, 600);
	defender::g_renderer.SetClearColor(defender::Color{ 50, 50, 50, 255 });

	//Create Actors
	defender::Scene scene;

	bool quit = false;
	while (!quit)
	{
		// Update (Engine)
		defender::g_time.Tick();
		defender::g_inputSystem.Update();
		defender::g_audiosystem.Update();

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
}