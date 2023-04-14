#include "Token.h"

namespace maml
{


	SToken::SToken() : 
		m_type(TokenType_None), m_line(UINT_MAX)
	{
	}


	SToken::SToken(TokenType type, const String& text, uint32_t line) :
		m_type(type), m_line(line), m_text(text.c_str())
	{
	}


}