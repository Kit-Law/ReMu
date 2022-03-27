#pragma once

#include "..\Note\Note.h"

namespace ReMu {

	class ScaleInfo
	{
	private:
		const int* intervales;
		const int scaleLength;
		const short relativeMajorKeyStep;
	public:
		ScaleInfo(int* __intervales, int __scaleLength, short __relativeMajorKeyStep) : intervales(__intervales), scaleLength(__scaleLength), relativeMajorKeyStep(__relativeMajorKeyStep){ }
		~ScaleInfo() { delete intervales; }

		inline const Note getRelativeMajorKey(Note rootNote)
		{
			int interval = 0;

			for (int i = 0; i < relativeMajorKeyStep; i++)
				interval += intervales[i];

			return rootNote.incrementNote(interval);
		}

		inline const int* getIntervales() { return intervales; }
		inline const int getScaleLength() { return scaleLength; }
	};

}