#ifndef _MAML_LEXER_PASS_INTERFACE_H_
#define _MAML_LEXER_PASS_INTERFACE_H_


#include "LexerPass.h"


namespace maml
{

	class CLexerPassInterface : public ILexerPass
	{
	public:

		virtual bool scan(CTokenStream& stream) override;
		



	protected:
		uint32_t m_cursor;

		bool m_panik;


	protected:
		void _step();

		bool _can_advance(uint32_t steps);

		TokenType _advance();

		TokenType _peek_current();

		TokenType _peek_next();


		TokenType _get_token_type_at_index(uint32_t index);

		String _get_token_text_at_index(uint32_t index);

		uint32_t _get_token_line_at_index(uint32_t index);


		void _erase_tokens_in_range(uint32_t index, uint32_t count);


		void _create_error(const String& message);
	};

}


#endif