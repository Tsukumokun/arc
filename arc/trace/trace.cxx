/******************************************************************************
 * 'arc' - is a c++ framework for generic development. This framework         *
 *         offers a diverse range of tools and algorithms as the base         *
 *         for any project.                                                   *
 *                                                                            *
 *                             Copyright (C) 2014                             *
 *                Christopher Kelley <tsukumokun(at)icloud.com>               *
 *                                                                            *
 * This work is licensed under the                                            *
 * Creative Commons Attribution-NonCommercial-NoDerivatives 4.0               *
 * International License. To view a copy of this license, visit               *
 * http://creativecommons.org/licenses/by-nc-nd/4.0/deed.en_US.               *
 *                                                                            *
 * This program is distributed in the hope that it will be useful,            *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of             *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.                       *
 ******************************************************************************/


// External std library includes
#include <string>
#include <sstream>


// External other library includes
#include <boost/lexical_cast.hpp>


// Internal project includes
#include "trace.hxx"


namespace arc   {
namespace trace {


//---------- Trace::Trace() ----------------------------------------------------
Trace::Trace()
{ }


//---------- Trace::trace() ----------------------------------------------------
void Trace::trace(const std::string &file, int line, const std::string &msg)
{
    std::string sfil = boost::lexical_cast<std::string>(file);
    sfil.resize(TRACE_FILENAME_LENGTH,' ');
    std::string slin = boost::lexical_cast<std::string>(line);
    slin.resize(TRACE_LINENUM_LENGTH,' ');

    std::stringstream out;
    out << "<" << sfil << ":" << slin << "> - " << msg;

    std::cout << out.str() << std::endl;
}


//---------- Trace::shortFileName() --------------------------------------------
std::string Trace::shortFileName(const char *file)
{
    std::string shortName(file);
    unsigned found = shortName.find_last_of("/\\");
    return shortName.substr(found+1);
}


}
}
