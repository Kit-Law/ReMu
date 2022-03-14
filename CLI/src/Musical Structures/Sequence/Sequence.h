#pragma once

#include "../Note/Pitch.h"
#include "../Chord/Chord.h"

namespace ReMu {

	enum structType
	{
		PITCH,
		CHORD,
	};

	class Sequence
	{
	private:
		std::vector<std::pair<void*, structType>> structsToMapping;
	public:
		inline void pushBack(Pitch* note)
		{
			structsToMapping.push_back(std::pair<void*, structType>(note, PITCH));
		}

		inline void pushBack(Chord* chord)
		{
			structsToMapping.push_back(std::pair<void*, structType>(chord, CHORD));
		}

		inline std::vector<std::pair<void*, structType>>* getStuctsToMapping() { return &structsToMapping; }
	};

}