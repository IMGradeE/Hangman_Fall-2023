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

    string wordsxphrases[2][20]{{"shrek",
                     "coriander",
                     "slay",
                     "queen",
                     "giving",
                     "work",
                     "word",
                     "kick",
                     "slick",
                     "tick",
                     "sick",
                     "innocent",
                     "guilty",
                     "reward",
                     "punishment",
                     "vocabulary",
                     "near",
                     "far",
                     "done",
                     "finished"},{"thirty to fifty feral hogs",
            "stun amogus",
            "say sike right now",
            "mean girls",
            "don't be a menace to south central while sipping your juice in the hood",
            "chinese room",
            "callous daoboys",
            "invent animate",
            "arizona iced tea",
            "knocked loose",
            "deep in the willow",
            "everything is quiet now",
            "djent is not a genre",
            "made up words",
            "irony means getting a degree in trigonometry",
            "fair trial",
            "descartes really crossed a line", // this is the best one
            "bored ape to blind ape pipeline",
            "phrase nineteen",
            "great job everyone"}};



    int lives = 7;
    List<char>* characterList = nullptr;
    Queue<string>* frameQueue = nullptr;
    string lossIndicator[4] ={"l\\  r/ |--| |  |  |--\\ --- |--- |--\\  \n",
                              " l\\r/  |  | |  |  |  |  |  |___ |  |  \n",
                              "  t|t   |  | |  |  |  |  |  |    |  |  \n",
                              "  t|t   |__| |__|  |__/ ___ |___ |__/  \n"};


public:
    GameInstance(int diffChoice = 1){
        frameQueue = (new Queue<string>());
        characterList = new List<char>(wordsxphrases[diffChoice-1][ASCIIRender().randomIndex(20)]);
        frameQueue->getHangmanQueue();
    }

    void display(){
        stringstream ss;
        ASCIIRender().clearConsole();
        ss << frameQueue->getFrame();
        cout << ss.str();
        cout << "    Your word is : " << characterList << "\n";
    }

    void display(bool w){
        stringstream ss;
        ASCIIRender().clearConsole();
        ss << frameQueue->getFrame();
        cout<<ss.str();
        ss.clear();
        Sleep(1000);
        if (w){
            cout << "    You are free to go.";
        }else{
            cout << frameQueue->getFrame();
            for(string s: lossIndicator) {
                ss << ASCIIRender().enhance(s);
            }
            cout << ss.str();
        }
    }


    bool checkValidity(char val){
        if(characterList->find(val)){
            characterList->removeAllMatches(val);
            return true;
        }else if(characterList->find(toupper(val))){
            cout << "\n    You have already guessed "<< val << ", try again.\n     ";
            cin >> val;
            return checkValidity(val);
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

};
#endif //QUEUE2_GAME_H
