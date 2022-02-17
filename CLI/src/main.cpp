#include <iostream>

#include "antlr4-runtime.h"
#include ".\Grammar\SheetMusicLexer.h"
#include ".\Grammar\SheetMusicParser.h"
#include ".\Grammar\SheetMusicBaseListener.h"

#include "Listeners/Listener.h"

#include "Tokens/scaleRule.h"

#include "Musical Structures/KeySig/KeySig.h"

#include "pugixml.hpp"

#include <chrono>

#define PARSER_TESTING
#define XML_TESTING
#define XPATH

template <template<class, class, class...> class C, typename K, typename V, typename... Args>
V GetWithDef(const C<K, V, Args...>& m, K const& key, const V& defval)
{
	typename C<K, V, Args...>::const_iterator it = m.find(key);
	if (it == m.end())
		return defval;
	return it->second;
}

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
	ReMu::KeySig::initalize();

	antlr4::tree::ParseTree* tree = parser.script();
	ReMu::Listener listener;
	antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
#endif // 

#ifdef XML_TESTING
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file("..//D_Major_Scale.musicxml");
	if (!result)
		return -1;
	//1:45 meeting on thur
#ifdef XPATH
	std::map<std::string, ReMu::Section*> sections = listener.getSections();

	for (auto const& section : sections)
	{
		pugi::xpath_node_set notes = doc.select_nodes(("/score-partwise/part/measure[@number >= " + std::to_string(section.second->getStartingMessure()) + " and @number < " + std::to_string(section.second->getEndingMessure()) + "] /note/pitch").c_str());
		ReMu::TransitionTable* transitionTable = section.second->getTransitionTable();

		const ReMu::Pitch* relativeMajorKey = transitionTable->getRelativeMajorKey();
		pugi::xpath_node_set keys = doc.select_nodes(("/score-partwise/part/measure[@number >= " + std::to_string(section.second->getStartingMessure()) + " and @number < " + std::to_string(section.second->getEndingMessure()) + "] /attributes/key/fifths").c_str());

		for (pugi::xpath_node key : keys) //Let key change notes in sections
			key.node().first_child().set_value(std::to_string(ReMu::KeySig::getFiths(relativeMajorKey)).c_str());

		std::unordered_map<ReMu::Pitch, ReMu::Pitch, ReMu::Pitch> noteTransitions;
		for (auto transition : *(transitionTable->getNoteTransitions()))
			noteTransitions[transition.first] = transition.second;
		
		for (pugi::xpath_node node : notes)
		{
			pugi::xml_node note = node.node();

			ReMu::Pitch intialNote = ReMu::Pitch(note.child_value("step")[0], note.child("alter") ? ReMu::Accidental(std::stoi(note.child_value("alter"))) : ReMu::Accidental::None);

			if (noteTransitions.count(intialNote) > 0)
			{
				ReMu::Note resultNote = noteTransitions.at(intialNote);

				pugi::char_t noteStep[2] = { resultNote.getStep() };
				note.child("step").last_child().set_value(noteStep);

				if (note.child("alter"))
				{
					if (resultNote.getAccidental() == ReMu::Accidental::None)
						note.remove_child("alter");
					else
						note.child("alter").last_child().set_value(std::to_string(resultNote.getAccidental()).c_str());
				}
				else if (!resultNote.getAccidental() == ReMu::Accidental::None)
					note.insert_child_after("alter", note.child("step")).text().set(std::to_string(resultNote.getAccidental()).c_str());
			}
		}
	}

	std::cout << "Saving result: " << doc.save_file("save_file_output.xml") << std::endl;
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