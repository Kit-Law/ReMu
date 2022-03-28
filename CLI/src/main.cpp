#include "API.h"

#include "./Timers/DeltaTime.h"

#define DEBUG

#ifdef DEBUG
int main()
#else
int main(const char* argv[])
#endif // DEBUG
{
	Utils::DeltaTime deltaTime;
	deltaTime.resetDeltaTime();

	std::ifstream stream;
#ifdef DEBUG
	stream.open("..//Programs//example.txt");
#else
	stream.open(argv[1]);
#endif // DEBUG

	ReMu::Listener* listener = ReMu::API::parse(stream);

	deltaTime.calDeltaTime();
	std::cout << "Parsing Time = " << deltaTime.getDeltaTime() << "s" << std::endl;

#ifdef DEBUG
	ReMu::API::eval(listener, "..//MusicXMLFiles//Output//AAAAAA.musicxml", "..//MusicXMLFiles//Output//occurTest.musicxml");

	//ReMu::Evaluator::Evaluator(listener.getSections(), "..//MusicXMLFiles//Input//Chord.musicxml", "..//MusicXMLFiles//Output//Gmin.musicxml");
	//ReMu::Evaluator::Evaluator(listener.getSections(), "..//MusicXMLFiles//Input//D_Major_Scale.musicxml", "..//MusicXMLFiles//Output//D_Lydian_scale.musicxml");
	//ReMu::Evaluator::Evaluator(listener.getSections(), "..//MusicXMLFiles//Output//AAAAAA.musicxml", "..//MusicXMLFiles//Output//PatternTest.musicxml");

	//ReMu::Evaluator::Evaluator(listener.getSections(), "..//MusicXMLFiles//Input//D_Major_Scale.musicxml", "..//MusicXMLFiles//Output//AAAAAA.musicxml");
#else
	ReMu::API::eval(listener, argv[2], argv[3]);
#endif // DEBUG
	
	deltaTime.calDeltaTime();
	std::cout << "Evaluation Time = " << deltaTime.getDeltaTime() << "s" << std::endl;

	delete listener;

	return 0;
}