//
//  BeetleGame.cpp
//

#include "BeetleGame.h"
#include "BeetleDrawing.h"

#include <iostream>

namespace cs31
{

BeetleGame::BeetleGame() : mHuman(), mComputer(), mHumanDie(), mComputerDie()
{
    
}

// draw the board by using a BeetleDrawing to draw the two Beetles
std::string BeetleGame::display(std::string msg) const
{
    BeetleDrawing drawing( mHuman, mComputer );
    std::string result = drawing.draw() + "\n" + msg;
    return( result );
}


// TODO when amount is zero, it is a random roll...
// otherwise, an amount value is a cheating value...
void BeetleGame::humanRoll( int amount )
{
    // if the amount is zero, roll the Human's die
    // otherwise, cheat by forcing the amount into the Human's die
    if (amount == 0) {
        mHumanDie.roll();
    } else {
        mHumanDie.setValue(amount);
    }
}

// TODO return the value of the Human's die
int BeetleGame::getHumanDie( ) const
{
    return mHumanDie.getValue();
}

// TODO convert the Human's die value to a Beetle's body part
// then depending on the body part involved, enforce the game ordering of body parts:
// - namely, body before everything else and head before eyes or antenna
// if allowed, build the desired body part on the Human's beetle
// if a body part was successfully built, return true
// otherwise, return false
bool BeetleGame::humanPlay( )
{
    Beetle::BodyPart value = mHuman.convertRollToBodyPart(mHumanDie.getValue());
    switch (value) {
        case Beetle::BodyPart::BODY :
            if (!mHuman.hasBody()) {
                mHuman.buildBody();
                return true;
            } else {
                return false;
            }
            break;
        case Beetle::BodyPart::HEAD :
            if (mHuman.hasBody() && !mHuman.hasHead()) {
                mHuman.buildHead();
                return true;
            } else {
                return false;
            }
            break;
        case Beetle::BodyPart::LEG :
            if (mHuman.hasLeg4()) {
                return false;
                break;
            }
            
            if (mHuman.hasBody()) {
                mHuman.buildLeg();
                return true;
            } else {
                return false;
            }
            break;
        case Beetle::BodyPart::TAIL :
            if (mHuman.hasBody() && !mHuman.hasTail()) {
                mHuman.buildTail();
                return true;
            } else {
                return false;
            }
            break;
        case Beetle::BodyPart::ANTENNA :
            if (mHuman.hasAntenna2()) {
                return false;
                break;
            }
            
            if (mHuman.hasHead()) {
                mHuman.buildAntenna();
                return true;
            } else {
                return false;
            }
            break;
        case Beetle::BodyPart::EYE :
            if (mHuman.hasEye2()) {
                return false;
                break;
            }
            
            if (mHuman.hasHead()) {
                mHuman.buildEye();
                return true;
            } else {
                return false;
            }
            break;
        case Beetle::BodyPart::NOTVALID :
            break;
    }
    return false;
}

// TODO when amount is zero, it is a random roll...
// otherwise, an amount value is a cheating value...
void BeetleGame::computerRoll( int amount )
{
    // if the amount is zero, roll the Computer's die
    // otherwise, cheat by forcing the amount into the Computer's die
    if (amount == 0) {
        mComputerDie.roll();
    } else {
        mComputerDie.setValue(amount);
    }
}

// TODO return the value of the Computer's die
int BeetleGame::getComputerDie( ) const
{
    return mComputerDie.getValue();
}

// TODO convert the Computer's die value to a Beetle's body part
// then depending on the body part involved, enforce the game ordering of body parts:
// - namely, body before everything else and head before eyes or antenna
// if allowed, build the desired body part on the Computer's beetle
// if a body part was successfully built, return true
// otherwise, return false
bool BeetleGame::computerPlay( )
{
    Beetle::BodyPart value = mComputer.convertRollToBodyPart(mComputerDie.getValue());
    bool result = false;
    switch (value) {
        case Beetle::BodyPart::BODY :
            if (!mComputer.hasBody()) {
                mComputer.buildBody();
                return true;
            }
            break;
        case Beetle::BodyPart::HEAD :
            if (mComputer.hasBody() && !mComputer.hasHead()) {
                mComputer.buildHead();
                return true;
            } else {
                return false;
            }
            break;
        case Beetle::BodyPart::LEG :
            if (mComputer.hasLeg4()) {
                return false;
                break;
            }
            
            if (mComputer.hasBody()) {
                mComputer.buildLeg();
                return true;
            } else {
                return false;
            }
            break;
        case Beetle::BodyPart::TAIL :
            if (mComputer.hasBody()) {
                mComputer.buildTail();
                return true;
            } else {
                return false;
            }
            break;
        case Beetle::BodyPart::ANTENNA :
            if (mComputer.hasAntenna2()) {
                return false;
                break;
            }
            
            if (mComputer.hasHead()) {
                mComputer.buildAntenna();
                return true;
            } else {
                return false;
            }
            break;
        case Beetle::BodyPart::EYE :
            if (mComputer.hasEye2()) {
                return false;
                break;
            }
            
            if (mComputer.hasHead()) {
                mComputer.buildEye();
                return true;
            } else {
                return false;
            }
            break;
        case Beetle::BodyPart::NOTVALID :
            break;
    }
    return result;
}

// TODO what is the current state of the game
BeetleGame::GameOutcome  BeetleGame::determineGameOutcome( ) const
{
    if (mHuman.isComplete()) {
        return (GameOutcome::HUMANWONGAME);
    } else if (mComputer.isComplete()) {
        return (GameOutcome::COMPUTERWONGAME);
    } else {
        return (GameOutcome::GAMENOTOVER);
    }
}

std::string  BeetleGame::stringifyGameOutcome( ) const
{
    std::string result = "";
    switch( determineGameOutcome() )
    {
        case GameOutcome::COMPUTERWONGAME:
            result = "Computer Won!";
            break;
        case GameOutcome::HUMANWONGAME:
            result = "Human Won!";
            break;
        case GameOutcome::GAMENOTOVER:
            result = "Game Not Over!";
            break;
    }
    return( result );
}

// TODO has the game ended with a winner?
bool BeetleGame::gameIsOver() const
{
    if (mHuman.isComplete() || mComputer.isComplete()) {
        return true;
    } else {
        return false;
    }
}


Beetle BeetleGame::getHumanBeetle( ) const
{
    return( mHuman );
}

Beetle BeetleGame::getComputerBeetle( ) const
{
    return( mComputer );
}

}


