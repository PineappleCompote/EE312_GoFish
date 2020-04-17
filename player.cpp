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
	//if new card makes a pair, add to book and remove old card from hand
	if(rankInHand(c)){
		for(int i = 0; i < myHand.size(); i++){
			if(myHand[i].getRank() == c.getRank()){
				bookCards(c, myHand[i]);
				removeCardFromHand(myHand[i]);
			}
		}
	}

	else
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
 	srand(time(0)); 
	int ind = rand() % myHand.size();   
	return  myHand[ind];
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
            myHand.erase(myHand.begin()+ i);//I think it should be +i instead of +(i-1)
            return returnCard;
        }
    }
}

string Player::showHand() const{
	string ret = "";
	if(!myHand.empty()){
		for(int i = 0; i < myHand.size(); i++)
			 ret += myHand.at(i).toString() + " ";
	}
	return ret + "\n";
}

string Player::showBooks() const{
	string ret = "";
	if(!myBook.empty()){
		for(int i = 0; i < myBook.size(); i++)
			ret += myBook[i].toString() + " ";
	}
	return ret + "\n";	
}

int Player::getHandSize() const{
	return myHand.size();
}

int Player::getBookSize() const{
	return myBook.size();
}





