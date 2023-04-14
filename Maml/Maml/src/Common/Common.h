#ifndef _MAML_COMMON_H_
#define _MAML_COMMON_H_


#include <string>
#include <filesystem>
#include <assert.h>
#include <vector>


#define MAML_NOVTABLE __declspec(novtable)

#if MAML_DEBUG
#define MAML_ASSERT(expression, message) \
assert((message, expression))

#define MAML_VERIFY(expression, message) \
assert((message, expression))

#elif MAML_RELEASE or MAML_DISTR
#define MAML_ASSERT(expression, message)

#define MAML_VERIFY(expression, message) \
assert((message, expression))
#endif



namespace maml
{

	using String = std::string;

	template < typename T >
	using Vector = std::vector< T >;


	class INonCopyable
	{
	protected:
		INonCopyable() = default;
		virtual ~INonCopyable() = default;



	private:
		INonCopyable(const INonCopyable&) = default;
		INonCopyable& operator =(const INonCopyable&) = default;
	};


}



#define STATIC_GET(CLASS, STATIC_MEMBER) \
static CLASS& Get() \
{ static CLASS STATIC_MEMBER; return STATIC_MEMBER;} \





#endif