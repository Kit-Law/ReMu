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
	TEST_CLASS(DimChordEvaluation)
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

		TEST_METHOD(CDim)
		{
			program << "A -> C dim,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('E', ReMu::Accidental::Flat));
			resultNotes.push_back(ReMu::Pitch('G', ReMu::Accidental::Flat));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(CSharpDim)
		{
			program << "A -> C# dim,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('E', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('G', ReMu::Accidental::None));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}


		TEST_METHOD(DDim)
		{
			program << "A -> D dim,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('D', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('F', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('A', ReMu::Accidental::Flat));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(DSharpDim)
		{
			program << "A -> D# dim,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('D', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('F', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('A', ReMu::Accidental::None));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(EDim)
		{
			program << "A -> E dim,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('E', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('G', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('B', ReMu::Accidental::Flat));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(FDim)
		{
			program << "A -> F dim,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('F', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('A', ReMu::Accidental::Flat));
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::Flat));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(FSharpDim)
		{
			program << "A -> F# dim,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('F', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('A', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::None));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(GDim)
		{
			program << "A -> G dim,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('G', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('B', ReMu::Accidental::Flat));
			resultNotes.push_back(ReMu::Pitch('D', ReMu::Accidental::Flat));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(GSharpDim)
		{
			program << "A -> G# dim,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('G', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('B', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('D', ReMu::Accidental::None));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(ADim)
		{
			program << "A -> A dim,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('A', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('E', ReMu::Accidental::Flat));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(ASharpDim)
		{
			program << "A -> A# dim,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('A', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::Sharp));
			resultNotes.push_back(ReMu::Pitch('E', ReMu::Accidental::None));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(BDim)
		{
			program << "A -> B dim,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('B', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('D', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('F', ReMu::Accidental::None));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}
	};
}