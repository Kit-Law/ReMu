#pragma once

#include <iostream>

namespace ReMu {

	enum Accidental
	{
		TripleSharp = 3,
		DoubleSharp = 2,
		Sharp = 1,
		None = 0,
		Flat = -1,
		DoubleFlat = -2,
		TripleFlat = -3
	};

	std::ostream& operator<<(std::ostream& os, const Accidental& accidental);

}