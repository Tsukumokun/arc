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

#pragma once

// External std library includes
#include <string>
#include <sstream>

#define TRACE_LEVEL_ERROR   1
#define TRACE_LEVEL_WARN    2
#define TRACE_LEVEL_INFO    3
#define TRACE_LEVEL_DEBUG   4
#define TRACE_LEVEL_NOTE    5
#define TRACE_LEVEL_ALL     6

#ifdef TRACE_LEVEL
#define TRACE_ON
#endif

#ifndef TRACE_FILENAME_LENGTH
#define TRACE_FILENAME_LENGTH 25
#endif
#ifndef TRACE_LINENUM_LENGTH
#define TRACE_LINENUM_LENGTH 5
#endif

#ifdef TRACE_ON

#   define TRACE(file,line,msg)                             \
        {                                                   \
            std::stringstream _msg;                         \
            _msg << msg;                                    \
            arc::trace::Trace::self()->trace(               \
                file,                                       \
                line,                                       \
                std::string(_msg.str(),_msg.gcount())); \
        }

#   define TRACE_MSG(msg) TRACE(                            \
            arc::trace::Trace::shortFileName(__FILE__),     \
            __LINE__,                                       \
            msg);

#   define ERROR(x)     TRACE_MSG("[ERROR ] " << x)
#   define SEVERE(x)    TRACE_MSG("[SEVERE] " << x)

#   define WARN(x)      TRACE_MSG("[WARN  ] " << x)

#   define INFO(x)      TRACE_MSG("[INFO  ] " << x)

#   define SYSTEM(x)    TRACE_MSG("[SYSTEM] " << x)

#   define NOTE(x)      TRACE_MSG("[NOTE  ] " << x)
#   define TODO(x)      TRACE_MSG("[TODO  ] " << x)
#   define XXX(x)       TRACE_MSG("[XXX   ] " << x)

#   if  TRACE_LEVEL < TRACE_LEVEL_NOTE
#       undef  NOTE
#       define NOTE(x)
#       undef  TODO
#       define TODO(x)
#       undef  XXX
#       define XXX(x)
#   endif
#   if  TRACE_LEVEL < TRACE_LEVEL_DEBUG
#       undef  SYSTEM
#       define SYSTEM(x)
#   endif
#   if  TRACE_LEVEL < TRACE_LEVEL_INFO
#       undef  INFO
#       define INFO(x)
#   endif
#   if  TRACE_LEVEL < TRACE_LEVEL_WARN
#       undef  WARN
#       define WARN(x)
#   endif

#else
#   define ERROR(x)
#   define SEVERE(x)
#   define WARN(x)
#   define INFO(x)
#   define SYSTEM(x)
#   define NOTE(x)
#   define TODO(x)
#   define XXX(x)
#endif


namespace arc   {
namespace trace {

class Trace
{
private:
    Trace();
    Trace(Trace const &copy);           //not implemented
    Trace &operator=(Trace const&copy); //not implemented

public:
    static inline Trace *self();

    void trace(const std::string &file, int line, const std::string &msg);

    static std::string shortFileName(const char *file);

    void start();
    void stop();

};

//---------- Trace::self() -----------------------------------------------------
Trace *Trace::self()
{
    static Trace instance;
    return &instance;
}

}
}
