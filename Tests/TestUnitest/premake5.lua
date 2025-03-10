project "TestUnitest"
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
        libs.nkentseu.include,
        libs.logger.include,
        libs.unitest.include,
    }

    links {
        "Unitest",
        "Logger",
        "Nkentseu"
    }

    DefineApiInfo()

    filter "system:windows"
        systemversion "latest"
		optimize "off"
        -- entrypoint "WinMainCRTStartup"

        -- PostBuilds("Nkentseu", "%{prj.name}")
        -- PostBuilds("Logger", "%{prj.name}")
        -- PostBuilds("Unkeny", "%{prj.name}")
        -- PostBuilds("Unitest", "%{prj.name}")
    
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
