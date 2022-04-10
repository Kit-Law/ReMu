#pragma once

#include <iostream>

#include ".\Accidental.h"

namespace ReMu {

	class Pitch;
	Pitch mapNumToNote(int, int);

	class Pitch
	{
	protected:
		char step;
		Accidental accidental = None;
		int duration = -1;
	public:
		Pitch() { }
		Pitch(char __note, Accidental __accidental = None) : step(__note), accidental(__accidental) {  }
		Pitch(char __note, int __duration, Accidental __accidental = None) : step(__note), duration(__duration), accidental(__accidental) { }

		inline void setStep(char step) { this->step = step; }
		inline void setAccidental(Accidental modifier) { this->accidental = modifier; }
		inline void setDuration(int duration) { this->duration = duration; }

		inline char getStep() { return step; }
		inline Accidental getAccidental() { return accidental; }
		inline int getDuration() { return duration; }

		size_t operator()(const Pitch& p) const
		{
			return step * accidental;
		}

		Pitch incrementNote(int interval)
		{
			return mapNumToNote(mapNoteToNum() + interval, duration);
		};

		inline int mapStepToNum() const
		{
			int interval = step - 'A';
			return interval + (interval >= 1 ? interval >= 3 ? interval >= 4 ? interval >= 6 ? interval >= 7 ? 5 : 4 : 3 : 2 : 1 : 0);
		};

		inline int mapNoteToNum() const
		{
			int step = mapStepToNum() + accidental;
			return step < 0 ? step + 12 : step > 11 ? step - 12 : step;
		}

		friend bool operator==(const Pitch& lhs, const Pitch& rhs);
		friend std::ostream& operator<<(std::ostream& os, const Pitch& note);
	};

	inline Pitch mapNumToNote(int num, int duration = -1)
	{
		num = num % 12;
		return Pitch((char)(num + 'A' - (num >= 1 ? num >= 4 ? num >= 6 ? num >= 9 ? num >= 11 ? 5 : 4 : 3 : 2 : 1 : 0)),
			duration,
			(num == 1 || num == 4 || num == 6 || num == 9 || num == 11) ? Accidental::Sharp : Accidental::None);
	}

	inline bool operator==(const Pitch& lhs, const Pitch& rhs)
	{
		return lhs.mapNoteToNum() == rhs.mapNoteToNum();
	}

	inline std::ostream& operator<<(std::ostream& os, const Pitch& note)
	{
		os << note.step << note.accidental;
		if (note.duration > 0) os << "[" << note.duration << "]";

		return os;
	}

}