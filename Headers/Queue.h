//
// Created by wilke on 9/27/2023.
//
#ifndef PROJECT_TEAM_QUEUE_H
#define PROJECT_TEAM_QUEUE_H

#include <iostream>
#include <sstream>
#include <Windows.h>
#include "HangManImage.h"

using namespace std;

template<class T>
class Queue{

public:
    struct Node{
       shared_ptr<Node> next_node;
       T Frame;
       Node(T val):Frame(val),next_node(nullptr){}
   };
    shared_ptr<Node> head = nullptr;

    Queue<T>(){
    }
    void getHangmanQueue();
    T getFrame();
    boolean remove();
    boolean isEmpty();
    void add(T data);
};

template<class T>
void Queue<T>::getHangmanQueue() {
    for(int i = 0; i <= 7; ++i) {
       this->add(HangManImageFrame(i).getFrame());
    }
}

//private
template<class T>
boolean Queue<T>::isEmpty() {
    if(head == nullptr){
        return true;
    }
    return false;
}

template<class T>
void Queue<T>::add(T data) {
    shared_ptr<Node> temp(new Node(data));
    if (isEmpty()){
        head = temp;
        return;
    }
    auto current = head;
    while(current->next_node != nullptr){
        current = current->next_node;
    }
    current->next_node = temp;
}

template<class T>
T Queue<T>::getFrame(){
    if(isEmpty()){
        return NULL;
    }
    return head->Frame;
}

template<class T>
boolean Queue<T>::remove() {
    try{
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        auto temp = head->next_node;
        head = nullptr;
        head = temp;
        return true;
    }catch (exception){
        return false;
    }
}

#endif //PROJECT_TEAM_QUEUE_H
