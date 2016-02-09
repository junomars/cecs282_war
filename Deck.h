//
// Created by Jonathan on 1/26/2016.
//

#ifndef PROJECT_001_DECK_H
#define PROJECT_001_DECK_H

#include <vector>
#include "Card.h"

class Deck {
private:
    std::vector<Card> cards;
    int cards_dealt;
protected:
public:
    Deck();

    int size() { return (int) cards.size(); }

    Card deal();

    int cards_left();

    void shuffle();

    void reset_deck();

    void add(Card card);
};


#endif //PROJECT_001_DECK_H
