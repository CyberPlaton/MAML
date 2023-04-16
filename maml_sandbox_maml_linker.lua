function LinkLibraryForPlatformAndConfig(platform, config, library, library_path)
	print("[".. platform .."][".. config.."]Linking Library: \"" .. library .. "\" at " .. library_path)

	filter {"platforms:".. platform, "configurations:" .. config}
		libdirs{"libs", library_path}
		links{
			library
		}

	filter{}
end

mint_dir = os.getcwd()
mint_dir = mint_dir .. "/bin"

if os.target() == "windows" then
	filter {"platforms:Windows", "configurations:Debug"}
		LinkLibraryForPlatformAndConfig("Windows", "Debug", "Maml", mint_dir .. "/Debug_Windows/Maml")
	filter {"platforms:Windows", "configurations:Release"}
		LinkLibraryForPlatformAndConfig("Windows", "Release", "Maml", mint_dir .. "/Release_Windows/Maml")
	filter {"platforms:Windows", "configurations:Distr"}
		LinkLibraryForPlatformAndConfig("Windows", "Distr", "Maml", mint_dir .. "/Distr_Windows/Maml")
		
elseif os.target() == "linux" then
	filter {"platforms:Linux", "configurations:Debug"}
		LinkLibraryForPlatformAndConfig("Linux", "Debug", "Maml", mint_dir .. "/Debug_Linux/Maml")
	filter {"platforms:Linux", "configurations:Release"}
		LinkLibraryForPlatformAndConfig("Linux", "Release", "Maml", mint_dir .. "/Release_Linux/Maml")
	filter {"platforms:Linux", "configurations:Distr"}
		LinkLibraryForPlatformAndConfig("Linux", "Distr", "Maml", mint_dir .. "/Distr_Linux/Maml")
end
