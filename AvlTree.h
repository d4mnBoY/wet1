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
    AvlTree():data(T()),leftSon(nullptr),rightSon(nullptr){}
    ~AvlTree(){
        ClearTree(this); // we should define this
    }
    AvlTree<T>* insert(AvlTree *root, T data)
    {
        if (root== nullptr)
            return new AvlTree<T>(data);
        if(data>root->data){
            insert(root->rightSon ,data);
            balanceTree(root);
        }
        else if(data<root->data){
                insert(root->leftSon, data);
                balanceTree(root);
        }
        else {

        }// need to check about equals //throw ?
        return root
    }
    void balanceTree(AvlTree* root)
    {
        int factor= checkFactor(root);  // we get this from the tree
        if(factor > 1){
            //ll rotation or lr rotation
            if(checkFactor(root->leftSon)==-1)
                root=lrRotation(root);
            else root= llRotation(root);
        }
        if(factor < -1){
            //rr rotation or rl rotation
            if(checkFactor(root->rightSon)==1)
                root=rlRotation(root);
            else root= rrRotation(root);
        }
    }
    int checkFactor(AvlTree* root){
        return height(root->rightSon)-height(root->leftSon);
    }

    AvlTree<T>* findSuccessor(AvlTree* root){
        AvlTree* temp=root->rightSon;
        AvlTree* tempFather=root;
        while(temp->leftSon){
            tempFather=temp;
            temp=temp->leftSon;
        }
        if(temp->rightSon)
            tempFather->leftSon=temp->rightSon;
        return temp;
    }

    AvlTree<T>* removeNode(AvlTree* root, T data)
    {
        if(root == nullptr)
            return root;//chekc if need throw
        if (data== nullptr)
            return root;//chekc if need throw
        AvlTree<T>* toDelete = get(data);
        if (toDelete== nullptr)
            return root;//chekc if need throw
        if(toDelete->leftSon == nullptr || toDelete->rightSon == nullptr ){
            AvlTree* temp = toDelete->leftSon ? toDelete->leftSon : toDelete->rightSon;
            if(temp == nullptr){
                AvlTree* father = getFather(toDelete);
                if(father->leftSon == toDelete){
                    father->leftSon = nullptr;}
                else{
                    father->rightSon = nullptr;}
                temp = toDelete;
                toDelete = nullptr;
            } else{
                AvlTree* father = getFather(toDelete);
                if(father->leftSon == toDelete){
                    father->leftSon == temp;}
                else {
                    father->rightSon == temp;}
                toDelete=temp;
            }
            delete (temp);
        } else{
            AvlTree* successor= findSuccessor(toDelete);
            successor->leftSon=toDelete->leftSon;
            successor->rightSon=toDelete->rightSon;
            //father point to succesor
            AvlTree* father = getFather(toDelete);
            if(father->leftSon == toDelete){
                father->leftSon=successor;
            } else {
                father->rightSon=successor};
            delete(toDelete);
        }
        balanceTree(root);
        return root;
    }
    AvlTree<T>* rrRotation(AvlTree* root)
    {
        AvlTree* temp= root->rightSon;//a
        root->rightSon = temp->leftSon;//b->ar
        temp->leftSon=root;//a->b
        return temp;
    }
    AvlTree<T>* rlRotation(AvlTree* root)
    {
        AvlTree* tempb= root->rightSon->leftSon;
        AvlTree* tempa= root->rightSon;
        root->rightSon=tempb->leftSon;//c->br
        tempa->leftSon=tempb->rightSon;//
        tempb->rightSon=tempa;
        tempb->leftSon=root;
        return tempb;
    }
    AvlTree<T>* lrRotation(AvlTree* root)
    {
        AvlTree* tempb= root->leftSon->rightSon;
        AvlTree* tempa= root->leftSon;
        root->leftSon=tempb->rightSon;//c->br
        tempa->rightSon=tempb->leftSon;//
        tempb->leftSon=tempa;
        tempb->rightSon=root;
        return tempb;
    }
    AvlTree<T>* llRotation(AvlTree* root)
    {
        AvlTree* temp= root->leftSon;//a
        root->leftSon = temp->rightSon;//b->ar
        temp->rightSon=root;//a->b
        return temp;
    }
    AvlTree<T>* get(T data)
    {
        if(this==nullptr)
            return nullptr;
        if(this->data == data)
            return this;
        else if(this->leftSon && this->data > data)
            return this->leftSon->get(data);
        else if(this->rightSon && this->data < data)
            return this->rightSon->get(data);
        return nullptr;
    }
    AvlTree<T>* getFather(T data) // fix this
    {
        if(this==nullptr)
            return nullptr;
        if(this->rightSon->data == data||this->leftSon->data == data)
            return this;
        else if(this->leftSon && this->leftSon->data > data)
                return this->leftSon->getFather(data);
        else if(this->rightSon && this->rightSon->data < data)
                return this->rightSon->getFather(data);
        return nullptr;
    }
    int height(AvlTree* tree)
    {
        int h=0;
        if(tree != nullptr) {
            int leftTree = height(tree->leftSon);
            int rightTree = height(tree->rightSon);
            if (leftTree > rightTree){
                h = leftTree + 1;
            }
            else {
                h = rightTree + 1;
            }
        }
        return h;
    }


    void preorder(AvlTree* tree){
        if(tree == nullptr)
            return;
        cout<<tree->data<<" ";
        inorder(tree->leftSon);
        inorder(tree->rightSon);

    }
    void inorder(AvlTree* tree){
        if(tree == nullptr)
            return;
        inorder(tree->leftSon);
        cout<<tree->data<<" ";
        inorder(tree->rightSon);
    }
    void postorder(AvlTree* tree){
        if(tree == nullptr)
            return;
        postorder(tree->leftSon);
        postorder(tree->rightSon);
        cout<<tree->data<<" ";
    }

};

template <class T>
void ClearTree(AvlTree<T>* tree){
    if(tree != nullptr){
        ClearTree(tree->leftSon);
        ClearTree(tree->rightSon);
        delete &(tree->data);
    }
}


#endif //HW2_AVLTREE_H
