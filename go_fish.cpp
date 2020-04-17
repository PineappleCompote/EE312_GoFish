// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <fstream>
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

void gameOver(ofstream& out, Player p1, Player p2){
	out << "Game over!\n";
	
	out << p1.getName() << "'s books are: ";
	out << p1.showBooks();
	out << p2.getName() << "'s books are: ";
	out << p2.showBooks();
	out << endl;

	if(p1.getBookSize() > p2.getBookSize()){
		out << p1.getName() << " won with " << p1.getBookSize() << " books!\n";
		out << p2.getName() << " only had " << p2.getBookSize() << " books.\n";
	}
	else if(p2.getBookSize() > p1.getBookSize()){
		out << p2.getName() << " won with " << p2.getBookSize() << " books!\n";
		out << p1.getName() << " only had " << p1.getBookSize() << " books.\n";
	}
	else
		out << "It's a tie!\n";  
}

int main(){
	ofstream out;
	out.open("gofish_results.txt");
	Player p1 = Player("Alice");
	Player p2 = Player("Ben");

	Deck d = Deck();
	d.shuffle();

	for(int i = 0; i < 7; i++){
		p1.addCard(d.dealCard());
		p2.addCard(d.dealCard());
	}

	out << p1.getName() << "'s initial hand: " << p1.showHand();
	out << p1.getName() << "'s initial books: " << p1.showBooks();
	out << p2.getName() << "'s initial hand: " << p2.showHand();
	out << p2.getName() << "'s initial books: " << p2.showBooks();
	out << endl;

	Card check[4];
	bool GameOver = false;
	while(!GameOver){
		//p1's turn
		while(!GameOver){
			if(p1.getHandSize() == 0){
				//if one player is out of cards and there are no cards left in deck
				//all pairs must have been formed
				if(d.size() > 0){
					Card draw = d.dealCard();
					p1.addCard(draw);
					out << p1.getName() << " ran out of cards and drew " << draw.toString() << ".\n";
				}
				else{
					out << "Deck is out of Cards!\n";
					GameOver = true;
					gameOver(out, p1, p2);
				}
				break;
			}

			Card choice1 = p1.chooseCardFromHand();
			out << p1.getName() << " asks, \"" << p2.getName() << ", do you have a " << choice1.getRank() << "?\"\n";
			if(p2.rankInHand(choice1)){
				out << p2.getName() << " answers, \"yes, I do.\"\n";
				check[0] = Card(choice1.getRank(), Card::spades);
				check[1] = Card(choice1.getRank(), Card::diamonds);
				check[2] = Card(choice1.getRank(), Card::clubs);
				check[3] = Card(choice1.getRank(), Card::hearts);
				for(int i = 0; i < 4; i++){
					if(p2.cardInHand(check[i])){
						p2.removeCardFromHand(check[i]);
						p1.addCard(check[i]);
						out << p2.getName() << " handed over " << check[i].toString() << ".\n";
					}
				}
			
				out << p1.getName() << " current books: " << p1.showBooks() << endl;
			}

			else{
				out<< p2.getName() << " answers, \"Go Fish!\"\n";
				if(d.size() > 0){
					Card dealt = d.dealCard();
					p1.addCard(dealt);
					out << p1.getName() << " drew " << dealt.toString() << ".\n";
				}
				else
					out << "Deck is out of cards!\n";
				break; 
			}
		}
		out << endl;

		//p2's turn -> the same as p1 turn but with players switched
		while(!GameOver){
			if(p2.getHandSize() == 0){
				if(d.size() > 0){
					Card draw = d.dealCard();
					p2.addCard(draw);
					out << p2.getName() << " ran out of cards and drew " << draw.toString() << ".\n";
				}
				else{
					out << "Deck is out of cards!\n";
					GameOver = true;
					gameOver(out, p1, p2);
				}
				break;
			}

			Card choice2 = p2.chooseCardFromHand();
			out << p2.getName() << " asks, \"" << p1.getName() << ", do you have a " << choice2.getRank() << "?\"\n";
			if(p1.rankInHand(choice2)){
				out << p1.getName() << " answers, \"yes, I do.\"\n";
				check[0] = Card(choice2.getRank(), Card::spades);
				check[1] = Card(choice2.getRank(), Card::diamonds);
				check[2] = Card(choice2.getRank(), Card::clubs);
				check[3] = Card(choice2.getRank(), Card::hearts);
				for(int i = 0; i < 4; i++){
					if(p1.cardInHand(check[i])){
						p1.removeCardFromHand(check[i]);
						p2.addCard(check[i]);
						out << p1.getName() << " handed over " << check[i].toString() << ".\n";
					}
				}
			
				out << p2.getName() << " current books: " << p2.showBooks() << endl;
			}

			else{
				out<< p1.getName() << " answers, \"Go Fish!\"\n";
				if(d.size() > 0){
					Card dealt = d.dealCard();
					p2.addCard(dealt);
					out << p2.getName() << " drew " << dealt.toString() << ".\n";
				}
				else 
					out << "Deck is out of cards!\n";
				break; 
			}
		}
		out << endl;

	}



	out.close();
/*
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


    cout << endl << endl;
    cout << "Testing Player......" << endl;

    Deck newDeck = Deck();
    newDeck.shuffle();

    Player p1 = Player("Bob");
    Player p2 = Player("Amy");

    cout << "Player 1 is " << p1.getName() << endl;
    cout << "Player 2 is " << p2.getName() << endl;

    for(int i = 0; i < 7; i ++){
        p1.addCard(newDeck.dealCard());
        p2.addCard(newDeck.dealCard());
    }

    cout << "Size of deck: " << newDeck.size() << endl;

	
	cout << p1.showHand();
	cout << p1.showBooks();
	cout << p2.showHand();
	cout << p2.showBooks();
*/	

}
