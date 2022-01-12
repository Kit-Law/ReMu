#pragma once

#include <iostream>

#include ".\Accidental.h"

namespace ReMu {

	class Pitch
	{
	protected:
		char step;
		Accidental accidental = None;
	public:
		Pitch() { }
		Pitch(char __note, Accidental __accidental = None) { step = __note; accidental = __accidental; }

		inline void setStep(char step) { this->step = step; }
		inline void setAccidental(Accidental modifier) { this->accidental = modifier; }

		inline char getStep() { return step; }
		inline Accidental getAccidental() { return accidental; }

		friend bool operator==(const Pitch& lhs, const Pitch& rhs);
		friend std::ostream& operator<<(std::ostream& os, const Pitch& note);
	};

	inline bool operator==(const Pitch& lhs, const Pitch& rhs)
	{
		return lhs.step == rhs.step && lhs.accidental == rhs.accidental;
	} //TODO: Fix this because this isn't true

	inline std::ostream& operator<<(std::ostream& os, const Pitch& note)
	{
		os << note.step << note.accidental;
		return os;
	}

}