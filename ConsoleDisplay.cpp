//
// Created by jonat on 2/7/2016.
//

#include "ConsoleDisplay.h"

void ConsoleDisplay::menu() {
    std::wcout << "\n1. Get a new card deck" << std::endl
    << "2. Show all cards in the deck" << std::endl
    << "3. Show remaining cards in the deck" << std::endl
    << "4. Shuffle" << std::endl
    << "5. Play WAR!" << std::endl
    << "6. Exit\n" << std::endl;
}

void ConsoleDisplay::winner(int score1, int score2) {
    // Compare scores
    std::cout << "You have " << score1 << " points" << std::endl;
    std::cout << "I have " << score2 << " points" << std::endl;

    if (score1 == score2)
        std::cout << "Tie game - I challenge you again." << std::endl;
    else if (score1 > score2) {
        std::cout << "You win...this time." << std::endl;
    } else {
        std::cout << "In your face! - I win!" << std::endl;
    }
}

bool ConsoleDisplay::cards_left(int cards_left) {
    // Check if there are any cards available
    if (cards_left == 0) {
        std::cout << "No more cards are available. Please shuffle first." << std::endl;
        return false;
    } else {
        // Display # of cards left
        std::cout << "There are " << cards_left << " cards in the deck." << std::endl;
        return true;
    }
}

void ConsoleDisplay::buffer_card(Card card) {
    this->cards.push_back(card);
}

void ConsoleDisplay::buffered_cards() {
    std::array<std::wstring, 9> output;
    std::array<std::wstring, 9> temp;
    std::vector<Card> hand;
    int total_players = 2; // TODO: global variable?

    for (int player = 0; player < total_players; player++) {
        for (int index = player; index < this->cards.size(); index += 2)
            hand.push_back(this->cards.at(index));

        temp = this->cards_to_str(hand);

        for (int index = 0; index < output.size(); index++)
            output[index] += temp[index];

        if (player != (total_players - 1)) {
            output[0] += L"      ";
            output[1] += L"      ";
            output[2] += L"      ";
            output[3] += L"      ";
            output[4] += L"  vs  ";
            output[5] += L"      ";
            output[6] += L"      ";
            output[7] += L"      ";
            output[8] += L"      ";
        }
    } // end of player for loop

    // TODO: update so output is more consistent
    for (auto part_of_output : output)
        std::wcout << part_of_output << std::endl;
}

