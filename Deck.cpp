//
// Created by Jonathan on 1/26/2016.
//

#include <time.h>
#include <iostream>
#include "Deck.h"

Deck::Deck() {
}

void Deck::add(Card card) {
    this->cards.push_back(card);
}

Card Deck::deal() {
    return this->cards[--this->cards_dealt];
}

int Deck::cards_left() {
    return this->cards_dealt;
}

void Deck::shuffle() {
    // Pick a new seed for our rand() function
    srand((unsigned int) time(NULL));

    // Create some vars
    int randomIndex;
    Card placeholder;

    // Shuffle all the cards starting from the end to the start
    for (int index = this->cards_dealt - 1; index > 0; index--) {
        // Pick a random index to move it to
        randomIndex = rand() % this->cards_dealt;

        // Swap the index with the random index
        placeholder = this->cards.at(index);
        this->cards.at(index) = this->cards.at(randomIndex);
        this->cards.at(randomIndex) = placeholder;
        /**
        placeholder.set_card(this->cards.at(index));
        this->cards.at(index).set_card(this->cards.at(randomIndex));
        this->cards.at(randomIndex).set_card(placeholder);
         *//
    }
}

void Deck::reset_deck() {
    // For each suit and each rank create a buffered_cards
    for (int suit_index = 1; suit_index < 5; suit_index++)
        for (int rank_index = 1; rank_index < 14; rank_index++)
            this->cards.push_back(Card(static_cast<Rank>(rank_index), static_cast<Suit>(suit_index)));

    // Initialize variables
    this->cards_dealt = (int) this->cards.size();
}
