#include "CppUnitTest.h"

#include "../Helper.h"
#include "API.h"

#include "Musical Structures/Section.h"
#include "Musical Structures/Chord/Chord.h"

#include "Exceptions/ParseExceptions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Parsing
{
	//Generated using https://www.omnicalculator.com/other/chord
	TEST_CLASS(Minor6ChordParsing)
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

		TEST_METHOD(CMinor6)
		{
			program << "C min6 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Note('C', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Note('E', ReMu::Accidental::Flat), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Note('G', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Note('B', ReMu::Accidental::DoubleFlat), true);
			}
		}

		TEST_METHOD(CSharpMinor6)
		{
			program << "C# min6 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Note('C', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Note('E', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Note('G', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Note('B', ReMu::Accidental::Flat), true);
			}
		}


		TEST_METHOD(DMinor6)
		{
			program << "D min6 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Note('D', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Note('F', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Note('A', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Note('C', ReMu::Accidental::Flat), true);
			}
		}

		TEST_METHOD(DSharpMinor6)
		{
			program << "D# min6 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Note('D', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Note('F', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Note('A', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Note('C', ReMu::Accidental::None), true);
			}
		}

		TEST_METHOD(EMinor6)
		{
			program << "E min6 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Note('E', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Note('G', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Note('B', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Note('D', ReMu::Accidental::Flat), true);
			}
		}

		TEST_METHOD(FMinor6)
		{
			program << "F min6 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Note('F', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Note('A', ReMu::Accidental::Flat), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Note('C', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Note('D', ReMu::Accidental::None), true);
			}
		}

		TEST_METHOD(FSharpMinor6)
		{
			program << "F# min6 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Note('F', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Note('A', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Note('C', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Note('E', ReMu::Accidental::Flat), true);
			}
		}

		TEST_METHOD(GMinor6)
		{
			program << "G min6 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Note('G', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Note('B', ReMu::Accidental::Flat), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Note('D', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Note('F', ReMu::Accidental::Flat), true);
			}
		}

		TEST_METHOD(GSharpMinor6)
		{
			program << "G# min6 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Note('G', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Note('B', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Note('D', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Note('F', ReMu::Accidental::None), true);
			}
		}

		TEST_METHOD(AMinor6)
		{
			program << "A min6 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Note('A', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Note('C', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Note('E', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Note('G', ReMu::Accidental::Flat), true);
			}
		}

		TEST_METHOD(ASharpMinor6)
		{
			program << "A# min6 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Note('A', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Note('C', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Note('E', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Note('G', ReMu::Accidental::None), true);
			}
		}

		TEST_METHOD(BMinor6)
		{
			program << "B min6 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Note('B', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Note('D', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Note('F', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Note('A', ReMu::Accidental::Flat), true);
			}
		}
	};
}