#include "CppUnitTest.h"

#include "../Helper.h"
#include "API.h"

#include "Musical Structures/Section.h"
#include "Musical Structures/Chord/Chord.h"

#include "Exceptions/ParseExceptions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Parsing { namespace Chords {

	//Generated using https://www.omnicalculator.com/other/chord
	TEST_CLASS(SusChordParsing)
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

		TEST_METHOD(CSus4)
		{
			program << "C sus4 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('C', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('F', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('G', ReMu::Accidental::None), true);
			}
		}

		TEST_METHOD(CSharpSus4)
		{
			program << "C# sus4 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('C', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('F', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('G', ReMu::Accidental::Sharp), true);
			}
		}


		TEST_METHOD(DSus4)
		{
			program << "D sus4 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('D', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('G', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('A', ReMu::Accidental::None), true);
			}
		}

		TEST_METHOD(DSharpSus4)
		{
			program << "D# sus4 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('D', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('G', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('A', ReMu::Accidental::Sharp), true);
			}
		}

		TEST_METHOD(ESus4)
		{
			program << "E sus4 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('E', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('A', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('B', ReMu::Accidental::None), true);
			}
		}

		TEST_METHOD(FSus4)
		{
			program << "F sus4 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('F', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('B', ReMu::Accidental::Flat), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('C', ReMu::Accidental::None), true);
			}
		}

		TEST_METHOD(FSharpSus4)
		{
			program << "F# sus4 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('F', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('B', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('C', ReMu::Accidental::Sharp), true);
			}
		}

		TEST_METHOD(GSus4)
		{
			program << "G sus4 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('G', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('C', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('D', ReMu::Accidental::None), true);
			}
		}

		TEST_METHOD(GSharpSus4)
		{
			program << "G# sus4 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('G', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('C', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('D', ReMu::Accidental::Sharp), true);
			}
		}

		TEST_METHOD(ASus4)
		{
			program << "A sus4 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('A', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('D', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('E', ReMu::Accidental::None), true);
			}
		}

		TEST_METHOD(ASharpSus4)
		{
			program << "A# sus4 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('A', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('D', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('E', ReMu::Accidental::Sharp), true);
			}
		}

		TEST_METHOD(BSus4)
		{
			program << "B sus4 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('B', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('E', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('F', ReMu::Accidental::Sharp), true);
			}
		}

		TEST_METHOD(CSus2)
		{
			program << "C sus2 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('C', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('D', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('G', ReMu::Accidental::None), true);
			}
		}

		TEST_METHOD(CSharpSus2)
		{
			program << "C# sus2 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('C', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('D', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('G', ReMu::Accidental::Sharp), true);
			}
		}


		TEST_METHOD(DSus2)
		{
			program << "D sus2 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('D', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('E', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('A', ReMu::Accidental::None), true);
			}
		}

		TEST_METHOD(DSharpSus2)
		{
			program << "D# sus2 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('D', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('E', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('A', ReMu::Accidental::Sharp), true);
			}
		}

		TEST_METHOD(ESus2)
		{
			program << "E sus2 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('E', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('F', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('B', ReMu::Accidental::None), true);
			}
		}

		TEST_METHOD(FSus2)
		{
			program << "F sus2 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('F', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('G', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('C', ReMu::Accidental::None), true);
			}
		}

		TEST_METHOD(FSharpSus2)
		{
			program << "F# sus2 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('F', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('G', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('C', ReMu::Accidental::Sharp), true);
			}
		}

		TEST_METHOD(GSus2)
		{
			program << "G sus2 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('G', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('A', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('D', ReMu::Accidental::None), true);
			}
		}

		TEST_METHOD(GSharpSus2)
		{
			program << "G# sus2 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('G', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('A', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('D', ReMu::Accidental::Sharp), true);
			}
		}

		TEST_METHOD(ASus2)
		{
			program << "A sus2 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('A', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('B', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('E', ReMu::Accidental::None), true);
			}
		}

		TEST_METHOD(ASharpSus2)
		{
			program << "A# sus2 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('A', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('B', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('E', ReMu::Accidental::Sharp), true);
			}
		}

		TEST_METHOD(BSus2)
		{
			program << "B sus2 -> A,";
			std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(program)->getSections();

			for (auto const& section : sections)
			{
				Assert::AreEqual(section.second->getTransitionTable()->getNoteTransitions()->size(), (size_t)0);

				auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
				ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

				Assert::AreEqual(chord->getComponents()->size() == 3, true);
				Assert::AreEqual(chord->getComponents()->at(0) == ReMu::Pitch('B', ReMu::Accidental::None), true);
				Assert::AreEqual(chord->getComponents()->at(1) == ReMu::Pitch('C', ReMu::Accidental::Sharp), true);
				Assert::AreEqual(chord->getComponents()->at(2) == ReMu::Pitch('F', ReMu::Accidental::Sharp), true);
			}
		}
	};
} }