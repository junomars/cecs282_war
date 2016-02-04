#include <iostream>
#include "Deck.h"

using namespace std;

void display_menu();

void display_winner(int play_score, int comp_score);

bool display_cards_left(int cards_left);

int main() {
    Deck deck;
    Card dealt_card;
    string input;
    string play_again;
    int play_score;
    int comp_score;

    do {
        // Present menu for input
        display_menu();
        cout << "Please enter your input: ";
        cin >> input;

        // From the input follow the appropriate path
        switch (input[0]) {
            case '1':
                // Get a new card deck
                deck.reset_deck();
                break;
            case '2':
                // Show all cards in the deck
                deck.display_deck();
                break;
            case '3':
                // Show remaining cards in the deck
                deck.display_deck(deck.cards_left());
            case '4':
                // Shuffle
                deck.shuffle();
                break;
            case '5':
                // Get ready to loop
                cout << "Get ready to play two-card WAR!!!" << endl;
                display_cards_left(deck.cards_left());

                while (deck.cards_left() > 0) {
                    // zero out pass plays
                    play_score = 0;
                    comp_score = 0;

                    // Deal the cards
                    cout << "...dealing..." << endl;
                    cout << "One for you...\n\t";
                    dealt_card.set_card(deck.deal());
                    play_score += dealt_card.get_value();

                    cout << "One for me...\n\t";
                    dealt_card.set_card(deck.deal());
                    comp_score += dealt_card.get_value();

                    cout << "Two for you...\n\t";
                    dealt_card.set_card(deck.deal());
                    play_score += dealt_card.get_value();

                    cout << "Two for me...\n\t";
                    dealt_card.set_card(deck.deal());
                    comp_score += dealt_card.get_value();

                    // Print winners
                    display_winner(play_score, comp_score);

                    // Check to see if we can play first
                    if (!display_cards_left(deck.cards_left()))
                        break;

                    // Ask to play again
                    cout << "\nWanna play again? (Y/N)" << endl;
                    cin >> play_again;

                    if (tolower(play_again[0]) != 'y')
                        break;
                }
                break;
            default:
                // Exit otherwise
                cout << "Terminating program." << endl;
        }
    } while (input != "6");
    return 0;
}

void display_menu() {
    cout << "\n1. Get a new card deck" << endl
    << "2. Show all cards in the deck" << endl
    << "3. Show remaining cards in the deck" << endl
    << "4. Shuffle" << endl
    << "5. Play WAR!" << endl
    << "6. Exit\n" << endl;
}

void display_winner(int play_score, int comp_score) {
    // Compare scores
    cout << "You have " << play_score << " points" << endl;
    cout << "I have " << comp_score << " points" << endl;

    if (play_score == comp_score)
        cout << "Tie game - I challenge you again." << endl;
    else if (play_score > comp_score) {
        cout << "You win...this time." << endl;
    } else {
        cout << "In your face! - I win!" << endl;
    }
}

bool display_cards_left(int cards_left) {
    // Check if there are any cards available
    if (cards_left == 0) {
        cout << "No more cards are available. Please shuffle first." << endl;
        return false;
    } else {
        // Display # of cards left
        cout << "There are " << cards_left << " cards in the deck." << endl;
        return true;
    }
}