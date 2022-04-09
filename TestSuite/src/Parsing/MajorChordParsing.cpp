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
	TEST_CLASS(MajorChordParsing)
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

		TEST_METHOD(CMajor)
		{
			program << "C maj -> A,";
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
			}
		}

		TEST_METHOD(CSharpMajor)
		{
			program << "C# maj -> A,";
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
			}
		}


		TEST_METHOD(DMajor)
		{
			program << "D maj -> A,";
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
			}
		}

		TEST_METHOD(DSharpMajor)
		{
			program << "D# maj -> A,";
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
			}
		}

		TEST_METHOD(EMajor)
		{
			program << "E maj -> A,";
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
			}
		}

		TEST_METHOD(FMajor)
		{
			program << "F maj -> A,";
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
			}
		}

		TEST_METHOD(FSharpMajor)
		{
			program << "F# maj -> A,";
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
			}
		}

		TEST_METHOD(GMajor)
		{
			program << "G maj -> A,";
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
			}
		}

		TEST_METHOD(GSharpMajor)
		{
			program << "G# maj -> A,";
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
			}
		}

		TEST_METHOD(AMajor)
		{
			program << "A maj -> A,";
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
			}
		}

		TEST_METHOD(ASharpMajor)
		{
			program << "A# maj -> A,";
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
			}
		}

		TEST_METHOD(BMajor)
		{
			program << "B maj -> A,";
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
			}
		}
	};
}