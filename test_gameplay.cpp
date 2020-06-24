#include <iostream>
#include <string>

#include "gameplay.h"

using namespace std;

void print_deck(_Deck deck) {
    for(int i=0; i < deck.get_cards().size(); i++) {
        clog << "clog::Card symbol --> " << deck.get_cards()[i].get_symbol() << " Card value --> " << deck.get_cards()[i].get_card_value() << endl;
    }
};

int main() {

    //initialization cards to test

    _Card card1 = _Card("Spade", 10);
    _Card card2 = _Card("Spade", 1);
    _Card card3 = _Card("Spade", 11);
    _Card card4 = _Card("Spade", 12);
    _Card card5 = _Card("Spade", 13);

    _Deck deck1 = _Deck({card1, card2});
    _Deck deck2 = _Deck({card3, card4, card5});

    _Deck deck3 = deck1 + deck2;

    print_deck(deck3);

    clog << "is Pair?" << (card5 == _Card("Heart", 13)) << endl; 
}