----------------------------------------------
-- Maml Sandbox application
----------------------------------------------
	project "Sandbox"
		print("\n")
		print("Defining Project \"Sandbox\"")
		location "Sandbox/Sandbox"
		kind "ConsoleApp"
		language "C++"
		architecture "x86_64"
		cppdialect "C++17"
		-- use latest available system version (e.g. latest Windows SDK)
		systemversion "latest"
		staticruntime "Off"

		filter "action:vs*"
			buildoptions{
				"/Zc:__cplusplus"
			}


		mint_engine_path = path.getabsolute("Maml")
		includedirs{
			mint_engine_path .. "/Maml",
			mint_engine_path .. "/Maml/src"
		}
		print("Include Maml header and source files at: " .. mint_engine_path .. "/Maml, " .. mint_engine_path .. "/Maml/src")



		files{
			"%{prj.name}/%{prj.name}/Main.h",
			"%{prj.name}/%{prj.name}/Main.cpp",
		}
		includedirs{
			"%{prj.name}/%{prj.name}/src"
		}
		print("Include project source and header files...")


		includedirs{
			"%{prj.location}/common/include",
		}
		print("Include third party files...")


		print("Linking of third party libraries and Maml library...")
		group "Linking"
			include "maml_sandbox_linker.lua"
			include "maml_sandbox_maml_linker.lua"
		group ""

		print("Create common defines...")
		group "Defines"
			include "maml_sandbox_defines.lua"
		group ""

		print("Completed!")