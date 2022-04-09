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
		Note(char __note, int __duration, Accidental __accidental = None) : Pitch(__note, __duration, __accidental) { }
		Note(class Pitch& pitch) : Pitch(pitch.getStep(), pitch.getAccidental()) { }

		Note incrementNote(int interval)
		{
			Pitch cunt = mapNumToNote(mapNoteToNum() + interval, duration);
			return Note(cunt);
		};
	};

}