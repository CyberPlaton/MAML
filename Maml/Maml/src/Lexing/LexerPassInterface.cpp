#include "LexerPassInterface.h"


namespace maml
{


	bool CLexerPassInterface::scan(CTokenStream& stream)
	{
		return ILexerPass::scan(stream);
	}


	void CLexerPassInterface::_step()
	{
		m_cursor++;
	}


	bool CLexerPassInterface::_can_advance(uint32_t steps)
	{
		return m_cursor + steps < m_stream->size(); 
	}


	maml::TokenType CLexerPassInterface::_advance()
	{
		const auto& token = m_stream->at(++m_cursor);

		return token.m_type;
	}


	maml::TokenType CLexerPassInterface::_peek_current()
	{
		const auto& token = m_stream->at(m_cursor);

		return token.m_type;
	}


	maml::TokenType CLexerPassInterface::_peek_next()
	{
		const auto& token = m_stream->at(m_cursor + 1);

		return token.m_type;
	}


	maml::SToken& CLexerPassInterface::_get_token_at_index(uint32_t index)
	{
		return m_stream->at(index);
	}


	void CLexerPassInterface::_erase_tokens_in_range(uint32_t index, uint32_t count)
	{
		m_stream->erase_tokens_in_range(index, count);
	}


	void CLexerPassInterface::_create_error(const String& message)
	{
		CError::push_error_message(ErrorType_PostProcess_LexingError, message);

		m_panik = true;
	}


}