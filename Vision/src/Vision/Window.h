#pragma once

#include <SFML/Graphics.hpp>

#include "Core.h"

namespace Vision {

	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Vision Engine", unsigned int width = 1280, unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	class Window
	{
	public:
		Window(const WindowProps& props = WindowProps());
		~Window();

		inline unsigned int GetWidth() const { return m_Data.Width; }
		inline unsigned int GetHeight() const { return m_Data.Height; }

		inline sf::RenderWindow* GetNativeWindow() const { return m_Window; }

		void SetVSync(bool enabled);
		void SetFramerateLimit(unsigned int frames);
		inline bool IsVSync() const { return m_Data.VSync; }

		bool IsOpen() const;
	private:
		void Init(const WindowProps& props);
	private:
		sf::RenderWindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;
		};

		WindowData m_Data;
	};

}