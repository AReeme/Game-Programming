#pragma once
#include "Framework/Game.h"
#include "Framework/Event.h"

class ReemeGame : public defender::Game
{
public:
	enum class gameState
	{
		titleScreen,
		startLevel,
		game,
		playerDead,
		gameOver
	};

public:
	virtual void Initialize() override;
	virtual void Shutdown() override;
	virtual void Update() override;
	virtual void Draw(defender::Renderer& renderer) override;

	void OnAddPoints(const defender::Event& event);
	void OnPlayerDead(const defender::Event& event);

private:
	gameState m_gameState = gameState::titleScreen;
	float m_stateTimer = 0;
	int m_lives = 3;
};
