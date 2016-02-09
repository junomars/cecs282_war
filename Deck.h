//
// Created by Jonathan on 1/26/2016.
//

#ifndef PROJECT_001_DECK_H
#define PROJECT_001_DECK_H

#include <array>
#include "Card.h"

class Deck {
private:
    std::array<Card, 52> cards;
    int cards_dealt;
protected:
public:
    Deck();

    Card deal();

    int cards_left();

    void shuffle();

    void reset_deck();
};


#endif //PROJECT_001_DECK_H
