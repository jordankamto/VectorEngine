project "VEditor"
    kind "ConsoleApp"
    LangageInformations()
    staticruntime "off"

    BuildsInfos("%{prj.name}")

    files {
        "src/**.h",
        "src/**.hpp",
        "src/**.cpp"
    }

    includedirs {
        "./src/",
        libs.vengine.include,
        libs.logger.include,
        libs.core.include,
    }

    links {
        "VectorEngine",
        "Logger",
        "Core"
    }

    DefineApiInfo()

    filter "system:windows"
        systemversion "latest"
		optimize "off"
        -- entrypoint "WinMainCRTStartup"

        -- PostBuilds("Nkentseu", "%{prj.name}")
        -- PostBuilds("Logger", "%{prj.name}")
        -- PostBuilds("Unkeny", "%{prj.name}")
    
    filter "system:macosx"

    filter "system:linux"

    filter "configurations:Debug"
        defines { "_ALLOW_ITERATOR_DEBUG_LEVEL_MISMATCH" }
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"

    filter {}
