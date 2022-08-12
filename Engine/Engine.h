#pragma once
#include "Core/Memory.h"
#include "Core/File.h"
#include "Core/Time.h"

#include "Math/MathUtils.h"
#include "Math/Random.h"

#include "Framework/Scene.h"
#include "Framework/Game.h"

#include "Components/PlayerComponent.h"
#include "Components/SpriteComponent.h"
#include "Components/AudioComponent.h"
#include "Components/PhysicsComponent.h"
#include "Components/ModelComponent.h"


#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"

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
}

