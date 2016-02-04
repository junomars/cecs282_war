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
    // TODO: Maybe change this to control when a dealt card is displayed
    display_card_at(--cards_dealt);
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

void Deck::display_deck() {
    for (int index = (int) cards.size() - 1; index > 0; index--)
        cards[index].display_card();
}

void Deck::display_deck(int cards_left) {
    for (int index = cards_left; index > 0; index--)
        cards[index].display_card();
}

void Deck::display_card_at(int i) {
    // TODO: Limit input to be in between array bounds
    cards[i].display_card();
}

void Deck::reset_deck() {
    // Initialize our deck
    int card_count = 0;

    // For each suit and each rank create a card
    for (int suit_index = 0; suit_index < Card::get_suit_size(); suit_index++)
        for (int rank_index = 0; rank_index < Card::get_rank_size(); rank_index++)
            cards[card_count++].set_card(rank_index, suit_index);
}
