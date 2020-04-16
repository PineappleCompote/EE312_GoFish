// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

int main(){

    cout << "Testing Card class..." << endl;
    Card c0 = Card();
    Card c1 = Card(5, Card::hearts);
    Card c2 = Card(11, Card::diamonds);
    Card c3 = Card(12, Card::spades);
    Card c4 = Card(8, Card::clubs);
    Card c5 = Card();

    cout << "Card 1: " << c0.toString() << endl;
    cout << "Card 2: " << c1.toString() << endl;
    cout << "Card 3: " << c2.toString() << endl;
    cout << "Card 4: " << c3.toString() << endl;
    cout << "Card 5: " << c4.toString() << endl;
    cout << "Card 6: " << c5.toString() << endl;

    cout << "Are card 1 and card 2 the same? " << (c0 == c1) << endl;
    cout << "Are card 1 and card 6 the same? " << (c0 == c5) << endl;
    cout << "Are card 3 and card 4 the same? " << (c2 == c3) << endl;

    cout << "Are card 4 and card 6 the same suit? " << c3.sameSuitAs(c5) << endl;
    cout << "Are card 1 and card 6 the same suit? " << c0.sameSuitAs(c5) << endl;
    cout << "Are card 2 and card 4 the same suit? " << c1.sameSuitAs(c3) << endl;

    cout << "Card 1 rank: " << c0.rankString(c0.getRank()) << endl << endl;

    cout << "Testing Deck class..." << endl;
    Deck d0 = Deck();
    cout << "Deck size is " << d0.size() << endl;
    cout << "Dealing the sorted deck..." << endl;
    for(int i = 0; i < 52; i++){
        cout << "Card: " << d0.dealCard().toString() << " Num cards left: " << d0.size() << endl;
    }

    cout << endl;
    cout << "Shuffle cards..." << endl;
    d0.shuffle();
    for(int i = 0; i < 52; i++){
        cout << "Card: " << d0.dealCard().toString() << " Num cards left: " << d0.size() << endl;
    }
}
