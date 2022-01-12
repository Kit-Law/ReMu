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
		Note(const class Pitch&) { }

		Note incrementNote(int interval);
	};

}