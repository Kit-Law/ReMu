#include "CppUnitTest.h"

#include "../Helper.h"

#include "Musical Structures/Section.h"
#include "Musical Structures/Chord/Chord.h"

#include "Exceptions/ParseExceptions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Parsing
{
	TEST_CLASS(ParsingTests)
	{
	public:
		TEST_CLASS_INITIALIZE(ParsingTestsInitalize)
		{
			ReMu::ScaleDatabase::initalize();
		}

		TEST_METHOD(emptyFile)
		{
			std::map<std::string, ReMu::Section*> sections = parseProgram("../TestSuite/Files/Programs/empty.txt");

			Assert::AreEqual(sections.size(), (size_t)0);
		}

		TEST_METHOD(sectionDefinitionOutOfBounds)
		{
			try
			{
				std::map<std::string, ReMu::Section*> sections = parseProgram("../TestSuite/Files/Programs/Errors/secDefOFB.txt");

				Assert::AreEqual(true, false);
			}
			catch (SectionDefOutOfBounds& e)
			{
				Assert::AreEqual(true, true);
			}
			catch (std::exception& e)
			{
				Assert::AreEqual(true, false);
			}
		}

		TEST_METHOD(undefinedSection)
		{
			try
			{
				std::map<std::string, ReMu::Section*> sections = parseProgram("../TestSuite/Files/Programs/Errors/undefSec.txt");

				Assert::AreEqual(true, false);
			}
			catch (UndefinedSection& e)
			{
				Assert::AreEqual(true, true);
			}
			catch (std::exception& e)
			{
				Assert::AreEqual(true, false);
			}
		}

		TEST_METHOD(redefinedSection)
		{
			try
			{
				std::map<std::string, ReMu::Section*> sections = parseProgram("../TestSuite/Files/Programs/Errors/redefSec.txt");

				Assert::AreEqual(true, false);
			}
			catch (RedefinedSection& e)
			{
				Assert::AreEqual(true, true);
			}
			catch (std::exception& e)
			{
				Assert::AreEqual(true, false);
			}
		}

		TEST_METHOD(overlappingSections)
		{
			try
			{
				std::map<std::string, ReMu::Section*> sections = parseProgram("../TestSuite/Files/Programs/Errors/overlapSec.txt");

				Assert::AreEqual(true, false);
			}
			catch (OverlappingSections& e)
			{
				Assert::AreEqual(true, true);
			}
			catch (std::exception& e)
			{
				Assert::AreEqual(true, false);
			}
		}

		TEST_METHOD(redefinedScale)
		{
			try
			{
				std::map<std::string, ReMu::Section*> sections = parseProgram("../TestSuite/Files/Programs/Errors/redefScale.txt");

				Assert::AreEqual(true, false);
			}
			catch (RedefinedScale& e)
			{
				Assert::AreEqual(true, true);
			}
			catch (std::exception& e)
			{
				Assert::AreEqual(true, false);
			}
		}

		TEST_METHOD(redefinedChord)
		{
			try
			{
				std::map<std::string, ReMu::Section*> sections = parseProgram("../TestSuite/Files/Programs/Errors/redefChord.txt");

				Assert::AreEqual(true, false);
			}
			catch (RedefinedChord& e)
			{
				Assert::AreEqual(true, true);
			}
			catch (std::exception& e)
			{
				Assert::AreEqual(true, false);
			}
		}

		TEST_METHOD(scaleNotFonud)
		{
			try
			{
				std::map<std::string, ReMu::Section*> sections = parseProgram("../TestSuite/Files/Programs/Errors/scaleNotFound.txt");

				Assert::AreEqual(true, false);
			}
			catch (ScaleNotFonud& e)
			{
				Assert::AreEqual(true, true);
			}
			catch (std::exception& e)
			{
				Assert::AreEqual(true, false);
			}
		}

		TEST_METHOD(chordNotFonud)
		{
			try
			{
				std::map<std::string, ReMu::Section*> sections = parseProgram("../TestSuite/Files/Programs/Errors/chordNotFound.txt");

				Assert::AreEqual(true, false);
			}
			catch (ChordNotFonud& e)
			{
				Assert::AreEqual(true, true);
			}
			catch (std::exception& e)
			{
				Assert::AreEqual(true, false);
			}
		}

		TEST_METHOD(unbalancedTranstion)
		{
			try
			{
				std::map<std::string, ReMu::Section*> sections = parseProgram("../TestSuite/Files/Programs/Errors/unbalancedTranstion.txt");

				Assert::AreEqual(true, false);
			}
			catch (UnbalancedTranstion& e)
			{
				Assert::AreEqual(true, true);
			}
			catch (std::exception& e)
			{
				Assert::AreEqual(true, false);
			}
		}

		TEST_METHOD(incompleteTranstionRythem)
		{
			try
			{
				std::map<std::string, ReMu::Section*> sections = parseProgram("../TestSuite/Files/Programs/Errors/incompleteTranstionRythem.txt");

				Assert::AreEqual(true, false);
			}
			catch (IncompleteTranstionRythem& e)
			{
				Assert::AreEqual(true, true);
			}
			catch (std::exception& e)
			{
				Assert::AreEqual(true, false);
			}
		}
	};
}