#include "Bullet.h"
#include "..\Project1\Player.h"
#include "Engine.h"

void Bullet::Update()
{
	//
	m_lifespan -= defender::g_time.deltaTime;
	if (m_lifespan <= 0) m_destroy = true;

	//Calculate Velocity
	defender::Vector2 direction{ 1, 0 };
	direction = defender::Vector2::Rotate(direction, m_transform.rotation);
	defender::Vector2 velocity = direction * m_speed * defender::g_time.deltaTime;
	//Move
	m_transform.position += velocity;


	//Wrap
	if (m_transform.position.x > defender::g_renderer.GetWidth()) m_transform.position.x = 0;
	if (m_transform.position.x < 0) m_transform.position.x = (float)defender::g_renderer.GetWidth();
	if (m_transform.position.y > defender::g_renderer.GetHeight()) m_transform.position.y = 0;
	if (m_transform.position.y < 0) m_transform.position.y = (float)defender::g_renderer.GetHeight();
}

void Bullet::OnCollision(Actor* other)
{
	if (dynamic_cast<Player*>(other) && other->GetTag() == "Player")
	{
		m_destroy = true;
	}

	if (dynamic_cast<Player*>(other) && other->GetTag() == "Enemy")
	{
		m_destroy = true;
	}
}
