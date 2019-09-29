#include "vipch.h"
#include "Application.h"

#include "Vision/Log.h"

namespace Vision {

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		VI_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;
		
		m_Window = std::unique_ptr<Window>(new Window());
	}

	void Application::Run()
	{
		while (m_Window->IsOpen())
		{
			sf::Event event;
			while (m_Window->GetNativeWindow()->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					m_Window->GetNativeWindow()->close();
			}

			m_Window->GetNativeWindow()->clear(sf::Color::Black);

			m_Window->GetNativeWindow()->display();
		}
	}

}