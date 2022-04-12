#pragma once

#include "../Musical Structures/Section.h"
#include "../Musical Structures/KeySig/KeySig.h"
#include "../Listeners/Listener.h"

#include "./NoteEvaluator.h"
#include "./SequenceEvaluator.h"

#include "./DivisionsMap.h"

#include "../Logger/Logger.h"

#include "pugixml.hpp"

#include <map>
#include <unordered_map>
#include <string>

namespace ReMu { namespace Evaluator {

	class Evaluator
	{
	public:
		Evaluator(std::map<std::string, Section*> sections, const char* input, const char* output);

		inline static pugi::xml_document openDoc(const char* input)
		{
			pugi::xml_document doc;
			pugi::xml_parse_result result = doc.load_file(input);
			if (!result)
				throw;

			return doc;
		}

		inline static void closeDoc(pugi::xml_document &doc, const char* output)
		{
			Logger() << "Saving result: " << doc.save_file(output) << std::endl;
		}
	private:
		void changeKey(const ReMu::Pitch* relativeMajorKey, Section* section, std::string instrument, pugi::xml_document& doc);
		void evaluateSection(pugi::xml_document& doc, Section* section, TransitionTable* transitionTable, std::string instrument, DivisionsMap& divisionsMap);
	};

} }