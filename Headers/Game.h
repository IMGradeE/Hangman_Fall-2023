//
// Created by wilke on 10/30/2023.
//

#ifndef QUEUE2_GAME_H
#define QUEUE2_GAME_H
#include <iostream>
#include <sstream>
#include <Windows.h>
#include "Queue.h"
#include "list.h"
class GameInstance{
private:
    boolean wincond;
    string easy[20]{};
    string hard[20]{};
    int lives = 7;
    List<char>* characterList = nullptr;
    Queue<string>* frameQueue = nullptr;
public:
    GameInstance(int diffChoice):wincond(false){
        frameQueue = (new Queue<string>());
        characterList = new List<char>("giving");
        frameQueue->getHangmanQueue();

        // remove all matches until list all uppercase, or loss.
        /*hard->append("giving");
        easy->append("giving");*/
        //take a word at random from array corresponding to difficulty choice
    }
    // if find == nullptr --lives
    void display(){
        stringstream ss;
        ss << frameQueue->getFrame();
        cout << ss.str();
        cout << characterList;
    }

    bool checkValidity(char val){
        if(characterList->find(val)){
            characterList->removeAllMatches(val);
            return true;
        }else{
            return false;
        }
    }

    int getLives(){
        return lives;
    }

    void wrongGuess(){
        --lives;
        frameQueue->remove();
    }


    /*
     * do {
            cout << "\n\n\n\n\n\n\n\n\n\n";
            cout << frameQueue->getFrame();
            Sleep(1000);
        } while (frameQueue->remove() && !wincond);
     * */
};
#endif //QUEUE2_GAME_H
