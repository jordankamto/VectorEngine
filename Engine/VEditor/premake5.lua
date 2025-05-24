project "VEditor"
    kind "ConsoleApp"
    LangageInformations()
    staticruntime "off"

    BuildsInfos("%{prj.name}")

    files {
        "src/**.h",
        "src/**.hpp",
        "src/**.cpp",
        "src/VEditor.cpp/Vwindow.cpp" -- Explicitly include Vwindow.cpp if needed
    }

    includedirs {
        "./src/",
        "src/VEditor/VWindow.h", -- Add the directory containing Vwindow.h if needed
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
        -- Uncomment if using WinMain
        -- entrypoint "WinMainCRTStartup"

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
