#include <iostream>

#include "antlr4-runtime.h"
#include ".\Grammar\SheetMusicLexer.h"
#include ".\Grammar\SheetMusicParser.h"
#include ".\Grammar\SheetMusicBaseListener.h"

#include "Listeners/Listener.h"

#include "Evaluators/Evaluator.h"

#include "Tokens/scaleRule.h"

#include "Musical Structures/KeySig/KeySig.h"

#include "pugixml.hpp"

#include "Timers/DeltaTime.h"

int main()//const char* argv[]) 
{
	Utils::DeltaTime deltaTime;
	deltaTime.resetDeltaTime();

	std::ifstream stream;
	//stream.open(argv[1]);
	stream.open("..//Programs//example.txt");
	antlr4::ANTLRInputStream input(stream);
	SheetMusicLexer lexer(&input);
	antlr4::CommonTokenStream tokens(&lexer);
	SheetMusicParser parser(&tokens);

	ReMu::ScaleDatabase::initalize();
	ReMu::KeySig::initalize();

	antlr4::tree::ParseTree* tree = parser.script();
	ReMu::Listener listener;

	try
	{
		antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);

		deltaTime.calDeltaTime();
		std::cout << "Parsing Time = " << deltaTime.getDeltaTime() << "s" << std::endl;

		//ReMu::Evaluator::Evaluator(listener.getSections(), "..//MusicXMLFiles//Input//Chord.musicxml", "..//MusicXMLFiles//Output//Gmin.musicxml");
		//ReMu::Evaluator::Evaluator(listener.getSections(), "..//MusicXMLFiles//Input//D_Major_Scale.musicxml", "..//MusicXMLFiles//Output//D_Lydian_scale.musicxml");
		ReMu::Evaluator::Evaluator(listener.getSections(), "..//MusicXMLFiles//Output//C_Major.musicxml", "..//MusicXMLFiles//Output//D#_Mixolydian.musicxml");

		//ReMu::Evaluator::Evaluator(listener.getSections(), "..//MusicXMLFiles//Input//D_Major_Scale.musicxml", "..//MusicXMLFiles//Output//AAAAAA.musicxml");

		deltaTime.calDeltaTime();
		std::cout << "Evaluation Time = " << deltaTime.getDeltaTime() << "s" << std::endl;

	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}