#pragma once
#include "Framework/Actor.h"

class Bullet : public defender::Actor
{
public:
	Bullet() = default;
	Bullet(const defender::Model& model, const defender::Transform& transform, float damage = 1) :
		Actor{ model, transform },
		m_damage{ damage } {}

	void Update() override;
	void OnCollision(Actor* other) override;

	float GetDamage() { return m_damage; }

private:
	float m_damage = 1;
	float m_speed = 400;
	float m_lifespan = 2;
};