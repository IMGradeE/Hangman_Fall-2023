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
#include "ASCII.h"
class GameInstance{
private:
    boolean wincond;
    string easy[20]{};
    string hard[20]{};
    int lives = 7;
    List<char>* characterList = nullptr;
    Queue<string>* frameQueue = nullptr;
    string lostSplashScreen[4] ={ "      l\\  r/ |--| |  |   |--\\ --- |--- |--\\    \n",
                                  "       l\\r/  |  | |  |   |  |  |  |___ |  |    \n",
                                  "        t|t   |  | |  |   |  |  |  |    |  |    \n",
                                  "        t|t   |__| |__|   |__/ ___ |___ |__/    \n"};
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
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
        ss << frameQueue->getFrame();
        cout << ss.str();
        cout << characterList;
    }

    void display(bool w){
        stringstream ss;
        cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
        ss << frameQueue->getFrame();
        cout<<ss.str();
        ss.clear();

        if (w){
            cout << "";
        }else{
            cout << frameQueue->getFrame();
            for(string s: lostSplashScreen) {
                ss << ASCIIRender().enhance(s);
            }
            cout << ss.str();
        }
    }


    bool checkValidity(char val){
        if(characterList->find(val)){
            characterList->removeAllMatches(val);
            return true;
        }else{
            return false;
        }
    }

    bool winCheck(){
        auto temp = characterList->head;

        while(temp){
            if (islower(temp->nodeData)) {
                return false;
            }
            temp = temp->next_node;
        }
        return true;
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
