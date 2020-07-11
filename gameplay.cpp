#include <iterator>

#include "gameplay.h"

#define _LOG_DEBUG false

/*
* Section for auxiliar functions to evaluate decks
* - ALA
* Review:
* -
*/
void sort_deck(_Deck* _deck) {

    vector<_Card> _cards_to_order = _deck->get_cards();
    sort(_cards_to_order.begin(), _cards_to_order.end(), [](const _Card& left_card, const _Card& right_card) {
      return left_card.get_card_value() < right_card.get_card_value();
    });
    /*sort(_deck->get_cards().begin(), _deck->get_cards().end());
    for (const auto &i: _deck.get_cards())
      cout << i << ' '<<endl;
      cout<<"Elements after sorting"<<endl;
      sort(v.begin(), v.end());
   for (const auto &card: _deck.get_cards())
      cout <<  << ' '<<endl;*/
}

bool evaluate_flush(_Deck* _deck_to_evaluate) {
    //sort_deck(_deck_to_evaluate);
    for (int i=0; i < _deck_to_evaluate->get_cards().size(); i++) { 
        _Card _current_card = _deck_to_evaluate->get_cards()[i];
        // clog << "Card " << _current_card.get_symbol() << " Value " << _current_card.get_card_value() << endl;
        for (int j=0; j < _deck_to_evaluate->get_cards().size(); j++) {
            if ( i != j ) {
                int compare = _current_card.get_symbol().compare(_deck_to_evaluate->get_cards()[j].get_symbol());
                if (compare != 0)
                    return false;
            }
                
        }
    }
    return true;
}

bool evaluate_royal_flush(_Deck* _deck_to_evaluate) {
    if (evaluate_flush(_deck_to_evaluate)) {
        int _points_of_royal_flush = 0;
        for (int i=0; i < _deck_to_evaluate->get_cards().size(); i++) {
            _Card _card_to_evaluate = _deck_to_evaluate->get_cards()[i];
            if (_card_to_evaluate.get_card_value() == 10 || 
                _card_to_evaluate.get_card_value() == 1 || 
                _card_to_evaluate.get_card_value() == 11 || 
                _card_to_evaluate.get_card_value() == 12 || 
                _card_to_evaluate.get_card_value() == 13)
            _points_of_royal_flush++;
        }
        return (_points_of_royal_flush == 5);
    } else {
        return false;
    }
    
}

/*
* Section class methods implementation
* - ALA
* Review:
* -
*/
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

map<int,int> _Deck::get_evaluate_kind() {
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





_Deck_Value _Deck::get_value(){
    int _count_pairs = 0;
    int _count_thirds = 0;
    int _count_poker = 0;
    map<int, int> _deck_value = this->get_evaluate_kind();

    map<int, int>::iterator it = _deck_value.begin();

    while (it != _deck_value.end()) {
        if (_LOG_DEBUG)
            clog << it->first << " :: " << it->second << endl;

        switch (it->second) { 
            case 2: {
                _count_pairs++;
                break;
            }
            case 3: {
                _count_thirds++;
                break;
            }
            case 4: {
                _count_poker++;
                break;
            }
        }  
      it++;    
    }

    if (evaluate_royal_flush(this))
        return _Deck_Value::ROYAL_FLUSH;
    if (_count_poker == 1)
        return _Deck_Value::POKER;    
    if (_count_pairs == 1 && _count_thirds == 1) 
        return _Deck_Value::FULL_HOUSE;
    if (evaluate_flush(this))
        return _Deck_Value::FLUSH;
    if (_count_thirds == 1) 
        return _Deck_Value::THREE_OF_KIND;    
    if (_count_pairs == 1) 
        return _Deck_Value::PAIR;
    else if (_count_pairs == 2)
        return _Deck_Value::DOUBLE_PAIR;
        
    return _Deck_Value::NONE;
}



