workspace "DeskBrew"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["WinGL"] = "WinGL/include"

project "DeskBrew"
    location "DeskBrew"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" ..outDir.. "/%{prj.name}")
	objdir ("bin-int/" ..outDir.. "/%{prj.name}")

	includedirs
    {
        "%{prj.name}/src",
		"%{IncludeDir.WinGL}"
    }

	links
	{
		"WinGL"
	}

    files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**cpp"
	}

    filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

        defines
		{
			"DB_PLATFORM_WINDOWS",
			"DB_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outDir.. "/DeskLab")
		}

	filter "configurations:Debug"
		buildoptions "/MDd"
		defines "DB_DEBUG"
		symbols "On"

	filter "configurations:Release"
		buildoptions "/MD"
		defines "DB_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		buildoptions "/MD"
		defines "DB_DIST"
		optimize "On"



project "DeskLab"
	location "DeskLab"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" ..outDir.. "/%{prj.name}")
	objdir ("bin-int/" ..outDir.. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	includedirs
	{
		"DeskBrew/src"
	}
	links
	{
		"DeskBrew"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
	
		defines
		{
			"DB_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		buildoptions "/MDd"
		defines "DB_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		buildoptions "/MD"
		defines "DB_RELEASE"
		optimize "On"
	
	filter "configurations:Dist"
		buildoptions "/MD"
		defines "DB_DIST"
		optimize "On"

project "WinGL"
    location "WinGL"
    kind "StaticLib"
    language "C++"

    targetdir ("bin/" ..outDir.. "/%{prj.name}")
    objdir ("bin-int/" ..outDir.. "/%{prj.name}")

    files
    {
		"%{prj.name}/include/**.h",
        "%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
    }
	links
	{
		"opengl32.lib",
		"glu32.lib",
		"glew32.lib"
	}
	defines
	{
		"WIN32_LEAN_AND_MEAN"
	}
	includedirs
	{
		"%{prj.name}/include",
		"%{prj.name}/src"
	}

    filter "system:windows"
		systemversion "latest"
		staticruntime "On"

	filter "configurations:Debug"
	buildoptions "/MDd"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		runtime "Release"
		optimize "on"
		