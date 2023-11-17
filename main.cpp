#include <iostream>
#include <sstream>
#include "Headers/Game.h"
#include <windows.h>

using namespace std;
int main() {
bool winner = false;
int difficulty;
char choice = '0';
ASCIIRender ascii = ASCIIRender();

stringstream ss;
string titleCard[10] = {
                        "| | r/l\\ |l\\ |t|-- |l\\r/| r/l\\ |l\\ |\n",
                       "|-|r/r\\l\\| l\\|t|_/ | l/ |r/r\\l\\| l\\|\n"};
ss<< "\n\n\n";
for (int i = 0; i <3;++i){
    for (string s: titleCard) {
        ss << ascii.enhance(s)+ "\n\n";
    }
}
cout << ss.str();
ss.clear();
cout << "\n    Choose between difficulty level 1 or 2 to Begin: ";

cin >> difficulty;
    do{
        GameInstance game = GameInstance(difficulty);
        do {
            game.display();
            try {
                cout << "\n\n    Choose wisely: ";
                cin >> choice;
            } catch (exception) {
                cout << "\n\n    Please try again; only input one character.";
                continue;
            }
            choice = tolower(choice);
            if (game.checkValidity(choice)) {
                if (game.winCheck()) {
                    winner = true;
                    break;
                }
                continue;
            } else {
                game.wrongGuess();
                continue;
            }
        } while (game.getLives() > 0);

        game.display(winner);
        cout << "\n\n    continue? (n to quit)";
        cin >> choice;
    }while(choice != 'n');
}