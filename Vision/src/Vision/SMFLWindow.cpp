#include "vipch.h"
#include "SFMLWindow.h"

namespace Vision {

	SFMLWindow::SFMLWindow(const WindowProps& props)
	{
		Init(props);
	}

	SFMLWindow::~SFMLWindow()
	{
		delete m_Window;
	}

	void SFMLWindow::SetVSync(bool enabled)
	{
		m_Window->setVerticalSyncEnabled(enabled);
	}

	void SFMLWindow::SetFramerateLimit(unsigned int frames)
	{
		m_Window->setFramerateLimit(frames);
	}

	bool SFMLWindow::IsOpen() const
	{
		return m_Window->isOpen();
	}

	void SFMLWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		m_Window = new sf::RenderWindow(sf::VideoMode(m_Data.Width, m_Data.Height), m_Data.Title);

	}

	Window* Window::Create(const WindowProps& props)
	{
		return new SFMLWindow(props);
	}

}