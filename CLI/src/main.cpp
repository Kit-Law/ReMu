#include "API.h"

#include "./Timers/DeltaTime.h"
#include "./Logger/Logger.h"

#include <iostream>

//#define CLI
//#define DEBUG
#define XML

#ifdef DEBUG
int main()
#else
int main(int argc, const char* argv[])
#endif // DEBUG
{






	ReMu::ScaleDatabase::initalize();

	std::stringstream prog;
	prog << "\"test\" = 1 - 20;\n\n\"test\":";
	prog << "F min -> A,";
	std::map<std::string, ReMu::Section*> sections = ReMu::API::parse(prog)->getSections();

	for (auto const& section : sections)
	{
		auto transition = section.second->getTransitionTable()->getSequenceTransitions()->at(0);
		ReMu::Chord* chord = (ReMu::Chord*)(std::get<0>(transition).getStuctsToMapping()->at(0).first);

		std::cout << (chord->getComponents()->at(0) == ReMu::Note('F', ReMu::Accidental::None));
		std::cout << (chord->getComponents()->at(1) == ReMu::Note('A', ReMu::Accidental::Flat));
		std::cout << (chord->getComponents()->at(2) == ReMu::Note('C', ReMu::Accidental::None));
	}








	Utils::DeltaTime deltaTime;
	deltaTime.resetDeltaTime();

#ifdef DEBUG | CLI
	std::ifstream stream;
#else
	std::stringstream stream;
#endif

#ifdef DEBUG
	stream.open("../TestSuite/Files/Programs/ChordParsing/A#_Major.txt");//..//Programs//example.txt");
#endif // DEBUG
#ifdef CLI
	stream.open(argv[1]);
#endif // CLI
#ifdef XML
	pugi::xml_document doc = ReMu::Evaluator::Evaluator::openDoc(argv[1]);

	const char* inputFile = doc.child("InputFile").text().as_string();
	const char* outputFile = doc.child("OutputFile").text().as_string();
	const char* logFile = doc.child("LogFile").text().as_string();
	const char* program = doc.child("Program").text().as_string();

	ReMu::Logger logger(logFile);

	stream << program;
#else
	ReMu::Logger logger;
#endif // XML
	try 
	{
		ReMu::Listener* listener = ReMu::API::parse(stream);

		deltaTime.calDeltaTime();
		logger << "Parsing Time = " << deltaTime.getDeltaTime() << "s" << std::endl;

	#ifdef DEBUG
		ReMu::API::eval(listener, "..//MusicXMLFiles//Output//AAAAAA.musicxml", "..//MusicXMLFiles//Output//instTest.musicxml");

		//ReMu::Evaluator::Evaluator(listener.getSections(), "..//MusicXMLFiles//Input//Chord.musicxml", "..//MusicXMLFiles//Output//Gmin.musicxml");
		//ReMu::Evaluator::Evaluator(listener.getSections(), "..//MusicXMLFiles//Input//D_Major_Scale.musicxml", "..//MusicXMLFiles//Output//D_Lydian_scale.musicxml");
		//ReMu::Evaluator::Evaluator(listener.getSections(), "..//MusicXMLFiles//Output//AAAAAA.musicxml", "..//MusicXMLFiles//Output//PatternTest.musicxml");

		//ReMu::Evaluator::Evaluator(listener.getSections(), "..//MusicXMLFiles//Input//D_Major_Scale.musicxml", "..//MusicXMLFiles//Output//AAAAAA.musicxml");
	#endif // DEBUG
	#ifdef CLI
		ReMu::API::eval(listener, argv[2], argv[3]);
	#endif // CLI
	#ifdef XML
		ReMu::API::eval(listener, inputFile, outputFile);
	#endif // XML
	
		deltaTime.calDeltaTime();
		logger << "Evaluation Time = " << deltaTime.getDeltaTime() << "s" << std::endl;

		delete listener;
	}
	catch (std::exception& e)
	{
		logger.setLogLevel(LOG_LEVEL_ERROR);
		logger << "[ERROR] ";
		logger << e.what();
	}

	return 0;
}