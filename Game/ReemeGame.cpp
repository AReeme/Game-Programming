#include "ReemeGame.h"
#include "GameComponents/EnemyComponent.h"
#include "Engine.h"

void ReemeGame::Initialize()
{
	defender::REGISTER_CLASS(EnemyComponent);

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

	defender::g_eventManager.Subscribe("EVENT_ADD_POINTS", std::bind(&ReemeGame::OnAddPoints, this, std::placeholders::_1));
}

void ReemeGame::Shutdown()
{
	m_scene->RemoveAll();
}

void ReemeGame::Update()
{
	switch (m_gameState)
	{
	case ReemeGame::gameState::titleScreen:
		if (defender::g_inputSystem.GetKeyDown(defender::key_space) == defender::InputSystem::State::Pressed)
		{
			m_scene->GetActorFromName("Title")->SetActive(false);

			m_gameState = gameState::startLevel;
		}
		break;

	case ReemeGame::gameState::startLevel:
		for (int i = 0; i < 10; i++)
		{
			auto actor = defender::Factory::Instance().Create<defender::Actor>("Coin");
			actor->GetTransform().position = { defender::randomf(0, 800), 100.0f };
			actor->Initialize();

			m_scene->Add(std::move(actor));
		}
		for (int i = 0; i < 3; i++)
		{
			auto actor = defender::Factory::Instance().Create<defender::Actor>("Ghost");
			actor->GetTransform().position = { defender::randomf(0, 800), 100.0f };
			actor->Initialize();

			m_scene->Add(std::move(actor));
		}

		m_gameState = gameState::game;
		break;

	case ReemeGame::gameState::game:
	{
		auto actor = m_scene->GetActorFromName("Score");
		auto component = actor->GetComponent<defender::TextComponent>();
		component->SetText(std::to_string(m_score));
	}
	{
		auto actor = m_scene->GetActorFromName("Health");
		auto component = actor->GetComponent<defender::TextComponent>();

		auto player = m_scene->GetActorFromName("Player");
		if (player)
		{
			auto playerComponent = player->GetComponent<defender::PlayerComponent>();
			component->SetText(std::to_string((int)playerComponent->health));

			if (playerComponent->health <= 0)
			{
				m_gameState = gameState::playerDead;
			}

		}

		if (player)
		{
			m_stateTimer--;
			if (m_stateTimer <= 0)
			{
				for (int i = 0; i < 1; i++)
				{
					auto actor = defender::Factory::Instance().Create<defender::Actor>("Coin");
					actor->GetTransform().position = { defender::randomf(0, 800), 100.0f };
					actor->Initialize();

					m_scene->Add(std::move(actor));
					m_stateTimer = 50.0f;
				}
			}
		}
	}
	{
		auto actor = m_scene->GetActorFromName("Lives");
		auto component = actor->GetComponent<defender::TextComponent>();

		auto player = m_scene->GetActorFromName("Player");
		if (player)
		{
			auto playerComponent = player->GetComponent<defender::PlayerComponent>();
			component->SetText(std::to_string((int)playerComponent->lives));
		}

	}
		break;

	case ReemeGame::gameState::playerDead:
		m_stateTimer -= defender::g_time.deltaTime;
		if (m_stateTimer <= 0)
		{
			auto player = m_scene->GetActorFromName("Player");
			auto playerComponent = player->GetComponent<defender::PlayerComponent>();
			m_gameState = (playerComponent->lives > 0) ? gameState::startLevel : gameState::gameOver;
		}
		break;
	case ReemeGame::gameState::gameOver:
		m_gameState = gameState::startLevel;
		break;

	default:
		break;
	}

	m_scene->Update();
}

void ReemeGame::Draw(defender::Renderer& renderer)
{
	m_scene->Draw(renderer);
}

void ReemeGame::OnAddPoints(const defender::Event& event)
{
	AddPoints(std::get<int>(event.data));

	std::cout << event.name << std::endl;
	std::cout << GetScore() << std::endl;
}

void ReemeGame::OnPlayerDead(const defender::Event& event)
{
	m_gameState = gameState::playerDead;
	m_stateTimer = 50.0f;

}
