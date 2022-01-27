#pragma once

#include "antlr4-runtime.h"
#include "./Grammar/SheetMusicLexer.h"
#include "./Grammar/SheetMusicParser.h"
#include "./Grammar/SheetMusicBaseListener.h"

#include "Listeners/Listener.h"

#include "Musical Structures/Section.h"

#include <map>
#include <string>

inline std::map<std::string, ReMu::Section*> parseProgram(const char* filepath)
{
	std::ifstream stream;
	stream.open(filepath);
	antlr4::ANTLRInputStream input(stream);
	SheetMusicLexer lexer(&input);
	antlr4::CommonTokenStream tokens(&lexer);
	SheetMusicParser parser(&tokens);

	antlr4::tree::ParseTree* tree = parser.script();
	ReMu::Listener listener;
	antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);

	return listener.getSections();
}