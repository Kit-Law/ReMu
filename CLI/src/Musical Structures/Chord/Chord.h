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

		inline const std::vector<Note>* getComponents()
		{
			return &components;
		}

		friend std::ostream& operator<<(std::ostream& os, const Chord& chord);
		friend bool operator==(const Chord& lhs, const Chord& rhs);
		friend bool operator==(const std::vector<Pitch>& lhs, const Chord& rhs);
	};

	inline std::ostream& operator<<(std::ostream& os, const Chord& chord)
	{
		for (Note component : chord.components)
			os << component << " ";

		return os;
	}

	inline bool operator==(const Chord& lhs, const Chord& rhs)
	{
		bool diff = false;
		bool found = false;

		for (Note lnote : lhs.components)
		{
			found = false;

			for (Note rnote : rhs.components)
				if (lnote == rnote)
				{
					found = true;
					break;
				}

			if (!found)
			{
				diff = true;
				break;
			}
		}
			
		return !diff && lhs.components.size() == rhs.components.size();
	}

	inline bool operator==(const std::vector<Pitch>& lhs, const Chord& rhs)
	{
		bool diff = false;
		bool found = false;

		for (Pitch lnote : lhs)
		{
			found = false;

			for (Note rnote : rhs.components)
				if (lnote == rnote)
				{
					found = true;
					break;
				}

			if (!found)
			{
				diff = true;
				break;
			}
		}

		return !diff && lhs.size() == rhs.components.size();
	}

}