#pragma once
#include "../Math/Vector2.h"
#include <cstdint>
#include <vector>
#include <array>

namespace defender
{
	class InputSystem
	{
	public:
		enum State
		{
			Idle,
			Pressed,
			Held,
			Released
		};
	public:
		InputSystem() = default;
		~InputSystem() = default;

		void Initialize();
		void ShutDown();

		void Update();

		bool GetKeyDown(int key) { return m_keyboardState[key]; }

		const Vector2& GetMousePosition() const { return m_mousePosition; }

		State GetButtonState(uint32_t button);
		bool GetButtonDown(uint32_t button) { return m_mouseButtonState[button]; }
		bool GetPreviousButtonDown(uint32_t button) { return m_prevMouseButtonState[button]; }


	private:
		//Keyboard
		int m_numKeys;
		std::vector<uint8_t> m_keyboardState;
		std::vector<uint8_t> m_prevKeyboardState;

		//Mouse
		Vector2 m_mousePosition;
		std::array<uint8_t, 3> m_mouseButtonState;
		std::array<uint8_t, 3> m_prevMouseButtonState;
	};

	extern const uint32_t key_space;
	extern const uint32_t key_up;
	extern const uint32_t key_down;
	extern const uint32_t key_left;
	extern const uint32_t key_right;
	extern const uint32_t key_escape;
	extern const uint32_t button_left;
	extern const uint32_t button_middle;
	extern const uint32_t button_right;
	extern const uint32_t button_left;
	extern const uint32_t button_middle;
	extern const uint32_t button_right;
}