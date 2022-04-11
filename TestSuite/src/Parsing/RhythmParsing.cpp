#include "CppUnitTest.h"

#include "../Helper.h"
#include "API.h"

#include "Musical Structures/Section.h"
#include "Musical Structures/Chord/Chord.h"

#include "Exceptions/ParseExceptions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Parsing {

	//Generated using https://www.omnicalculator.com/other/chord
	TEST_CLASS(RhythmParsing)
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
			program << "\"test\" = 1 - 20;\n\n\"test\":";
		}

		TEST_METHOD(MatchingRhythmNotes)
		{
			program << "C[1] -> A[1],";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				auto inital = std::get<0>(transition).getStuctsToMapping();
				auto result = std::get<1>(transition).getStuctsToMapping();

				Assert::AreEqual(((ReMu::Pitch*)inital->at(0).first)->getDuration() == 1, true);

				Assert::AreEqual(((ReMu::Pitch*)result->at(0).first)->getDuration() == 1, true);
			}
		}

		TEST_METHOD(MatchingRhythmChords)
		{
			program << "C maj[1] -> A min[1],";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				auto inital = std::get<0>(transition).getStuctsToMapping();
				auto result = std::get<1>(transition).getStuctsToMapping();

				Assert::AreEqual(((ReMu::Chord*)inital->at(0).first)->getDuration() == 1, true);

				Assert::AreEqual(((ReMu::Chord*)result->at(0).first)->getDuration() == 1, true);
			}
		}

		TEST_METHOD(MatchingRhythmRest)
		{
			program << "[1] -> [1],";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				auto inital = std::get<0>(transition).getStuctsToMapping();
				auto result = std::get<1>(transition).getStuctsToMapping();

				Assert::AreEqual(((ReMu::Pitch*)inital->at(0).first)->getDuration() == 1, true);

				Assert::AreEqual(((ReMu::Pitch*)result->at(0).first)->getDuration() == 1, true);
			}
		}

		TEST_METHOD(MatchingRhythmMix)
		{
			program << "A[1] -> B maj[1],";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				auto inital = std::get<0>(transition).getStuctsToMapping();
				auto result = std::get<1>(transition).getStuctsToMapping();

				Assert::AreEqual(((ReMu::Pitch*)inital->at(0).first)->getDuration() == 1, true);

				Assert::AreEqual(((ReMu::Chord*)result->at(0).first)->getDuration() == 1, true);
			}
		}

		TEST_METHOD(EqualRhythmNotes)
		{
			program << "A[2] A[4] -> B[4] A[2],";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				auto inital = std::get<0>(transition).getStuctsToMapping();
				auto result = std::get<1>(transition).getStuctsToMapping();

				Assert::AreEqual(((ReMu::Pitch*)inital->at(0).first)->getDuration() == 2, true);
				Assert::AreEqual(((ReMu::Pitch*)inital->at(1).first)->getDuration() == 4, true);

				Assert::AreEqual(((ReMu::Pitch*)result->at(0).first)->getDuration() == 4, true);
				Assert::AreEqual(((ReMu::Pitch*)result->at(1).first)->getDuration() == 2, true);
			}
		}

		TEST_METHOD(EqualRhythmChords)
		{
			program << "A maj[2] A min[4] -> B maj[4] A min[2],";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				auto inital = std::get<0>(transition).getStuctsToMapping();
				auto result = std::get<1>(transition).getStuctsToMapping();

				Assert::AreEqual(((ReMu::Chord*)inital->at(0).first)->getDuration() == 2, true);
				Assert::AreEqual(((ReMu::Chord*)inital->at(1).first)->getDuration() == 4, true);

				Assert::AreEqual(((ReMu::Chord*)result->at(0).first)->getDuration() == 4, true);
				Assert::AreEqual(((ReMu::Chord*)result->at(1).first)->getDuration() == 2, true);
			}
		}

		TEST_METHOD(EqualRhythmMix)
		{
			program << "A maj[2] A[4] -> B[4] A min[2],";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				auto inital = std::get<0>(transition).getStuctsToMapping();
				auto result = std::get<1>(transition).getStuctsToMapping();

				Assert::AreEqual(((ReMu::Chord*)inital->at(0).first)->getDuration() == 2, true);
				Assert::AreEqual(((ReMu::Pitch*)inital->at(1).first)->getDuration() == 4, true);

				Assert::AreEqual(((ReMu::Pitch*)result->at(0).first)->getDuration() == 4, true);
				Assert::AreEqual(((ReMu::Chord*)result->at(1).first)->getDuration() == 2, true);
			}
		}

		TEST_METHOD(RestRhythmNotes)
		{
			program << "A[2] [4] -> [4] A[2],";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				auto inital = std::get<0>(transition).getStuctsToMapping();
				auto result = std::get<1>(transition).getStuctsToMapping();

				Assert::AreEqual(((ReMu::Pitch*)inital->at(0).first)->getDuration() == 2, true);
				Assert::AreEqual(((ReMu::Pitch*)inital->at(1).first)->getDuration() == 4, true);

				Assert::AreEqual(((ReMu::Pitch*)result->at(0).first)->getDuration() == 4, true);
				Assert::AreEqual(((ReMu::Pitch*)result->at(1).first)->getDuration() == 2, true);
			}
		}

		TEST_METHOD(RestRhythmChords)
		{
			program << "A maj[2] [4] -> B maj[4] [2],";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				auto inital = std::get<0>(transition).getStuctsToMapping();
				auto result = std::get<1>(transition).getStuctsToMapping();

				Assert::AreEqual(((ReMu::Chord*)inital->at(0).first)->getDuration() == 2, true);
				Assert::AreEqual(((ReMu::Pitch*)inital->at(1).first)->getDuration() == 4, true);

				Assert::AreEqual(((ReMu::Chord*)result->at(0).first)->getDuration() == 4, true);
				Assert::AreEqual(((ReMu::Pitch*)result->at(1).first)->getDuration() == 2, true);
			}
		}

		TEST_METHOD(RestRhythmMix)
		{
			program << "[2] A[4] -> [4] A min[2],";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				auto inital = std::get<0>(transition).getStuctsToMapping();
				auto result = std::get<1>(transition).getStuctsToMapping();

				Assert::AreEqual(((ReMu::Pitch*)inital->at(0).first)->getDuration() == 2, true);
				Assert::AreEqual(((ReMu::Pitch*)inital->at(1).first)->getDuration() == 4, true);

				Assert::AreEqual(((ReMu::Pitch*)result->at(0).first)->getDuration() == 4, true);
				Assert::AreEqual(((ReMu::Chord*)result->at(1).first)->getDuration() == 2, true);
			}
		}

		TEST_METHOD(AdditionalRhythmNotes)
		{
			program << "A[1] -> A[2] A[2],";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				auto inital = std::get<0>(transition).getStuctsToMapping();
				auto result = std::get<1>(transition).getStuctsToMapping();

				Assert::AreEqual(((ReMu::Pitch*)inital->at(0).first)->getDuration() == 1, true);

				Assert::AreEqual(((ReMu::Pitch*)result->at(0).first)->getDuration() == 2, true);
				Assert::AreEqual(((ReMu::Pitch*)result->at(1).first)->getDuration() == 2, true);
			}
		}

		TEST_METHOD(AdditionalRhythmChords)
		{
			program << "A maj[1] -> A min[2] A min[2],";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				auto inital = std::get<0>(transition).getStuctsToMapping();
				auto result = std::get<1>(transition).getStuctsToMapping();

				Assert::AreEqual(((ReMu::Chord*)inital->at(0).first)->getDuration() == 1, true);

				Assert::AreEqual(((ReMu::Chord*)result->at(0).first)->getDuration() == 2, true);
				Assert::AreEqual(((ReMu::Chord*)result->at(1).first)->getDuration() == 2, true);
			}
		}

		TEST_METHOD(AdditionalRhythmMix)
		{
			program << "A[1] -> A maj[2] A[2],";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				auto inital = std::get<0>(transition).getStuctsToMapping();
				auto result = std::get<1>(transition).getStuctsToMapping();

				Assert::AreEqual(((ReMu::Pitch*)inital->at(0).first)->getDuration() == 1, true);

				Assert::AreEqual(((ReMu::Chord*)result->at(0).first)->getDuration() == 2, true);
				Assert::AreEqual(((ReMu::Pitch*)result->at(1).first)->getDuration() == 2, true);
			}
		}

		TEST_METHOD(SubtractionRhythmNotes)
		{
			program << "A[2] A[4] A[4] -> A[1],";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				auto inital = std::get<0>(transition).getStuctsToMapping();
				auto result = std::get<1>(transition).getStuctsToMapping();

				Assert::AreEqual(((ReMu::Pitch*)inital->at(0).first)->getDuration() == 2, true);
				Assert::AreEqual(((ReMu::Pitch*)inital->at(1).first)->getDuration() == 4, true);
				Assert::AreEqual(((ReMu::Pitch*)inital->at(2).first)->getDuration() == 4, true);

				Assert::AreEqual(((ReMu::Pitch*)result->at(0).first)->getDuration() == 1, true);
			}
		}

		TEST_METHOD(SubtractionRhythmChords)
		{
			program << "A maj[2] A min[4] A maj[4] -> A min[1],";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				auto inital = std::get<0>(transition).getStuctsToMapping();
				auto result = std::get<1>(transition).getStuctsToMapping();

				Assert::AreEqual(((ReMu::Chord*)inital->at(0).first)->getDuration() == 2, true);
				Assert::AreEqual(((ReMu::Chord*)inital->at(1).first)->getDuration() == 4, true);
				Assert::AreEqual(((ReMu::Chord*)inital->at(2).first)->getDuration() == 4, true);

				Assert::AreEqual(((ReMu::Chord*)result->at(0).first)->getDuration() == 1, true);
			}
		}

		TEST_METHOD(SubtractionRhythmMix)
		{
			program << "A[2] A maj[4] A[4] -> A min[1],";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				auto inital = std::get<0>(transition).getStuctsToMapping();
				auto result = std::get<1>(transition).getStuctsToMapping();

				Assert::AreEqual(((ReMu::Pitch*)inital->at(0).first)->getDuration() == 2, true);
				Assert::AreEqual(((ReMu::Chord*)inital->at(1).first)->getDuration() == 4, true);
				Assert::AreEqual(((ReMu::Pitch*)inital->at(2).first)->getDuration() == 4, true);

				Assert::AreEqual(((ReMu::Chord*)result->at(0).first)->getDuration() == 1, true);
			}
		}
	};
}