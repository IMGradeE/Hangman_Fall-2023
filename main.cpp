#include <iostream>
#include <sstream>
#include "Queue.h"
#include <windows.h>
using namespace std;
/*
    class Node {
    public:


        // if frame x, from y+ print data=0:0 (empty)
        bool isHung = false;
        int count;
        Node* nextNode;
        Node(int val):nextNode(nullptr){
            int count = 0;
            stringstream stringstream1;

            if (val == 0){ // counting up
                isHung = true;
            }
            if (val > 0)
                ;

        }


        ~Node(){
            delete nextNode;
        }
    };


class QUEUE {
public:

    QUEUE():head(nullptr){
    }

    Node* head;

    enum main_menu{
        QUIT = 0,
        ADD,
        REMOVE,
        PEEK,
        OVERLOAD
    };


    bool isEmpty(){
        if(head == nullptr){
            return true;
        }else{
            return false;
        }
    }

    void add(int val){
        Node* temp = new Node(val);
        if(isEmpty())
        {
            head = temp;
            temp = nullptr;
            delete temp;
        }
        else
        {
            auto temp2 = head;
            while(temp2->nextNode != nullptr)
                temp2 = temp2->nextNode;
            temp2->nextNode = temp;

            temp2 = nullptr;
            temp = nullptr;
            delete temp2;
            delete temp;
        }
    }

    void remove() {
        if(!isEmpty()){
            auto temp = head->nextNode;
            head->nextNode = nullptr;
            delete head;
            head = temp;
            temp = nullptr;
            delete temp;
        }
    }


    string peek(){
        stringstream ss;
        if(!(isEmpty())){
            ss << head->data;
            return  "\"" + ss.str() + "\"";
        }else{
            return "\nStack is empty.\n";
        }
    }

    void test(){
        int arr [5] = {1,2,3,4,5};
        for (int i: arr) {
            add(i);
        }
    }
    ~QUEUE(){
        delete head;
    }
};


ostream &operator<<( ostream &out *//*LHS*//*, QUEUE* s *//*RHS*//*){
    Node* temp = s->head;
    while (temp != nullptr){
        stringstream ss;
        ss << temp->data;
        out << "\"" + ss.str() +  "\",";
        temp = temp->nextNode;
        ss.clear();
    }
    temp = nullptr;
    delete temp;
    out << "\n";
    return out;
}*/

int main() {
    for(int i = 0; i < 7; ++i) {
        unique_ptr<HangManImageFrame> frame(new HangManImageFrame(i));
        cout << frame->frame;
        Sleep(2000);
        cout << '\n'<< '\n'<< '\n'<< '\n'<< '\n';
    }
return 0;
}