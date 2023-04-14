#include "TokenStream.h"


namespace maml
{


	CTokenStream::CTokenStream() : 
		INonCopyable()
	{

	}


	bool CTokenStream::has_data() const
	{
		return !m_stream.empty();
	}


	maml::CTokenStreamIterator CTokenStream::begin()
	{
		return CTokenStreamIterator(&m_stream[0]);
	}


	maml::CTokenStreamIterator CTokenStream::end()
	{
		return CTokenStreamIterator(&m_stream[m_stream.size() - 1]);
	}


	bool CTokenStream::is_at_end(uint32_t index)
	{
		return index >= m_stream.size();
	}


	maml::SToken CTokenStream::at(uint32_t index)
	{
		if (!is_at_end(index))
		{
			return m_stream[index];
		}

		return SToken{};
	}


	maml::SToken CTokenStream::operator[](uint32_t index)
	{
		return at(index);
	}


	CTokenStreamIterator::CTokenStreamIterator(pointer_type pointer) :
		m_pointer(pointer)
	{
	}


}