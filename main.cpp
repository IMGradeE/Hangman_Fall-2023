#include <iostream>
#include "Headers/Game.h"
using namespace std;



int main() {
    char diffchoice;
    int difficulty;

    GameInstance* game = new GameInstance();

    cout << "\n    Choose between difficulty level 1 or 2 to Begin: ";

    START:
        cin >> diffchoice;
        if ((diffchoice == '1' || diffchoice == '2')) {
            difficulty = diffchoice - 49;
        } else {
            cout << "    Try again; select either 1 or 2:  ";
            goto START;
        }
    string w_or_p;

    switch (difficulty) {
        case 0:
            w_or_p = "word";
            break;
        case 1:
            w_or_p = "phrase";
            break;
    }

    game->init(difficulty);

    char choice = '0';
    do{
        bool winner = false;
        do {
            game->display(w_or_p);
            try {
                cout << "\n\n    Choose wisely: ";
                cin >> choice;
            } catch (exception) {
                cout << "\n\n    Please try again; only input one character.";
                continue;
            }
            choice = tolower(choice);
            if (game->checkValidity(choice)) {
                if (game->winCheck()) {
                    winner = true;
                    break;
                }
                continue;
            } else {
                game->wrongGuess();
                continue;
            }
        } while (game->getLives() > 0);

        game->display(winner);
        cout << "\n\n    continue? (n to quit)";
        cin >> choice;
        if(!game->nextWord() && choice != 'n'){
            cout << "You played every " + w_or_p + " available in this difficulty! I'll send you back to the menu.";
            goto START;
        }
    }while(choice != 'n');
    delete game;
}
