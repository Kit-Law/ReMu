#include <iostream>

#include "antlr4-runtime.h"
#include "SheetMusicLexer.h"
#include "SheetMusicParser.h"
#include "SheetMusicBaseListener.h"

#include "Listeners/Listener.h"

#include "Tokens/scaleRule.h"

int main()//const char* argv[]) 
{
	std::ifstream stream;
	//stream.open(argv[1]);
	stream.open("..//Programs//example.txt");
	antlr4::ANTLRInputStream input(stream);
	SheetMusicLexer lexer(&input);
	antlr4::CommonTokenStream tokens(&lexer);
	SheetMusicParser parser(&tokens);

	ReMu::ScaleDatabase::initalize();

	antlr4::tree::ParseTree* tree = parser.script();
	ReMu::Listener listener;
	antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);

	return 0;
}