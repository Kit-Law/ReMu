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

}