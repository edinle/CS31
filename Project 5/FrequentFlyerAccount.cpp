//  FrequentFlyerAccount.cpp
//  Project 5
//  Edin Le
//  UID: 006147784

#include <iostream>
#include <string>
#include <cassert>
#include "FrequentFlyerAccount.h"

/*
 Each FrequentFlyerAccount object has a
 name associated with the account and its mileage balance. Solely the name parameter is
 provided to the FrequentFlyerAccount constructor. In the beginning of time, the balance
 should start at zero.
 */
FrequentFlyerAccount::FrequentFlyerAccount(string name) {
    mName = name;
    mBalance = 0;
}

double FrequentFlyerAccount::getBalance() {
    return mBalance;
}
string FrequentFlyerAccount::getName() {
    return mName;
}

/* The mileage balance gets increased by adding flights to the account via calls
to .addFlightToAccount( ... ) when the passenger's name matches the frequent flyer account
name.

.addFlightToAccount( ... ) should return true when the names match and return false
otherwise. */
bool FrequentFlyerAccount::addFlightToAccount(PlaneFlight flight) {
    if (flight.getName() == mName) {
        mBalance = mBalance + flight.getMileage();
        return true;
    } else {
        return false;
    }
}

/* FrequentFlyerAccount can also be used to determine if enough of a mileage
 balance is available for a desired flight via calls to .canEarnFreeFlight( ) which returns the
 appropriate boolean answer. */
bool FrequentFlyerAccount::canEarnFreeFlight(double mileage) {
    if (mileage <= mBalance) {
        return true;
    } else {
        return false;
    }
}

/* Free flights can be redeemed from a FrequentFlyerAccount via calls
 to .freeFlight( ... ) which should use the passed parameters to create the desired PlaneFlight
 with a zero cost, adjusting the mileage balance accordingly. .freeFlight( ... ) should return
 true when enough of a mileage balance existed to create a free flight and return false
 otherwise. */
bool FrequentFlyerAccount::freeFlight(string from, string to, double mileage, PlaneFlight &flight) {
    if (mileage <= mBalance) {
        flight.setName(mName);
        flight.setFromCity(from);
        flight.setToCity(to);
        flight.setCost(0);
        flight.setMileage(mileage);
        mBalance = mBalance - mileage;
        return true;
    } else {
        return false;
    }
}
