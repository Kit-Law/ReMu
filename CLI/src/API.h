#pragma once

#include <iostream>

#include "antlr4-runtime.h"

#include ".\Grammar\SheetMusicLexer.h"
#include ".\Grammar\SheetMusicParser.h"
#include ".\Grammar\SheetMusicBaseListener.h"

#include "Listeners/Listener.h"

#include "Evaluators/Evaluator.h"

#include "Tokens/scaleRule.h"

#include "Musical Structures/KeySig/KeySig.h"

#include "pugixml.hpp"

#include "Timers/DeltaTime.h"

namespace ReMu {

	class API
	{
	public:
		static ReMu::Listener* parse(std::stringstream &inputProgram);

		static void eval(ReMu::Listener* listener, const char* input, const char* output);
	};

}