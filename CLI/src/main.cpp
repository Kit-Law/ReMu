#include <iostream>

#include "antlr4-runtime.h"
#include "SheetMusicLexer.h"
#include "SheetMusicParser.h"
#include "SheetMusicBaseListener.h"

#include "Listeners/Listener.h"

#include "Tokens/scaleRule.h"

#include "pugixml.hpp"

#include <chrono>

#define PARSER_TESTING
#define XPATH

int main()//const char* argv[]) 
{
#ifdef PARSER_TESTING
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
#endif // 

#ifdef XML_TESTING
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("..//Saltarello.musicxml");
	if (!result)
		return -1;

#ifdef XPATH
	pugi::xpath_node_set notes = doc.select_nodes("/score-partwise/part[@id='P1']/measure/note/pitch");

	for (pugi::xpath_node node : notes)
	{
		pugi::xml_node note = node.node();
		std::cout << "Note: " << note.child_value("step") << " " << note.child_value("octave") << std::endl;
	}
#endif // DEBUG
	
#ifdef ITERATION
	for (pugi::xml_node measure : doc.child("score-partwise").child("part").child("measure"))
	{
		std::cout << "Measure Number: " << measure.attribute("number").value() << std::endl << std::endl;

		for (pugi::xml_node notes : measure.children("note"))
		{
			for (pugi::xml_node pitch : notes.children("pitch"))
				std::cout << "Note: " << pitch.child_value("step") << " " << pitch.child("octave").value() << std::endl;
		}		
	}
#endif // DEBUG

#endif // XML_TESTING

	return 0;
}