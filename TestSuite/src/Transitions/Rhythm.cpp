#include "CppUnitTest.h"

#include "../Helper.h"
#include "API.h"

#include "Musical Structures/Section.h"
#include "Musical Structures/Chord/Chord.h"

#include "Exceptions/ParseExceptions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Parsing { namespace Rhythm {

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

		TEST_METHOD(ClonedRhythmNotes)
		{
			program << "A[1] -> C[1],";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				std::vector<std::pair<void*, ReMu::structType>>* inital = std::get<0>(transition).getStuctsToMapping();
				std::vector<std::pair<void*, ReMu::structType>>* result = std::get<1>(transition).getStuctsToMapping();

				Assert::AreEqual(*((ReMu::Pitch*)inital->at(0).first) == ReMu::Pitch('A', ReMu::Accidental::None), true);
				Assert::AreEqual(((ReMu::Pitch*)inital->at(0).first)->getDuration() == 1, true);

				Assert::AreEqual(*((ReMu::Pitch*)result->at(0).first) == ReMu::Pitch('C', ReMu::Accidental::None), true);
				Assert::AreEqual(((ReMu::Pitch*)result->at(0).first)->getDuration() == 1, true);
			}
		}

		TEST_METHOD(EqualRhythmNotes)
		{
			program << "A[4] C[2] C[2] -> A[2] C[4] C[2],";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Pitch* note = (ReMu::Pitch*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(*note == ReMu::Pitch('C', ReMu::Accidental::Sharp), true);
			}
		}


		TEST_METHOD(AdditionalRhythmNotes)
		{
			program << "A[1] -> A[4] A[4] A[4] A[4],";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Pitch* note = (ReMu::Pitch*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(*note == ReMu::Pitch('D', ReMu::Accidental::None), true);
			}
		}

		TEST_METHOD(SubtractionRhythmNotes)
		{
			program << "A[4] C[2] C[2] -> A[1],";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Pitch* note = (ReMu::Pitch*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(*note == ReMu::Pitch('D', ReMu::Accidental::Sharp), true);
			}
		}
	};
} }