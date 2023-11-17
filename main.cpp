#include <iostream>
#include <sstream>
#include "Headers/Game.h"

using namespace std;
int main() {
bool winner = false;
int difficulty;
char choice;
/*cin >> difficulty;*/

GameInstance game = GameInstance(difficulty = 0);
do {
    game.display();
    try{
        cin >> choice;
    }catch (exception){
        cout << "\nPlease try again; only input one character.";
        continue;
    }
    choice = tolower(choice);
    if (game.checkValidity(choice)){
        if (game.winCheck()) {
            winner = true;
            break;
        }
        continue;
    }else{
        game.wrongGuess();
        continue;
    }
}while(game.getLives() > 0);

game.display(winner);

}