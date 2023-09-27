#include <iostream>
#include <sstream>

using namespace std;

template<class Y>
    class Node {
    public:
        Y data;
        Node<Y>* nextNode;
        Node(Y val = NULL):data(val),nextNode(nullptr){
        }
        ~Node(){
            delete nextNode;
        }
    };

template<class T>
class QUEUE {
public:

    QUEUE():head(nullptr){
    }

    Node<T>* head;

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

    void add(T val){
        Node<T>* temp = new Node<T>(val);
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

template<class T>
ostream &operator<<( ostream &out /*LHS*/, QUEUE<T>* s /*RHS*/){
    Node<T>* temp = s->head;
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
}

int main() {
    QUEUE<int> fifo;
    int intin;
    int choice = 0;
    bool quit = false;
    fifo.test();
        do{
        cout << "\nPlease enter the number that corresponds to the desired operation:\n"
                "0. Quit;\n"
                "1. Add int to queue;\n"
                "2. Delete int from queue (last added is removed);\n"
                "3. Peek (Returns the value next in line);\n"
                "4. Overload (Returns all values in the queue in order);\n";
        cin >> choice;
        choice = static_cast<QUEUE<int>::main_menu>(choice);
        switch (choice) {
            case QUEUE<int>::QUIT:{
                quit = true;
                break;
            }
            case QUEUE<int>::ADD:{
                cout << "\n Please enter the integer you want to add to the list, "
                        "then press enter. (Do not include spaces, and press 0 to stop.)\n";
                do{
                    cout << "\n Please enter the integer you want to add to the list, "
                            "then press enter. (Do not include spaces, and press 0 to stop.)\n";
                    cin >> intin;
                    if(intin!=0)
                        fifo.add(intin);
                }while(intin != 0);
                break;
            }
            case QUEUE<int>::REMOVE:{
                fifo.remove();
                break;
            }
            case QUEUE<int>::PEEK:{
                cout << fifo.peek();
                break;
            }
            case QUEUE<int>::OVERLOAD:{
                cout << &fifo;
                break;
            }
            default:
                choice = -1;
                cout<< "\nThat input was not valid, please try again.\n";
                break;
        }
        cout << "\n\n";
    }while(!quit);
}