#pragma once

#include <string>

namespace ReMu {

	class Symbol
	{
	private:
		std::string quality;
		int interval;
	public:
		Symbol(std::string __quality, int __interval) { quality = __quality, interval = __interval; }
	};

}