#include "gameplay.h"

#define _LOG_DEBUG false

_Card::_Card(string new_symbol, int new_value) {
    _symbol = new_symbol;
    _card_value = new_value;
}

string _Card::get_symbol() {
    return _symbol;
}

int _Card::get_card_value() {
    return _card_value;
}

_Deck::_Deck(vector<_Card> new_cards) {
    _cards = new_cards;
}

vector<_Card> _Deck::get_cards() {
    return _cards;
}

bool _Card::operator == (const _Card& _temp_card) {
    if (_LOG_DEBUG) {
        clog << "_temp_card : " << _temp_card._card_value;
        clog << "this->get_card_value() : " << this->get_card_value();
    }
    return (this->get_card_value() == _temp_card._card_value);
}

void _Deck::set_cards(vector<_Card> new_cards) {
    _cards = new_cards;
}

_Deck _Deck::operator + (const _Deck& add_deck) {
    _Deck temp_deck = _Deck (add_deck._cards);

    vector<_Card> cards = add_deck._cards;

    if (_LOG_DEBUG) {
        for (int i=0; i < temp_deck.get_cards().size(); i++) {
            cout << temp_deck.get_cards()[i].get_card_value() << endl;
        }
    }
    
    for (int i=0; i < this->get_cards().size(); i++) {
        if (_LOG_DEBUG) { 
            cout << this->get_cards()[i].get_card_value() << endl;
        }
        _Card card_temp = _Card(this->get_cards()[i].get_symbol(), this->get_cards()[i].get_card_value());
        cards.push_back(card_temp);
    }
    
    temp_deck.set_cards(cards);

    return temp_deck;

}

map<int,int> _Deck::get_deck_evaluation() {
    map<int, int> _deck_value;
    int _counter = 0;
    
    for (int i=0; i < this->get_cards().size(); i++) {
        _Card _current_card = this->get_cards()[i];
        _counter = 1;

        for (int j=0; j < this->get_cards().size(); j++) {
            if ( i != j ) {
                if (_current_card == this->get_cards()[j])
                    _counter++;
            }
        }

        _deck_value.insert(make_pair(_current_card.get_card_value(), _counter));
    }

    return _deck_value;
}

