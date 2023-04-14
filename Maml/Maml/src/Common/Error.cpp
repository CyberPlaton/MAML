#include "Error.h"


namespace maml
{

	ErrorType CError::s_errorType;
	maml::String CError::s_errorMessage;

	void CError::push_error_message(ErrorType type, const String& message)
	{
		s_errorMessage = message;
		s_errorType = type;
	}


	ErrorType CError::get_last_error_type()
	{
		return s_errorType;
	}


	maml::String CError::get_last_error_message()
	{
		return s_errorMessage;
	}


	bool CError::had_error()
	{
		return s_errorType != ErrorType_None;
	}

}