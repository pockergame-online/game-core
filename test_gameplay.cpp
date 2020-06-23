#include <iostream>
#include <string>

#include "gameplay.h"

using namespace std;

void print_deck(Deck deck) {
    for(int i=0; i < deck.get_cards().size(); i++) {
        cout << "Card symbol --> " << deck.get_cards()[i].get_symbol() << " Card value --> " << deck.get_cards()[i].get_card_value() << endl;
    }
};

int main() {

    //initialization cards to test

    Card card1 = Card("Spade", 10);
    Card card2 = Card("Spade", 1);
    Card card3 = Card("Spade", 11);
    Card card4 = Card("Spade", 12);
    Card card5 = Card("Spade", 13);

    Deck deck1 = Deck({card1, card2});
    Deck deck2 = Deck({card3, card4, card5});

    Deck deck3 = deck1 + deck2;

    print_deck(deck3);
}