#include "Engine.h"

namespace defender
{
	AudioSystem g_audiosystem;
	InputSystem g_inputSystem;
	Renderer g_renderer;
	Time g_time;
	ResourceManager g_resources;
	PhysicsSystem g_physicsSystem;
	EventManager g_eventManager;

	void Engine::Register()
	{
		REGISTER_CLASS(Actor);
		REGISTER_CLASS(AudioComponent);
		REGISTER_CLASS(ModelComponent);
		REGISTER_CLASS(PhysicsComponent);
		REGISTER_CLASS(CollisionComponent);
		REGISTER_CLASS(RBPhysicsComponent);
		REGISTER_CLASS(PlayerComponent);
		REGISTER_CLASS(SpriteComponent);
		REGISTER_CLASS(SpriteAnimComponent);
		REGISTER_CLASS(TextComponent);
		REGISTER_CLASS(TileMapComponent);
		REGISTER_CLASS(CameraComponent);
	}
}