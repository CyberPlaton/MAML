#ifndef _MAML_TOKEN_STREAM_H_
#define _MAML_TOKEN_STREAM_H_


#include "Token.h"

#include <iterator>


namespace maml
{
	class CTokenStreamIterator;

	class CTokenStream : public INonCopyable
	{
		friend class CTokenStreamIterator;
	public:
		CTokenStream();
		~CTokenStream() = default;


		bool has_data() const;

		uint32_t size() const;


		CTokenStreamIterator begin();

		CTokenStreamIterator end();


		bool is_at_end(uint32_t index);

		SToken at(uint32_t index);

		SToken operator[](uint32_t index);

		void erase_tokens_in_range(uint32_t index, uint32_t count);

		void replace(uint32_t index, const SToken& token);


	private:
		Vector< SToken > m_stream;
	};



	class CTokenStreamIterator
	{
	public:
		using iterator_category = std::forward_iterator_tag;
		using difference_type = uint32_t;
		using value_type = SToken;
		using pointer_type = SToken*;
		using reference_type = SToken&;


		CTokenStreamIterator(pointer_type pointer);


		reference_type operator*() const { return *m_pointer; }

		pointer_type operator->() { return m_pointer; }

		CTokenStreamIterator& operator++() { m_pointer++; return *this; }

		CTokenStreamIterator operator++(int) { CTokenStreamIterator iter = *this; ++(*this); return iter; }


		friend bool operator==(const CTokenStreamIterator& lh, const CTokenStreamIterator& rh) { return lh.m_pointer == rh.m_pointer; }
		friend bool operator!=(const CTokenStreamIterator& lh, const CTokenStreamIterator& rh) { return lh.m_pointer != rh.m_pointer; };


	private:
		pointer_type m_pointer;

	};
}


#endif