//
// Created by abusa on 11/24/2021.
//

#ifndef HW2_AVLTREE_H
#define HW2_AVLTREE_H
#include "iostream"
using namespace std;

template <class T>
class AvlTree{
public:
    class AvlTree* leftSon;
    class AvlTree* rightSon;
    T data;

    AvlTree(T data):data(data),leftSon(nullptr),rightSon(nullptr){}
    ~AvlTree(){
        ClearTree(this);
    }
    AvlTree():data(T()),leftSon(nullptr),rightSon(nullptr){}

    AvlTree<T>* insert(AvlTree *root, T data);
    AvlTree<T>* removeNode(AvlTree* root, T data);
    AvlTree<T>* get(T data);
    asdjasdp
ersdfsdf

test test
};




#endif //HW2_AVLTREE_H
