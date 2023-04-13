#ifndef _MAML_ERROR_H_
#define _MAML_ERROR_H_


#include "Common.h"


namespace maml
{
	class CError
	{
	public:
		enum Type
		{
			Type_None = 0,

			Type_FileAccess_InvalidArgument = EINVAL,
			Type_FileAccess_PermissionDenied = EACCES,
			Type_FileAccess_FileNotFound = ENOENT,
			Type_FileAccess_DomainError = EDOM,
			Type_FileAccess_IllegalByteSequence = EILSEQ,



		};


	public:
		static void push_error_message(Type type, const String& message);

		static Type get_last_error_type();

		static String get_last_error_message();

		static bool had_error();


	private:
		static Type s_errorType;

		static String s_errorMessage;

	};


}


#endif