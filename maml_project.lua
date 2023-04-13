----------------------------------------------
-- MAML library
----------------------------------------------
	project "Maml"
		print("\n")
		print("Defining Project \"Maml\"")
		location "Maml/Maml"
		kind "StaticLib"
		language "C++"
		architecture "x86_64"
		cppdialect "C++17"
		systemversion "latest"
		staticruntime "Off"

		filter "action:vs*"
			buildoptions{
				"/Zc:__cplusplus"
			}



		maml_location = "Maml/Maml"
		maml_dirs_to_load = {
			"Common/STL",
			"Common",
			"Document",
			"Lexing",
			"Node",
			"Parsing",
		}

		-- Specify which source files to include
		maml_abs_path = path.getabsolute(maml_location)
		maml_abs_path = maml_abs_path .. "/src"
		print("Loading files from " .. maml_abs_path)
		-- Load project interface files
		files{
				maml_location .. "/Maml.h", 
				maml_location .. "/Maml.cpp",
			}
		-- Allow including from src
		includedirs{
			maml_abs_path
		}

		-- Load project folders and create virtual paths
		for index = 1, #maml_dirs_to_load do
			fldr = maml_dirs_to_load[index]
			print("Loading folder: " .. "[" .. fldr.."]" .. " = " .. maml_abs_path .. "/" .. fldr)

			
			print("Create Virtual folder: [" .. fldr .. "] = " .. maml_abs_path)
			vpaths{
				[fldr] = {maml_abs_path .. "/" .. fldr .. "/**.h", maml_abs_path .. "/" .. fldr .. "/**.cpp"}
			}
			-- Load files to project
			files{
				maml_abs_path .. "/" .. fldr .. "/**.h", maml_abs_path .. "/" .. fldr .. "/**.cpp"
			}
			-- Allow including folder headers across project
			print("Create Include folder: " .. fldr)
			includedirs{
				fldr
			}
		end


		-- Includes
		includedirs{
			"%{prj.location}/common/include",
		}

		-- Platform specific defines and linking
		group "Linking"
			include "maml_linker.lua"
		group ""

		group "Defines"
			include "maml_defines.lua"
		group ""