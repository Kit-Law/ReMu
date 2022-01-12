#pragma once

#define Notes ReMu::Note*

#include <iostream>

#include ".\Pitch.h"

namespace ReMu {

	class Note : public Pitch
	{
	public:
		Note() { }
		Note(char __note, Accidental __accidental = None) : Pitch(__note, __accidental) { }
		Note(class Pitch& pitch) : Pitch(pitch.getStep(), pitch.getAccidental()) { }

		Note incrementNote(int interval);
	};

}