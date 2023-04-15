#ifndef _MAML_HEADER_GUARD_H_
#define _MAML_HEADER_GUARD_H_


#include "Common/SourceFile.h"
#include "Lexing/LexerBasePass.h"
#include "Lexing/LexerPassInterface.h"
#include "Lexing/LexerPasses/VectorizingLexerPass.h"


namespace maml
{
	struct SInit
	{
		List< ILexerPass* > m_lexerPasses;
	};

	void init(const SInit& settings);

	void terminate();

	bool scan_file(const String& source_file_path);
}


#endif