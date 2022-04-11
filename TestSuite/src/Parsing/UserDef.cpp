#include "CppUnitTest.h"

#include "../Helper.h"
#include "API.h"

#include "Musical Structures/Section.h"
#include "Musical Structures/Chord/Chord.h"

#include "Exceptions/ParseExceptions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Parsing {

	//Generated using https://www.omnicalculator.com/other/chord
	TEST_CLASS(UserDefParsing)
	{
	private:
		std::stringstream program;
	public:
		TEST_CLASS_INITIALIZE(ParsingTestsInitalize)
		{
			ReMu::ScaleDatabase::initalize();
		}

		TEST_METHOD_INITIALIZE(StringStreamSetup)
		{
			program << "\"test\" = 1 - 20;\n";
		}

		TEST_METHOD(UserDefScaleParsing)
		{
			program << "\\addScale zero {0,0,0,0,0,0}\n\\addScale scale {0,1,2,3,4,5}\n\n\"test\": Scale: F zero -> A scale,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				std::vector<std::pair<ReMu::Pitch, ReMu::Pitch>*>* transition = section.second->getTransitionTable()->getNoteTransitions();

				Assert::AreEqual(transition->at(0)->first == ReMu::Pitch('F', ReMu::None), true);
				Assert::AreEqual(transition->at(1)->first == ReMu::Pitch('F', ReMu::None), true);
				Assert::AreEqual(transition->at(2)->first == ReMu::Pitch('F', ReMu::None), true);
				Assert::AreEqual(transition->at(3)->first == ReMu::Pitch('F', ReMu::None), true);
				Assert::AreEqual(transition->at(4)->first == ReMu::Pitch('F', ReMu::None), true);
				Assert::AreEqual(transition->at(5)->first == ReMu::Pitch('F', ReMu::None), true);

				Assert::AreEqual(transition->at(0)->second == ReMu::Pitch('A', ReMu::None), true);
				Assert::AreEqual(transition->at(1)->second == ReMu::Pitch('A', ReMu::None), true);
				Assert::AreEqual(transition->at(2)->second == ReMu::Pitch('A', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(3)->second == ReMu::Pitch('C', ReMu::None), true);
				Assert::AreEqual(transition->at(4)->second == ReMu::Pitch('D', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(5)->second == ReMu::Pitch('G', ReMu::None), true);
			}
		}

		TEST_METHOD(UserDefChordParsing)
		{
			program << "\\addChord chrom {1,2,3,4,5,6,7}\n\n\"test\": A chrom -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('A', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('A', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('B', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Pitch('C', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(4) == ReMu::Pitch('D', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(5) == ReMu::Pitch('E', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(6) == ReMu::Pitch('F', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(7) == ReMu::Pitch('G', ReMu::Accidental::Sharp), true);
			}
		}
	};
}