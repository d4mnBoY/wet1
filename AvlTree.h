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
    AvlTree* insert(AvlTree* root, T dataToAdd)
    {
        if (root == nullptr)
            return new AvlTree<T>(dataToAdd);
        if(dataToAdd > root->data){
            root->rightSon = insert(root->rightSon ,dataToAdd);
            root = balanceTree(root);
        }
        else if(dataToAdd < root->data){
            root->leftSon = insert(root->leftSon, dataToAdd);
            root = balanceTree(root);
        }
        /*
        else {

        }*/// need to check about equals //throw ?
        return root;
    }
    AvlTree* balanceTree(AvlTree* root)
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
        return root;
    }
    int checkFactor(AvlTree* root){
        int leftHeight = height(root->leftSon);
        int rightHeight = height(root->rightSon);
        int Factor = leftHeight-rightHeight;
        return Factor;
    }
    AvlTree<T>* findSuccessor(AvlTree* root,AvlTree** parent){
        AvlTree* current=root->rightSon;
        *parent= nullptr;
        while(current->leftSon){
            *parent = current;
            current=current->leftSon;
        }
        return current;
    }
    AvlTree<T>* removeNode(AvlTree* root, T data)
    {

        if(root == nullptr)
            return root;//chekc if need throw
        if(data < root->data)
            root->leftSon = removeNode(root->leftSon,data);
        else if(data > root->data)
            root->rightSon = removeNode(root->rightSon,data);
        else{ // this is the node to remove
            AvlTree* temp1 = root;
            if( root->leftSon == nullptr || root->rightSon == nullptr){
                // mode with 1 child or 0 childes
                AvlTree* temp= root->leftSon ? root->leftSon : root->rightSon;
                if(temp == nullptr){
                    //0 childes
                    temp =root;
                    root = nullptr;
                } else{
                    root=temp;
                }
                //free(rootTemp); //fix this
            } else{
                // node with 2 childes
                AvlTree* parent = temp1;
                AvlTree* temp = findSuccessor(root,&parent);
                root=temp;
                if(parent != nullptr){
                    parent->leftSon=temp->rightSon;
                    root->leftSon = temp1->leftSon;
                    root->rightSon = temp1->rightSon;
                    //free(rootTemp);
                } else{
                    temp->leftSon = temp1->leftSon;
                    //free(rootTemp);
                }
            }

        }
        if(root == nullptr) //tree with 1 node
            return root;
        root = root->balanceTree(root);
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
        return tempb; //
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
    AvlTree<T>* getFather(T data)
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
            if (leftTree > rightTree)
                h = leftTree + 1;
            else
                h = rightTree + 1;
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
    /**
    void* inorderFunc(AvlTree* tree,func){// maybe needed
        if(tree == nullptr)
            return;
        inorder(tree->leftSon);
        func(data);
        inorder(tree->rightSon);
    }**/
    void postorder(AvlTree* tree){
        if(tree == nullptr)
            return;
        postorder(tree->leftSon);
        postorder(tree->rightSon);
        cout<<tree->data<<" ";
    }


    /*
* Display AVL Tree for testing ...
*/
    void display(AvlTree *ptr, int level)
    {
        int i;
        if (ptr!=NULL)
        {
            display(ptr->rightSon, level + 1);
            printf("\n");
            if (ptr )
                cout<<"Root -> ";
            for (i = 0; i < level && ptr ; i++)
                cout<<"        ";
            cout<<ptr->data;
            display(ptr->leftSon, level + 1);
        }
    }
    AvlTree& operator=(const AvlTree&) = default;
};

template <class T>
void ClearTree(AvlTree<T>* tree){
    if(tree != nullptr){
        ClearTree(tree->leftSon);
        ClearTree(tree->rightSon);
        //delete &(tree->data); // fix this
    }
}


#endif //HW2_AVLTREE_H
