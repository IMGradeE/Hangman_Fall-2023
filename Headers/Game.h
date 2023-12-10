//
// Created by wilke on 10/30/2023.
//

#ifndef QUEUE2_GAME_H
#define QUEUE2_GAME_H
#include <iostream>
#include <sstream>
#include <Windows.h>
#include "Queue.h"
#include "SingleLinkedList.h"
#include "HangmanGraphics.h"
#include "CircularlyLinkedList.h"

class GameInstance{
private:
    int lives = 7;
    ASCIIRender ascii;
    CircularlyLinkedList* words = nullptr;
    Queue<string>* frameQueue;
    List<char>* characterList;
    Graphics* graphics = new Graphics();

    void getWords(int difficulty){
        words = new CircularlyLinkedList(difficulty);
    }

    void setCharacterList(){
        default_random_engine engine;
        uniform_int_distribution<int> distribution(0,20);
        characterList = new List<char>(words->pop(distribution(engine)));
    }


public:

    GameInstance():words(nullptr),characterList(nullptr),frameQueue(nullptr){}

    void init(int difficulty){
        getWords(difficulty);
        setCharacterList();
        frameQueue = (new Queue<string>());
        frameQueue->getHangmanQueue();
        graphics->pseudo_animation(0);
    }

    bool nextWord(){
        if(words->isempty()){
            return false;
        }
        setCharacterList();
        frameQueue = (new Queue<string>());
        frameQueue->getHangmanQueue();
        return true;
    }


    void display(string w_or_p){
        stringstream ss;
        ascii.clearConsole();
        ss << frameQueue->getFrame();
        cout << ss.str();
        cout << "    Your " + w_or_p + " is : " << characterList << "\n";
    }

    void display(bool w){
        stringstream ss;
        ascii.clearConsole();
        ss << frameQueue->getFrame();
        cout<<ss.str();
        ss.clear();
        Sleep(1000);
        if (w){
            cout << "    You are free to go.";
        }else{
            cout << frameQueue->getFrame();
            graphics->pseudo_animation(1);
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
