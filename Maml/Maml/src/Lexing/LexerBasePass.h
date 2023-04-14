#ifndef _MAML_LEXER_BASE_PASS_H_
#define _MAML_LEXER_BASE_PASS_H_


#include "Common/SourceFile.h"
#include "Token/TokenStream.h"


namespace maml
{

	class CLexerBasePass
	{
	public:
		CLexerBasePass();
		~CLexerBasePass() = default;


		bool scan(const String& source_file_path, CTokenStream& stream);


	private:
		CSourceFile m_source;

		String m_currentToken;

		CTokenStream* m_tokenStream;

		uint32_t m_cursor;

		uint32_t m_currentLine;

		bool m_panik;

	private:

		SToken _scan_next_token();


		SToken _create_identifier_token();

		SToken _create_string_token();

		SToken _create_number_token(bool negative = false);

		SToken _create_token(TokenType type, const String& text, uint32_t line);

		SToken _create_error(const String& message);


		bool _is_eof(char c);

		bool _is_digit(char c);

		bool _is_whitespace(char c);

		bool _is_identifier(char c);

		bool _is_newline(char c);

		bool _is_comment(char c);

		bool _is_end(const String& c);

		bool _is_false(const String& c);

		bool _is_true(const String& c);

		bool _is_number(TokenType type);



		void _step();

		char _advance();

		char _peek_current();

		char _peek_next();

	};
}


#endif