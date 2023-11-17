//
// Created by wilke on 10/30/2023.
//

#ifndef QUEUE2_LIST_H
#define QUEUE2_LIST_H
template<class Type>
class List;



template <class Type>
class List{
public:
    struct Node{
        Node* next_node;

        Type nodeData;
        Node(Type val):
                nodeData(val), next_node(nullptr){}
    };
    Node* head = nullptr;


    List<Type>():head(nullptr){}

    List<Type>(string data):head(nullptr){
        for (Type i : data){
            add(i);
        }
    }

    boolean isEmpty(){
        if(head == nullptr){
            return true;
        }
        return false;
    }

    void add(Type data){
        auto temp = new Node(data);
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

    Node* find(Type val){
        auto temp = this->head;

        while(temp && temp->nodeData != val){
            temp = temp->next_node;
        }
        return temp;
    }
    void removeAllMatches(Type val){
        auto temp = find(val);
        if (temp){
            temp->nodeData = toupper(temp->nodeData);
            removeAllMatches(val);
        }
    }

friend ostream& operator<<(ostream &out, List<Type>* list){
    Node* temp = list->head;
    while(temp){
        if (isalpha(temp->nodeData)){
            if(temp->nodeData == tolower(temp->nodeData)) {
                out << '_';
            }else{
                char c = tolower(temp->nodeData);
                out << c;
            }
        }else if(temp->nodeData == ' '){
            out << ' ';
        }else if (temp->nodeData == '\''){
            out << '\'';
        }
        temp = temp->next_node;
    }

    return out;
}

};

#endif //QUEUE2_LIST_H
