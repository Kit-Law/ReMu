#include "CppUnitTest.h"

#include "../Helper.h"

#include "Musical Structures/Section.h"
#include "Musical Structures/Chord/Chord.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Parsing { namespace Scales {

	TEST_CLASS(RelativeKeys)
	{
	public:
		TEST_CLASS_INITIALIZE(Initalize)
		{
			ReMu::ScaleDatabase::initalize();
		}

		TEST_METHOD(RelativeKeyOneStep)
		{
			std::map<std::string, ReMu::Section*> sections = parseProgram("../TestSuite/Files/Programs/relativeKeyOneStep.txt");

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getSequenceTransitions()->size(), (size_t)0);

				std::vector<std::pair<ReMu::Pitch, ReMu::Pitch>*>* transition = section.second->getTransitionTable()->getNoteTransitions();

				for (int i = 0; i < 7; i++)
					Assert::AreEqual(transition->at(i)->second == transition->at(((i < 6) ? (i + 1) : (i - 6)))->first, true);
			}
		}

		TEST_METHOD(RelativeKeyTwoSteps)
		{
			std::map<std::string, ReMu::Section*> sections = parseProgram("../TestSuite/Files/Programs/relativeKeyTwoSteps.txt");

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getSequenceTransitions()->size(), (size_t)0);

				std::vector<std::pair<ReMu::Pitch, ReMu::Pitch>*>* transition = section.second->getTransitionTable()->getNoteTransitions();

				for (int i = 0; i < 7; i++)
					Assert::AreEqual(transition->at(i)->second == transition->at(((i < 5) ? (i + 2) : (i - 5)))->first, true);
			}
		}

		TEST_METHOD(RelativeKeyThreeSteps)
		{
			std::map<std::string, ReMu::Section*> sections = parseProgram("../TestSuite/Files/Programs/relativeKeyThreeSteps.txt");

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getSequenceTransitions()->size(), (size_t)0);

				std::vector<std::pair<ReMu::Pitch, ReMu::Pitch>*>* transition = section.second->getTransitionTable()->getNoteTransitions();

				for (int i = 0; i < 7; i++)
					Assert::AreEqual(transition->at(i)->second == transition->at(((i < 4) ? (i + 3) : (i - 4)))->first, true);
			}
		}

		TEST_METHOD(RelativeKeyFourSteps)
		{
			std::map<std::string, ReMu::Section*> sections = parseProgram("../TestSuite/Files/Programs/relativeKeyFourSteps.txt");

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getSequenceTransitions()->size(), (size_t)0);

				std::vector<std::pair<ReMu::Pitch, ReMu::Pitch>*>* transition = section.second->getTransitionTable()->getNoteTransitions();

				for (int i = 0; i < 7; i++)
					Assert::AreEqual(transition->at(i)->second == transition->at(((i < 3) ? (i + 4) : (i - 3)))->first, true);
			}
		}

		TEST_METHOD(RelativeKeyFiveSteps)
		{
			std::map<std::string, ReMu::Section*> sections = parseProgram("../TestSuite/Files/Programs/relativeKeyFiveSteps.txt");

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getSequenceTransitions()->size(), (size_t)0);

				std::vector<std::pair<ReMu::Pitch, ReMu::Pitch>*>* transition = section.second->getTransitionTable()->getNoteTransitions();

				for (int i = 0; i < 7; i++)
					Assert::AreEqual(transition->at(i)->second == transition->at(((i < 2) ? (i + 5) : (i - 2)))->first, true);
			}
		}

		TEST_METHOD(RelativeKeySixSteps)
		{
			std::map<std::string, ReMu::Section*> sections = parseProgram("../TestSuite/Files/Programs/relativeKeySixSteps.txt");

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getSequenceTransitions()->size(), (size_t)0);

				std::vector<std::pair<ReMu::Pitch, ReMu::Pitch>*>* transition = section.second->getTransitionTable()->getNoteTransitions();

				for (int i = 0; i < 7; i++)
					Assert::AreEqual(transition->at(i)->second == transition->at(((i < 1) ? (i + 6) : (i - 1)))->first, true);
			}
		}
	};
} }