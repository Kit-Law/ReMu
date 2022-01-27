#include "CppUnitTest.h"

#include "../Helper.h"

#include "Musical Structures/Section.h"
#include "Musical Structures/Chord/Chord.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Transitions
{
	TEST_CLASS(TransitionsToSelf)
	{
	public:
		TEST_CLASS_INITIALIZE(ParsingTestsInitalize)
		{
			ReMu::ScaleDatabase::initalize();
		}

		TEST_METHOD(ScaleTransitionToSelf)
		{
			std::map<std::string, ReMu::Section*> sections = parseProgram("../TestSuite/Files/Programs/scaleSelf.txt");

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);
				Assert::AreEqual(section.second->getTransitionTable()->getSequenceTransitions()->size(), (size_t)0);
				Assert::AreEqual(section.second->getTransitionTable()->getChordTransitions()->size(), (size_t)0);
			}
		}

		TEST_METHOD(ChordTransitionToSelf)
		{
			std::map<std::string, ReMu::Section*> sections = parseProgram("../TestSuite/Files/Programs/chordSelf.txt");

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);
				Assert::AreEqual(section.second->getTransitionTable()->getSequenceTransitions()->size(), (size_t)0);

				for (std::pair<ReMu::Chord, ReMu::Chord> transition : *section.second->getTransitionTable()->getChordTransitions())
				{
					Assert::AreEqual(transition.first == transition.second, true);
				}
			}
		}

		TEST_METHOD(SequenceTransitionToSelf)
		{
			std::map<std::string, ReMu::Section*> sections = parseProgram("../TestSuite/Files/Programs/sequenceSelf.txt");

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);
				Assert::AreEqual(section.second->getTransitionTable()->getChordTransitions()->size(), (size_t)0);

				for (std::pair<std::vector<ReMu::Pitch>, std::vector<ReMu::Pitch>> transition : *section.second->getTransitionTable()->getSequenceTransitions())
				{
					Assert::AreEqual(transition.first == transition.second, true);
				}
			}
		}
	};
}