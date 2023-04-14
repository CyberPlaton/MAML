#ifndef _MAML_LEXER_PASS_H_
#define _MAML_LEXER_PASS_H_


#include "Token/TokenStream.h"


namespace maml
{
	class ILexerPass
	{
	public:
		virtual bool scan(CTokenStream&) = 0;
	};
}


#endif