std::array<std::wstring, 9> ConsoleDisplay::cards_to_str(std::vector<Card> print_cards) {
    std::array<std::wstring, 9> output;
    std::wstring suit;
    std::wstring rank;

    for (int index = 0; index < print_cards.size(); index++) {
        rank = print_cards.at(index).get_rank_as_str();
        suit = print_cards.at(index).get_suit_as_str();

        // The following is mostly OCD formatting though I prefer to say it was CDO
        // because then at least the letters would be in alphabetical order.
        if (index == (print_cards.size() - 1)) {
            output[0] += L"\u256D\u2500\u2500\u2500\u2500\u2500\u256E";
            output[1] += L"\u2502" + rank + L"\u2005\u2006\u2003\u2003\u2003\u2003\u2502";
            output[7] += L"\u2502\u2005\u2006\u2003\u2003\u2003\u2003" + rank + L"\u2502";
            output[8] += L"\u2570\u2500\u2500\u2500\u2500\u2500\u256F";

            switch (this->cards.at(index).get_rank()) {
                case ZERO:
                    output[2] += L"\u2502" + suit + L"\u2003\u2003\u2003\u2003\u2006\u200A\u2502";
                    output[3] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    output[4] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    output[5] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    output[6] += L"\u2502\u200A\u2003\u2003\u2003\u2003\u2006" + suit + L"\u2502";
                    break;
                case ACE:
                    output[2] += L"\u2502" + suit + L"\u2003\u2003\u2003\u2003\u2006\u200A\u2502";
                    output[3] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    output[4] += L"\u2502\u2003\u2003\u2006" + suit + L"\u2003\u2003\u200A\u2502";
                    output[5] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    output[6] += L"\u2502\u200A\u2003\u2003\u2003\u2003\u2006" + suit + L"\u2502";
                    break;
                case TWO:
                    output[2] += L"\u2502" + suit + L"\u2003\u2004" + suit + L"\u2003\u2003\u200A\u2502";
                    output[3] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    output[4] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    output[5] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    output[6] += L"\u2502\u2003\u2003\u2006" + suit + L"\u2003\u2006\u200A" + suit + L"\u2502";
                    break;
                case THREE:
                    output[2] += L"\u2502" + suit + L"\u2003\u2004" + suit + L"\u2003\u2003\u200A\u2502";
                    output[3] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    output[4] += L"\u2502\u2003\u2003\u2006" + suit + L"\u2003\u2003\u200A\u2502";
                    output[5] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    output[6] += L"\u2502\u2003\u2003\u2006" + suit + L"\u2003\u2006\u200A" + suit + L"\u2502";
                    break;
                case FOUR:
                    output[2] += L"\u2502" + suit + L"\u2003\u2003\u2003\u2003\u2006\u200A\u2502";
                    output[3] += L"\u2502\u2003\u2006" + suit + L"\u2003\u2006" + suit + L"\u2003\u200A\u2502";
                    output[4] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    output[5] += L"\u2502\u2003\u2006" + suit + L"\u2003\u2006" + suit + L"\u2003\u200A\u2502";
                    output[6] += L"\u2502\u200A\u2003\u2003\u2003\u2003\u2006" + suit + L"\u2502";
                    break;
                case FIVE:
                    output[2] += L"\u2502" + suit + L"\u2002" + suit + L"\u2002\u2004" + suit +
                                 L"\u2003\u2006\u200A\u2502";
                    output[3] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    output[4] += L"\u2502\u2003\u2003\u2006" + suit + L"\u2003\u2003\u200A\u2502";
                    output[5] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    output[6] += L"\u2502\u2003\u2004" + suit + L"\u2002\u2004" + suit + L"\u2004\u200A" + suit +
                                 L"\u2502";
                    break;
                case SIX:
                    output[2] += L"\u2502" + suit + L"\u2002" + suit + L"\u2002\u2004" + suit +
                                 L"\u2003\u2006\u200A\u2502";
                    output[3] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    output[4] +=
                            L"\u2502\u2003\u2004" + suit + L"\u2002\u2004" + suit + L"\u2003\u2006\u200A\u2502";
                    output[5] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    output[6] += L"\u2502\u2003\u2004" + suit + L"\u2002\u2004" + suit + L"\u2004\u200A" + suit +
                                 L"\u2502";
                    break;
                case SEVEN:
                    output[2] += L"\u2502" + suit + L"\u2002" + suit + L"\u2002\u2004" + suit +
                                 L"\u2003\u2006\u200A\u2502";
                    output[3] += L"\u2502\u2003\u2003\u2006" + suit + L"\u2003\u2003\u200A\u2502";
                    output[4] +=
                            L"\u2502\u2003\u2004" + suit + L"\u2002\u2004" + suit + L"\u2003\u2006\u200A\u2502";
                    output[5] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    output[6] += L"\u2502\u2003\u2004" + suit + L"\u2002\u2004" + suit + L"\u2004\u200A" + suit +
                                 L"\u2502";
                    break;
                case EIGHT:
                    output[2] += L"\u2502" + suit + L"\u2002" + suit + L"\u2002\u2004" + suit +
                                 L"\u2003\u2006\u200A\u2502";
                    output[3] += L"\u2502\u2003\u2003\u2006" + suit + L"\u2003\u2003\u200A\u2502";
                    output[4] +=
                            L"\u2502\u2003\u2004" + suit + L"\u2002\u2004" + suit + L"\u2003\u2006\u200A\u2502";
                    output[5] += L"\u2502\u2003\u2003\u2006" + suit + L"\u2003\u2003\u200A\u2502";
                    output[6] += L"\u2502\u2003\u2004" + suit + L"\u2002\u2004" + suit + L"\u2004\u200A" + suit +
                                 L"\u2502";
                    break;
                case NINE:
                    output[2] += L"\u2502" + suit + L"\u2002" + suit + L"\u2002\u2004" + suit +
                                 L"\u2003\u2006\u200A\u2502";
                    output[3] +=
                            L"\u2502\u2003\u2004" + suit + L"\u2002\u2004" + suit + L"\u2003\u2006\u200A\u2502";
                    output[4] += L"\u2502\u2003\u2003\u2006" + suit + L"\u2003\u2003\u200A\u2502";
                    output[5] +=
                            L"\u2502\u2003\u2004" + suit + L"\u2002\u2004" + suit + L"\u2003\u2006\u200A\u2502";
                    output[6] += L"\u2502\u2003\u2004" + suit + L"\u2002\u2004" + suit + L"\u2004\u200A" + suit +
                                 L"\u2502";
                    break;
                case TEN:
                    output[1] += L"\u2502" + rank + L"\u2002\u2004\u2003\u2003\u2003\u2502";
                    output[2] += L"\u2502" + suit + L"\u2002" + suit + L"\u2002\u2004" + suit +
                                 L"\u2003\u2006\u200A\u2502";
                    output[3] +=
                            L"\u2502\u2003\u2004" + suit + L"\u2002\u2004" + suit + L"\u2003\u2006\u200A\u2502";
                    output[4] +=
                            L"\u2502\u2003\u2004" + suit + L"\u2002\u2004" + suit + L"\u2003\u2006\u200A\u2502";
                    output[5] +=
                            L"\u2502\u2003\u2004" + suit + L"\u2002\u2004" + suit + L"\u2003\u2006\u200A\u2502";
                    output[6] += L"\u2502\u2003\u2004" + suit + L"\u2002\u2004" + suit + L"\u2004\u200A" + suit +
                                 L"\u2502";
                    output[7] += L"\u2502\u2002\u2004\u2003\u2003\u2003" + rank + L"\u2502";
                    break;
                case JACK:
                    output[2] += L"\u2502" + suit + L"\u2003\u2003\u2003\u2003\u2006\u200A\u2502";
                    output[3] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    output[4] += L"\u2502\u2003\u2003\u2004" + rank + L"\u200A\u2003\u2003\u200A\u2502";
                    output[5] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    output[6] += L"\u2502\u200A\u2003\u2003\u2003\u2003\u2006" + suit + L"\u2502";
                    break;
                case QUEEN:
                    output[2] += L"\u2502" + suit + L"\u2003\u2003\u2003\u2003\u2006\u200A\u2502";
                    output[3] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    output[4] += L"\u2502\u2003\u2003\u2004" + rank + L"\u200A\u2003\u2003\u200A\u2502";
                    output[5] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    output[6] += L"\u2502\u200A\u2003\u2003\u2003\u2003\u2006" + suit + L"\u2502";
                    break;
                case KING:
                    output[2] += L"\u2502" + suit + L"\u2003\u2003\u2003\u2003\u2006\u200A\u2502";
                    output[3] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    output[4] += L"\u2502\u2003\u2003\u2004" + rank + L"\u200A\u2003\u2003\u200A\u2502";
                    output[5] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    output[6] += L"\u2502\u200A\u2003\u2003\u2003\u2003\u2006" + suit + L"\u2502";
                    break;
            }
        } else {
            output[0] += L"\u256D\u2500";
            output[1] += L"\u2502" + rank + L"\u2004\u200A";
            output[2] += L"\u2502" + suit + L"\u2006";
            output[3] += L"\u2502\u2003";
            output[4] += L"\u2502\u2003";
            output[5] += L"\u2502\u2003";
            output[6] += L"\u2502\u2003";
            output[7] += L"\u2502\u2003";
            output[8] += L"\u2570\u2500";
        }
    } // end of adding print_cards

    return output;
}

void ConsoleDisplay::display_message(std::wstring message) {
    std::wcout << message;
}

wchar_t ConsoleDisplay::process_input() {
    std::wstring input;

    std::cout << "Please enter your input: ";
    std::wcin >> input;

    return input[0];
}
