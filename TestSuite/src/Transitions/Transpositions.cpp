#include "CppUnitTest.h"

#include "../Helper.h"

#include "Musical Structures/Section.h"
#include "Musical Structures/Chord/Chord.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Transitions
{
	TEST_CLASS(Transposition)
	{
	public:
		TEST_CLASS_INITIALIZE(TranspositionTestsInitalize)
		{
			ReMu::ScaleDatabase::initalize();
		}

		TEST_METHOD(TranspositionOneStep)
		{
			std::map<std::string, ReMu::Section*> sections = parseProgram("../TestSuite/Files/Programs/transpositionOneStep.txt");

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getSequenceTransitions()->size(), (size_t)0);

				std::vector<std::pair<ReMu::Pitch, ReMu::Pitch>*>* transition = section.second->getTransitionTable()->getNoteTransitions();

				Assert::AreEqual(transition->at(0)->first == ReMu::Pitch('A', ReMu::None), true);
				Assert::AreEqual(transition->at(1)->first == ReMu::Pitch('B', ReMu::None), true);
				Assert::AreEqual(transition->at(2)->first == ReMu::Pitch('C', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(3)->first == ReMu::Pitch('D', ReMu::None), true);
				Assert::AreEqual(transition->at(4)->first == ReMu::Pitch('E', ReMu::None), true);
				Assert::AreEqual(transition->at(5)->first == ReMu::Pitch('F', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(6)->first == ReMu::Pitch('G', ReMu::Sharp), true);

				Assert::AreEqual(transition->at(6)->second == ReMu::Pitch('A', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(0)->second == ReMu::Pitch('B', ReMu::None), true);
				Assert::AreEqual(transition->at(1)->second == ReMu::Pitch('C', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(2)->second == ReMu::Pitch('D', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(3)->second == ReMu::Pitch('E', ReMu::None), true);
				Assert::AreEqual(transition->at(4)->second == ReMu::Pitch('F', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(5)->second == ReMu::Pitch('G', ReMu::Sharp), true);
			}
		}

		TEST_METHOD(TranspositionTwoSteps)
		{
			std::map<std::string, ReMu::Section*> sections = parseProgram("../TestSuite/Files/Programs/transpositionTwoSteps.txt");

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getSequenceTransitions()->size(), (size_t)0);

				std::vector<std::pair<ReMu::Pitch, ReMu::Pitch>*>* transition = section.second->getTransitionTable()->getNoteTransitions();

				Assert::AreEqual(transition->at(0)->first == ReMu::Pitch('A', ReMu::None), true);
				Assert::AreEqual(transition->at(1)->first == ReMu::Pitch('B', ReMu::None), true);
				Assert::AreEqual(transition->at(2)->first == ReMu::Pitch('C', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(3)->first == ReMu::Pitch('D', ReMu::None), true);
				Assert::AreEqual(transition->at(4)->first == ReMu::Pitch('E', ReMu::None), true);
				Assert::AreEqual(transition->at(5)->first == ReMu::Pitch('F', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(6)->first == ReMu::Pitch('G', ReMu::Sharp), true);

				Assert::AreEqual(transition->at(5)->second == ReMu::Pitch('A', ReMu::None), true);
				Assert::AreEqual(transition->at(6)->second == ReMu::Pitch('B', ReMu::None), true);
				Assert::AreEqual(transition->at(0)->second == ReMu::Pitch('C', ReMu::None), true);
				Assert::AreEqual(transition->at(1)->second == ReMu::Pitch('D', ReMu::None), true);
				Assert::AreEqual(transition->at(2)->second == ReMu::Pitch('E', ReMu::None), true);
				Assert::AreEqual(transition->at(3)->second == ReMu::Pitch('F', ReMu::None), true);
				Assert::AreEqual(transition->at(4)->second == ReMu::Pitch('G', ReMu::None), true);
			}
		}

		TEST_METHOD(TranspositionThreeSteps)
		{
			std::map<std::string, ReMu::Section*> sections = parseProgram("../TestSuite/Files/Programs/transpositionThreeSteps.txt");

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getSequenceTransitions()->size(), (size_t)0);

				std::vector<std::pair<ReMu::Pitch, ReMu::Pitch>*>* transition = section.second->getTransitionTable()->getNoteTransitions();

				Assert::AreEqual(transition->at(0)->first == ReMu::Pitch('A', ReMu::None), true);
				Assert::AreEqual(transition->at(1)->first == ReMu::Pitch('B', ReMu::None), true);
				Assert::AreEqual(transition->at(2)->first == ReMu::Pitch('C', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(3)->first == ReMu::Pitch('D', ReMu::None), true);
				Assert::AreEqual(transition->at(4)->first == ReMu::Pitch('E', ReMu::None), true);
				Assert::AreEqual(transition->at(5)->first == ReMu::Pitch('F', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(6)->first == ReMu::Pitch('G', ReMu::Sharp), true);

				Assert::AreEqual(transition->at(4)->second == ReMu::Pitch('A', ReMu::None), true);
				Assert::AreEqual(transition->at(5)->second == ReMu::Pitch('B', ReMu::None), true);
				Assert::AreEqual(transition->at(6)->second == ReMu::Pitch('C', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(0)->second == ReMu::Pitch('D', ReMu::None), true);
				Assert::AreEqual(transition->at(1)->second == ReMu::Pitch('E', ReMu::None), true);
				Assert::AreEqual(transition->at(2)->second == ReMu::Pitch('F', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(3)->second == ReMu::Pitch('G', ReMu::None), true);
			}
		}

		TEST_METHOD(TranspositionFourSteps)
		{
			std::map<std::string, ReMu::Section*> sections = parseProgram("../TestSuite/Files/Programs/transpositionFourSteps.txt");

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getSequenceTransitions()->size(), (size_t)0);

				std::vector<std::pair<ReMu::Pitch, ReMu::Pitch>*>* transition = section.second->getTransitionTable()->getNoteTransitions();

				Assert::AreEqual(transition->at(0)->first == ReMu::Pitch('A', ReMu::None), true);
				Assert::AreEqual(transition->at(1)->first == ReMu::Pitch('B', ReMu::None), true);
				Assert::AreEqual(transition->at(2)->first == ReMu::Pitch('C', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(3)->first == ReMu::Pitch('D', ReMu::None), true);
				Assert::AreEqual(transition->at(4)->first == ReMu::Pitch('E', ReMu::None), true);
				Assert::AreEqual(transition->at(5)->first == ReMu::Pitch('F', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(6)->first == ReMu::Pitch('G', ReMu::Sharp), true);

				Assert::AreEqual(transition->at(3)->second == ReMu::Pitch('A', ReMu::None), true);
				Assert::AreEqual(transition->at(4)->second == ReMu::Pitch('B', ReMu::None), true);
				Assert::AreEqual(transition->at(5)->second == ReMu::Pitch('C', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(6)->second == ReMu::Pitch('D', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(0)->second == ReMu::Pitch('E', ReMu::None), true);
				Assert::AreEqual(transition->at(1)->second == ReMu::Pitch('F', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(2)->second == ReMu::Pitch('G', ReMu::Sharp), true);
			}
		}

		TEST_METHOD(TranspositionFiveSteps)
		{
			std::map<std::string, ReMu::Section*> sections = parseProgram("../TestSuite/Files/Programs/transpositionFiveSteps.txt");

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getSequenceTransitions()->size(), (size_t)0);

				std::vector<std::pair<ReMu::Pitch, ReMu::Pitch>*>* transition = section.second->getTransitionTable()->getNoteTransitions();

				Assert::AreEqual(transition->at(0)->first == ReMu::Pitch('A', ReMu::None), true);
				Assert::AreEqual(transition->at(1)->first == ReMu::Pitch('B', ReMu::None), true);
				Assert::AreEqual(transition->at(2)->first == ReMu::Pitch('C', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(3)->first == ReMu::Pitch('D', ReMu::None), true);
				Assert::AreEqual(transition->at(4)->first == ReMu::Pitch('E', ReMu::None), true);
				Assert::AreEqual(transition->at(5)->first == ReMu::Pitch('F', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(6)->first == ReMu::Pitch('G', ReMu::Sharp), true);

				Assert::AreEqual(transition->at(2)->second == ReMu::Pitch('A', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(3)->second == ReMu::Pitch('B', ReMu::None), true);
				Assert::AreEqual(transition->at(4)->second == ReMu::Pitch('C', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(5)->second == ReMu::Pitch('D', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(6)->second == ReMu::Pitch('F', ReMu::None), true);
				Assert::AreEqual(transition->at(0)->second == ReMu::Pitch('F', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(1)->second == ReMu::Pitch('G', ReMu::Sharp), true);
			}
		}

		TEST_METHOD(TranspositionSixSteps)
		{
			std::map<std::string, ReMu::Section*> sections = parseProgram("../TestSuite/Files/Programs/transpositionSixSteps.txt");

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getSequenceTransitions()->size(), (size_t)0);

				std::vector<std::pair<ReMu::Pitch, ReMu::Pitch>*>* transition = section.second->getTransitionTable()->getNoteTransitions();

				Assert::AreEqual(transition->at(0)->first == ReMu::Pitch('A', ReMu::None), true);
				Assert::AreEqual(transition->at(1)->first == ReMu::Pitch('B', ReMu::None), true);
				Assert::AreEqual(transition->at(2)->first == ReMu::Pitch('C', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(3)->first == ReMu::Pitch('D', ReMu::None), true);
				Assert::AreEqual(transition->at(4)->first == ReMu::Pitch('E', ReMu::None), true);
				Assert::AreEqual(transition->at(5)->first == ReMu::Pitch('F', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(6)->first == ReMu::Pitch('G', ReMu::Sharp), true);

				Assert::AreEqual(transition->at(1)->second == ReMu::Pitch('A', ReMu::None), true);
				Assert::AreEqual(transition->at(2)->second == ReMu::Pitch('B', ReMu::None), true);
				Assert::AreEqual(transition->at(3)->second == ReMu::Pitch('C', ReMu::None), true);
				Assert::AreEqual(transition->at(4)->second == ReMu::Pitch('D', ReMu::None), true);
				Assert::AreEqual(transition->at(5)->second == ReMu::Pitch('E', ReMu::None), true);
				Assert::AreEqual(transition->at(6)->second == ReMu::Pitch('F', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(0)->second == ReMu::Pitch('G', ReMu::None), true);
			}
		}
	};
}