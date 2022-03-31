#include "API.h"

#include "./Timers/DeltaTime.h"

//#define CLI
//#define DEBUG
#define XML

#ifdef DEBUG
int main()
#else
int main(int argc, const char* argv[])
#endif // DEBUG
{
	Utils::DeltaTime deltaTime;
	deltaTime.resetDeltaTime();

#ifdef DEBUG | CLI
	std::ifstream stream;
#else
	std::stringstream stream;
#endif

#ifdef DEBUG
	stream.open("..//Programs//example.txt");
#endif // DEBUG
#ifdef CLI
	stream.open(argv[1]);
#endif // CLI
#ifdef XML
	pugi::xml_document doc = ReMu::Evaluator::Evaluator::openDoc(argv[1]);

	const char* inputFile = doc.child("InputFile").text().as_string();
	const char* outputFile = doc.child("OutputFile").text().as_string();
	const char* program = doc.child("Program").text().as_string();

	stream << program;
#endif // XML

	ReMu::Listener* listener = ReMu::API::parse(stream);

	deltaTime.calDeltaTime();
	std::cout << "Parsing Time = " << deltaTime.getDeltaTime() << "s" << std::endl;

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
	std::cout << "Evaluation Time = " << deltaTime.getDeltaTime() << "s" << std::endl;

	delete listener;

	return 0;
}