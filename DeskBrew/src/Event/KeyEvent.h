#pragma once

#include "Event.h"

#include <sstream>

namespace DeskBrew
{
	class DB_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }
		EVENT_CLASS_CATEGORY(KeyboardEvent | InputEvent);

	protected:
		KeyEvent(int keycode) : m_KeyCode(keycode) {}
		int m_KeyCode;
	};


	class DB_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCnt) : KeyEvent(keycode), m_RepeatCount(repeatCnt) {}
		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << "(" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		int m_RepeatCount;
	};
	class DB_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}