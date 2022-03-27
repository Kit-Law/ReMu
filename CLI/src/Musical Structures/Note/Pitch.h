#pragma once

#include <iostream>

#include ".\Accidental.h"

namespace ReMu {

	class Pitch
	{
	protected:
		char step;
		Accidental accidental = None;
		float duration = -1;
	public:
		Pitch() { }
		Pitch(char __note, Accidental __accidental = None) : step(__note), accidental(__accidental) {  }
		Pitch(char __note, float __duration, Accidental __accidental = None) : step(__note), duration(__duration), accidental(__accidental) { }

		inline void setStep(char step) { this->step = step; }
		inline void setAccidental(Accidental modifier) { this->accidental = modifier; }
		inline void setDuration(float duration) { this->duration = duration; }

		inline char getStep() { return step; }
		inline Accidental getAccidental() { return accidental; }
		inline float getDuration() { return duration; }

		friend bool operator==(const Pitch& lhs, const Pitch& rhs);
		friend std::ostream& operator<<(std::ostream& os, const Pitch& note);

		size_t operator()(const Pitch& p) const
		{
			return step * accidental;
		}
	};

	inline bool operator==(const Pitch& lhs, const Pitch& rhs)
	{
		return lhs.step + lhs.accidental == rhs.step + rhs.accidental;
	}

	inline std::ostream& operator<<(std::ostream& os, const Pitch& note)
	{
		os << note.step << note.accidental;
		if (note.duration > 0) os << "[" << note.duration << "]";

		return os;
	}

}