#include "./KeySig.h"

namespace ReMu {

	std::unordered_map<Pitch, short, Pitch> KeySig::database;

	Pitch KeySig::sharpNotes[7] = { Pitch('F', Accidental::Sharp),
									Pitch('C', Accidental::Sharp),
									Pitch('G', Accidental::Sharp),
									Pitch('D', Accidental::Sharp),
									Pitch('A', Accidental::Sharp),
									Pitch('E', Accidental::Sharp),
									Pitch('B', Accidental::Sharp) };

	Pitch KeySig::flatNotes[7] = {  Pitch('B', Accidental::Flat),
									Pitch('E', Accidental::Flat),
									Pitch('A', Accidental::Flat),
									Pitch('D', Accidental::Flat),
									Pitch('G', Accidental::Flat),
									Pitch('C', Accidental::Flat),
									Pitch('F', Accidental::Flat) };

	void KeySig::initalize()
	{
		database[Pitch('C', Accidental::Flat)] = -7;
		database[Pitch('G', Accidental::Flat)] = -6;
		database[Pitch('D', Accidental::Flat)] = -5;
		database[Pitch('A', Accidental::Flat)] = -4;
		database[Pitch('E', Accidental::Flat)] = -3;
		database[Pitch('B', Accidental::Flat)] = -2;
		database[Pitch('F', Accidental::None)] = -1;
		database[Pitch('C', Accidental::None)] = 0;
		database[Pitch('G', Accidental::None)] = 1;
		database[Pitch('D', Accidental::None)] = 2;
		database[Pitch('A', Accidental::None)] = 3;
		database[Pitch('E', Accidental::None)] = 4;
		database[Pitch('B', Accidental::None)] = 5;
		database[Pitch('F', Accidental::Sharp)] = 6;
		database[Pitch('C', Accidental::Sharp)] = 7;
	}

	const std::unordered_map<char, Accidental> KeySig::getNoteMapping(const Pitch* rootNote)
	{
		return genNoteMapping(database[*rootNote]);
	}

	const std::unordered_map<char, Accidental> KeySig::getNoteMapping(short fiths)
	{
		return genNoteMapping(fiths);
	}

	const std::unordered_map<char, Accidental> KeySig::genNoteMapping(short fiths)
	{
		std::unordered_map<char, Accidental> mapping;
	
		for (int i = 0; i < fiths; i++)
			mapping[sharpNotes[i].getStep()] = Accidental::Sharp;

		for (int i = 0; i < -fiths; i++)
			mapping[flatNotes[i].getStep()] = Accidental::Flat;

		return mapping;
	}

	const short KeySig::getFiths(const Pitch* rootNote)
	{
		return database[*rootNote];
	}

}