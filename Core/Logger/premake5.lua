project "Logger"
    kind (libraryType)
    LangageInformations()
    staticruntime "off"

    -- Définir les répertoires de sortie pour l'exécutable et les fichiers objets
    BuildsInfos("%{prj.name}")
    PrecompileHeader("%{prj.name}")
    
    files {
        "src/**.h", "src/**.hpp", "src/**.inl", "src/**.cpp", -- src file
    }

    includedirs {
        "./src",
        libs.core.include
    }

    libdirs {
    }

    links {
        "Core",
    }

    defines {
		"_CRT_SECURE_NO_WARNINGS", "GLFW_INCLUDE_NONE"
    }

    DefineExport()
    DefineApiInfo()

    filter "system:windows"
        systemversion "latest"
		optimize "off"
        linkoptions { "-lpthread" }

    filter "system:macosx"
        xcodebuildsettings
        {
            ["MACOSX_DEPLOYMENT_TARGET"] = "10.15",
            ["USeModernBuildSystem"] = "NO"
        }

        links {
        }

        -- Options de compilation pour macOS
        buildoptions { "-stdlib=libc++", "-fPIC", "-pthread" }

    filter "system:linux"
        -- Options de compilation pour Linux
        buildoptions { "-fPIC", "-pthread" }

    filter "configurations:Debug"
        defines { "_ALLOW_ITERATOR_DEBUG_LEVEL_MISMATCH" }
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"

    filter {}
