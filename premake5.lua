workspace "FruitSalad"
	architecture "x64" -- Platform 

	configurations
	{
		"Debug", -- Debug
		"Release", -- Faster version of Debug
		"Dist" -- Actual distribution version
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "FruitSalad"
	location "FruitSalad"
	kind "SharedLib" -- dynamic library
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	--Filters

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"FS_PLATFORM_WINDOWS",
			"FS_BUILD_DLL"
		}
		
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "FS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "FS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "FS_DIST"
		optimize "On"

	postbuildcommands
	{
	("{COPY %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	}

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"FruitSalad/vendor/spdlog/include",
		"FruitSalad/src"
	}

	links
	{
		"FruitSalad"
	}

	--Filters

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"FS_PLATFORM_WINDOWS"
		}
		
	filter "configurations:Debug"
		defines "FS_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "FS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "FS_DIST"
		optimize "On"