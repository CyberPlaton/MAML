#ifndef _MAML_SOURCEFILE_H_
#define _MAML_SOURCEFILE_H_


#include "Common.h"
#include "FileReaderWriter.h"


namespace maml
{

	class CSourceFile : public INonCopyable
	{
	public:
		CSourceFile();
		~CSourceFile();


		bool read_from_file_handle(FILE* file);

		bool read_from_file_at_path(const String& source_file_path);

		bool has_data();


	public:
		char* m_buffer;
		uint32_t m_bufferSize;
		uint32_t m_bytes;
	};

}


#endif