workspace "Vision"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{ 
		"Debug", 
		"Release" 
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["SFML"] = "Vision/vendor/SFML-2.5.1/include"

project "Vision"
	location "Vision"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "vipch.h"
	pchsource "Vision/src/vipch.cpp"

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.SFML}"
	}

	libdirs
	{
		"%{prj.name}/vendor/SFML-2.5.1/lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"VI_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "VI_DEBUG"
		runtime "Debug"
		symbols "on"

		links 
		{ 
		"sfml-system-s-d.lib",
		"sfml-window-s-d.lib",
		"sfml-graphics-s-d.lib",
		"sfml-audio-s-d.lib",
		"sfml-network-s-d.lib",
		"opengl32.lib",
		"freetype.lib",
		"winmm.lib",
		"gdi32.lib",
		"openal32.lib",
		"flac.lib",
		"vorbisenc.lib",
		"vorbisfile.lib",
		"vorbis.lib",
		"ogg.lib",
		"ws2_32.lib"
		}

	filter "configurations:Release"
		defines "VI_RELEASE"
		runtime "Release"
		optimize "on"

		links 
		{ 
		"sfml-system-s.lib",
		"sfml-window-s.lib",
		"sfml-graphics-s.lib",
		"sfml-audio-s.lib",
		"sfml-network-s.lib",
		"opengl32.lib",
		"freetype.lib",
		"winmm.lib",
		"gdi32.lib",
		"openal32.lib",
		"flac.lib",
		"vorbisenc.lib",
		"vorbisfile.lib",
		"vorbis.lib",
		"ogg.lib",
		"ws2_32.lib"
		}

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Vision/vendor/spdlog/include",
		"Vision/src",
		"Vision/vendor"
	}

	links
	{
		"Vision"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"VI_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "VI_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "VI_RELEASE"
		runtime "Release"
		optimize "on"