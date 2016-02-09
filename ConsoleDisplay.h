//
// Created by jonat on 2/7/2016.
//

#ifndef PROJECT_001_CONSOLEDISPLAY_H
#define PROJECT_001_CONSOLEDISPLAY_H


#include <windows.h>
#include <vector>
#include <fcntl.h>
#include <array>
#include <io.h>
#include <iostream>
#include "Card.h"
#include "DisplayInterface.h"

class ConsoleDisplay : public DisplayInterface {
private:
    std::vector<Card> cards;
    std::array<std::wstring, 9> output;
protected:
public:
    ConsoleDisplay() { _setmode(_fileno(stdout), _O_U16TEXT); }

    virtual void menu();

    virtual void winner(int score1, int score2);

    virtual bool cards_left(int cards_left);

    virtual void buffer(Card card);

    virtual void buffer(Deck deck);

    virtual void buffered_cards();

    void deck_to_str(Deck deck);

    virtual void display_message(std::wstring message);

    virtual wchar_t process_input();
};

#endif //PROJECT_001_CONSOLEDISPLAY_H
