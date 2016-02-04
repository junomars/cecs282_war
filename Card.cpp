//
// Created by Jonathan on 1/25/2016.
//

#include "Card.h"
#include <iostream>

Card::Card() {
    this->rank = -1;
    this->suit = -1;
}

Card::Card(int rank, int suit) {
    this->rank = rank;
    this->suit = suit;
}

int Card::get_value() {
    if (this->rank > 9)
        return 10;
    else return this->rank;
}

int Card::get_rank() {
    return this->rank;
}

int Card::get_suit() {
    return this->suit;
}

void Card::set_card(Card card) {
    this->rank = card.get_rank();
    this->suit = card.get_suit();
}

void Card::set_card(int rank, int suit) {
    this->rank = rank;
    this->suit = suit;
}

void Card::display_card() {
    if (this->get_rank() == -1 || this->get_suit() == -1)
        std::cout << "Blank card" << std::endl;
    else
        std::cout << RANK_STR[this->rank] << " of " << SUIT_STR[this->suit] << std::endl;
}
