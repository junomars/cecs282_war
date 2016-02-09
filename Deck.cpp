//
// Created by Jonathan on 1/26/2016.
//

#include <time.h>
#include <iostream>
#include "Deck.h"

Deck::Deck() {
    // Initialize variables
    cards_dealt = (int) cards.size();

    // Initialize our deck
    reset_deck();
}

Card Deck::deal() {
    return cards[cards_dealt];
}

int Deck::cards_left() {
    return cards_dealt;
}

void Deck::shuffle() {
    // Pick a new seed for our rand() function
    srand((unsigned int) time(NULL));

    // Create some vars
    int randomIndex;
    Card placeholder;

    // Shuffle all the cards starting from the end to the start
    for (int index = cards_dealt - 1; index > 0; index--) {
        // Pick a random index to move it to
        randomIndex = rand() % cards_dealt;

        // Swap the index with the random index
        placeholder.set_card(cards[index]);
        cards[index].set_card(cards[randomIndex]);
        cards[randomIndex].set_card(placeholder);
    }
}

void Deck::reset_deck() {
    // Initialize our deck
    int card_count = 0;

    // For each suit and each rank create a buffered_cards
    for (int suit_index = 1; suit_index < 5; suit_index++)
        for (int rank_index = 1; rank_index < 14; rank_index++)
            cards[card_count++].set_card(static_cast<Rank>(rank_index), static_cast<Suit>(suit_index));
}
