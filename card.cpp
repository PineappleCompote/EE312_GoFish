
// card.cpp
// Teddy Hsieh and Dilya Anvarbekova
//

#include <iostream>
#include <cstdlib>
#include <string>
#include "card.h"

using namespace std;

Card::Card(){
    myRank = 1;
    mySuit = spades;
}

Card::Card(int rank, Suit s){
    myRank = rank;
    mySuit = s;
}

string Card::toString() const {
    string strCard;

    if((myRank > 1) && (myRank < 11)){
        strCard = to_string(myRank);
    }
    else if (myRank == 1){
        strCard = 'A';
    }
    else if (myRank == 11){
        strCard = 'J';
    }
    else if (myRank == 12){
        strCard = 'Q';
    }
    else if (myRank == 13){
        strCard = 'K';
    }

    if(mySuit == spades){
        strCard += 's';
    }
    else if(mySuit == hearts){
        strCard += 'h';
    }
    else if(mySuit == diamonds){
        strCard += 'd';
    }
    else{
        strCard += 'c';
    }

    return strCard;
}

bool Card::sameSuitAs(const Card &c) const {
    return (mySuit == c.mySuit);
}

int Card::getRank() const {
    return myRank;
}

string Card::suitString(Suit s) const {
    string suit;

    if (s == spades){
        suit = 's';
    }
    else if(s == hearts){
        suit = 'h';
    }
    else if(s == diamonds){
        suit = 'd';
    }
    else{
        suit = 'c';
    }

    return suit;
}

string Card::rankString(int r) const {
    string rank;
    if((r > 1) && (r < 11)){
        rank = to_string(r);
    }
    else if(r == 1){
        rank = 'A';
    }
    else if(r == 11){
        rank = 'J';
    }
    else if(r == 12){
        rank = 'Q';
    }
    else{
        rank = 'K';
    }
    return rank;
}

bool Card::operator==(const Card &rhs) const {
    if(myRank == rhs.myRank){
        if(mySuit == rhs.mySuit){
            return true;
        }
    }

    return false;
}

bool Card::operator!=(const Card &rhs) const {
    if(myRank == rhs.myRank){
        if(mySuit == rhs.mySuit){
            return false;
        }
    }

    return true;
}