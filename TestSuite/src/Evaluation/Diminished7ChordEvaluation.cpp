#include "CppUnitTest.h"

#include "../Helper.h"
#include "API.h"

#include "Musical Structures/Section.h"
#include "Musical Structures/Chord/Chord.h"

#include "Exceptions/ParseExceptions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Evaluation { namespace Chords {

	//Generated using https://www.omnicalculator.com/other/chord
	TEST_CLASS(Dim7ChordEvaluation)
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
			program << "A -> C dim7,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('E', ReMu::Accidental::Flat));
			resultNotes.push_back(ReMu::Pitch('G', ReMu::Accidental::Flat));
			resultNotes.push_back(ReMu::Pitch('B', ReMu::Accidental::DoubleFlat));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(CSharpDim7)
		{
			program << "A -> C# dim7,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('E', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('G', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('B', ReMu::Accidental::Flat));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}


		TEST_METHOD(DDim7)
		{
			program << "A -> D dim7,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('D', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('F', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('A', ReMu::Accidental::Flat));
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::Flat));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(DSharpDim7)
		{
			program << "A -> D# dim7,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('D', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('F', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('A', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::None));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(EDim7)
		{
			program << "A -> E dim7,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('E', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('G', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('B', ReMu::Accidental::Flat));
			resultNotes.push_back(ReMu::Pitch('D', ReMu::Accidental::Flat));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(FDim7)
		{
			program << "A -> F dim7,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('F', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('A', ReMu::Accidental::Flat));
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::Flat));
			resultNotes.push_back(ReMu::Pitch('D', ReMu::Accidental::None));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(FSharpDim7)
		{
			program << "A -> F# dim7,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('F', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('A', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('E', ReMu::Accidental::Flat));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(GDim7)
		{
			program << "A -> G dim7,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('G', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('B', ReMu::Accidental::Flat));
			resultNotes.push_back(ReMu::Pitch('D', ReMu::Accidental::Flat));
			resultNotes.push_back(ReMu::Pitch('F', ReMu::Accidental::Flat));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(GSharpDim7)
		{
			program << "A -> G# dim7,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('G', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('B', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('D', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('F', ReMu::Accidental::None));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(ADim7)
		{
			program << "A -> A dim7,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('A', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('E', ReMu::Accidental::Flat));
			resultNotes.push_back(ReMu::Pitch('G', ReMu::Accidental::Flat));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(ASharpDim7)
		{
			program << "A -> A# dim7,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('A', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('E', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('G', ReMu::Accidental::None));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(BDim7)
		{
			program << "A -> B dim7,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('B', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('D', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('F', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('A', ReMu::Accidental::Flat));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}
	};
} }