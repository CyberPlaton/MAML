function CreateBinaryAndIntermediateOutputDirectory(is_binary, configuration, platform)
	if is_binary then
		targetdir ("bin/" .. configuration .. "_" .. platform .. "/%{prj.name}")
	else
		objdir ("intermediate/" .. configuration .. "_" .. platform .. "/%{prj.name}")
	end		
end

function LinkLibraryForPlatformAndConfig(platform, config, library, library_path)
	print("[".. platform .."][".. config.."]Linking Library: \"" .. library .. "\" at " .. library_path)

	filter {"platforms:".. platform, "configurations:" .. config}
		libdirs{"libs", library_path}
		links{
			library
		}

	filter{}
end



if os.target() == "windows" then
	-----------------------------------------------------------
	-- Windows defines
	-----------------------------------------------------------
	filter "platforms:Windows"
	system "windows"

	filter "Debug"
		optimize "Off"
		symbols "On"
		defines{
		}
		CreateBinaryAndIntermediateOutputDirectory(true, "Debug", "Windows")
		CreateBinaryAndIntermediateOutputDirectory(false, "Debug", "Windows")

	filter "Release"
		optimize "Full"
		symbols "On"
		defines{
		}

		CreateBinaryAndIntermediateOutputDirectory(true, "Release", "Windows")
		CreateBinaryAndIntermediateOutputDirectory(false, "Release", "Windows")

	filter "Distr"
		optimize "Full"
		symbols "Off"
		defines{
		}
		CreateBinaryAndIntermediateOutputDirectory(true, "Distr", "Windows")
		CreateBinaryAndIntermediateOutputDirectory(false, "Distr", "Windows")

elseif os.target() == "linux" then
	-----------------------------------------------------------
	-- Linux linking
	-----------------------------------------------------------
	filter "platforms:Linux"
	system "linux"

	filter "Debug"
		optimize "Off"
		symbols "On"
		defines{
		}
		CreateBinaryAndIntermediateOutputDirectory(true, "Debug", "Linux")
		CreateBinaryAndIntermediateOutputDirectory(false, "Debug", "Linux")

	filter "Release"
		optimize "Full"
		symbols "On"
		defines{
		}

		CreateBinaryAndIntermediateOutputDirectory(true, "Release", "Linux")
		CreateBinaryAndIntermediateOutputDirectory(false, "Release", "Linux")

	filter "Distr"
		optimize "Full"
		symbols "Off"
		defines{
		}
		CreateBinaryAndIntermediateOutputDirectory(true, "Distr", "Linux")
		CreateBinaryAndIntermediateOutputDirectory(false, "Distr", "Linux")
end