#ifndef _MAML_COMMON_H_
#define _MAML_COMMON_H_


#define MAML_NOVTABLE __declspec(novtable)


#include <string>
#include <filesystem>


namespace maml
{
	using String = std::string;



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