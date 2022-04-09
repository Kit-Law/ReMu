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
	TEST_CLASS(Major6ChordParsing)
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

		TEST_METHOD(CMajor6)
		{
			program << "C maj6 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Note('C', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Note('E', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Note('G', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Note('A', ReMu::Accidental::None), true);
			}
		}

		TEST_METHOD(CSharpMajor6)
		{
			program << "C# maj6 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Note('C', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Note('F', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Note('G', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Note('A', ReMu::Accidental::Sharp), true);
			}
		}


		TEST_METHOD(DMajor6)
		{
			program << "D maj6 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Note('D', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Note('F', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Note('A', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Note('B', ReMu::Accidental::None), true);
			}
		}

		TEST_METHOD(DSharpMajor6)
		{
			program << "D# maj6 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Note('D', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Note('F', ReMu::Accidental::DoubleSharp), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Note('A', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Note('C', ReMu::Accidental::None), true);
			}
		}

		TEST_METHOD(EMajor6)
		{
			program << "E maj6 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Note('E', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Note('G', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Note('B', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Note('C', ReMu::Accidental::Sharp), true);
			}
		}

		TEST_METHOD(FMajor6)
		{
			program << "F maj6 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Note('F', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Note('A', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Note('C', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Note('D', ReMu::Accidental::None), true);
			}
		}

		TEST_METHOD(FSharpMajor6)
		{
			program << "F# maj6 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Note('F', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Note('A', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Note('C', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Note('D', ReMu::Accidental::Sharp), true);
			}
		}

		TEST_METHOD(GMajor6)
		{
			program << "G maj6 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Note('G', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Note('B', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Note('D', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Note('E', ReMu::Accidental::Sharp), true);
			}
		}

		TEST_METHOD(GSharpMajor6)
		{
			program << "G# maj6 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Note('G', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Note('B', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Note('D', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Note('F', ReMu::Accidental::None), true);
			}
		}

		TEST_METHOD(AMajor6)
		{
			program << "A maj6 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Note('A', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Note('C', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Note('E', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Note('F', ReMu::Accidental::Sharp), true);
			}
		}

		TEST_METHOD(ASharpMajor6)
		{
			program << "A# maj6 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Note('A', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Note('C', ReMu::Accidental::DoubleSharp), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Note('E', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Note('G', ReMu::Accidental::None), true);
			}
		}

		TEST_METHOD(BMajor6)
		{
			program << "B maj6 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Note('B', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Note('D', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Note('F', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Note('G', ReMu::Accidental::Sharp), true);
			}
		}
	};
}