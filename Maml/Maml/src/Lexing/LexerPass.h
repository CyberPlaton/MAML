#ifndef _MAML_LEXER_PASS_H_
#define _MAML_LEXER_PASS_H_


#include "Token/TokenStream.h"
#include "Common/Error.h"


namespace maml
{

	class ILexerPass
	{
	public:
		static void push_lexer_pass(ILexerPass* lexer_pass);

		static void pop_lexer_pass();

		static Vector< ILexerPass* >& get_all_lexer_passes();


		ILexerPass();
		virtual ~ILexerPass();


		virtual bool scan(CTokenStream& stream);


	private:
		static Vector< ILexerPass* > s_passes;


	protected:
		CTokenStream* m_stream;

	};

}


#endif	