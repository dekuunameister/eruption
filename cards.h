//
//  cards.h
//  Eruption
//
//  Created by Fangbo Yuan on 5/9/17.
//  Copyright © 2017 Fangbo Yuan. All rights reserved.
//

#ifndef cards_h
#define cards_h

#include <iostream>
using std::cin;
using std::cerr;
using std::endl;
#include <vector>
using std::vector;
#include <string>
using std::string;
#include <sstream>
using std::ostream;

class Card{
public:
    int value;
    int affector; // 1-J, 2-Q, 3-K, 4-A, 5-Joker
    char suit; // H-hearts D-diamonds S-spades C-clubs
    bool affected; // if a powerup changed the value of the card

    Card(int value, char suit);
    
    bool operator < (const Card &second);

};

Card::Card(int value, char suit):
value(value), suit(suit), affected(false){}


bool this_card_wins (const Card &first, const Card &second, const char top_suit){
    // needs two cards to compare, as well as suit of top
    // returns true if first trumps second
    
    if (first.value > second.value)
        return true;
    
    else if (first.value == second.value){
        if (first.affected == false && second.affected == true)
            return true;
        
        else if (first.affected == true && second.affected == true){
            if (first.affector > second.affector)
                return true;
            
            else if (first.affector == second.affector){
                if (top_suit == 'H'){
                    if (first.suit == 'H' || (first.suit == 'S' && second.suit != 'H')
                        || (first.suit == 'D' && second.suit == 'C'))
                        return true;
                }
                
                if (top_suit == 'D'){
                    if (first.suit == 'D' || (first.suit == 'C' && second.suit != 'D')
                        || (first.suit == 'H' && second.suit == 'S'))
                        return true;
                }
                
                if (top_suit == 'S'){
                    if (first.suit == 'S' || (first.suit == 'H' && second.suit != 'S')
                        || (first.suit == 'C' && second.suit == 'D'))
                        return true;
                }
                
                if (top_suit == 'C'){
                    if (first.suit == 'C' || (first.suit == 'D' && second.suit != 'C')
                        || (first.suit == 'S' && second.suit == 'H'))
                        return true;
                }
            }
            
        }
    }
    
    return false;
}



#endif /* cards_h */
