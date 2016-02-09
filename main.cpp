#include <iostream>
#include "Deck.h"
#include "ConsoleDisplay.h"

using namespace std;

int main() {
    // TODO: Go through program, any array or vector of type card should be converted to deck.
    // TODO: Deck should be modified to contain a dynamic amount of cards
    ConsoleDisplay display;
    Deck deck;

    deck.add(Card(ACE, SPADES));

    display.deck_to_str()

}
/**
Card dealt_card;
int play_score;
int comp_score;
bool again = true;

while (again) {
    // Present menu for input
    display.menu();

    // From the input follow the appropriate path
    switch (display.process_input()) {
        case '1':
            // Get a new buffered_cards deck
            deck.reset_deck();
            break;
        case '2':
            // Show all cards in the deck
            // TODO: this
            break;
        case '3':
            // Show remaining cards in the deck
            // TODO: this
        case '4':
            // Shuffle
            deck.shuffle();
            break;
        case '5':
            // Get ready to loop
            display.display_message(L"Get ready to play two-card WAR!!!\n");
            display.cards_left(deck.cards_left());

            while (deck.cards_left() > 0) {
                // zero out pass plays
                play_score = 0;
                comp_score = 0;

                // Deal the cards
                // TODO: change to a loop so we can play 1...n card war
                display.display_message(L"...dealing...\n");
                display.display_message(L"One for you...\n\t");
                dealt_card.set_card(deck.deal());
                display.buffer_card(dealt_card);
                display.buffered_cards();
                play_score += dealt_card.get_value();

                display.display_message(L"One for me...\n\t");
                dealt_card.set_card(deck.deal());
                display.buffer_card(dealt_card);
                display.buffered_cards();
                comp_score += dealt_card.get_value();

                display.display_message(L"Two for you...\n\t");
                dealt_card.set_card(deck.deal());
                display.buffer_card(dealt_card);
                display.buffered_cards();
                play_score += dealt_card.get_value();

                display.display_message(L"Two for me...\n\t");
                dealt_card.set_card(deck.deal());
                display.buffer_card(dealt_card);
                display.buffered_cards();
                comp_score += dealt_card.get_value();

                // Print winners
                display.winner(play_score, comp_score);

                // Check to see if we can play first
                if (!display.cards_left(deck.cards_left()))
                    break;

                // Ask to play again
                display.display_message(L"Wanna play again? ");
                if (tolower(display.process_input()) != 'y')
                    break;
            }
            break;
        case '6':
            // Exit otherwise
            again = false;
    }
};
return 0;
}*/