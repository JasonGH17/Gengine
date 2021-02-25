workspace "DeskBrew"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "DeskBrew"
    location "DeskBrew"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" ..outDir.. "/%{prj.name}")
	objdir ("bin-int/" ..outDir.. "/%{prj.name}")

	includedirs
    {
        "DeskBrew/src"
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
        "DeskLab/src/**.h",
		"DeskLab/src/**.cpp"
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