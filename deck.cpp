/*
 * deck.cpp
 * Teddy Hsieh and Dilya Anvarbekova
 *
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
#include "deck.h"

using namespace std;

Deck::Deck(){
    int rank = 1;
    Card::Suit suit = Card::spades;
    myIndex = 0;
    for(int i = 0; i < SIZE; i++){
        if(i == 13){
            suit = Card::diamonds;
        }
        else if(i == 26){
            suit = Card::clubs;
        }
        else if(i == 39){
            suit = Card::hearts;
        }
        myCards[i] = Card(rank, suit);
        rank = (rank+1) % 14;
        if(rank == 0){
            rank = 1;
        }
    }
}

int Deck::size() const {
    return SIZE - (myIndex);
}

Card Deck::dealCard() {
    Card deal = myCards[myIndex];
    myIndex += 1;
    return deal;
}

//resets the deck into random order
//note this changes deck size back to 52
void Deck::shuffle() {
    myIndex = 0;
    Card temp;
    srand(time(0));
    for(int i = 0; i < SIZE - 2; i++){
        int j = rand() % (SIZE - i) + i;
        temp = myCards[i];
        myCards[i] = myCards[j];
        myCards[j] = temp;
    }
}
