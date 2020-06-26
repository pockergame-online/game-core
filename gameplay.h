#include <string>
#include <vector>
#include <iostream>
#include <map>

#ifndef _GAMEPLAY_H
#define _GAMEPLAY_H

using namespace std;

// enum hand_type {};

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
        map<int,int> get_deck_evaluation();
};

#endif //_GAMEPLAY_H