#include "ReemeGame.h"
#include "Engine.h"

void ReemeGame::Initialize()
{
	m_scene = std::make_unique<defender::Scene>();

	rapidjson::Document document;
	std::vector<std::string> sceneNames = {"Scenes/prefabs.txt", "Scenes/tilemap.txt", "Scenes/level.txt" };

	for (auto sceneName : sceneNames)
	{
		bool success = defender::json::Load(sceneName, document);
		if (!success)
		{
			LOG("Could Not Load Scene %s", sceneName.c_str());
			continue;
		}
		m_scene->Read(document);
	}

	m_scene->Initialize();

	for (int i = 0; i < 10; i++)
	{
		auto actor = defender::Factory::Instance().Create<defender::Actor>("Coin");
		actor->GetTransform().position = { defender::randomf(0, 800), 100.0f };
		actor->Initialize();

		m_scene->Add(std::move(actor));
	}
}

void ReemeGame::Shutdown()
{
	m_scene->RemoveAll();
}

void ReemeGame::Update()
{
	m_scene->Update();
}

void ReemeGame::Draw(defender::Renderer& renderer)
{
	m_scene->Draw(renderer);
}
