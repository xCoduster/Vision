#include "vipch.h"
#include "Application.h"

#include "Vision/Log.h"

#include "SFMLWindow.h"
#include <SFML/Graphics.hpp>

namespace Vision {

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		VI_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;
		
		m_Window = Window::Create(WindowProps());
	}

	void Application::Run()
	{
		while (m_Window->IsOpen())
		{
			sf::Event event;
			while ((sf::RenderWindow*)(m_Window->GetNativeWindow())->pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					m_Window->GetNativeWindow()->close();
			}

			m_Window->GetNativeWindow()->clear(sf::Color::Black);

			m_Window->GetNativeWindow()->display();
		}
	}

}