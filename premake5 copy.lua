include "./Scripts/lua/config.lua"

workspace "Unkeny"
    configurations { "Debug", "Release" }
    platforms { "x64" }
	startproject ("UkEditor")
    
    group "Core"
        include "./Core/Logger"
        include "./Core/Nkentseu"
        include "./Core/Unitest"
    group ""

    group "Engine"
        include "./Engine/UkEditor"
        include "./Engine/Unkeny"
    group ""

    group "Tests"
        include "./Tests/TestUnitest"
    group ""
