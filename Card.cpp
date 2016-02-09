//
// Created by Jonathan on 1/25/2016.
//

#include "Card.h"

Card::Card() {
    this->rank = Rank::ZERO;
    this->suit = Suit::NONE;
}

Card::Card(Rank rank, Suit suit) {
    this->rank = rank;
    this->suit = suit;
}

int Card::get_value() {
    switch (this->rank) {
        case Rank::TEN: // Intentional fall through
        case Rank::JACK:
        case Rank::QUEEN:
        case Rank::KING:
            return 10;
        default:
            return (int) this->rank;
    }
}

Rank Card::get_rank() {
    return this->rank;
}

Suit Card::get_suit() {
    return this->suit;
}

void Card::set_card(Card card) {
    this->rank = card.get_rank();
    this->suit = card.get_suit();
}

void Card::set_card(Rank rank, Suit suit) {
    this->rank = rank;
    this->suit = suit;
}

std::wstring Card::get_suit_as_str() {
    switch (this->suit) {
        case SPADES:
            return L"\u2660";
        case HEARTS:
            return L"\u2665";
        case CLUBS:
            return L"\u2663";
        case DIAMONDS:
            return L"\u2666";
        default:
            return L"\u25A1";
    }
}

std::wstring Card::get_rank_as_str() {
    switch (this->rank) {
        case ACE:
            return L"1";
        case TWO:
            return L"2";
        case THREE:
            return L"3";
        case FOUR:
            return L"4";
        case FIVE:
            return L"5";
        case SIX:
            return L"6";
        case SEVEN:
            return L"7";
        case EIGHT:
            return L"8";
        case NINE:
            return L"9";
        case TEN:
            return L"10";
        case JACK:
            return L"J";
        case QUEEN:
            return L"Q";
        case KING:
            return L"K";
        default:
            return L"0";
    }
}