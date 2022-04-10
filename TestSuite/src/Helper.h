#pragma once

#include "antlr4-runtime.h"
#include "./Grammar/SheetMusicLexer.h"
#include "./Grammar/SheetMusicParser.h"
#include "./Grammar/SheetMusicBaseListener.h"

#include "Listeners/Listener.h"

#include "Musical Structures/Section.h"
#include "Musical Structures/Note/Pitch.h"

#include "Evaluators/NoteEvaluator.h"
#include "Evaluators/Evaluator.h"

#include "pugixml.hpp"

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
	ReMu::Listener* listener = new ReMu::Listener();
	antlr4::tree::ParseTreeWalker::DEFAULT.walk(listener, tree);

	return listener->getSections();
}

inline bool verifyXmlFile(const char* docPath, std::vector<ReMu::Pitch>& resultNotes)
{
	pugi::xml_document doc = ReMu::Evaluator::Evaluator::openDoc(docPath);
	pugi::xpath_node_set notes = doc.select_nodes("/score-partwise/part/measure/note/pitch");
	bool result = true;

	for (int i = 0; i < notes.size(); i++)
	{
		if (ReMu::Evaluator::NoteEvaluator::parseNote(notes[i].node()) == resultNotes[i])
			continue;
		
		result = false;
		break;
	}

	return result;
}





/*
program << "([A-G]#? [a-z]*[0-9]?) -> A,";
			std::map<std::string, ReMu::Section\*> sections = ReMu::API::parse\(program\)->getSections\(\);

			for \(auto const& section : sections\)
			{
				Assert::AreEqual\(section\.second->getTransitionTable\(\)->getNoteTransitions\(\)->size\(\), \(size_t\)0\);

				auto transition = section\.second->getTransitionTable\(\)->getSequenceTransitions\(\)->at\(0\);
				ReMu::Chord\* chord = \(ReMu::Chord\*\)\(std::get<0>\(transition\)\.getStuctsToMapping\(\)->at\(0\)\.first\);

				Assert::AreEqual\(chord->getComponents\(\)->size\(\) == 3, true\);
				Assert::AreEqual\(chord->getComponents\(\)->at\(0\) == (ReMu::Pitch\('[A-G]', ReMu::Accidental::[A-Za-z]*\)), true\);
				Assert::AreEqual\(chord->getComponents\(\)->at\(1\) == (ReMu::Pitch\('[A-G]', ReMu::Accidental::[A-Za-z]*\)), true\);
				Assert::AreEqual\(chord->getComponents\(\)->at\(2\) == (ReMu::Pitch\('[A-G]', ReMu::Accidental::[A-Za-z]*\)), true\);
				Assert::AreEqual\(chord->getComponents\(\)->at\(3\) == (ReMu::Pitch\('[A-G]', ReMu::Accidental::[A-Za-z]*\)), true\);
			}
*/

/*
program << "A -> $1,";\n\n			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");\n\n			std::vector<ReMu::Pitch> resultNotes;\n			resultNotes.push_back($2);\n			resultNotes.push_back($3);\n			resultNotes.push_back($4);\n			resultNotes.push_back($5);\n\n			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
*/