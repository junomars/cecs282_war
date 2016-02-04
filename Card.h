//
// Created by Jonathan on 1/25/2016.
//

#ifndef PROJECT_001_CARD_H
#define PROJECT_001_CARD_H

#include <string>

class Card {
private:
    // This would have been nice as enum types for clarity?
    int rank;
    int suit;

    const std::string SUIT_STR[4] = {"Spades", "Hearts", "Clubs", "Diamonds"};
    const std::string RANK_STR[13] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
protected:
public:
    Card();

    Card(int rank, int suit);

    int get_value();

    int get_rank();

    int get_suit();

    // TODO: overload = operator?
    void set_card(Card card);

    void set_card(int rank, int suit);

    void display_card();

    // Note: sizeof returns size of the total memory size of array
    static int get_rank_size() { return sizeof(RANK_STR) / sizeof(std::string); }

    static int get_suit_size() { return sizeof(SUIT_STR) / sizeof(std::string); }
};

#endif //PROJECT_001_CARD_H
