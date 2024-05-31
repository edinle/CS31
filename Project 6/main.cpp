//
//  main.cpp
//
//
#include <cassert>
#include <iostream>
#include "Beetle.h"
#include "BeetleGame.h"
#include "BeetleDrawing.h"
#include "Die.h"

using namespace std;

void clearScreen();

int main()
    {
             using namespace cs31;
             using namespace std;

//             // sample test code working with Die
//             Die d;
//             d.roll();
//             int value = d.getValue();
//             assert( value >= 1 && value <= 6 );
//
//             // sample test code working with Beetle
//             Beetle b;
//
//             // beetle does what you tell it to do, not enforce rules of the game.
//             // rules of the game are left to BeetleGame to implement
//
//             assert( b.hasHead() == false );
//             assert( b.isComplete() == false );
//             b.buildHead();
//             assert( b.hasHead() );
//             assert( b.isComplete() == false );
//
//             // build Leg1 before Leg2 before Leg3 before Leg4
//             assert( b.hasLeg1() == false );
//             assert( b.hasLeg2() == false );
//             assert( b.hasLeg3() == false );
//             assert( b.hasLeg4() == false );
//             assert( b.isComplete() == false );
//             b.buildLeg();
//             assert( b.hasLeg1() );
//             assert( b.hasLeg2() == false );
//             assert( b.hasLeg3() == false );
//             assert( b.hasLeg4() == false );
//             b.buildLeg();
//             assert( b.hasLeg1() );
//             assert( b.hasLeg2() );
//             assert( b.hasLeg3() == false );
//             assert( b.hasLeg4() == false );
//             b.buildLeg();
//             assert( b.hasLeg1() );
//             assert( b.hasLeg2() );
//             assert( b.hasLeg3() );
//             assert( b.hasLeg4() == false );
//             b.buildLeg();
//             assert( b.hasLeg1() );
//             assert( b.hasLeg2() );
//             assert( b.hasLeg3() );
//             assert( b.hasLeg4() );
//             assert( b.isComplete() == false );
//
//             // build Eye1 before Eye2
//             assert( b.hasEye1() == false );
//             assert( b.hasEye2() == false );
//             assert( b.isComplete() == false );
//             b.buildEye();
//             assert( b.hasEye1() );
//             assert( b.hasEye2() == false );
//             b.buildEye();
//             assert( b.hasEye1() );
//             assert( b.hasEye2() );
//             assert( b.isComplete() == false );
//
//             assert( b.hasTail() == false );
//             assert( b.isComplete() == false );
//             b.buildTail();
//             assert( b.hasTail() );
//             assert( b.isComplete() == false );
//
//             // build Antenna1 before Antenna2
//             assert( b.hasAntenna1() == false );
//             assert( b.hasAntenna2() == false );
//             assert( b.isComplete() == false );
//             b.buildAntenna();
//             assert( b.hasAntenna1() );
//             assert( b.hasAntenna2() == false );
//             b.buildAntenna();
//             assert( b.hasAntenna1() );
//             assert( b.hasAntenna2() );
//             assert( b.isComplete() == false );
//
//             assert( b.hasBody() == false );
//             assert( b.isComplete() == false );
//             b.buildBody();
//             assert( b.hasBody() );
//             assert( b.isComplete() == true );
//
//             // cheating play
//             BeetleGame game;
//             assert( game.gameIsOver() == false );
//             game.humanRoll( 1 );
//             game.humanPlay();
//             game.computerRoll( 1 );
//             game.computerPlay();
//             assert( game.getHumanBeetle().isComplete() == false );
//             assert( game.getHumanBeetle().hasBody() == false );
//             assert( game.getComputerBeetle().isComplete() == false );
//             assert( game.getComputerBeetle().hasBody() == false );
//             assert( game.gameIsOver() == false );
//             game.humanRoll( 6 );
//             game.humanPlay();
//             game.computerRoll( 6 );
//             game.computerPlay();
//             assert( game.getHumanBeetle().isComplete() == false );
//             assert( game.getHumanBeetle().hasBody() );
//             assert( game.getComputerBeetle().isComplete() == false );
//             assert( game.getComputerBeetle().hasBody() );
//
//             cout << "all tests passed!" << endl;
//             return( 0 );
//     }

//int main() {
//    
//    using namespace cs31;
//    using namespace std;
    
//    // Test Beetle class
//        Beetle b;
//
//        // Test building head
//        assert(b.hasHead() == false);
//        assert(b.isComplete() == false);
//        b.buildHead();
//        assert(b.hasHead()); // Test building the head
//        assert(b.isComplete() == false); // Beetle is not complete yet
//
//        // Test building legs
//        assert(b.hasLeg1() == false);
//        assert(b.hasLeg2() == false);
//        assert(b.hasLeg3() == false);
//        assert(b.hasLeg4() == false);
//        assert(b.isComplete() == false);
//        b.buildLeg();
//        assert(b.hasLeg1()); // Test building leg 1
//        assert(b.hasLeg2() == false);
//        assert(b.hasLeg3() == false);
//        assert(b.hasLeg4() == false);
//        b.buildLeg();
//        assert(b.hasLeg1());
//        assert(b.hasLeg2()); // Test building leg 2
//        assert(b.hasLeg3() == false);
//        assert(b.hasLeg4() == false);
//        b.buildLeg();
//        assert(b.hasLeg1());
//        assert(b.hasLeg2());
//        assert(b.hasLeg3()); // Test building leg 3
//        assert(b.hasLeg4() == false);
//        b.buildLeg();
//        assert(b.hasLeg1());
//        assert(b.hasLeg2());
//        assert(b.hasLeg3());
//        assert(b.hasLeg4()); // Test building leg 4
//        assert(b.isComplete() == false);
//
//        // Test building eyes
//        assert(b.hasEye1() == false);
//        assert(b.hasEye2() == false);
//        assert(b.isComplete() == false);
//        b.buildEye();
//        assert(b.hasEye1()); // Test building eye 1
//        assert(b.hasEye2() == false);
//        b.buildEye();
//        assert(b.hasEye1());
//        assert(b.hasEye2()); // Test building eye 2
//        assert(b.isComplete() == false);
//
//        // Test building tail
//        assert(b.hasTail() == false);
//        assert(b.isComplete() == false);
//        b.buildTail();
//        assert(b.hasTail()); // Test building tail
//        assert(b.isComplete() == false);
//
//        // Test building antenna
//        assert(b.hasAntenna1() == false);
//        assert(b.hasAntenna2() == false);
//        assert(b.isComplete() == false);
//        b.buildAntenna();
//        assert(b.hasAntenna1()); // Test building antenna 1
//        assert(b.hasAntenna2() == false);
//        b.buildAntenna();
//        assert(b.hasAntenna1());
//        assert(b.hasAntenna2()); // Test building antenna 2
//        assert(b.isComplete() == false);
//
//        // Test building body
//        assert(b.hasBody() == false);
//        assert(b.isComplete() == false);
//        b.buildBody();
//        assert(b.hasBody()); // Test building body
//        assert(b.isComplete() == true); // Beetle is complete now
//
//        // Test BeetleGame class
//        BeetleGame game;
//
//        // Test gameIsOver function when the game just started
//        assert(game.gameIsOver() == false);
//
//        // Test game progress with human and computer rolls
//        game.humanRoll(1);
//        game.humanPlay();
//        game.computerRoll(1);
//        game.computerPlay();
//        assert(game.getHumanBeetle().isComplete() == false);
//        assert(game.getHumanBeetle().hasBody() == false);
//        assert(game.getComputerBeetle().isComplete() == false);
//        assert(game.getComputerBeetle().hasBody() == false);
//        assert(game.gameIsOver() == false);
//
//        // Test game progress with more rolls and plays
//        game.humanRoll(6);
//        game.humanPlay();
//        game.computerRoll(6);
//        game.computerPlay();
//        assert(game.getHumanBeetle().isComplete() == false);
//        assert(game.getHumanBeetle().hasBody());
//        assert(game.getComputerBeetle().isComplete() == false);
//        assert(game.getComputerBeetle().hasBody());
//    
//           BeetleGame game2;
//           game2.computerRoll(0);
//           assert(game2.getComputerDie()>=1 && game2.getComputerDie()<=6);
//           //test to make sure cheating roll works for human die
//           game2.computerRoll(1);
//           assert(game2.getComputerDie()==1);
//           game2.computerRoll(5);
//           assert(game2.getComputerDie()==5);
//    
//           //test computerPlay when first roll is not 6, make sure body and bodypart associated with the roll are both not built
//           game2.computerRoll(1);
//           game2.computerRoll(2);
//           game2.computerRoll(3);
//           game2.computerRoll(4);
//           game2.computerRoll(5);
//           assert(game2.computerPlay()==false);
//           assert(game2.getComputerBeetle().hasBody()== false);
//           assert(game2.getComputerBeetle().hasEye1()== false);
//           assert(game2.getComputerBeetle().hasEye2()== false);
//           assert(game2.getComputerBeetle().hasTail()== false);
//           assert(game2.getComputerBeetle().hasHead()== false);
//           assert(game2.getComputerBeetle().hasLeg1()== false);
//           assert(game2.getComputerBeetle().hasLeg2()== false);
//           assert(game2.getComputerBeetle().hasLeg3()== false);
//           assert(game2.getComputerBeetle().hasLeg4()== false);
//           assert(game2.getComputerBeetle().hasAntenna1()== false);
//           assert(game2.getComputerBeetle().hasAntenna2()== false);
//           //test to make sure determineGameOutcome and gameIsOver determines that the game isn't over when all body parts aren't built
//           assert(game2.determineGameOutcome()==BeetleGame::GameOutcome::GAMENOTOVER);
//           assert(game2.gameIsOver()==false);
//    
//           //test computerPlay when roll is 6
//           game2.computerRoll(6);
//           assert(game2.computerPlay()==true);
//           assert(game2.getComputerBeetle().hasBody());
//           assert(game2.getComputerBeetle().hasEye1()== false);
//           assert(game2.getComputerBeetle().hasEye2()== false);
//           assert(game2.getComputerBeetle().hasTail()== false);
//           assert(game2.getComputerBeetle().hasHead()== false);
//           assert(game2.getComputerBeetle().hasLeg1()== false);
//           assert(game2.getComputerBeetle().hasLeg2()== false);
//           assert(game2.getComputerBeetle().hasLeg3()== false);
//           assert(game2.getComputerBeetle().hasLeg4()== false);
//           assert(game2.getComputerBeetle().hasAntenna1()== false);
//           assert(game2.getComputerBeetle().hasAntenna2()== false);
//           assert(game2.determineGameOutcome()==BeetleGame::GameOutcome::GAMENOTOVER);
//           assert(game2.gameIsOver()==false);
//    
//           //test to make sure computerRoll returns false when a body part is already built
//           game2.computerRoll(6);
//           assert(game2.computerPlay()==false);
//    
//           //test to make sure antenna and tail won't be built by computerPlay when only body is built
//           game2.computerRoll(2);
//           assert(game2.computerPlay()==false);
//           game2.computerRoll(1);
//           assert(game2.computerPlay()==false);
//           assert(game2.getComputerBeetle().hasBody());
//           assert(game2.determineGameOutcome()==BeetleGame::GameOutcome::GAMENOTOVER);
//           assert(game2.gameIsOver()==false);
//    
//           //test to make sure head will get built by computerPlay when a 5 is rolled
//           game2.computerRoll(5);
//           assert(game2.computerPlay());
//           assert(game2.getComputerBeetle().hasBody());
//           assert(game2.getComputerBeetle().hasHead());
//    
//           //test to make sure Leg1 and no other leg is built after rolling a 2
//           game2.computerRoll(3);
//           assert(game2.computerPlay());
//           assert(game2.getComputerBeetle().hasLeg1());
//           assert(game2.getComputerBeetle().hasLeg2()==false);
//           assert(game2.getComputerBeetle().hasLeg3()==false);
//           assert(game2.getComputerBeetle().hasLeg4()==false);
//    
//           //test to make sure Leg2 and no other is built after rolling a second 2
//           game2.computerRoll(3);
//           assert(game2.computerPlay());
//           assert(game2.getComputerBeetle().hasLeg1());
//           assert(game2.getComputerBeetle().hasLeg2());
//           assert(game2.getComputerBeetle().hasLeg3()==false);
//           assert(game2.getComputerBeetle().hasLeg4()==false);
//    
//           //test to make sure all legs but Leg4 are built after 3rd 2 roll
//           game2.computerRoll(3);
//           assert(game2.computerPlay());
//           assert(game2.getComputerBeetle().hasLeg1());
//           assert(game2.getComputerBeetle().hasLeg2());
//           assert(game2.getComputerBeetle().hasLeg3());
//           assert(game2.getComputerBeetle().hasLeg4()==false);
//    
//           //test to make sure all legs are built after 4th 2 roll
//           game2.computerRoll(3);
//           assert(game2.computerPlay());
//           assert(game2.getComputerBeetle().hasLeg1());
//           assert(game2.getComputerBeetle().hasLeg2());
//           assert(game2.getComputerBeetle().hasLeg3());
//           assert(game2.getComputerBeetle().hasLeg4());
//    
//           //test to make sure humanPlay returns false after trying a 5th 2 roll
//           assert(game2.computerPlay()==false);
//    
//           //test to make sure tail is not built before trying to build
//           assert(game2.getComputerBeetle().hasTail()==false);
//           game2.computerRoll(4);
//           //test to make sure tail is built when 4 is rolled
//           assert(game2.computerPlay());
//           assert(game2.getComputerBeetle().hasTail());
//    
//           //test to make sure Antenna1 and not Antenna2 are built after rolling a 2
//           game2.computerRoll(2);
//           assert(game2.computerPlay());
//           assert(game2.getComputerBeetle().hasAntenna1());
//           assert(game2.getComputerBeetle().hasAntenna2()==false);
//    
//           //test to make sure both antennas are built after second 2 roll
//           game2.computerRoll(2);
//           assert(game2.computerPlay());
//           assert(game2.getComputerBeetle().hasAntenna1());
//           assert(game2.getComputerBeetle().hasAntenna2());
//    
//           //test to make sure the game is determined to not be over if all body parts but the eyes are built
//           assert(game2.determineGameOutcome()==BeetleGame::GameOutcome::GAMENOTOVER);
//           assert(game2.gameIsOver()==false);
//    
//           //test to make sure Eye1 and not Eye2 are built after rolling a 1
//           game2.computerRoll(1);
//           assert(game2.computerPlay());
//           assert(game2.getComputerBeetle().hasEye1());
//           assert(game2.getComputerBeetle().hasEye2()==false);
//    
//           //test to make sure both eyes are built after second 2 roll
//           game2.computerRoll(1);
//           assert(game2.computerPlay());
//           assert(game2.getComputerBeetle().hasEye1());
//           assert(game2.getComputerBeetle().hasEye2());
//    
//           //test to make sure the game is determined to be over and won by computer when the computer's beetle is built
//           assert(game2.determineGameOutcome()==BeetleGame::GameOutcome::COMPUTERWONGAME);
//           assert(game2.gameIsOver());
//    
//    
//
//        cout << "All test cases passed!" << endl;
    
//    BeetleGame game2;
//
//        game2.humanRoll( 6 );
//        // this plays the Body of the human bug successfully
//        //checks throughout if the logic of BeetleGame works as intended
//        //checks if beetle also returns body parts correctly throughout
//        assert( game2.humanPlay( ) == true );
//        assert( !game2.getHumanBeetle().isComplete() ); // not complete
//
//        game2.humanRoll( 6 );
//        // this does not play the Body of the human bug successfully since this roll didn't accomplish that task
//        assert( game2.humanPlay( ) == false );
//    
//    game2.humanRoll(5);
//    assert( game2.humanPlay( ) == true );
//    game2.humanRoll(5);
//    assert( game2.humanPlay( ) == false );
    
    
//    Beetle b;
//
//                //test to see that it has no head starting out
//                 assert( b.hasHead() == false );
//                 assert( b.isComplete() == false );
//                 b.buildHead();
//                //test to make sure buildHead works properly and isComplete doesn't say the Beetle is built
//                 assert( b.hasHead() );
//                 assert( b.isComplete() == false );
//
//                 // test to see that all legs are false before testing building legs
//                 assert( b.hasLeg1() == false );
//                 assert( b.hasLeg2() == false );
//                 assert( b.hasLeg3() == false );
//                 assert( b.hasLeg4() == false );
//                 assert( b.isComplete() == false );
//                 b.buildLeg();
//                //test that first leg and no other legs are built after first call to buildLeg
//                 assert( b.hasLeg1() );
//                 assert( b.hasLeg2() == false );
//                 assert( b.hasLeg3() == false );
//                 assert( b.hasLeg4() == false );
//                 b.buildLeg();
//                //test that first and second leg and no other legs are built after 2nd buildLeg
//                 assert( b.hasLeg1() );
//                 assert( b.hasLeg2() );
//                 assert( b.hasLeg3() == false );
//                 assert( b.hasLeg4() == false );
//                 b.buildLeg();
//                //test that first, second, and third leg and no other legs are built after 3rd buildLeg
//                 assert( b.hasLeg1() );
//                 assert( b.hasLeg2() );
//                 assert( b.hasLeg3() );
//                 assert( b.hasLeg4() == false );
//                 b.buildLeg();
//                //test that all 4 legs are built after 4th buildLeg
//                 assert( b.hasLeg1() );
//                 assert( b.hasLeg2() );
//                 assert( b.hasLeg3() );
//                 assert( b.hasLeg4() );
//                //test to make sure isComplete works properly if all legs are built but not all body parts
//                 assert( b.isComplete() == false );
//
//                 // make sure eyes are not built before calling buildEye
//                 assert( b.hasEye1() == false );
//                 assert( b.hasEye2() == false );
//                 assert( b.isComplete() == false );
//                 b.buildEye();
//                //test to see that first eye is built but not 2nd eye after 1st call to builtEye
//                 assert( b.hasEye1() );
//                 assert( b.hasEye2() == false );
//                 b.buildEye();
//                //makes sure both eyes are built after 2 calls to buildEye
//                 assert( b.hasEye1() );
//                 assert( b.hasEye2() );
//                //test to make sure isComplete works properly if eyes are built but not all parts
//                 assert( b.isComplete() == false );
//                
//                //makes sure tail is not built before building tail
//                 assert( b.hasTail() == false );
//                 assert( b.isComplete() == false );
//                 b.buildTail();
//                //test to make sure tail is built after calling buildTail function
//                 assert( b.hasTail() );
//                //test to make sure isComplete works properly if tail is built but not all parts
//                 assert( b.isComplete() == false );
//
//                 // makes sure both antennas are not built before testing the build functions
//                 assert( b.hasAntenna1() == false );
//                 assert( b.hasAntenna2() == false );
//                 assert( b.isComplete() == false );
//                 b.buildAntenna();
//                //test to make sure first call to buildAntenna builds first antenna but not second
//                 assert( b.hasAntenna1() );
//                 assert( b.hasAntenna2() == false );
//                 b.buildAntenna();
//                //test to make sure second call to buildAntenna builds second antenna
//                 assert( b.hasAntenna1() );
//                 assert( b.hasAntenna2() );
//                //make sure beetle is not considered complete after antennas are built but not all body parts
//                 assert( b.isComplete() == false );
//                
//                //makes sure body is not built before trying to test building
//                 assert( b.hasBody() == false );
//                 assert( b.isComplete() == false );
//                 b.buildBody();
//                //test to see that body is built correctly after hasBuilt
//                 assert( b.hasBody() );
//                
//                //test to make sure isComplete returns true when all body parts are built
//                 assert( b.isComplete() == true );
//
//                 /**BeetleGame CLASS CODE TESTS**/
//                 BeetleGame game;
//                 
//                //test to make sure random roll works for human die
//                game.humanRoll(0);
//                assert(game.getHumanDie()>=1 && game.getHumanDie()<=6);
//                //test to make sure cheating roll works for human die
//                game.humanRoll(1);
//                assert(game.getHumanDie()==1);
//                game.humanRoll(5);
//                assert(game.getHumanDie()==5);
//            
//            //test humanPlay when first roll is not 6, make sure body and bodypart associated with the roll are both not built
//            game.humanRoll(1);
//            game.humanRoll(2);
//            game.humanRoll(3);
//            game.humanRoll(4);
//            game.humanRoll(5);
//            assert(game.humanPlay()==false);
//            assert(game.getHumanBeetle().hasBody()== false);
//            assert(game.getHumanBeetle().hasEye1()== false);
//            assert(game.getHumanBeetle().hasEye2()== false);
//            assert(game.getHumanBeetle().hasTail()== false);
//            assert(game.getHumanBeetle().hasHead()== false);
//            assert(game.getHumanBeetle().hasLeg1()== false);
//            assert(game.getHumanBeetle().hasLeg2()== false);
//            assert(game.getHumanBeetle().hasLeg3()== false);
//            assert(game.getHumanBeetle().hasLeg4()== false);
//            assert(game.getHumanBeetle().hasAntenna1()== false);
//            assert(game.getHumanBeetle().hasAntenna2()== false);
//            //test to make sure determineGameOutcome and gameIsOver determines that the game isn't over when all body parts aren't built
//            assert(game.determineGameOutcome()==BeetleGame::GameOutcome::GAMENOTOVER);
//            assert(game.gameIsOver()==false);
//            
//            //test humanPlay when roll is 6
//            game.humanRoll(6);
//            assert(game.humanPlay()==true);
//            assert(game.getHumanBeetle().hasBody());
//            assert(game.getHumanBeetle().hasEye1()== false);
//            assert(game.getHumanBeetle().hasEye2()== false);
//            assert(game.getHumanBeetle().hasTail()== false);
//            assert(game.getHumanBeetle().hasHead()== false);
//            assert(game.getHumanBeetle().hasLeg1()== false);
//            assert(game.getHumanBeetle().hasLeg2()== false);
//            assert(game.getHumanBeetle().hasLeg3()== false);
//            assert(game.getHumanBeetle().hasLeg4()== false);
//            assert(game.getHumanBeetle().hasAntenna1()== false);
//            assert(game.getHumanBeetle().hasAntenna2()== false);
//            assert(game.determineGameOutcome()==BeetleGame::GameOutcome::GAMENOTOVER);
//            assert(game.gameIsOver()==false);
//            
//            //test to make sure humanRoll returns false when a body part is already built
//            game.humanRoll(6);
//            assert(game.humanPlay()==false);
//            
//            //test to make sure antenna and tail won't be built by humanPlay when only body is built
//            game.humanRoll(2);
//            assert(game.humanPlay()==false);
//            game.humanRoll(1);
//            assert(game.humanPlay()==false);
//            assert(game.getHumanBeetle().hasBody());
//            assert(game.determineGameOutcome()==BeetleGame::GameOutcome::GAMENOTOVER);
//            assert(game.gameIsOver()==false);
//            
//            //test to make sure head will get built by humanPlay when a 5 is rolled
//            game.humanRoll(5);
//            assert(game.humanPlay());
//            assert(game.getHumanBeetle().hasBody());
//            assert(game.getHumanBeetle().hasHead());
//            
//            //test to make sure Leg1 and no other leg is built after rolling a 2
//            game.humanRoll(3);
//            assert(game.humanPlay());
//            assert(game.getHumanBeetle().hasLeg1());
//            assert(game.getHumanBeetle().hasLeg2()==false);
//            assert(game.getHumanBeetle().hasLeg3()==false);
//            assert(game.getHumanBeetle().hasLeg4()==false);
//            
//            //test to make sure Leg2 and no other is built after rolling a second 2
//            game.humanRoll(3);
//            assert(game.humanPlay());
//            assert(game.getHumanBeetle().hasLeg1());
//            assert(game.getHumanBeetle().hasLeg2());
//            assert(game.getHumanBeetle().hasLeg3()==false);
//            assert(game.getHumanBeetle().hasLeg4()==false);
//            
//            //test to make sure all legs but Leg4 are built after 3rd 2 roll
//            game.humanRoll(3);
//            assert(game.humanPlay());
//            assert(game.getHumanBeetle().hasLeg1());
//            assert(game.getHumanBeetle().hasLeg2());
//            assert(game.getHumanBeetle().hasLeg3());
//            assert(game.getHumanBeetle().hasLeg4()==false);
//            
//            //test to make sure all legs are built after 4th 2 roll
//            game.humanRoll(3);
//            assert(game.humanPlay());
//            assert(game.getHumanBeetle().hasLeg1());
//            assert(game.getHumanBeetle().hasLeg2());
//            assert(game.getHumanBeetle().hasLeg3());
//            assert(game.getHumanBeetle().hasLeg4());
//            
//            //test to make sure humanPlay returns false after trying a 5th 2 roll
//            assert(game.humanPlay()==false);
//            
//            //test to make sure tail is not built before trying to build
//            assert(game.getHumanBeetle().hasTail()==false);
//            game.humanRoll(4);
//            //test to make sure tail is built when 4 is rolled
//            assert(game.humanPlay());
//            assert(game.getHumanBeetle().hasTail());
//            
//            //test to make sure Antenna1 and not Antenna2 are built after rolling a 2
//            game.humanRoll(2);
//            assert(game.humanPlay());
//            assert(game.getHumanBeetle().hasAntenna1());
//            assert(game.getHumanBeetle().hasAntenna2()==false);
//            
//            //test to make sure both antennas are built after second 2 roll
//            game.humanRoll(2);
//            assert(game.humanPlay());
//            assert(game.getHumanBeetle().hasAntenna1());
//            assert(game.getHumanBeetle().hasAntenna2());
//            
//            //test to make sure the game is determined to not be over if all body parts but the eyes are built
//            assert(game.determineGameOutcome()==BeetleGame::GameOutcome::GAMENOTOVER);
//            assert(game.gameIsOver()==false);
//            
//            //test to make sure Eye1 and not Eye2 are built after rolling a 1
//            game.humanRoll(1);
//            assert(game.humanPlay());
//            assert(game.getHumanBeetle().hasEye1());
//            assert(game.getHumanBeetle().hasEye2()==false);
//            
//            //test to make sure both eyes are built after second 2 roll
//            game.humanRoll(1);
//            assert(game.humanPlay());
//            assert(game.getHumanBeetle().hasEye1());
//            assert(game.getHumanBeetle().hasEye2());
//            
//            //test to make sure the game is determined to be over and won by human when the human's beetle is built
//            assert(game.determineGameOutcome()==BeetleGame::GameOutcome::HUMANWONGAME);
//            assert(game.gameIsOver());
//            
//            
//            //TESTING Computer stuff
//            BeetleGame game2;
//            
//           //test to make sure random roll works for computer die
//           game2.computerRoll(0);
//           assert(game2.getComputerDie()>=1 && game2.getComputerDie()<=6);
//           //test to make sure cheating roll works for human die
//           game2.computerRoll(1);
//           assert(game2.getComputerDie()==1);
//           game2.computerRoll(5);
//           assert(game2.getComputerDie()==5);
//       
//       //test to make sure random roll works for computer die
//       game2.computerRoll(0);
//       assert(game2.getComputerDie()>=1 && game2.getComputerDie()<=6);
//       //test to make sure cheating roll works for human die
//       game2.computerRoll(1);
//       assert(game2.getComputerDie()==1);
//       game2.computerRoll(5);
//       assert(game2.getComputerDie()==5);
//       
//       //test computerPlay when first roll is not 6, make sure body and bodypart associated with the roll are both not built
//       game2.computerRoll(1);
//       game2.computerRoll(2);
//       game2.computerRoll(3);
//       game2.computerRoll(4);
//       game2.computerRoll(5);
//       assert(game2.computerPlay()==false);
//       assert(game2.getComputerBeetle().hasBody()== false);
//       assert(game2.getComputerBeetle().hasEye1()== false);
//       assert(game2.getComputerBeetle().hasEye2()== false);
//       assert(game2.getComputerBeetle().hasTail()== false);
//       assert(game2.getComputerBeetle().hasHead()== false);
//       assert(game2.getComputerBeetle().hasLeg1()== false);
//       assert(game2.getComputerBeetle().hasLeg2()== false);
//       assert(game2.getComputerBeetle().hasLeg3()== false);
//       assert(game2.getComputerBeetle().hasLeg4()== false);
//       assert(game2.getComputerBeetle().hasAntenna1()== false);
//       assert(game2.getComputerBeetle().hasAntenna2()== false);
//       //test to make sure determineGameOutcome and gameIsOver determines that the game isn't over when all body parts aren't built
//       assert(game2.determineGameOutcome()==BeetleGame::GameOutcome::GAMENOTOVER);
//       assert(game2.gameIsOver()==false);
//       
//       //test computerPlay when roll is 6
//       game2.computerRoll(6);
//       assert(game2.computerPlay()==true);
//       assert(game2.getComputerBeetle().hasBody());
//       assert(game2.getComputerBeetle().hasEye1()== false);
//       assert(game2.getComputerBeetle().hasEye2()== false);
//       assert(game2.getComputerBeetle().hasTail()== false);
//       assert(game2.getComputerBeetle().hasHead()== false);
//       assert(game2.getComputerBeetle().hasLeg1()== false);
//       assert(game2.getComputerBeetle().hasLeg2()== false);
//       assert(game2.getComputerBeetle().hasLeg3()== false);
//       assert(game2.getComputerBeetle().hasLeg4()== false);
//       assert(game2.getComputerBeetle().hasAntenna1()== false);
//       assert(game2.getComputerBeetle().hasAntenna2()== false);
//       assert(game2.determineGameOutcome()==BeetleGame::GameOutcome::GAMENOTOVER);
//       assert(game2.gameIsOver()==false);
//       
//       //test to make sure computerRoll returns false when a body part is already built
//       game2.computerRoll(6);
//       assert(game2.computerPlay()==false);
//       
//       //test to make sure antenna and tail won't be built by computerPlay when only body is built
//       game2.computerRoll(2);
//       assert(game2.computerPlay()==false);
//       game2.computerRoll(1);
//       assert(game2.computerPlay()==false);
//       assert(game2.getComputerBeetle().hasBody());
//       assert(game2.determineGameOutcome()==BeetleGame::GameOutcome::GAMENOTOVER);
//       assert(game2.gameIsOver()==false);
//       
//       //test to make sure head will get built by computerPlay when a 5 is rolled
//       game2.computerRoll(5);
//       assert(game2.computerPlay());
//       assert(game2.getComputerBeetle().hasBody());
//       assert(game2.getComputerBeetle().hasHead());
//       
//       //test to make sure Leg1 and no other leg is built after rolling a 2
//       game2.computerRoll(3);
//       assert(game2.computerPlay());
//       assert(game2.getComputerBeetle().hasLeg1());
//       assert(game2.getComputerBeetle().hasLeg2()==false);
//       assert(game2.getComputerBeetle().hasLeg3()==false);
//       assert(game2.getComputerBeetle().hasLeg4()==false);
//       
//       //test to make sure Leg2 and no other is built after rolling a second 2
//       game2.computerRoll(3);
//       assert(game2.computerPlay());
//       assert(game2.getComputerBeetle().hasLeg1());
//       assert(game2.getComputerBeetle().hasLeg2());
//       assert(game2.getComputerBeetle().hasLeg3()==false);
//       assert(game2.getComputerBeetle().hasLeg4()==false);
//       
//       //test to make sure all legs but Leg4 are built after 3rd 2 roll
//       game2.computerRoll(3);
//       assert(game2.computerPlay());
//       assert(game2.getComputerBeetle().hasLeg1());
//       assert(game2.getComputerBeetle().hasLeg2());
//       assert(game2.getComputerBeetle().hasLeg3());
//       assert(game2.getComputerBeetle().hasLeg4()==false);
//       
//       //test to make sure all legs are built after 4th 2 roll
//       game2.computerRoll(3);
//       assert(game2.computerPlay());
//       assert(game2.getComputerBeetle().hasLeg1());
//       assert(game2.getComputerBeetle().hasLeg2());
//       assert(game2.getComputerBeetle().hasLeg3());
//       assert(game2.getComputerBeetle().hasLeg4());
//       
//       //test to make sure humanPlay returns false after trying a 5th 2 roll
//       assert(game2.computerPlay()==false);
//       
//       //test to make sure tail is not built before trying to build
//       assert(game2.getComputerBeetle().hasTail()==false);
//       game2.computerRoll(4);
//       //test to make sure tail is built when 4 is rolled
//       assert(game2.computerPlay());
//       assert(game2.getComputerBeetle().hasTail());
//       
//       //test to make sure Antenna1 and not Antenna2 are built after rolling a 2
//       game2.computerRoll(2);
//       assert(game2.computerPlay());
//       assert(game2.getComputerBeetle().hasAntenna1());
//       assert(game2.getComputerBeetle().hasAntenna2()==false);
//       
//       //test to make sure both antennas are built after second 2 roll
//       game2.computerRoll(2);
//       assert(game2.computerPlay());
//       assert(game2.getComputerBeetle().hasAntenna1());
//       assert(game2.getComputerBeetle().hasAntenna2());
//       
//       //test to make sure the game is determined to not be over if all body parts but the eyes are built
//       assert(game2.determineGameOutcome()==BeetleGame::GameOutcome::GAMENOTOVER);
//       assert(game2.gameIsOver()==false);
//       
//       //test to make sure Eye1 and not Eye2 are built after rolling a 1
//       game2.computerRoll(1);
//       assert(game2.computerPlay());
//       assert(game2.getComputerBeetle().hasEye1());
//       assert(game2.getComputerBeetle().hasEye2()==false);
//       
//       //test to make sure both eyes are built after second 2 roll
//       game2.computerRoll(1);
//       assert(game2.computerPlay());
//       assert(game2.getComputerBeetle().hasEye1());
//       assert(game2.getComputerBeetle().hasEye2());
//       
//       //test to make sure the game is determined to be over and won by computer when the computer's beetle is built
//       assert(game2.determineGameOutcome()==BeetleGame::GameOutcome::COMPUTERWONGAME);
//       assert(game2.gameIsOver());
            

    clearScreen();
    
    BeetleGame game;
    std::string action, spots, message = "(r)oll (q)uit: ";

    
    do {
        cout << game.display( message ) << endl;
        cin.clear();
        getline( cin, action );
        while (action.size() == 0) {
            getline( cin, action );  // no blank entries allowed....
        } switch (action[0]) {
            default:   // if bad move, nobody moves
                cout << '\a' << endl;  // beep
                continue;
            case 'Q':
            case 'q':
                exit( 0 );
                break;
            case 'r':
            case 'R':
                game.humanRoll();
                cout << "human rolled:" << game.getHumanDie() << endl;
                if (game.humanPlay( )) {
                    
                } else {
                    cout << "no Human move possible!" << endl;
                }
                    game.computerRoll();
                    cout << "computer rolled:" << game.getComputerDie() << endl;
                if (game.computerPlay()) {
                    
                } else {
                    cout << "no Computer move possible!" << endl;
                }
                break;
        }
    } while(!game.gameIsOver());
    cout << game.display( ) << endl;
    cout << game.stringifyGameOutcome() << endl;

    return( 0 );
}



