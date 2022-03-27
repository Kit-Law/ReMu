#pragma once

#define Notes ReMu::Note*

#include <iostream>

#include "Pitch.h"
#include "Note.h"

#define MAJOR_INTERVALS { 2,2,1,2,2,2,1 }

namespace ReMu {

	class Degree : public Pitch
	{
	private:
		static int intervals[];
	public:
		Degree() { }
		Degree(char __note, Accidental __accidental = None) : Pitch(__note, __accidental) { }
		Degree(class Pitch& pitch) : Pitch(pitch.getStep(), pitch.getAccidental()) { step -= '0'; }

		Note evaluateNote(Note& rootNote);
	};

}