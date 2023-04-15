#ifndef _VECTORIZING_LEXER_PASS_H_
#define _VECTORIZING_LEXER_PASS_H_


#include "../LexerPassInterface.h"


namespace maml
{

	class CVectorizingLexerPass : public CLexerPassInterface
	{
	public:
		bool scan(CTokenStream& stream) override final;
	

	private:

		bool _is_vector_n(uint32_t dimension);

		bool _is_number(TokenType type);

		void _create_vector_token(uint32_t dimension);
	};


}


#endif