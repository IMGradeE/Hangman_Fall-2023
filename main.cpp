#include <iostream>
#include <sstream>
#include "Headers/Game.h"

using namespace std;
int main() {
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
        continue;
    }else{
        game.wrongGuess();
        continue;
    }
}while(game.getLives() > 0);

game.display();

}