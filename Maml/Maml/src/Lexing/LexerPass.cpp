#include "LexerPass.h"


namespace maml
{
	maml::Vector< ILexerPass* > ILexerPass::s_passes;


	ILexerPass::ILexerPass() : 
		m_stream(nullptr)
	{

	}


	ILexerPass::~ILexerPass()
	{
		m_stream = nullptr;
	}


	bool ILexerPass::scan(CTokenStream& stream)
	{
		m_stream = &stream;

		return true;
	}


	void ILexerPass::push_lexer_pass(ILexerPass* lexer_pass)
	{
		s_passes.push_back(lexer_pass);
	}


	void ILexerPass::pop_lexer_pass()
	{
		s_passes.pop_back();
	}


	maml::Vector< ILexerPass* >& ILexerPass::get_all_lexer_passes()
	{
		return s_passes;
	}


}