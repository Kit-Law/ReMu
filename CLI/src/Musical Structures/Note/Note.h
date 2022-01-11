#pragma once

#define Notes ReMu::Note*

namespace ReMu {

	enum Modifier
	{
		TripleSharp,
		DoubleSharp,
		Sharp,
		None,
		Flat,
		DoubleFlat,
		TripleFlat
	};

	class Note
	{
	private:
		char note;
		Modifier modifier = None;
	public:
		Note() { }
		Note(char __note, Modifier __modidier = None) { note = __note; modifier = __modidier; }

		Note incrementNote(int interval);

		inline void setNote(char note) { this->note = note; }
		inline void setModifier(Modifier modifier) { this->modifier = modifier; }

		inline char* getNote() { return &note; }
		inline Modifier* getModifier() { return &modifier; }

		friend bool operator==(const Note& lhs, const Note& rhs);
	};

	inline bool operator==(const Note& lhs, const Note& rhs) { return lhs.note == rhs.note && lhs.modifier == rhs.modifier; } //TODO: Fix this because this isn't true

}