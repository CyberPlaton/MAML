#include "VectorizingLexerPass.h"


namespace maml
{


	bool CVectorizingLexerPass::scan(CTokenStream& stream)
	{
		CLexerPassInterface::scan(stream);

		for(const auto& token: *m_stream)
		{
			auto type = token.m_type;

			if(_is_number(type))
			{
				if(_is_vector_n(4))
				{
					_create_vector_token(4);
				}
				else if (_is_vector_n(3))
				{
					_create_vector_token(3);
				}
				else if (_is_vector_n(2))
				{
					_create_vector_token(2);
				}
			}

			m_cursor++;
		}

		return true;
	}


	bool CVectorizingLexerPass::_is_vector_n(uint32_t dimension)
	{
		if(_can_advance(dimension))
		{
			bool accumulator = true;

			for(uint32_t i = 0; i < dimension; i++)
			{
				accumulator &= _is_number(_get_token_type_at_index(m_cursor + i));

				if (!accumulator) break;
			}

			return accumulator;
		}
		return false;
	}


	bool CVectorizingLexerPass::_is_number(TokenType type)
	{
		return (type == TokenType_Float ||
				type == TokenType_UInt ||
				type == TokenType_SInt);
	}


	void CVectorizingLexerPass::_create_vector_token(uint32_t dimension)
	{
		String text;
		TokenType type;


		switch (dimension)
		{
		case 2:
		{
			type = TokenType_Vector2;

			text = _get_token_text_at_index(m_cursor);

			text += " ";

			text += _get_token_text_at_index(m_cursor + 1);

			break;
		}
		case 3:
		{
			type = TokenType_Vector3;

			text = _get_token_text_at_index(m_cursor);

			text += " ";

			text += _get_token_text_at_index(m_cursor + 1);

			text += " ";

			text += _get_token_text_at_index(m_cursor + 2);

			break;
		}
		case 4:
		{
			type = TokenType_Vector4;

			text = _get_token_text_at_index(m_cursor);

			text += " ";

			text += _get_token_text_at_index(m_cursor + 1);

			text += " ";

			text += _get_token_text_at_index(m_cursor + 2);

			text += " ";

			text += _get_token_text_at_index(m_cursor + 3);

			break;
		}
		default:
		{
			String message = "Unrecognized Vector dimension of "+ std::to_string(dimension);

			_create_error(message);
			
			return;
		}
		}


		SToken token(type, text, _get_token_line_at_index(m_cursor));

		m_stream->replace(m_cursor, token);

		_erase_tokens_in_range(m_cursor + 1, dimension - 1);
	}


}