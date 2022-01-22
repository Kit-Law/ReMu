#include <iostream>

#include "antlr4-runtime.h"
#include "SheetMusicLexer.h"
#include "SheetMusicParser.h"
#include "SheetMusicBaseListener.h"

#include "Listeners/Listener.h"

#include "Tokens/scaleRule.h"

#include "pugixml.hpp"

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

	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("xgconsole.xml");
	if (!result)
		return -1;

	for (pugi::xml_node tool : doc.child("Profile").child("Tools").children("Tool"))
	{
		int timeout = tool.attribute("Timeout").as_int();

		if (timeout > 0)
			std::cout << "Tool " << tool.attribute("Filename").value() << " has timeout " << timeout << "\n";
	}

	return 0;
}