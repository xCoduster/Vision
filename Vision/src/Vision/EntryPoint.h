#pragma once

#ifdef VI_PLATFORM_WINDOWS

extern Vision::Application* Vision::CreateApplication();

int main(int argc, char** argv)
{
	Vision::Log::Init();
	VI_CORE_WARN("Initialized Log!");
	int a = 5;
	VI_INFO("Hello! Var={0}", a);

	auto app = Vision::CreateApplication();
	app->Run();
	delete app;
}

#endif