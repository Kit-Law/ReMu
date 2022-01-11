#include ".\Note.h"

namespace ReMu {

	Note Note::incrementNote(int interval)
	{
		Note result(*this->getStep(), *this->getAccidental());

		for (int i = 0; i < interval; i++)
		{
			if (*result.getStep() == 'B' || *result.getStep() == 'E')
				(*result.getStep())++;
			else if (*result.getStep() == 'G' && *result.getAccidental() == Sharp)
			{
				*result.getAccidental() = None;
				*result.getStep() = 'A';
			}
			else if (*result.getAccidental() == Sharp)
			{
				*result.getAccidental() = None;
				(*result.getStep())++;
			}
			else if (*result.getAccidental() == Flat)
				*result.getAccidental() = None;
			else
				*result.getAccidental() = Sharp;
		}

		return result;
	}

	std::ostream& operator<<(std::ostream& os, const Accidental& accidental)
	{
		switch (accidental)
		{
		case TripleFlat:  os << "bbb"; break;
		case DoubleFlat:  os << "bb "; break;
		case Flat:		  os << "b  "; break;
		case None:		  os << "   "; break;
		case Sharp:		  os << "#  "; break;
		case DoubleSharp: os << "## "; break;
		case TripleSharp: os << "###"; break;
		default: throw;
		}

		return os;
	}

}