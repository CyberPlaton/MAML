#ifndef _MAML_SOURCEFILE_H_
#define _MAML_SOURCEFILE_H_


#include "Common.h"
#include "FileReaderWriter.h"


#include <iterator>


namespace maml
{

	class CSourceFileIterator;

	class CSourceFile : public INonCopyable
	{
		friend class CSourceFileIterator;

	public:
		CSourceFile();
		~CSourceFile();


		bool read_from_file_handle(FILE* file);

		bool read_from_file_at_path(const String& source_file_path);

		bool has_data() const;



		CSourceFileIterator begin();

		CSourceFileIterator end();


	public:
		char* m_buffer;
		uint32_t m_bufferSize;
		uint32_t m_bytes;
	};



	class CSourceFileIterator
	{
	public:
		using iterator_category = std::forward_iterator_tag;
		using difference_type = uint32_t;
		using value_type = char;
		using pointer_type = char*;
		using reference_type = char&;


		CSourceFileIterator(pointer_type pointer);


		reference_type operator*() const { return *m_pointer; }

		pointer_type operator->() { return m_pointer; }

		CSourceFileIterator& operator++() { m_pointer++; return *this; }

		CSourceFileIterator operator++(int) { CSourceFileIterator iter = *this; ++(*this); return iter; }

		friend bool operator==(const CSourceFileIterator& lh, const CSourceFileIterator& rh) { return lh.m_pointer == rh.m_pointer; }
		friend bool operator!=(const CSourceFileIterator& lh, const CSourceFileIterator& rh) { return lh.m_pointer != rh.m_pointer; };


	private:
		pointer_type m_pointer;

	};


}


#endif