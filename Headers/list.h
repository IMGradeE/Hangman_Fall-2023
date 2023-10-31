//
// Created by wilke on 10/30/2023.
//

#ifndef QUEUE2_LIST_H
#define QUEUE2_LIST_H

class List{
public:
    struct Node{
        shared_ptr<Node> next_node;
        shared_ptr<Node> last_node;
        string Word;
        Node(string val):
        Word(val),next_node(nullptr),last_node(nullptr){}
    };

    shared_ptr<Node> head = nullptr;
    shared_ptr<Node> tail = nullptr;

    List():tail(nullptr),head(nullptr){}

    boolean isEmpty(){
        if(head == nullptr){
            return true;
        }
        return false;
    }

    void add(string data){
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
    };
};
#endif //QUEUE2_LIST_H
