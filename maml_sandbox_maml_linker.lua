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


filter {"platforms:Windows", "configurations:Debug"}
	LinkLibraryForPlatformAndConfig("Windows", "Debug", "Maml", mint_dir .. "/Debug_Windows/Maml")


filter {"platforms:Windows", "configurations:Release"}
	LinkLibraryForPlatformAndConfig("Windows", "Release", "Maml", mint_dir .. "/Release_Windows/Maml")


filter {"platforms:Windows", "configurations:Distr"}
	LinkLibraryForPlatformAndConfig("Windows", "Distr", "Maml", mint_dir .. "/Distr_Windows/Maml")
