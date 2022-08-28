#pragma once

#include "Serialization\Json.h"

#include "Core/Memory.h"
#include "Core/File.h"
#include "Core/Time.h"
#include "Core/Logger.h"

#include "Math/MathUtils.h"
#include "Math/Random.h"

#include "Framework/Scene.h"
#include "Framework/Game.h"
#include "Framework/Factory.h"
#include "Framework/Singleton.h"

#include "Components/AudioComponent.h"
#include "Components/PhysicsComponent.h"
#include "Components/RBPhysicsComponent.h"
#include "Components/PlayerComponent.h"
#include "Components/ModelComponent.h"
#include "Components/SpriteComponent.h"
#include "Components/SpriteAnimComponent.h"
#include "Components/CollisionComponent.h"
#include "Components/TextComponent.h"
#include "Components/TileMapComponent.h"

#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"
#include "Resource/Resource.h"
#include "Resource/ResourceManager.h"

#include "Physics/PhysicsSystem.h"

#include "Renderer/Renderer.h"
#include "Renderer/Text.h"
#include "Renderer/Font.h"
#include "Renderer/Texture.h"
#include "Renderer/Model.h"

#include <memory>
#include <vector>
#include <list>

namespace defender
{
	extern AudioSystem g_audiosystem;
	extern Renderer g_renderer;
	extern InputSystem g_inputSystem;
	extern Time g_time;
	extern ResourceManager g_resources;
	extern PhysicsSystem g_physicsSystem;
	
	class Engine : public Singleton<Engine>
	{
	public:
		void Register();
	};
}

