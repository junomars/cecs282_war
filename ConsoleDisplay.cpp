//
// Created by jonat on 2/7/2016.
//

#include "ConsoleDisplay.h"
#include "Deck.h"

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


/**
void ConsoleDisplay::buffered_cards() {
    std::array<std::wstring, 9> output;
    std::array<std::wstring, 9> temp;
    Deck hand;
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
*/

void ConsoleDisplay::buffer(Deck deck) {
    std::wstring suit;
    std::wstring rank;
    Card current_card;

    for (int index = 0; index < deck.size(); index++) {
        current_card.set_card(deck.deal());
        rank = current_card.get_rank_as_str();
        suit = current_card.get_suit_as_str();

        // The following is mostly OCD formatting though I prefer to say it was CDO
        // because then at least the letters would be in alphabetical order.
        if (index == (deck.size() - 1)) {
            this->output[0] += L"\u256D\u2500\u2500\u2500\u2500\u2500\u256E";
            this->output[1] += L"\u2502" + rank + L"\u2005\u2006\u2003\u2003\u2003\u2003\u2502";
            this->output[7] += L"\u2502\u2005\u2006\u2003\u2003\u2003\u2003" + rank + L"\u2502";
            this->output[8] += L"\u2570\u2500\u2500\u2500\u2500\u2500\u256F";

            switch (current_card.get_rank()) {
                case ZERO:
                    this->output[2] += L"\u2502" + suit + L"\u2003\u2003\u2003\u2003\u2006\u200A\u2502";
                    this->output[3] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    this->output[4] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    this->output[5] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    this->output[6] += L"\u2502\u200A\u2003\u2003\u2003\u2003\u2006" + suit + L"\u2502";
                    break;
                case ACE:
                    this->output[2] += L"\u2502" + suit + L"\u2003\u2003\u2003\u2003\u2006\u200A\u2502";
                    this->output[3] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    this->output[4] += L"\u2502\u2003\u2003\u2006" + suit + L"\u2003\u2003\u200A\u2502";
                    this->output[5] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    this->output[6] += L"\u2502\u200A\u2003\u2003\u2003\u2003\u2006" + suit + L"\u2502";
                    break;
                case TWO:
                    this->output[2] += L"\u2502" + suit + L"\u2003\u2004" + suit + L"\u2003\u2003\u200A\u2502";
                    this->output[3] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    this->output[4] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    this->output[5] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    this->output[6] += L"\u2502\u2003\u2003\u2006" + suit + L"\u2003\u2006\u200A" + suit + L"\u2502";
                    break;
                case THREE:
                    this->output[2] += L"\u2502" + suit + L"\u2003\u2004" + suit + L"\u2003\u2003\u200A\u2502";
                    this->output[3] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    this->output[4] += L"\u2502\u2003\u2003\u2006" + suit + L"\u2003\u2003\u200A\u2502";
                    this->output[5] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    this->output[6] += L"\u2502\u2003\u2003\u2006" + suit + L"\u2003\u2006\u200A" + suit + L"\u2502";
                    break;
                case FOUR:
                    this->output[2] += L"\u2502" + suit + L"\u2003\u2003\u2003\u2003\u2006\u200A\u2502";
                    this->output[3] += L"\u2502\u2003\u2006" + suit + L"\u2003\u2006" + suit + L"\u2003\u200A\u2502";
                    this->output[4] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    this->output[5] += L"\u2502\u2003\u2006" + suit + L"\u2003\u2006" + suit + L"\u2003\u200A\u2502";
                    this->output[6] += L"\u2502\u200A\u2003\u2003\u2003\u2003\u2006" + suit + L"\u2502";
                    break;
                case FIVE:
                    this->output[2] +=
                            L"\u2502" + suit + L"\u2002" + suit + L"\u2002\u2004" + suit + L"\u2003\u2006\u200A\u2502";
                    this->output[3] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    this->output[4] += L"\u2502\u2003\u2003\u2006" + suit + L"\u2003\u2003\u200A\u2502";
                    this->output[5] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    this->output[6] += L"\u2502\u2003\u2004" + suit + L"\u2002\u2004" + suit + L"\u2004\u200A" + suit +
                                 L"\u2502";
                    break;
                case SIX:
                    this->output[2] += L"\u2502" + suit + L"\u2002" + suit + L"\u2002\u2004" + suit +
                                       L"\u2003\u2006\u200A\u2502";
                    this->output[3] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    this->output[4] +=
                            L"\u2502\u2003\u2004" + suit + L"\u2002\u2004" + suit + L"\u2003\u2006\u200A\u2502";
                    this->output[5] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    this->output[6] += L"\u2502\u2003\u2004" + suit + L"\u2002\u2004" + suit + L"\u2004\u200A" + suit +
                                 L"\u2502";
                    break;
                case SEVEN:
                    this->output[2] += L"\u2502" + suit + L"\u2002" + suit + L"\u2002\u2004" + suit +
                                       L"\u2003\u2006\u200A\u2502";
                    this->output[3] += L"\u2502\u2003\u2003\u2006" + suit + L"\u2003\u2003\u200A\u2502";
                    this->output[4] +=
                            L"\u2502\u2003\u2004" + suit + L"\u2002\u2004" + suit + L"\u2003\u2006\u200A\u2502";
                    this->output[5] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    this->output[6] += L"\u2502\u2003\u2004" + suit + L"\u2002\u2004" + suit + L"\u2004\u200A" + suit +
                                 L"\u2502";
                    break;
                case EIGHT:
                    this->output[2] += L"\u2502" + suit + L"\u2002" + suit + L"\u2002\u2004" + suit +
                                       L"\u2003\u2006\u200A\u2502";
                    this->output[3] += L"\u2502\u2003\u2003\u2006" + suit + L"\u2003\u2003\u200A\u2502";
                    this->output[4] +=
                            L"\u2502\u2003\u2004" + suit + L"\u2002\u2004" + suit + L"\u2003\u2006\u200A\u2502";
                    this->output[5] += L"\u2502\u2003\u2003\u2006" + suit + L"\u2003\u2003\u200A\u2502";
                    this->output[6] += L"\u2502\u2003\u2004" + suit + L"\u2002\u2004" + suit + L"\u2004\u200A" + suit +
                                 L"\u2502";
                    break;
                case NINE:
                    this->output[2] += L"\u2502" + suit + L"\u2002" + suit + L"\u2002\u2004" + suit +
                                       L"\u2003\u2006\u200A\u2502";
                    this->output[3] +=
                            L"\u2502\u2003\u2004" + suit + L"\u2002\u2004" + suit + L"\u2003\u2006\u200A\u2502";
                    this->output[4] += L"\u2502\u2003\u2003\u2006" + suit + L"\u2003\u2003\u200A\u2502";
                    this->output[5] +=
                            L"\u2502\u2003\u2004" + suit + L"\u2002\u2004" + suit + L"\u2003\u2006\u200A\u2502";
                    this->output[6] += L"\u2502\u2003\u2004" + suit + L"\u2002\u2004" + suit + L"\u2004\u200A" + suit +
                                       L"\u2502";
                    break;
                case TEN:
                    this->output[1] += L"\u2502" + rank + L"\u2002\u2004\u2003\u2003\u2003\u2502";
                    this->output[2] += L"\u2502" + suit + L"\u2002" + suit + L"\u2002\u2004" + suit +
                                 L"\u2003\u2006\u200A\u2502";
                    this->output[3] +=
                            L"\u2502\u2003\u2004" + suit + L"\u2002\u2004" + suit + L"\u2003\u2006\u200A\u2502";
                    this->output[4] +=
                            L"\u2502\u2003\u2004" + suit + L"\u2002\u2004" + suit + L"\u2003\u2006\u200A\u2502";
                    this->output[5] +=
                            L"\u2502\u2003\u2004" + suit + L"\u2002\u2004" + suit + L"\u2003\u2006\u200A\u2502";
                    this->output[6] += L"\u2502\u2003\u2004" + suit + L"\u2002\u2004" + suit + L"\u2004\u200A" + suit +
                                       L"\u2502";
                    this->output[7] += L"\u2502\u2002\u2004\u2003\u2003\u2003" + rank + L"\u2502";
                    break;
                case JACK:
                    this->output[2] += L"\u2502" + suit + L"\u2003\u2003\u2003\u2003\u2006\u200A\u2502";
                    this->output[3] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    this->output[4] += L"\u2502\u2003\u2003\u2004" + rank + L"\u200A\u2003\u2003\u200A\u2502";
                    this->output[5] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    this->output[6] += L"\u2502\u200A\u2003\u2003\u2003\u2003\u2006" + suit + L"\u2502";
                    break;
                case QUEEN:
                    this->output[2] += L"\u2502" + suit + L"\u2003\u2003\u2003\u2003\u2006\u200A\u2502";
                    this->output[3] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    this->output[4] += L"\u2502\u2003\u2003\u2004" + rank + L"\u200A\u2003\u2003\u200A\u2502";
                    this->output[5] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    this->output[6] += L"\u2502\u200A\u2003\u2003\u2003\u2003\u2006" + suit + L"\u2502";
                    break;
                case KING:
                    this->output[2] += L"\u2502" + suit + L"\u2003\u2003\u2003\u2003\u2006\u200A\u2502";
                    this->output[3] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    this->output[4] += L"\u2502\u2003\u2003\u2004" + rank + L"\u200A\u2003\u2003\u200A\u2502";
                    this->output[5] += L"\u2502\u2003\u2003\u2003\u2003\u2003\u200A\u2502";
                    this->output[6] += L"\u2502\u200A\u2003\u2003\u2003\u2003\u2006" + suit + L"\u2502";
                    break;
            }
        } else {
            this->output[0] += L"\u256D\u2500";
            this->output[1] += L"\u2502" + rank + L"\u2004\u200A";
            this->output[2] += L"\u2502" + suit + L"\u2006";
            this->output[3] += L"\u2502\u2003";
            this->output[4] += L"\u2502\u2003";
            this->output[5] += L"\u2502\u2003";
            this->output[6] += L"\u2502\u2003";
            this->output[7] += L"\u2502\u2003";
            this->output[8] += L"\u2570\u2500";
        }
    } // end of adding print_cards
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
