#pragma once
#include "Framework/Game.h"

class ReemeGame : public defender::Game
{
public:
	virtual void Initialize() override;
	virtual void Shutdown() override;
	virtual void Update() override;
	virtual void Draw(defender::Renderer& renderer) override;
};
