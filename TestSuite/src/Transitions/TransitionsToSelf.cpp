#include "CppUnitTest.h"

#include "../Helper.h"

#include "Musical Structures/Section.h"
#include "Musical Structures/Chord/Chord.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Parsing { namespace Transitions {

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
			}
		}

		TEST_METHOD(ChordTransitionToSelf)
		{
			std::map<std::string, ReMu::Section*> sections = parseProgram("../TestSuite/Files/Programs/chordSelf.txt");

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				for (auto transition : *section.second->getTransitionTable()->getSequenceTransitions())
				{
					Assert::AreEqual(*(ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first) == *(ReMu::Chord*)(std::get<1>(transition).getStuctsToMapping()->at(0).first), true);
				}
			}
		}

		TEST_METHOD(SequenceTransitionToSelf)
		{
			std::map<std::string, ReMu::Section*> sections = parseProgram("../TestSuite/Files/Programs/sequenceSelf.txt");

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				for (auto transition : *section.second->getTransitionTable()->getSequenceTransitions())
				{
					Assert::AreEqual(*(ReMu::Pitch*)(std::get<0>(transition).getStuctsToMapping()->at(0).first) == *(ReMu::Pitch*)(std::get<1>(transition).getStuctsToMapping()->at(0).first), true);
				}
			}
		}
	};
} }