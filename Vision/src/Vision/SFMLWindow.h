#pragma once

#include <SFML/Graphics.hpp>

#include "Window.h"

namespace Vision {

	class SFMLWindow : public Window
	{
	public:
		SFMLWindow(const WindowProps& props);
		virtual ~SFMLWindow();

		inline virtual unsigned int GetWidth() const { return m_Data.Width; }
		inline virtual unsigned int GetHeight() const { return m_Data.Height; }

		inline virtual void* GetNativeWindow() const { return m_Window; }

		virtual void SetVSync(bool enabled);
		inline virtual bool IsVSync() const { return m_Data.VSync; }
		virtual void SetFramerateLimit(unsigned int frames);
		virtual bool IsOpen() const;
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