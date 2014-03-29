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
#include <list>

// External other library includes
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/any.hpp>

namespace arc     {
namespace pattern {

/**
 * @class Observer
 * @brief Parent class for observers looking at a subject.
 *
 * Observer pattern implementation follows details outlined
 * at http://en.wikipedia.org/wiki/Observer_pattern.
 */
class Observer;
/**
 * @var typedef boost::shared_ptr<Observer> P_Observer
 * @brief Definition for an observer pointer.
 */
typedef boost::shared_ptr<Observer> P_Observer;

/**
 * @class Observer
 * @brief Parent class for observer subjects being looked at.
 *
 * Observer subject pattern implementation follows details outlined
 * at http://en.wikipedia.org/wiki/Observer_pattern.
 */
class ObserverSubject;
/**
 * @var typedef boost::shared_ptr<ObserverSubject> P_ObserverSubject
 * @brief Definition for an observer subject pointer.
 */
typedef boost::shared_ptr<ObserverSubject> P_ObserverSubject;

//========== Observer ==========================================================
class Observer : public boost::enable_shared_from_this<Observer>
{
public:

    /**
     * @brief Notifies the observer of a change in the subject.
     *
     * Called by the notification function of an observer
     * subject to notify this observer that something has changed.
     *
     * @param sender Shared pointer to an observer subject.
     * @param data   Raw pointer to some data, unspecified type.
     */
    virtual void onNotify(P_ObserverSubject sender, boost::any data) = 0;
};

//========== ObserverSubject ===================================================
class ObserverSubject : public boost::enable_shared_from_this<ObserverSubject>
{
private:

    std::list<P_Observer> m_observers; //!< List of observers

public:

    /**
     * @brief Adds an observer to this subject.
     *
     * @param observer Shared pointer to the observer to add.
     */
    void attach(P_Observer observer);

    /**
     * @brief Removes an observer from this subject.
     *
     * @param observer Shared pointer to the observer to remove.
     */
    void detach(P_Observer observer);

    /**
     * @brief Sends a notification to the observers of this subject.
     *
     * This method will handle sending the data to all of the obsevers.
     *
     * @param data Anything that the observers should be expecting.
     */
    void notify(boost::any data);
};

}
}
