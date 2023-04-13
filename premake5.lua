workspace "MAML"
	print("\n")
	print("Creating Workspace: \"MAML\":")
	architecture "x86_64"
	startproject "Maml"
	configurations{
		"Debug",		-- Traditional Debugging build
		"Release",		-- Verbose build to be debugged in a "Release" environment
		"Distr"			-- Shipping build
	}
	
	platforms{
		"Windows", "Linux"
	}

	flags{
		"MultiProcessorCompile"
	}

	group "Maml"
		include "maml_project.lua"
	group ""

	group "Sandbox"
	include "maml_sandbox_project.lua"
	group ""



	print("\nDo not forget following steps for a clean build:\n")
	print("1.) Set working directory correctly for debugging in your IDE!\n")
	print("2.) Disable usage of vcpkg if using Visual Studio!\n")