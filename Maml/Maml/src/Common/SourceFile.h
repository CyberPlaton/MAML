#ifndef _MAML_SOURCEFILE_H_
#define _MAML_SOURCEFILE_H_


#include "Common.h"
#include "FileReaderWriter.h"


namespace maml
{

	class CSourceFile : public INonCopyable
	{
	public:
		CSourceFile(FILE* file);
		CSourceFile(const String& source_file_path);
		~CSourceFile();

		bool has_data();


	public:
		char* m_buffer;
		uint32_t m_bufferSize;
		uint32_t m_bytes;
	};

}


#endif