#include <string>
#include <vector>
#include <iostream>
#include <map>

#ifndef _GAMEPLAY_H
#define _GAMEPLAY_H

using namespace std;

enum _Deck_Value {NONE, PAIR, DOUBLE_PAIR, THREE_OF_KIND, FULL_HOUSE, POKER, FLUSH, ROYAL_FLUSH};

class _Card {
    private:
        string _symbol;
        int _card_value;

    public:
        _Card(string, int);
        string get_symbol();
        int get_card_value();
        bool operator == (const _Card&);
};

class _Deck {
    private:
        vector<_Card> _cards;

    public:
        _Deck(vector<_Card>);
        vector<_Card> get_cards();
        void set_cards(vector<_Card>);
        _Deck operator + (const _Deck&);
        map<int,int> get_evaluate_kind();
        _Deck_Value get_value();

};

/**
class _Player {
    private:
        _Deck _deck;
        string _nick_name;

    public:
        _Player(string _new_player_nick_name, _Deck _new_player_deck);

};*/

#endif //_GAMEPLAY_H