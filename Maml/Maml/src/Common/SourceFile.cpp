#include "SourceFile.h"


namespace maml
{


	CSourceFile::CSourceFile() : INonCopyable(), 
		m_buffer(nullptr), m_bufferSize(0), m_bytes(0)
	{
	}


	CSourceFile::~CSourceFile()
	{
		free(m_buffer);
	}


	bool CSourceFile::read_from_file_handle(FILE* file)
	{
		if (file != nullptr)
		{
			auto file_size = CFileReaderWriter::get_file_size(file);

			void* buffer = malloc(file_size);

			std::memset(buffer, NULL, file_size);

			if (auto read_bytes = fread(buffer, sizeof(char), file_size, file);
				read_bytes > 0)
			{
				m_bytes = read_bytes;
				m_bufferSize = file_size;

				m_buffer = reinterpret_cast<char*>(buffer);
				m_buffer[read_bytes + 1] = '\0';


				return true;
			}
		}

		return false;
	}


	bool CSourceFile::read_from_file_at_path(const String& source_file_path)
	{
		FILE* file = NULL;

		uint32_t file_size = 0;

		if (file = CFileReaderWriter::open(source_file_path, &file_size, CFileReaderWriter::AccessMode_Read);
			file != nullptr)
		{
			void* buffer = malloc(file_size);

			std::memset(buffer, NULL, file_size);

			if (auto read_bytes = fread(buffer, sizeof(char), file_size, file);
				read_bytes > 0)
			{
				m_bytes = read_bytes;
				m_bufferSize = file_size;

				m_buffer = reinterpret_cast<char*>(buffer);
				m_buffer[read_bytes + 1] = '\0';

				return true;
			}
		}
		
		return false;
	}


	bool CSourceFile::has_data() const
	{
		return m_bytes > 0;
	}


	uint32_t CSourceFile::size() const
	{
		return m_bytes / sizeof(char);
	}


	maml::CSourceFileIterator CSourceFile::begin()
	{
		return CSourceFileIterator(&m_buffer[0]);
	}


	char CSourceFile::at(uint32_t index)
	{
		if(!is_at_end(index))
		{
			return m_buffer[index];
		}

		return '\0';
	}


	char CSourceFile::operator[](uint32_t index)
	{
		return at(index);
	}


	maml::CSourceFileIterator CSourceFile::end()
	{
		return CSourceFileIterator(&m_buffer[m_bytes / sizeof(char)]);
	}


	bool CSourceFile::is_at_end(uint32_t index)
	{
		return index >= m_bytes / sizeof(char);
	}


	CSourceFileIterator::CSourceFileIterator(pointer_type pointer) :
		m_pointer(pointer)
	{
	}


}