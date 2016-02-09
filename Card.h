//
// Created by Jonathan on 1/25/2016.
//

#ifndef PROJECT_001_CARD_H
#define PROJECT_001_CARD_H

#include "Rank.h"
#include "Suit.h"
#include <string>

class Card {
private:
    Rank rank;
    Suit suit;
protected:
public:
    Card();

    Card(Rank rank, Suit suit);

    int get_value();

    Rank get_rank();

    Suit get_suit();

    // TODO: overload = operator?
    void set_card(Card card);

    void set_card(Rank rank, Suit suit);

    std::wstring get_suit_as_str();

    std::wstring get_rank_as_str();
};

#endif //PROJECT_001_CARD_H
