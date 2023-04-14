#include "LexerBasePass.h"


namespace maml
{


	CLexerBasePass::CLexerBasePass() : 
		m_tokenStream(nullptr), m_cursor(0), m_currentLine(0), m_panik(false)
	{

	}


	bool CLexerBasePass::scan(const String& source_file_path, CTokenStream& stream)
	{
		for(;;)
		{
			SToken token = _scan_next_token();

			if(m_panik)
			{
				return false;
			}

			
		}

		return true;
	}


	bool CLexerBasePass::_is_eof(char c)
	{
		return c == '\0';
	}


	bool CLexerBasePass::_is_digit(char c)
	{
		return c >= '0' && c <= '9';
	}


	bool CLexerBasePass::_is_whitespace(char c)
	{
		return (c == '\n' || c == '\t' ||
				c == '\f' || c == '\r' ||
				c == ' ');
	}


	bool CLexerBasePass::_is_identifier(char c)
	{
		return ((c >= 'a' && c <= 'z') ||
				(c >= 'A' && c <= 'Z') ||
				 c == '_');
	}


	bool CLexerBasePass::_is_newline(char c)
	{
		return c == '\n';
	}


	bool CLexerBasePass::_is_comment(char c)
	{
		return c == '#';
	}


	bool CLexerBasePass::_is_end(const String& c)
	{
		return c == "end";
	}


	bool CLexerBasePass::_is_false(const String& c)
	{
		return c == "False";
	}


	bool CLexerBasePass::_is_true(const String& c)
	{
		return c == "True";
	}


	bool CLexerBasePass::_is_number(TokenType type)
	{
		return (type == TokenType_Float ||
				type == TokenType_UInt ||
				type == TokenType_SInt);
	}


	void CLexerBasePass::_step()
	{
		m_cursor++;
	}


	char CLexerBasePass::_advance()
	{
		return m_source[++m_cursor];
	}


	char CLexerBasePass::_peek_current()
	{
		return m_source[m_cursor];
	}


	char CLexerBasePass::_peek_next()
	{
		return m_source[m_cursor + 1];
	}


	maml::SToken CLexerBasePass::_scan_next_token()
	{
		m_currentToken.clear();

		auto c = _peek_current();


		while(_is_whitespace(c))
		{
			if (_is_newline(c)) m_currentLine++;

			c = _advance();
		}

		if (_is_eof(c))
		{
			return _create_token(TokenType_EOF, "\0", m_currentLine);
		}

		if (_is_digit(c))
		{
			return _create_number_token();
		}

		if (_is_identifier(c))
		{
			return _create_identifier_token();
		}

		if (_is_comment(c))
		{
			_advance();

			while (_peek_current() != '\n')
			{
				c = _advance();
			}

			m_currentLine++;

			return _scan_next_token();
		}

		switch (c)
		{
		case '=':
		{
			_advance();

			return _create_token(TokenType_Equal, "=", m_currentLine);
		}
		case ':':
		{
			_advance();

			return _create_token(TokenType_Colon, ":", m_currentLine);
		}
		case '"':
		{
			_advance();

			return _create_string_token();
		}
		case '[':
		{
			_advance();

			return _create_token(TokenType_LBracket, "[", m_currentLine);
		}
		case ']':
		{
			_advance();

			return _create_token(TokenType_RBracket, "]", m_currentLine);
		}
		case ',':
		{
			_advance();

			return _create_token(TokenType_Comma, ",", m_currentLine);
		}
		case '-':
		{
			_advance();

			return _create_number_token(true);
		}
		default: break;
		}


		String error = "Unrecognized character \"";	error.push_back(c); error += "\" at line " + std::to_string(m_currentLine);

		return _create_error(error);
	}


	maml::SToken CLexerBasePass::_create_identifier_token()
	{
		String text;

		auto c = _peek_current();

		while(_is_identifier(c))
		{
			text += c;


			c = _advance();
		}

		m_currentToken = text;

		if(_is_end(m_currentToken))
		{
			return _create_token(TokenType_End, m_currentToken, m_currentLine);
		}
		if(_is_false(m_currentToken))
		{
			return _create_token(TokenType_False, m_currentToken, m_currentLine);
		}
		if (_is_true(m_currentToken))
		{
			return _create_token(TokenType_True, m_currentToken, m_currentLine);
		}

		return _create_token(TokenType_Identifier, m_currentToken, m_currentLine);
	}


	maml::SToken CLexerBasePass::_create_string_token()
	{
		String text;

		char c = _peek_current();

		while (c != '"' && !_is_eof(c) && c != '\n')
		{
			text += c;

			c = _advance();
		}

		if (_is_eof(c))
		{
			String error = "Unterminated string at line " + std::to_string(m_currentLine);

			return _create_error(error);
		}
		if (_is_newline(c))
		{
			String error = "Multiline string at line " + std::to_string(m_currentLine);

			return _create_error(error);
		}

		_advance();

		m_currentToken = text;

		return _create_token(TokenType_String, m_currentToken, m_currentLine);
	}


	maml::SToken CLexerBasePass::_create_number_token(bool negative /*= false*/)
	{
		std::string text;

		bool floating_point = false;

		if (negative) text = "-";

		while (_is_digit(_peek_current()))
		{
			text += _peek_current();

			_advance();
		}

		if (_peek_current() == '.')
		{
			floating_point = true;

			_advance();

			text += ".";

			while (_is_digit(_peek_current()))
			{
				text += _peek_current();

				_advance();
			}
		}


		if (floating_point)
		{
			m_currentToken = text;

			return _create_token(TokenType_Float, m_currentToken, m_currentLine);
		}

		if (negative)
		{
			m_currentToken = text;

			return _create_token(TokenType_SInt, m_currentToken, m_currentLine);
		}
		else
		{
			m_currentToken = text;

			return _create_token(TokenType_UInt, m_currentToken, m_currentLine);
		}
	}


	maml::SToken CLexerBasePass::_create_token(TokenType type, const String& text, uint32_t line)
	{
		return { type, text, line };
	}


	maml::SToken CLexerBasePass::_create_error(const String& message)
	{
		CError::push_error_message(ErrorType_LexingError, message);

		m_panik = true;

		return SToken{};
	}


}