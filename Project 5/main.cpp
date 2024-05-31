//  main.cpp
//  Project 5
//
//  Edin Le

#include <iostream>
#include <string>
#include <cassert>

#include "PlaneFlight.h"
#include "FrequentFlyerAccount.h"
using namespace std;

int main()
{
//    // sample test code
//    PlaneFlight shortleg( "Howard", "LAX", "LAS", 49.00, 285 );
//    PlaneFlight longleg( "Howard", "LAS", "NYC", 399.00, 2800 );
//    PlaneFlight sample( "Sample", "Sample", "Sample", 0, 1 );
//    FrequentFlyerAccount account( "Howard" );
//    assert( shortleg.getFromCity( ) == "LAX" );
//    assert( shortleg.getToCity( ) == "LAS" );
//    assert( shortleg.getName( ) == "Howard" );
//    assert( std::to_string( shortleg.getCost( ) ) == "49.000000" );
//    assert( std::to_string( shortleg.getMileage( ) ) == "285.000000" );
//    
//    // account balance starts at zero...
//    assert( std::to_string( account.getBalance( ) ) == "0.000000" );
//    assert( account.getName( ) == "Howard" );
//    assert( account.canEarnFreeFlight( 3300.00 ) == false );
//    
//    // flights add to an account balance
//    assert( account.addFlightToAccount( shortleg ) == true ); // returns true because the names match
//    assert( account.addFlightToAccount( longleg ) == true ); // returns true because the names match
//    assert( std::to_string( account.getBalance( ) ) == "3085.000000" );
//    
//    // free flights reduce an account balance
//    if (account.canEarnFreeFlight( 285 )) {
//        assert( account.freeFlight( "LAS", "LAX", 285, sample ) == true );
//        
//        // Howard earned a free flight...
//        assert( sample.getName( ) == "Howard" );
//        assert( std::to_string( sample.getCost( ) ) == "0.000000" );
//        assert( sample.getFromCity( ) == "LAS" );                           // failed
//        assert( sample.getToCity( ) == "LAX" );                             // failed
//        assert( std::to_string( sample.getMileage( ) ) == "285.000000" );   // failed
//        
//        // account has been reduced for this free flight...
//        assert( std::to_string( account.getBalance( ) ) == "2800.000000" );
//    } else {
//        assert( false ); // there are enough miles in the account...
//    }
    
    // 1. Valid PlaneFlight Initialization
    PlaneFlight validFlight("James Lee", "LAX", "JFK", 150.50, 2500);
    assert(validFlight.getName() == "James Lee");
    assert(validFlight.getFromCity() == "LAX");
    assert(validFlight.getToCity() == "JFK");
    assert(validFlight.getCost() == 150.50);
    assert(validFlight.getMileage() == 2500);

    // 2. Invalid PlaneFlight Initialization
    PlaneFlight invalidFlight("", "", "", -10, -500);
    assert(invalidFlight.getName() != "");
    assert(invalidFlight.getFromCity() != "");
    assert(invalidFlight.getToCity() != "");
    assert(invalidFlight.getCost() == -1);
    assert(invalidFlight.getMileage() == -1);

    // 3. Valid FrequentFlyerAccount Initialization
    FrequentFlyerAccount validAccount("James Lee");
    assert(validAccount.getName() == "James Lee");
    assert(validAccount.getBalance() == 0);

    // 4. Adding Flight to Account
    FrequentFlyerAccount account2("James Lee");
    PlaneFlight flight("James Lee", "LAX", "JFK", 150.50, 2500);
    assert(account2.addFlightToAccount(flight) == true);
    assert(account2.getBalance() == 2500);

    // 5. Adding Flight to Account with Non-Matching Names
    PlaneFlight nonMatchingFlight("Sarah Kim", "LAX", "JFK", 150.50, 2500);
    assert(account2.addFlightToAccount(nonMatchingFlight) == false);
    assert(account2.getBalance() == 2500); // Balance should remain unchanged

    // 6. Earning Free Flight
    assert(account2.canEarnFreeFlight(2000) == true); // Mileage <= Balance

    // 7. Earning Free Flight with Insufficient Balance
    assert(account2.canEarnFreeFlight(3000) == false); // Mileage > Balance

    // 8. Redeeming Free Flight
    PlaneFlight freeFlight("", "", "", 0, 2000); // Placeholder for the free flight
    assert(account2.freeFlight("LAX", "JFK", 2000, freeFlight) == true);
    assert(freeFlight.getName() == "James Lee");
    assert(freeFlight.getFromCity() == "LAX");
    assert(freeFlight.getToCity() == "JFK");
    assert(freeFlight.getCost() == 0);
    assert(freeFlight.getMileage() == 2000);
    assert(account2.getBalance() == 500); // Balance reduced by redeemed mileage

    // 9. Redeeming Free Flight with Insufficient Balance
    PlaneFlight insufficientFlight("", "", "", 0, 3000); // Placeholder for the free flight
    assert(account2.freeFlight("LAX", "JFK", 3000, insufficientFlight) == false); // Mileage > Balance

    // 10. Redeeming Free Flight with Invalid City Names
    PlaneFlight invalidCityFlight("", "", "", 0, 2000); // Placeholder for the free flight
    assert(account2.freeFlight("", "", 2000, invalidCityFlight) == false); // Empty city names
    assert(account2.freeFlight("LAX", "LAX", 2000, invalidCityFlight) == false); // Same city names

    // 11. Multiple Flights Adding to Account Balance
    PlaneFlight flight1("James Lee", "LAX", "JFK", 150.50, 2500);
    PlaneFlight flight2("James Lee", "JFK", "LAX", 150.50, 2500);
    assert(account2.addFlightToAccount(flight1) == true);
    assert(account2.addFlightToAccount(flight2) == true);
    assert(account2.getBalance() == 5500); // Total mileage accumulated from both flights

    // 12. Free Flight Redemptions Exhausting Account Balance
    assert(account2.freeFlight("LAX", "JFK", 5500, freeFlight) == true);
    assert(account2.getBalance() == 0); // Account balance exhausted
    
    cout << "All tests passed!" << endl;

    return 0;
}
