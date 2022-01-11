#include ".\Note.h"

namespace ReMu {

	Note Note::incrementNote(int interval)
	{
		Note result(*this->getNote(), *this->getModifier());

		for (int i = 0; i < interval; i++)
		{
			if (*result.getNote() == 'B' || *result.getNote() == 'E')
				(*result.getNote())++;
			else if (*result.getNote() == 'G' && modifier == Sharp)
			{
				*result.getModifier() = None;
				*result.getNote() = 'A';
			}
			else if (*result.getModifier() == Sharp)
			{
				*result.getModifier() = None;
				(*result.getNote())++;
			}
			else if (*result.getModifier() == Flat)
				*result.getModifier() = None;
			else
				*result.getModifier() = Sharp;
		}

		return result;
	}

}