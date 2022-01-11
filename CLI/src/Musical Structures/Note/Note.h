#pragma once

#define Notes ReMu::Note*

#include <iostream>

namespace ReMu {

	enum Accidental
	{
		TripleSharp,
		DoubleSharp,
		Sharp,
		None,
		Flat,
		DoubleFlat,
		TripleFlat
	};

	std::ostream& operator<<(std::ostream& os, const Accidental& accidental);

	class Note
	{
	private:
		char step;
		Accidental accidental = None;
	public:
		Note() { }
		Note(char __note, Accidental __accidental = None) { step = __note; accidental = __accidental; }

		Note incrementNote(int interval);

		inline void setStep(char step) { this->step = step; }
		inline void setAccidental(Accidental modifier) { this->accidental = modifier; }

		inline char* getStep() { return &step; }
		inline Accidental* getAccidental() { return &accidental; }

		//const char* accidentalToString();

		friend bool operator==(const Note& lhs, const Note& rhs);
		friend std::ostream& operator<<(std::ostream& os, const Note& note);
	};

	inline bool operator==(const Note& lhs, const Note& rhs) 
	{ 
		return lhs.step == rhs.step && lhs.accidental == rhs.accidental; 
	} //TODO: Fix this because this isn't true

	inline std::ostream& operator<<(std::ostream& os, const Note& note)
	{
		os << note.step << note.accidental;
		return os;
	}

}