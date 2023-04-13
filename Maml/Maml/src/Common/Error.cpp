#include "Error.h"


namespace maml
{

	CError::Type CError::s_errorType;
	maml::String CError::s_errorMessage;

	void CError::push_error_message(Type type, const String& message)
	{
		s_errorMessage = message;
		s_errorType = type;
	}


	CError::Type CError::get_last_error_type()
	{
		return s_errorType;
	}


	maml::String CError::get_last_error_message()
	{
		return s_errorMessage;
	}


	bool CError::had_error()
	{
		return s_errorType != Type_None;
	}

}