#include "CppUnitTest.h"

#include "../Helper.h"
#include "API.h"

#include "Musical Structures/Section.h"
#include "Musical Structures/Chord/Chord.h"

#include "Exceptions/ParseExceptions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Parsing { namespace Note {

	//Generated using https://www.omnicalculator.com/other/chord
	TEST_CLASS(NoteParsing)
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

		TEST_METHOD(CNote)
		{
			program << "C  -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Pitch* note = (ReMu::Pitch*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(*note == ReMu::Pitch('C', ReMu::Accidental::None), true);
			}
		}

		TEST_METHOD(CSharpNote)
		{
			program << "C#  -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Pitch* note = (ReMu::Pitch*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(*note == ReMu::Pitch('C', ReMu::Accidental::Sharp), true);
			}
		}


		TEST_METHOD(DNote)
		{
			program << "D  -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Pitch* note = (ReMu::Pitch*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(*note == ReMu::Pitch('D', ReMu::Accidental::None), true);
			}
		}

		TEST_METHOD(DSharpNote)
		{
			program << "D#  -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Pitch* note = (ReMu::Pitch*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(*note == ReMu::Pitch('D', ReMu::Accidental::Sharp), true);
			}
		}

		TEST_METHOD(ENote)
		{
			program << "E  -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Pitch* note = (ReMu::Pitch*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(*note == ReMu::Pitch('E', ReMu::Accidental::None), true);
			}
		}

		TEST_METHOD(FNote)
		{
			program << "F  -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Pitch* note = (ReMu::Pitch*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(*note == ReMu::Pitch('F', ReMu::Accidental::None), true);
			}
		}

		TEST_METHOD(FSharpNote)
		{
			program << "F#  -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Pitch* note = (ReMu::Pitch*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(*note == ReMu::Pitch('F', ReMu::Accidental::Sharp), true);
			}
		}

		TEST_METHOD(GNote)
		{
			program << "G  -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Pitch* note = (ReMu::Pitch*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(*note == ReMu::Pitch('G', ReMu::Accidental::None), true);
			}
		}

		TEST_METHOD(GSharpNote)
		{
			program << "G#  -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Pitch* note = (ReMu::Pitch*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(*note == ReMu::Pitch('G', ReMu::Accidental::Sharp), true);
			}
		}

		TEST_METHOD(ANote)
		{
			program << "A  -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Pitch* note = (ReMu::Pitch*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(*note == ReMu::Pitch('A', ReMu::Accidental::None), true);
			}
		}

		TEST_METHOD(ASharpNote)
		{
			program << "A#  -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Pitch* note = (ReMu::Pitch*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(*note == ReMu::Pitch('A', ReMu::Accidental::Sharp), true);
			}
		}

		TEST_METHOD(BNote)
		{
			program << "B  -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Pitch* note = (ReMu::Pitch*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(*note == ReMu::Pitch('B', ReMu::Accidental::None), true);
			}
		}
	};
} }