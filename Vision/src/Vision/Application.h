#pragma once

#include "Core.h"

#include "Window.h"

namespace Vision {

	class Application 
	{
	public:
		Application();

		void Run();

		inline static Application& Get() { return *s_Instance; }
	private:
		Window* m_Window;
		bool m_Running = true;
	private:
		static Application* s_Instance;
	};

	Application* CreateApplication();

}