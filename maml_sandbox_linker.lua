-----------------------------------------------------------
-- Windows linking
-----------------------------------------------------------
filter {"platforms:Windows","configurations:Debug"}
	libdirs{"libs", "%{prj.location}/common/lib/Debug"}
	links{
	}


filter {"platforms:Windows","configurations:Release"}
	libdirs{"libs", "%{prj.location}/common/lib/Release"}
	links{
	}


filter {"platforms:Windows","configurations:Distr"}
	libdirs{"libs", "%{prj.location}/common/lib/Distr"}
	links{
	}

-----------------------------------------------------------
-- Linux linking
-----------------------------------------------------------