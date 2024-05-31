//  FrequentFlyerAccount.h
//  Project 5
//  Edin Le
//  UID: 006147784

#include <iostream>
#include <string>
#include <cassert>
#include "PlaneFlight.h"
using namespace std;

#ifndef FrequentFlyerAccount_h
#define FrequentFlyerAccount_h

class FrequentFlyerAccount {
public:
    FrequentFlyerAccount(string name);
    
    double getBalance();
    string getName();

    bool addFlightToAccount(PlaneFlight flight);
    bool canEarnFreeFlight(double mileage);
    bool freeFlight(string from, string to, double mileage, PlaneFlight &flight);
    
private:
    string mName;
    double mBalance = 0;
};

#endif /* FrequentFlyerAccount_h */
