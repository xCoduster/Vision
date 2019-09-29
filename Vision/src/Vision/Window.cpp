#include "vipch.h"
#include "Window.h"

namespace Vision {

	Window::Window(const WindowProps& props)
	{
		Init(props);
	}

	Window::~Window()
	{
		delete m_Window;
	}

	void Window::SetVSync(bool enabled)
	{
		m_Window->setVerticalSyncEnabled(enabled);
	}

	void Window::SetFramerateLimit(unsigned int frames)
	{
		m_Window->setFramerateLimit(frames);
	}

	bool Window::IsOpen() const
	{
		return m_Window->isOpen();
	}

	void Window::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		m_Window = new sf::RenderWindow(sf::VideoMode(m_Data.Width, m_Data.Height), m_Data.Title);

	}

}