#include "pch.h"
#include "CppUnitTest.h"

#include <iostream>

#include "antlr4-runtime.h"
#include "SheetMusicLexer.h"
#include "SheetMusicParser.h"
#include "SheetMusicBaseListener.h"

#include "Listeners/Listener.h"

#include "Tokens/scaleRule.h"

#include "Musical Structures/Section.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestSuite
{
	TEST_CLASS(ParsingTests)
	{
	public:
		TEST_CLASS_INITIALIZE(ParsingTestsInitalize)
		{
			ReMu::ScaleDatabase::initalize();
		}

		TEST_METHOD(EmptyFile)
		{
			std::map<std::string, ReMu::Section*> sections = parseProgram("Files/Programs/empty.txt");


			Assert::AreEqual(sections.size(), (size_t)0);
		}
	private:
		std::map<std::string, ReMu::Section*> parseProgram(const char* filepath)
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
	};
}