void clearScreen();



///////////////////////////////////////////////////////////////////////////
//  clearScreen implementations
///////////////////////////////////////////////////////////////////////////

// DO NOT MODIFY OR REMOVE ANY CODE BETWEEN HERE AND THE END OF THE FILE!!!
// THE CODE IS SUITABLE FOR VISUAL C++, XCODE, AND g++ UNDER LINUX.

// Note to Xcode users:  clearScreen() will just write a newline instead
// of clearing the window if you launch your program from within Xcode.
// That's acceptable.

#ifdef _MSC_VER  //  Microsoft Visual C++

#include <windows.h>

void clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    DWORD dwConSize = csbi.dwSize.X * csbi.dwSize.Y;
    COORD upperLeft = { 0, 0 };
    DWORD dwCharsWritten;
    FillConsoleOutputCharacter(hConsole, TCHAR(' '), dwConSize, upperLeft,
                               &dwCharsWritten);
    SetConsoleCursorPosition(hConsole, upperLeft);
}

#else  // not Microsoft Visual C++, so assume UNIX interface

#include <cstring>

void clearScreen()  // will just write a newline in an Xcode output window
{
    using namespace std;
    static const char* term = getenv("TERM");
    if (term == nullptr  ||  strcmp(term, "dumb") == 0)
    {
        cout << endl << endl << endl << endl << endl << endl << endl << endl;
    }
    else
    {
        static const char* ESC_SEQ = "\x1B[";  // ANSI Terminal esc seq:  ESC [
        cout << ESC_SEQ << "2J" << ESC_SEQ << "H" << flush;
    }
}

#endif
