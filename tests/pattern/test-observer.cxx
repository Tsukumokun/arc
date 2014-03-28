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

#include "../../arc/pattern/observer.hxx"

#include <iostream>

#include <boost/any.hpp>

class ConcreteObserver : public arc::Observer
{
    void onNotify(arc::P_ObserverSubject sender,boost::any data)
    {
        std::cout << "Sender :" << sender << std::endl;
        std::cout << "Data   :" << boost::any_cast<int>(data) << std::endl;
    }
};

class ConcreteSubject : public arc::ObserverSubject
{
};

int main()
{
    arc::P_ObserverSubject subject(new ConcreteSubject());
    arc::P_Observer observer(new ConcreteObserver());

    subject->attach(observer);

    subject->notify(2);

    return 0;
}
