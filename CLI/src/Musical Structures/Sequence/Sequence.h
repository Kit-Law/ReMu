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
		bool hasDurationFlag = false;
	public:
		inline void pushBack(Pitch& note)
		{
			structsToMapping.push_back(std::pair<void*, structType>(new Pitch(note), PITCH));
		}

		inline void pushBack(Chord* chord)
		{
			structsToMapping.push_back(std::pair<void*, structType>(chord, CHORD));
		}

		inline std::vector<std::pair<void*, structType>>* getStuctsToMapping() { return &structsToMapping; }
		inline size_t size() { return structsToMapping.size(); }

		inline void setDurationFlag(bool flag) { hasDurationFlag = flag; }
		inline bool hasDuration() { return hasDurationFlag; }

		friend std::ostream& operator<<(std::ostream& os, const Sequence& sequence);
	};

	inline std::ostream& operator<<(std::ostream& os, const Sequence& sequence)
	{
		for (std::pair<void*, structType> seq : sequence.structsToMapping)
		{
			if (seq.second == PITCH)
				os << *(Pitch*)seq.first << " ";
			else if (seq.second == CHORD)
				os << "(" << *(Chord*)seq.first << "\b) ";
		}

		return os;
	}

}