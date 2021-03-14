#pragma once

#include "Event.h"

#include <sstream>

namespace DeskBrew
{
	class DB_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y) : m_MouseX(x), m_MouseY(y) {}
		inline float GetX() const { return m_MouseX; }
		inline float GetY() const { return m_MouseY; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(MouseEvent | InputEvent)

	private:
		float m_MouseX, m_MouseY;
	};
	class DB_API MouseScrolledEvent : public Event {
	public:
		MouseScrolledEvent(float x, float y) : m_OffsetX(x), m_OffsetY(y) {}
		inline float GetOffsetX() const { return m_OffsetX; }
		inline float GetOffsetY() const { return m_OffsetY; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << m_OffsetX << ", " << m_OffsetY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
			EVENT_CLASS_CATEGORY(MouseEvent | InputEvent)

	private:
		float m_OffsetX, m_OffsetY;
	};

	class DB_API MouseButtonEvent : public Event
	{
	public:
		inline int GetMouseButton() const { return m_Button; }
		EVENT_CLASS_CATEGORY(MouseEvent | InputEvent)

	protected:
		MouseButtonEvent(int btn) : m_Button(btn) {}
		int m_Button;
	};
	class DB_API MousePressedEvent : public MouseButtonEvent
	{
	public:
		MousePressedEvent(int btn) : MouseButtonEvent(btn) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};
	class DB_API MouseReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseReleasedEvent(int btn) : MouseButtonEvent(btn) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}