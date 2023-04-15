#include "Maml.h"


namespace maml
{


	void init(const SInit& settings)
	{
		ILexerPass::push_lexer_pass(new CVectorizingLexerPass());

		for(const auto& lexer_pass : settings.m_lexerPasses)
		{
			ILexerPass::push_lexer_pass(lexer_pass);
		}
	}


	void terminate()
	{
		auto& passes = ILexerPass::get_all_lexer_passes();

		while(!passes.empty())
		{
			delete passes[0];

			passes.erase(passes.begin());
		}
	}


	bool scan_file(const String& source_file_path)
	{
		CTokenStream stream;

		CLexerBasePass base_pass;

		bool result = true;

		if(base_pass.scan(source_file_path, stream))
		{
			for(auto lexing_pass : ILexerPass::get_all_lexer_passes())
			{
				result &= lexing_pass->scan(stream);
			}

			return result;
		}

		return false;
	}


}