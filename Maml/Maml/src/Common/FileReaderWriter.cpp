#include "FileReaderWriter.h"


namespace maml
{


	FILE* CFileReaderWriter::open(const String& file_path, uint32_t* file_size, AccessMode mode)
	{
		std::filesystem::directory_entry path(file_path.c_str());

		if(path.exists())
		{
			String m;
			switch (mode)
			{
			case AccessMode_Read:
				m = "r";
				break;
			case AccessMode_Write:
				m = "w";
				break;
			case AccessMode_Append:
				m = "a";
				break;
			case AccessMode_ReadWrite:
			default:
				m = "r+";
				break;
			}

			*file_size = path.file_size();

			return fopen(file_path.c_str(), m.c_str());
		}

		return nullptr;
	}


}