#pragma once

#include <vector>

#include "..\Note\Note.h"

namespace ReMu {

	class Chord
	{
	private:
		std::vector<Note> components;
	public:
		Chord(std::vector<Note> __components) {	components = __components; }

		inline void addNote(Note note) 
		{ 
			if (std::find(components.begin(), components.end(), note) != components.end()) components.push_back(note); 
		}
		inline void removeNote(Note note) 
		{ 
			std::remove_if(components.begin(), components.end(), [note](Note& component) { return component == note; });
		}

		friend std::ostream& operator<<(std::ostream& os, const Chord& chord);
	};

	inline std::ostream& operator<<(std::ostream& os, const Chord& chord)
	{
		for (Note component : chord.components)
			os << component << " ";

		return os;
	}

}