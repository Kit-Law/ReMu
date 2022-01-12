#include ".\Note.h"

namespace ReMu {

	Note Note::incrementNote(int interval)
	{
		Note result(this->getStep(), this->getAccidental());

		for (int i = 0; i < interval; i++)
		{
			if (result.getStep() == 'B' || result.getStep() == 'E')
				result.setStep(result.getStep() + 1);
			else if (result.getStep() == 'G' && result.getAccidental() == Sharp)
			{
				result.setAccidental(None);
				result.setStep('A');
			}
			else if (result.getAccidental() == Sharp)
			{
				result.setAccidental(None);
				result.setStep(result.getStep() + 1);
			}
			else if (result.getAccidental() == Flat)
				result.setAccidental(None);
			else
				result.setAccidental(Sharp);
		}

		return result;
	}

}