#include "API.h"

namespace ReMu {

	ReMu::Listener* API::parse(std::ifstream& inputProgram)
	{
		return parse(antlr4::ANTLRInputStream(inputProgram));
	}

	ReMu::Listener* API::parse(std::stringstream& inputProgram)
	{
		return parse(antlr4::ANTLRInputStream(inputProgram));
	}

	ReMu::Listener* API::parse(antlr4::ANTLRInputStream input)
	{
		SheetMusicLexer lexer(&input);
		antlr4::CommonTokenStream tokens(&lexer);
		SheetMusicParser parser(&tokens);

		ReMu::ScaleDatabase::initalize();
		ReMu::KeySig::initalize();

		antlr4::tree::ParseTree* tree = parser.script();
		ReMu::Listener* listener = new ReMu::Listener();
		antlr4::tree::ParseTreeWalker::DEFAULT.walk(listener, tree);

		ReMu::ScaleDatabase::destruct();
		tree->~ParseTree();
		tree = nullptr;

		return listener;
	}

	void API::eval(ReMu::Listener* listener, const char* input, const char* output)
	{
		ReMu::Evaluator::Evaluator(listener->getSections(), input, output);
	}

}