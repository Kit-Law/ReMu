#pragma once

#include <exception>
#include <sstream>
#include <string>

#include "../Musical Structures/Sequence/Sequence.h"

struct SectionDefOutOfBounds : public std::exception
{
    std::string message;

    SectionDefOutOfBounds(std::string section, short line) : message{"Section: " + section + ", at line " + std::to_string(line) + " has ill defined messures."} { }

    const char* what() const throw ()
    {
        return message.c_str();
    }
};

struct UndefinedSection : public std::exception
{
    std::string message;

    UndefinedSection(std::string section, short line) : message{"Section: " + section + ", at line " + std::to_string(line) + ", is undefined."} { }

    const char* what() const throw ()
    {
        return message.c_str();
    }
};

struct RedefinedSection : public std::exception
{
    std::string message;

    RedefinedSection(std::string section, short line) : message{ "Section: " + section + ", at line " + std::to_string(line) + ", is redefined." } { }

    const char* what() const throw ()
    {
        return message.c_str();
    }
};

struct OverlappingSections : public std::exception
{
    std::string message;

    OverlappingSections(std::string a, std::string b, short line) : message{ "Section: " + a + ", and section: " + b + ", at line " + std::to_string(line) + ", have overlapping mesures." } { }

    const char* what() const throw ()
    {
        return message.c_str();
    }
};

struct RedefinedScale : public std::exception
{
    std::string message;

    RedefinedScale(std::string scale, short line) : message{"Scale: " + scale + ", at line " + std::to_string(line) + ", already exists."} { }

    const char* what() const throw ()
    {
        return message.c_str();
    }
};

struct RedefinedChord : public std::exception
{
    std::string message;

    RedefinedChord(std::string chord) : message{"Chord: " + chord + ", already exists."} { }

    const char* what() const throw ()
    {
        return message.c_str();
    }
};

struct ScaleNotFonud : public std::exception
{
    std::string message;

    ScaleNotFonud(std::string scale, short line) : message{"Scale: " + scale + ", at line " + std::to_string(line) + ", doesn't exist."} { }

    const char* what() const throw ()
    {
        return message.c_str();
    }
};

struct ChordNotFonud : public std::exception //Fix userDef chords
{
    std::string message;

    ChordNotFonud(std::string chord) : message{"Chord: " + chord + ", doesn't exist."} { }

    const char* what() const throw ()
    {
        return message.c_str();
    }
};

struct UnbalancedTranstion : public std::exception
{
    std::string message;

    UnbalancedTranstion(ReMu::Sequence inital, ReMu::Sequence result) 
    { 
        std::stringstream ss;

        ss << "Transition: " << inital << " -> " << result << ", has an unbalanced rythem.";

        message = ss.str();
    }

    const char* what() const throw ()
    {
        return message.c_str();
    }
};

struct IncompleteTranstionRythem : public std::exception
{
    std::string message;

    IncompleteTranstionRythem(short line) : message{ "Transition at line: " + std::to_string(line) + ", has an incomplete rythem." }
    { }

    const char* what() const throw ()
    {
        return message.c_str();
    }
};