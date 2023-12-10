//
// Created by wilke on 12/9/2023.
//

#ifndef QUEUE2_CIRCULARLYLINKEDLIST_H
#define QUEUE2_CIRCULARLYLINKEDLIST_H
#include <sstream>

using namespace std;

struct CircNode{
    CircNode* next;
    CircNode* prev;
    string data;
    CircNode(const string s): next(nullptr), prev(nullptr), data(s){}
};

class CircularlyLinkedList{
private:
    CircNode* head;
    string wordsxphrases[2][20]
    {
        {"shrek",
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
                                        "finished"},
                                {"thirty to fifty feral hogs",
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
public:
    CircularlyLinkedList(int arraySelector):head(nullptr){
        for (int i = 0; i < 20; ++i) {
            string s = wordsxphrases[arraySelector][i];
            insert(s);
        }
    }
    CircularlyLinkedList(){}

    bool isempty(){
        if (head){
            return false;
        }else{
            return true;
        }
    }

    string pop(int n){
        if(!isempty()){
            for (int i = 0; i < n; ++i) {
             head = head->next;
            }
            string ret = head->data;

            auto headnext = head->next;
            auto headprev = head->prev;
            headprev->next = headnext;
            headnext->prev = headprev;
            head = headnext;

            return ret;
        }else{

            return " ";
        }
    }

    void insert(const string s){
        auto newitem = new CircNode(s);
        if (isempty()){
            head = move(newitem);
            head->next = head;
            head->prev = head;
        }else{
            newitem->prev = head;
            newitem->next = head->next;
            head->next->prev = newitem;
            head->next = newitem;
        }
    }

};

#endif //QUEUE2_CIRCULARLYLINKEDLIST_H
