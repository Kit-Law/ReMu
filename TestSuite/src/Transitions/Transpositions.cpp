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

				std::vector<std::pair<ReMu::Pitch, ReMu::Pitch>>* transition = section.second->getTransitionTable()->getNoteTransitions();

				Assert::AreEqual(transition->at(0).first == ReMu::Note('A', ReMu::None), true);
				Assert::AreEqual(transition->at(1).first == ReMu::Note('B', ReMu::None), true);
				Assert::AreEqual(transition->at(2).first == ReMu::Note('C', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(3).first == ReMu::Note('D', ReMu::None), true);
				Assert::AreEqual(transition->at(4).first == ReMu::Note('E', ReMu::None), true);
				Assert::AreEqual(transition->at(5).first == ReMu::Note('F', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(6).first == ReMu::Note('G', ReMu::Sharp), true);

				Assert::AreEqual(transition->at(6).second == ReMu::Note('A', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(0).second == ReMu::Note('B', ReMu::None), true);
				Assert::AreEqual(transition->at(1).second == ReMu::Note('C', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(2).second == ReMu::Note('D', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(3).second == ReMu::Note('E', ReMu::None), true);
				Assert::AreEqual(transition->at(4).second == ReMu::Note('F', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(5).second == ReMu::Note('G', ReMu::Sharp), true);
			}
		}

		TEST_METHOD(TranspositionTwoSteps)
		{
			std::map<std::string, ReMu::Section*> sections = parseProgram("../TestSuite/Files/Programs/transpositionTwoSteps.txt");

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getSequenceTransitions()->size(), (size_t)0);

				std::vector<std::pair<ReMu::Pitch, ReMu::Pitch>>* transition = section.second->getTransitionTable()->getNoteTransitions();

				Assert::AreEqual(transition->at(0).first == ReMu::Note('A', ReMu::None), true);
				Assert::AreEqual(transition->at(1).first == ReMu::Note('B', ReMu::None), true);
				Assert::AreEqual(transition->at(2).first == ReMu::Note('C', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(3).first == ReMu::Note('D', ReMu::None), true);
				Assert::AreEqual(transition->at(4).first == ReMu::Note('E', ReMu::None), true);
				Assert::AreEqual(transition->at(5).first == ReMu::Note('F', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(6).first == ReMu::Note('G', ReMu::Sharp), true);

				Assert::AreEqual(transition->at(5).second == ReMu::Note('A', ReMu::None), true);
				Assert::AreEqual(transition->at(6).second == ReMu::Note('B', ReMu::None), true);
				Assert::AreEqual(transition->at(0).second == ReMu::Note('C', ReMu::None), true);
				Assert::AreEqual(transition->at(1).second == ReMu::Note('D', ReMu::None), true);
				Assert::AreEqual(transition->at(2).second == ReMu::Note('E', ReMu::None), true);
				Assert::AreEqual(transition->at(3).second == ReMu::Note('F', ReMu::None), true);
				Assert::AreEqual(transition->at(4).second == ReMu::Note('G', ReMu::None), true);
			}
		}

		TEST_METHOD(TranspositionThreeSteps)
		{
			std::map<std::string, ReMu::Section*> sections = parseProgram("../TestSuite/Files/Programs/transpositionThreeSteps.txt");

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getSequenceTransitions()->size(), (size_t)0);

				std::vector<std::pair<ReMu::Pitch, ReMu::Pitch>>* transition = section.second->getTransitionTable()->getNoteTransitions();

				Assert::AreEqual(transition->at(0).first == ReMu::Note('A', ReMu::None), true);
				Assert::AreEqual(transition->at(1).first == ReMu::Note('B', ReMu::None), true);
				Assert::AreEqual(transition->at(2).first == ReMu::Note('C', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(3).first == ReMu::Note('D', ReMu::None), true);
				Assert::AreEqual(transition->at(4).first == ReMu::Note('E', ReMu::None), true);
				Assert::AreEqual(transition->at(5).first == ReMu::Note('F', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(6).first == ReMu::Note('G', ReMu::Sharp), true);

				Assert::AreEqual(transition->at(4).second == ReMu::Note('A', ReMu::None), true);
				Assert::AreEqual(transition->at(5).second == ReMu::Note('B', ReMu::None), true);
				Assert::AreEqual(transition->at(6).second == ReMu::Note('C', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(0).second == ReMu::Note('D', ReMu::None), true);
				Assert::AreEqual(transition->at(1).second == ReMu::Note('E', ReMu::None), true);
				Assert::AreEqual(transition->at(2).second == ReMu::Note('F', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(3).second == ReMu::Note('G', ReMu::None), true);
			}
		}

		TEST_METHOD(TranspositionFourSteps)
		{
			std::map<std::string, ReMu::Section*> sections = parseProgram("../TestSuite/Files/Programs/transpositionFourSteps.txt");

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getSequenceTransitions()->size(), (size_t)0);

				std::vector<std::pair<ReMu::Pitch, ReMu::Pitch>>* transition = section.second->getTransitionTable()->getNoteTransitions();

				Assert::AreEqual(transition->at(0).first == ReMu::Note('A', ReMu::None), true);
				Assert::AreEqual(transition->at(1).first == ReMu::Note('B', ReMu::None), true);
				Assert::AreEqual(transition->at(2).first == ReMu::Note('C', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(3).first == ReMu::Note('D', ReMu::None), true);
				Assert::AreEqual(transition->at(4).first == ReMu::Note('E', ReMu::None), true);
				Assert::AreEqual(transition->at(5).first == ReMu::Note('F', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(6).first == ReMu::Note('G', ReMu::Sharp), true);

				Assert::AreEqual(transition->at(3).second == ReMu::Note('A', ReMu::None), true);
				Assert::AreEqual(transition->at(4).second == ReMu::Note('B', ReMu::None), true);
				Assert::AreEqual(transition->at(5).second == ReMu::Note('C', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(6).second == ReMu::Note('D', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(0).second == ReMu::Note('E', ReMu::None), true);
				Assert::AreEqual(transition->at(1).second == ReMu::Note('F', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(2).second == ReMu::Note('G', ReMu::Sharp), true);
			}
		}

		TEST_METHOD(TranspositionFiveSteps)
		{
			std::map<std::string, ReMu::Section*> sections = parseProgram("../TestSuite/Files/Programs/transpositionFiveSteps.txt");

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getSequenceTransitions()->size(), (size_t)0);

				std::vector<std::pair<ReMu::Pitch, ReMu::Pitch>>* transition = section.second->getTransitionTable()->getNoteTransitions();

				Assert::AreEqual(transition->at(0).first == ReMu::Note('A', ReMu::None), true);
				Assert::AreEqual(transition->at(1).first == ReMu::Note('B', ReMu::None), true);
				Assert::AreEqual(transition->at(2).first == ReMu::Note('C', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(3).first == ReMu::Note('D', ReMu::None), true);
				Assert::AreEqual(transition->at(4).first == ReMu::Note('E', ReMu::None), true);
				Assert::AreEqual(transition->at(5).first == ReMu::Note('F', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(6).first == ReMu::Note('G', ReMu::Sharp), true);

				Assert::AreEqual(transition->at(2).second == ReMu::Note('A', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(3).second == ReMu::Note('B', ReMu::None), true);
				Assert::AreEqual(transition->at(4).second == ReMu::Note('C', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(5).second == ReMu::Note('D', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(6).second == ReMu::Note('F', ReMu::None), true);
				Assert::AreEqual(transition->at(0).second == ReMu::Note('F', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(1).second == ReMu::Note('G', ReMu::Sharp), true);
			}
		}

		TEST_METHOD(TranspositionSixSteps)
		{
			std::map<std::string, ReMu::Section*> sections = parseProgram("../TestSuite/Files/Programs/transpositionSixSteps.txt");

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getSequenceTransitions()->size(), (size_t)0);

				std::vector<std::pair<ReMu::Pitch, ReMu::Pitch>>* transition = section.second->getTransitionTable()->getNoteTransitions();

				Assert::AreEqual(transition->at(0).first == ReMu::Note('A', ReMu::None), true);
				Assert::AreEqual(transition->at(1).first == ReMu::Note('B', ReMu::None), true);
				Assert::AreEqual(transition->at(2).first == ReMu::Note('C', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(3).first == ReMu::Note('D', ReMu::None), true);
				Assert::AreEqual(transition->at(4).first == ReMu::Note('E', ReMu::None), true);
				Assert::AreEqual(transition->at(5).first == ReMu::Note('F', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(6).first == ReMu::Note('G', ReMu::Sharp), true);

				Assert::AreEqual(transition->at(1).second == ReMu::Note('A', ReMu::None), true);
				Assert::AreEqual(transition->at(2).second == ReMu::Note('B', ReMu::None), true);
				Assert::AreEqual(transition->at(3).second == ReMu::Note('C', ReMu::None), true);
				Assert::AreEqual(transition->at(4).second == ReMu::Note('D', ReMu::None), true);
				Assert::AreEqual(transition->at(5).second == ReMu::Note('E', ReMu::None), true);
				Assert::AreEqual(transition->at(6).second == ReMu::Note('F', ReMu::Sharp), true);
				Assert::AreEqual(transition->at(0).second == ReMu::Note('G', ReMu::None), true);
			}
		}
	};
}