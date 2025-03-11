include "./Scripts/lua/config.lua"

workspace "VectorEngine"
    configurations { "Debug", "Release" }
    platforms { "x64" }
	startproject ("VEditor")
    
    group "Core"
        include "./Core/Logger"
        include "./Core/Core"
        include "./Core/Unitest"
    group ""

    group "Engine"
        include "./Engine/VEditor"
        include "./Engine/VectorEngine"
    group ""

    group "Tests"
        include "./Tests/TestUnitest"
    group ""
