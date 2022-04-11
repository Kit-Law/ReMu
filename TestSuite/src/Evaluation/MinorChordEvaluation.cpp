#include "CppUnitTest.h"

#include "../Helper.h"
#include "API.h"

#include "Musical Structures/Section.h"
#include "Musical Structures/Chord/Chord.h"

#include "Exceptions/ParseExceptions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Evaluation { namespace Chords {

	//Generated using https://www.omnicalculator.com/other/chord
	TEST_CLASS(MinorChordEvaluation)
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

		TEST_METHOD(CMinor)
		{
			program << "A -> C min,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('E', ReMu::Accidental::Flat));
			resultNotes.push_back(ReMu::Pitch('G', ReMu::Accidental::None));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(CSharpMinor)
		{
			program << "A -> C# min,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('E', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('G', ReMu::Accidental::Sharp));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}


		TEST_METHOD(DMinor)
		{
			program << "A -> D min,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('D', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('F', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('A', ReMu::Accidental::None));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(DSharpMinor)
		{
			program << "A -> D# min,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('D', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('F', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('A', ReMu::Accidental::Sharp));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(EMinor)
		{
			program << "A -> E min,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('E', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('G', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('B', ReMu::Accidental::None));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(FMinor)
		{
			program << "A -> F min,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('F', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('A', ReMu::Accidental::Flat));
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::None));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(FSharpMinor)
		{
			program << "A -> F# min,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('F', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('A', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::Sharp));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(GMinor)
		{
			program << "A -> G min,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('G', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('B', ReMu::Accidental::Flat));
			resultNotes.push_back(ReMu::Pitch('D', ReMu::Accidental::None));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(GSharpMinor)
		{
			program << "A -> G# min,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('G', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('B', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('D', ReMu::Accidental::Sharp));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(AMinor)
		{
			program << "A -> A min,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('A', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('E', ReMu::Accidental::None));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(ASharpMinor)
		{
			program << "A -> A# min,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('A', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('E', ReMu::Accidental::Sharp));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(BMinor)
		{
			program << "A -> B min,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('B', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('D', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('F', ReMu::Accidental::Sharp));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}
	};
} }