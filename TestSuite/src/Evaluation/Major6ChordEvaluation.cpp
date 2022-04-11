#include "CppUnitTest.h"

#include "../Helper.h"
#include "API.h"

#include "Musical Structures/Section.h"
#include "Musical Structures/Chord/Chord.h"

#include "Exceptions/ParseExceptions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Evaluation { namespace Chords {

	//Generated using https://www.omnicalculator.com/other/chord
	TEST_CLASS(Major6ChordEvaluation)
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
			program << "A -> C maj6,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('E', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('G', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('A', ReMu::Accidental::None));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(CSharpMajor6)
		{
			program << "A -> C# maj6,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('F', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('G', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('A', ReMu::Accidental::Sharp));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}


		TEST_METHOD(DMajor6)
		{
			program << "A -> D maj6,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('D', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('F', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('A', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('B', ReMu::Accidental::None));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(DSharpMajor6)
		{
			program << "A -> D# maj6,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('D', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('F', ReMu::Accidental::DoubleSharp));
			resultNotes.push_back(ReMu::Pitch('A', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::None));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(EMajor6)
		{
			program << "A -> E maj6,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('E', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('G', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('B', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::Sharp));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(FMajor6)
		{
			program << "A -> F maj6,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('F', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('A', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('D', ReMu::Accidental::None));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(FSharpMajor6)
		{
			program << "A -> F# maj6,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('F', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('A', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('D', ReMu::Accidental::Sharp));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(GMajor6)
		{
			program << "A -> G maj6,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('G', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('B', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('D', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('E', ReMu::Accidental::None));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(GSharpMajor6)
		{
			program << "A -> G# maj6,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('G', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('B', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('D', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('F', ReMu::Accidental::None));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(AMajor6)
		{
			program << "A -> A maj6,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('A', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('E', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('F', ReMu::Accidental::Sharp));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(ASharpMajor6)
		{
			program << "A -> A# maj6,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('A', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::DoubleSharp));
			resultNotes.push_back(ReMu::Pitch('E', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('G', ReMu::Accidental::None));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(BMajor6)
		{
			program << "A -> B maj6,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('B', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('D', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('F', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('G', ReMu::Accidental::Sharp));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}
	};
} }