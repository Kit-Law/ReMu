#include "CppUnitTest.h"

#include "../Helper.h"
#include "API.h"

#include "Musical Structures/Section.h"
#include "Musical Structures/Chord/Chord.h"

#include "Exceptions/ParseExceptions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Evaluation {

	TEST_CLASS(WildcardEvaluation)
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

		TEST_METHOD(WildcardToNote)
		{
			program << "_ -> A,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('A', ReMu::Accidental::None));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}

		TEST_METHOD(WildcardToChord)
		{
			program << "_ -> C maj,";

			ReMu::API::eval(ReMu::API::parse(program), "../TestSuite/Files/MusicXML/Input/A.musicxml", "../TestSuite/Files/MusicXML/buffer.musicxml");

			std::vector<ReMu::Pitch> resultNotes;
			resultNotes.push_back(ReMu::Pitch('C', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('E', ReMu::Accidental::None));
			resultNotes.push_back(ReMu::Pitch('G', ReMu::Accidental::None));

			Assert::AreEqual(verifyXmlFile("../TestSuite/Files/MusicXML/buffer.musicxml", resultNotes), true);
		}
	};
}