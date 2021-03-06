#pragma once

#include <vector>

#include "..\Note\Pitch.h"

namespace ReMu {

	class Chord
	{
	private:
		std::vector<Pitch> components;
		float duration = -1;
	public:
		Chord(std::vector<Pitch> __components) : components(__components) { }

		inline void addNote(Pitch note)
		{ 
			if (std::find(components.begin(), components.end(), note) != components.end()) components.push_back(note); 
		}
		inline void removeNote(Pitch note)
		{ 
			components.erase(std::remove_if(components.begin(), components.end(), [note](Pitch& component) { return component == note; }));
		}

		inline const std::vector<Pitch>* getComponents()
		{
			return &components;
		}

		inline void setDuration(float duration) { this->duration = duration; }
		inline const float getDuration() { return duration; }

		friend std::ostream& operator<<(std::ostream& os, const Chord& chord);
		friend bool operator==(const Chord& lhs, const Chord& rhs);
		friend bool operator==(const std::vector<Pitch>& lhs, const Chord& rhs);
	};

	inline std::ostream& operator<<(std::ostream& os, const Chord& chord)
	{
		for (Pitch component : chord.components)
			os << component << " ";

		return os;
	}

	inline bool operator==(const Chord& lhs, const Chord& rhs)
	{
		bool diff = false;
		bool found = false;

		for (Pitch lnote : lhs.components)
		{
			found = false;

			for (Pitch rnote : rhs.components)
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

			for (Pitch rnote : rhs.components)
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