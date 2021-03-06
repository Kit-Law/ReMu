#include ".\Degree.h"

namespace ReMu {

	int Degree::intervals[] = MAJOR_INTERVALS;

	Pitch Degree::evaluateNote(Pitch& rootNote)
	{
		int interval = 0;

		for (int i = 0; i < step - 1; i++)
			interval += intervals[i];

		interval += this->accidental;
		return rootNote.incrementNote(interval);
	}

}