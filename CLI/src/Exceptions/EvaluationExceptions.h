#pragma once

#include <exception>
#include <sstream>
#include <string>

#include "../Musical Structures/Sequence/Sequence.h"

struct UnbalancedTranstion : public std::exception
{
    ReMu::Sequence inital;
    ReMu::Sequence result;
    UnbalancedTranstion(ReMu::Sequence __inital, ReMu::Sequence __result) { inital = __inital; result = __result; }

    const char* what() const throw ()
    {
        std::stringstream ss;
        
        ss << "Transition: " << inital << " -> " << result << ", has an unbalanced rythem.";

        return ss.str().c_str();
    }
};