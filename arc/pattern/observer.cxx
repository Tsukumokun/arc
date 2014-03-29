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
#include <list>


// Internal project includes
#include "observer.hxx"


namespace arc     {
namespace pattern {


//---------- ObserverSubject::attach() -----------------------------------------
void ObserverSubject::attach(P_Observer observer)
{
    this->m_observers.push_back(observer);
}


//---------- ObserverSubject::detach() -----------------------------------------
void ObserverSubject::detach(P_Observer observer)
{
    this->m_observers.remove(observer);
}


//---------- ObserverSubject::notify() -----------------------------------------
void ObserverSubject::notify(boost::any data)
{
    for (std::list<P_Observer>::const_iterator iter = this->m_observers.begin();
         iter != this->m_observers.end(); iter++)
    {
        if (*iter != NULL)
        {
            (*iter)->onNotify(this->shared_from_this(),data);
        }
    }
}


}
}
