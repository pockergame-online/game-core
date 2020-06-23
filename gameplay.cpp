#include "gameplay.h"

#define LOG_DEBUG false

Card::Card(string new_symbol, int new_value) {
    symbol = new_symbol;
    card_value = new_value;
}

string Card::get_symbol() {
    return symbol;
}

int Card::get_card_value() {
    return card_value;
}

Deck::Deck(vector<Card> new_cards) {
    cards = new_cards;
}

vector<Card> Deck::get_cards() {
    return cards;
}

void Deck::set_cards(vector<Card> new_cards) {
    cards = new_cards;
}

Deck Deck::operator+(const Deck& add_deck) {
    Deck temp_deck = Deck (add_deck.cards);

    vector<Card> cards = add_deck.cards;

    if (LOG_DEBUG) {
        for (int i=0; i < temp_deck.get_cards().size(); i++) {
            cout << temp_deck.get_cards()[i].get_card_value() << endl;
        }
    }
    
    for (int i=0; i < this->get_cards().size(); i++) {
        if (LOG_DEBUG) { 
            cout << this->get_cards()[i].get_card_value() << endl;
        }
        Card card_temp = Card(this->get_cards()[i].get_symbol(), this->get_cards()[i].get_card_value());
        cards.push_back(card_temp);
    }
    
    temp_deck.set_cards(cards);

    return temp_deck;

}