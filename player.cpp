/*
 * player.cpp
 * Teddy Hsieh and Dilya Anvarbekova
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include "card.h"
#include "player.h"

using namespace std;

Player::Player() {
    myName = "Player1";
}

void Player::addCard(Card c) {
    myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2) {
    myBook.push_back(c1);
    myBook.push_back(c2);
}

bool Player::checkHandForBook(Card &c1, Card &c2) {
    for(int i = 0 ; i < myHand.size(); i++){
        for(int j = 0; j < myHand.size(); j++){
            if(i != j){
                if(myHand[i].getRank() == myHand[j].getRank()){
                    c1 = myHand[i];
                    c2 = myHand[j];
                    return true;
                }
            }
        }
    }
    return false;
}

// NOT SURE WHAT THE DIFFERENCE BETWEEN rankInHand and cardInHand is
// Don't we only check for the rank anyway?

bool Player::rankInHand(Card c) const {
    for(int i = 0; i < myHand.size(); i++){
        if(myHand[i].getRank() == c.getRank()){
            return true;
        }
    }
    return false;
}

// TODO: Come up with a strategy for this function (is there a way to guess what the other players have?)

Card Player::chooseCardFromHand() const {
    Card c = myHand[0];
}

bool Player::cardInHand(Card c) const {
    for(int i = 0; i < myHand.size(); i++){
        if(myHand[i] == c){
            return true;
        }
    }
    return false;
}

Card Player::removeCardFromHand(Card c) {
    Card returnCard;
    for(int i = 0; i < myHand.size(); i++){
        if(myHand[i] == c){
            returnCard = myHand[i];
            myHand.erase(myHand.begin()+(i-1));
            return returnCard;
        }
    }
}
