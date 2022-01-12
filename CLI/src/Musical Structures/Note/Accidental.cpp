#include "Accidental.h"

namespace ReMu {

	std::ostream& operator<<(std::ostream& os, const Accidental& accidental)
	{
		switch (accidental)
		{
			case TripleFlat:  os << "bbb"; break;
			case DoubleFlat:  os << "bb"; break;
			case Flat:		  os << "b"; break;
			case None:		  os << ""; break;
			case Sharp:		  os << "#"; break;
			case DoubleSharp: os << "##"; break;
			case TripleSharp: os << "###"; break;
			default: throw;
		}

		return os;
	}

}