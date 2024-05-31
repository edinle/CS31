//  PlaneFlight.cpp
//  Project 5
//  Edin Le
//  UID: 006147784

#include <iostream>
#include <string>
#include <cassert>
#include "PlaneFlight.h"
using namespace std;

/*
 First, you will create the class PlaneFlight. This class represents plane trip. Each
 PlaneFlight object has a passenger name's, a cost, a from and to city as well as the mileage
 associated with this trip. All five of these parameters are provided to the PlaneFlight
 constructor.
 */

PlaneFlight::PlaneFlight(string passengerName, string fromCity, string toCity, double cost, double mileage) {
    // Constructor Validators
    if (!passengerName.empty()) {
        mName = passengerName;
    } else {
        mName = "null_Name";
    }
    
    if (!fromCity.empty()) {
        mFromCity = fromCity;
    } else {
        mFromCity = "null_FromCity";
    }
    
    if (!toCity.empty()) {
        mToCity = toCity;
    } else {
        mToCity = "null_ToCity";
    }
    
    if (cost >= 0) {
        mCost = cost;
    } else {
        mCost = -1;
    }
    
    if (mileage > 0) {
        mMileage = mileage;
    } else {
        mMileage = -1;
    }
}

// Cost
double PlaneFlight::getCost() {
    return mCost;
}
/*
 a valid cost must be a value of 0 or more. (A zero-cost flight will indicate a free flight
 earned by a frequent flyer. More on that shortly...). A PlaneFlight should store the value -1
 to indicate when an invalid flight cost was attempted to be stored.
 */
void PlaneFlight::setCost(double cost) {
    if (cost >= 0) {
        mCost = cost;
    } else {
        mCost = -1;
    }
}

// Mileage
double PlaneFlight::getMileage() {
    return mMileage;
}
/*
 a valid mileage must be a value greater than 0. A PlaneFlight should store the value -1 to
 indicate when an invalid mileage amount was attempted to be stored.
 */
void PlaneFlight::setMileage(double mileage) {
    if (mileage > 0) {
        mMileage = mileage;
    } else {
        mMileage = -1;
    }
}

// Name
string PlaneFlight::getName() {
    return mName;
}

// Similarly, the empty string is not valid for a passenger's Name. A PlaneFlight should ignore and not accept an invalid Name value
void PlaneFlight::setName(string name) {
    if (!name.empty()) {
        mName = name;
    }
}

// FromCity
string PlaneFlight::getFromCity() {
    return mFromCity;
}
/*
 empty string values are not valid for either a FromCity or a ToCity value. Additionally, the
 specified FromCity and ToCity must be different. A PlaneFlight should ignore and not
 accept an invalid FromCity or ToCity value. Similarly, the empty string is not valid for a
 passenger's Name. A PlaneFlight should ignore and not accept an invalid Name value.
 */
void PlaneFlight::setFromCity(string from) {
    if (!from.empty() && from != mToCity) {
        mFromCity = from;
    }
}

// ToCity
string PlaneFlight::getToCity() {
    return mToCity;
}
void PlaneFlight::setToCity(string to) {
    if (!to.empty() && to != mFromCity) {
        mToCity = to;
    }
}
