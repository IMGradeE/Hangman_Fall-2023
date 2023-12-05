//
// Created by wilke on 12/4/2023.
//


#ifndef QUEUE2_BINARYSEARCHTREE_H
#define QUEUE2_BINARYSEARCHTREE_H
#include <memory>
using namespace std;

template <class t>
struct Node{
    shared_ptr<Node> left;
    shared_ptr<Node> right;
    t data;
    Node(t val):left(nullptr),right(nullptr),data(val){}
};

template <class t>
class BST{
    BST(){}
    void insert(){

    }
};
#endif //QUEUE2_BINARYSEARCHTREE_H
