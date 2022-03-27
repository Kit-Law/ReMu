#pragma once

#include <unordered_map>
#include <unordered_set>

#include "../Note/Pitch.h"

namespace ReMu {

	class KeySig
	{
	private:
		static std::unordered_map<Pitch, short, Pitch> database;
		static Pitch sharpNotes[7];
		static Pitch flatNotes[7];
	public:
		static void initalize();

		static const std::unordered_map<char, Accidental> getNoteMapping(const Pitch* rootNote);
		static const std::unordered_map<char, Accidental> getNoteMapping(short fiths);

		static const short getFiths(const Pitch* rootNote);
	private:
		static const std::unordered_map<char, Accidental> genNoteMapping(short fiths);
	};

}