#include "CppUnitTest.h"

#include "../Helper.h"
#include "API.h"

#include "Musical Structures/Section.h"
#include "Musical Structures/Chord/Chord.h"

#include "Exceptions/ParseExceptions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Parsing { namespace Chords {

	//Generated using https://www.omnicalculator.com/other/chord
	TEST_CLASS(Dim7ChordParsing)
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

		TEST_METHOD(CDim7)
		{
			program << "C dim7 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 4, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('C', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('E', ReMu::Accidental::Flat), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('G', ReMu::Accidental::Flat), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Pitch('B', ReMu::Accidental::DoubleFlat), true);
			}
		}

		TEST_METHOD(CSharpDim7)
		{
			program << "C# dim7 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 4, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('C', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('E', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('G', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Pitch('B', ReMu::Accidental::Flat), true);
			}
		}


		TEST_METHOD(DDim7)
		{
			program << "D dim7 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 4, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('D', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('F', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('A', ReMu::Accidental::Flat), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Pitch('C', ReMu::Accidental::Flat), true);
			}
		}

		TEST_METHOD(DSharpDim7)
		{
			program << "D# dim7 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 4, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('D', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('F', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('A', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Pitch('C', ReMu::Accidental::None), true);
			}
		}

		TEST_METHOD(EDim7)
		{
			program << "E dim7 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 4, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('E', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('G', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('B', ReMu::Accidental::Flat), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Pitch('D', ReMu::Accidental::Flat), true);
			}
		}

		TEST_METHOD(FDim7)
		{
			program << "F dim7 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 4, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('F', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('A', ReMu::Accidental::Flat), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('C', ReMu::Accidental::Flat), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Pitch('D', ReMu::Accidental::None), true);
			}
		}

		TEST_METHOD(FSharpDim7)
		{
			program << "F# dim7 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 4, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('F', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('A', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('C', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Pitch('E', ReMu::Accidental::Flat), true);
			}
		}

		TEST_METHOD(GDim7)
		{
			program << "G dim7 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 4, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('G', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('B', ReMu::Accidental::Flat), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('D', ReMu::Accidental::Flat), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Pitch('F', ReMu::Accidental::Flat), true);
			}
		}

		TEST_METHOD(GSharpDim7)
		{
			program << "G# dim7 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 4, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('G', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('B', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('D', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Pitch('F', ReMu::Accidental::None), true);
			}
		}

		TEST_METHOD(ADim7)
		{
			program << "A dim7 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 4, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('A', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('C', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('E', ReMu::Accidental::Flat), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Pitch('G', ReMu::Accidental::Flat), true);
			}
		}

		TEST_METHOD(ASharpDim7)
		{
			program << "A# dim7 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 4, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('A', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('C', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('E', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Pitch('G', ReMu::Accidental::None), true);
			}
		}

		TEST_METHOD(BDim7)
		{
			program << "B dim7 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 4, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('B', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('D', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('F', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(3) == ReMu::Pitch('A', ReMu::Accidental::Flat), true);
			}
		}
	};
} }