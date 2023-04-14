#ifndef _MAML_ERROR_H_
#define _MAML_ERROR_H_


#include "Common.h"


namespace maml
{

	enum ErrorType
	{
		ErrorType_None = 0,

		ErrorType_FileAccess_InvalidArgument = EINVAL,
		ErrorType_FileAccess_PermissionDenied = EACCES,
		ErrorType_FileAccess_FileNotFound = ENOENT,
		ErrorType_FileAccess_DomainError = EDOM,
		ErrorType_FileAccess_IllegalByteSequence = EILSEQ,

		ErrorType_LexingError = 50,

	};


	class CError
	{
	public:
		static void push_error_message(ErrorType type, const String& message);

		static ErrorType get_last_error_type();

		static String get_last_error_message();

		static bool had_error();


	private:
		static ErrorType s_errorType;

		static String s_errorMessage;

	};


}


#endif