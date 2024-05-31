//  PlaneFlight.h
//  Project 5
//  Edin Le
//  UID: 006147784

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

#ifndef PlaneFlight_h
#define PlaneFlight_h

class PlaneFlight {
public:
    PlaneFlight(string passengerName, string fromCity, string toCity, double cost, double mileage);
    
    double getCost();
    void setCost(double cost);
    
    double getMileage();
    void setMileage(double mileage);

    string getName();
    void setName(string name);
    
    string getFromCity();
    void setFromCity(string from);
    
    string getToCity();
    void setToCity(string to);
    
private:
    double mCost;
    string mFromCity;
    string mToCity;
    string mName;
    double mMileage;
};

#endif /* PlaneFlight_h */
