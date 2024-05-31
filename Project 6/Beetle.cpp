//
//  Beetle.cpp
//
//

#include "Beetle.h"

namespace cs31
{

Beetle::Beetle()
{
    mBody = false;
    mTail = false;
    mLeg1 = false;
    mLeg2 = false;
    mLeg3 = false;
    mLeg4 = false;
    mHead = false;
    mEye1 = false;
    mEye2 = false;
    mAntenna1 = false;
    mAntenna2 = false;
}

// convert a tossed die value into a BodyPart
Beetle::BodyPart Beetle::convertRollToBodyPart( int die ) const
{
    // if not matching, then return NOTVALID
    BodyPart part = BodyPart::NOTVALID;
    if (die == 6)
        part = BodyPart::BODY;
    if (die == 5)
        part = BodyPart::HEAD;
    if (die == 4)
        part = BodyPart::TAIL;
    if (die == 3)
        part = BodyPart::LEG;
    if (die == 2)
        part = BodyPart::ANTENNA;
    if (die == 1)
        part = BodyPart::EYE;
    return( part );
}

// build the Beetle's body
void Beetle::buildBody()
{
    mBody = true;
}

// has the Beetle's body been built?
bool Beetle::hasBody() const
{
    if (mBody == true) {
        return true;
    } else {
        return false;
    }
}

// build the Beetle's tail but only if the body has already been built
void Beetle::buildTail()
{
    mTail = true;
}

// has the Beetle's tail been built?
bool Beetle::hasTail() const
{
    if (mTail == true) {
        return true;
    } else {
        return false;
    }
}

// build the Beetle's leg but only if the body has already been built
void Beetle::buildLeg()
{
    if (!mLeg1) {
        mLeg1 = true;
    } else if (!mLeg2) {
        mLeg2 = true;
    } else if (!mLeg3) {
        mLeg3 = true;
    } else if (!mLeg4) {
        mLeg4 = true;
    }
}

// has the Beetle's leg been built?
bool Beetle::hasLeg1() const
{
    if (mLeg1 == true) {
        return true;
    } else {
        return false;
    }
}

bool Beetle::hasLeg2() const
{
    if (mLeg2 == true) {
        return true;
    } else {
        return false;
    }
}

bool Beetle::hasLeg3() const
{
    if (mLeg3 == true) {
        return true;
    } else {
        return false;
    }
}

bool Beetle::hasLeg4() const
{
    if (mLeg4 == true) {
        return true;
    } else {
        return false;
    }
}

// build the Beetle's head but only if the body has already been built
void Beetle::buildHead()
{
    mHead = true;
}

// has the Beetle's head been built?
bool Beetle::hasHead() const
{
    if (mHead == true) {
        return true;
    } else {
        return false;
    }
}

// build the Beetle's eye but only if the head has already been built
void Beetle::buildEye()
{
    if (!mEye1) {
        mEye1 = true;
    } else if (!mEye2) {
        mEye2 = true;
    }
}

// has the Beetle's eye been built?
bool Beetle::hasEye1() const
{
    if (mEye1 == true) {
        return true;
    } else {
        return false;
    }
}

bool Beetle::hasEye2() const
{
    if (mEye2 == true) {
        return true;
    } else {
        return false;
    }
}

// build the Beetle's antenna but only if the head has already been built
void Beetle::buildAntenna()
{
    if (!mAntenna1) {
        mAntenna1 = true;
    } else if (!mAntenna2) {
        mAntenna2 = true;
    }
}

// has the Beetle's antenna been built?
bool Beetle::hasAntenna1() const
{
    if (mAntenna1 == true) {
        return true;
    } else {
        return false;
    }
}

bool Beetle::hasAntenna2() const
{
    if (mAntenna2 == true) {
        return true;
    } else {
        return false;
    }
}


// is this Beetle completely built out?
bool Beetle::isComplete() const
{
    if (mBody == true &&
        mTail == true &&
        mLeg1 == true && mLeg2 == true && mLeg3 == true && mLeg4 == true &&
        mHead == true &&
        mEye1 == true && mEye2 == true &&
        mAntenna1 == true && mAntenna2 == true) {
        return true;
    } else {
        return false;
    }
}


}


