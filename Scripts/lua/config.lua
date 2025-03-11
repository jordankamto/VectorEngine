outputdir 		= ""
build 			= ""
build_obj 		= ""

external = {}
external.path = "%{wks.location}/External"
external.libs = external.path .. "/Libs"

internal = {}
internal.path = "%{wks.location}"
internal.core = internal.path .. "/Core"
internal.engine = internal.path .. "/Engine"

libs = {}
libs.logger = {
    include = internal.core .. "/Logger/src"
}
libs.core = {
    include = internal.core .. "/Core/src"
}
libs.unitest = {
    include = internal.core .. "/Unitest/src"
}
libs.vengine = {
    include = internal.engine .. "/VectorEngine/src"
}

function OutputDir()
    outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
end

function BuildDir()
    build = "%{wks.location}/Build/bin"
end

function BuildIntDir()
    build_obj = "%{wks.location}/Build/obj"
end

function BuildsInfos(projectName)

    -- Configuration globale Debug
    filter "configurations:Debug"
        outputdir_target = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

    -- Configuration globale Release
    filter "configurations:Release"
        outputdir_target = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
        
    build_target = "%{wks.location}/Build"

    filter {}

    targetdir ( build_target .. "/bin/" .. outputdir_target .. "/" .. projectName )
    objdir ( build_target .. "/obj/" .. outputdir_target .. "/" .. projectName )
end

function PostBuilds(libName, projectName)
    if libraryType == "SharedLib" then
        postbuildcommands {
            ("{COPY} " .. build .. outputdir .. "/" .. libName .. "/" .. libName .. ".dll " .. build .. outputdir .. "/" .. projectName),
        }
    end
end

function PostBuilds2(path, libName, projectName)
    postbuildcommands {
        ("{COPY} " .. path .. "/" .. libName .. ".dll " .. build .. outputdir .. "/" .. projectName),
    }
end

function DefineExport()
    defines {
		"CORE_EXPORTS"
    }
end

function LangageInformations()
    language "C++"
    cppdialect "C++20"

    -- Détection automatique du compilateur
    filter "system:windows"
        toolset "clang"  -- Utiliser ClangCL sous Windows

    filter "system:linux or system:macosx"
        toolset "clang"  -- Utiliser Clang natif sous Linux/macOS

    filter {}
end

function GetLibraryType()
	libtype = "StaticLib"

    if libtype == "DYNAMIC_LIB" then
        return "SharedLib"
    else
        return "StaticLib"
    end
end

function DefineApiInfo()
    if libraryType == "StaticLib" then
        defines
		{
			"CORE_STATIC"
		}
    end

    -- Configuration globale Debug
    filter "configurations:Debug"
        symbols "On"
        optimize "Off"
        defines {  "CORE_DEBUG"}

    -- Configuration globale Release
    filter "configurations:Release"
        optimize "On"
        symbols "Off"
        defines { "CORE_RELEASE" }

    filter {}
end

function PrecompileHeader(pname)
    pchheader ("./pch/pch.h")
    pchsource ("./pch/pch.cpp")
    
    files {
        "pch/**.h", "pch/**.cpp" -- pch file
    }

    includedirs {
        "./pch",
    }
end

libraryType = GetLibraryType()