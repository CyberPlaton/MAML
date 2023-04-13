#include "SourceFile.h"


namespace maml
{


	CSourceFile::CSourceFile(FILE* file) :
		m_buffer(nullptr)
	{

	}


	CSourceFile::CSourceFile(const String& source_file_path) :
		m_buffer(nullptr)
	{
		FILE* file = NULL;

		uint32_t file_size = 0;

		if(file = CFileReaderWriter::open(source_file_path, &file_size, CFileReaderWriter::AccessMode_Read);
		   file != nullptr)
		{
			void* buffer = malloc(file_size);

			std::memset(buffer, NULL, file_size);

			if(auto read_bytes = fread(buffer, sizeof(char), file_size, file); 
			   read_bytes > 0)
			{
				m_bytes = read_bytes;
				m_bufferSize = file_size;

				m_buffer = reinterpret_cast<char*>(buffer);
				m_buffer[read_bytes + 1] = '\0';
			}
		}
	}


	CSourceFile::~CSourceFile()
	{
		free(m_buffer);
	}


	bool CSourceFile::has_data()
	{
		return m_bytes > 0;
	}


}