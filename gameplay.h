#include <string>
#include <vector>
#include <iostream>

#ifndef GAMEPLAY_H
#define GAMEPLAY_H

using namespace std;

// enum hand_type {};

class Card {
    private:
        string symbol;
        int card_value;

    public:
        Card(string, int);
        string get_symbol();
        int get_card_value();
};

class Deck {
    private:
        vector<Card> cards;

    public:
        Deck(vector<Card>);
        vector<Card> get_cards();
        void set_cards(vector<Card>);
        Deck operator+(const Deck&);    
};

#endif //GAMEPLAY_H