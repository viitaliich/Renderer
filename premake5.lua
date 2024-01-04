workspace "Renderer"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
--IncludeDir["GLFW"] = "Renderer/vendor/GLFW/include"
--IncludeDir["Glad"] = "Renderer/vendor/Glad/include"
--IncludeDir["ImGui"] = "Renderer/vendor/imgui"
--IncludeDir["glm"] = "Renderer/vendor/glm"
IncludeDir["spdlog"] = "Renderer/vendor/spdlog"

--group "Dependencies"
--    include "Renderer/vendor/GLFW"
--    include "Renderer/vendor/Glad"
--    include "Renderer/vendor/imgui"
--group ""

project "Renderer"
	location "Renderer"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pch.h"
	pchsource "Renderer/src/pch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		--"%{prj.name}/vendor/glm/glm/**.hpp",
		--"%{prj.name}/vendor/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		--"%{IncludeDir.GLFW}",
		--"%{IncludeDir.Glad}",
		--"%{IncludeDir.ImGui}",
		--"%{IncludeDir.glm}"
		--"%{IncludeDir.spdlog}"
	}

	links 
	{ 
		--"GLFW",
		--"Glad",
		--"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			--"EG_PLATFORM_WINDOWS",
			--"EG_BUILD_DLL",
			--"GLFW_INCLUDE_NONE"
			"CONF_DEBUG"
		}

	filter "configurations:Debug"
		defines "CONF_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "CONF_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "CONF_DIST"
		runtime "Release"
		optimize "on"

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
		"Renderer/vendor/spdlog/include",
		"Renderer/src",
		--"Renderer/vendor",
		--"%{IncludeDir.glm}"
		--"%{IncludeDir.spdlog}"
	}

	links
	{
		"Renderer"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"CONF_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "CONF_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "CONF_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "CONF_DIST"
		runtime "Release"
		optimize "on"