#pragma once
/*
#include "../Musical Structures/Section.h"
#include "../Musical Structures/KeySig/KeySig.h"
#include "../Listeners/Listener.h"

#include "./NoteTransitionEvaluator.h"
#include "./ChordTransitionEvaluator.h"

#include "pugixml.hpp"

#include <map>
#include <unordered_map>
#include <string>

namespace ReMu { namespace Evaluator {

	class Evaluator
	{
	public:
		Evaluator(std::map<std::string, Section*> sections, const char* input, const char* output);
	private:
		inline pugi::xml_document openDoc(const char* input)
		{
			pugi::xml_document doc;
			pugi::xml_parse_result result = doc.load_file(input);
			if (!result)
				throw;

			return doc;
		}

		inline void closeDoc(pugi::xml_document &doc, const char* output)
		{
			std::cout << "Saving result: " << doc.save_file(output) << std::endl;
		}

		void changeKey(const ReMu::Pitch* relativeMajorKey, Section* section, pugi::xml_document& doc);
	};

} }*/