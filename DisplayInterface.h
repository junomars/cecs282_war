//
// Created by jonat on 2/7/2016.
//

#ifndef PROJECT_001_DISPLAYINTERFACE_H
#define PROJECT_001_DISPLAYINTERFACE_H

#include "Card.h"

class DisplayInterface {
public:
    virtual ~DisplayInterface() { }

    virtual void menu() = 0;

    virtual void winner(int score1, int score2) = 0;

    virtual bool cards_left(int cards_left) = 0;

    virtual void buffer_card(Card card) = 0;

    virtual void buffered_cards() = 0;

    virtual void display_message(std::wstring message) = 0;

    virtual wchar_t process_input() = 0;
};


#endif //PROJECT_001_DISPLAYINTERFACE_H
