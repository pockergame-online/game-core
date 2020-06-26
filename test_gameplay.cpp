#include <iostream>
#include <string>
#include <map>
#include <iterator>

#include "gameplay.h"

using namespace std;

/**
bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

void print_deck(_Deck deck) {
    for(int i=0; i < deck.get_cards().size(); i++) {
        clog << "clog::Card symbol --> " << deck.get_cards()[i].get_symbol() << " Card value --> " << deck.get_cards()[i].get_card_value() << endl;
    }
};
*/

int main() {

    //initialization cards to test

    _Card card1 = _Card("Spade", 10);
    _Card card2 = _Card("Spade", 1);
    _Card card3 = _Card("Clubs", 1);
    _Card card4 = _Card("Hearts", 1);
    _Card card5 = _Card("Hearts", 10);

    _Deck deck1 = _Deck({card1, card2});
    _Deck deck2 = _Deck({card3, card4, card5});
    
    map<int, int> _value = (deck1 + deck2).get_deck_evaluation();
    map<int, int>::iterator it = _value.begin();

    while (it != _value.end()) {
      clog << it->first << " :: " << it->second << endl;
      it++;
    }
    

    //_Deck deck3 = deck1 + deck2;

    //print_deck(deck3);

    //clog << "is Pair?" << (card5 == _Card("Heart", 13)) << endl; 

    //std::map<char,int> first;

  //first['a']=10;
  //first['b']=30;
  //first['c']=50;
  //first['d']=70;

  //std::map<char,int> second (first.begin(),first.end());

  //std::map<char,int> third (second);

  //std::map<char,int,classcomp> fourth;                 // class as Compare

  // bool(*fn_pt)(char,char) = fncomp;
  // std::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare

  // clog << "Get Value from Key --> first['c'] : " << first['c'] << endl;

}