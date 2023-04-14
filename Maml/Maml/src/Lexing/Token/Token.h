#ifndef _MAML_TOKEN_H_
#define _MAML_TOKEN_H_


#include "Common/Common.h"


namespace maml
{
	enum TokenType
	{
		TokenType_None = 0,

		TokenType_EOF,
		TokenType_Error,

		TokenType_Identifier,
		TokenType_Equal,
		TokenType_Colon,
		TokenType_Comma,
		TokenType_LBracket,
		TokenType_RBracket,
		TokenType_End,
		TokenType_False,
		TokenType_True,
		TokenType_Float,
		TokenType_UInt,
		TokenType_SInt,
		TokenType_String,
		TokenType_Vector2,
		TokenType_Vector3,
		TokenType_Vector4
	};


	struct SToken
	{
		SToken();
		SToken(TokenType type, const String& text, uint32_t line);


		TokenType m_type;
		String m_text;
		uint32_t m_line;
	};
}

#endif