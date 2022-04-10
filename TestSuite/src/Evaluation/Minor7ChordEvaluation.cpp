#include "CppUnitTest.h"

#include "../Helper.h"
#include "API.h"

#include "Musical Structures/Section.h"
#include "Musical Structures/Chord/Chord.h"

#include "Exceptions/ParseExceptions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Evaluation
{
	//Generated using https://www.omnicalculator.com/other/chord
	TEST_CLASS(Minor7ChordEvaluation)
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

		TEST_METHOD(CMinor7)
		{
			program << "A -> C min7,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('E', ReMu::Accidental::Flat));
			resultNotes.push_back(ReMu::Pitch('G', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('B', ReMu::Accidental::Flat));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(CSharpMinor7)
		{
			program << "A -> C# min7,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('E', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('G', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('B', ReMu::Accidental::None));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}


		TEST_METHOD(DMinor7)
		{
			program << "A -> D min7,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('D', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('F', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('A', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::None));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(DSharpMinor7)
		{
			program << "A -> D# min7,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('D', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('F', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('A', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::Sharp));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(EMinor7)
		{
			program << "A -> E min7,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('E', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('G', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('B', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('D', ReMu::Accidental::None));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(FMinor7)
		{
			program << "A -> F min7,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('F', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('A', ReMu::Accidental::Flat));
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('D', ReMu::Accidental::Sharp));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(FSharpMinor7)
		{
			program << "A -> F# min7,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('F', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('A', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('E', ReMu::Accidental::None));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(GMinor7)
		{
			program << "A -> G min7,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('G', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('B', ReMu::Accidental::Flat));
			resultNotes.push_back(ReMu::Pitch('D', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('F', ReMu::Accidental::None));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(GSharpMinor7)
		{
			program << "A -> G# min7,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('G', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('B', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('D', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('F', ReMu::Accidental::Sharp));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(AMinor7)
		{
			program << "A -> A min7,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('A', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('E', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('G', ReMu::Accidental::None));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(ASharpMinor7)
		{
			program << "A -> A# min7,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('A', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('E', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('G', ReMu::Accidental::Sharp));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(BMinor7)
		{
			program << "A -> B min7,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('B', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('D', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('F', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('A', ReMu::Accidental::None));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}
	};
}