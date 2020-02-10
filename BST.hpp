#ifndef BST_HPP
#define BST_HPP

#include <iostream>

#include "BSTNode.hpp"

template <class T>
class BST {
public: // DO NOT CHANGE THIS PART.
    BST();
    BST(const BST<T> &obj);

    ~BST();

    BSTNode<T> *getRoot();

    void insert(const T &data);
    void remove(const T &data);
    BSTNode<T> *find(const T &data);
    void printInorder();

    BST<T> &operator=(const BST<T> &rhs);
    

private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.
    void printInorder(BSTNode<T> *node);
    void copyhelper(BSTNode<T>* &to,const BSTNode<T> *obje) const;
    void inserthelper(BSTNode<T>* &r,const T &data);
    BSTNode<T> *findhelper(BSTNode<T>* &r,const T &data);
    void equalhelper(BSTNode<T>* n1);
    T getmin(BSTNode<T>* r){
          if (r->left == NULL)
              return r->data;
          else
              return getmin(r->left);
        }
    void removehelper(BSTNode<T>* &r,const T &data);
    void removeall(BSTNode<T>* r);



private: // DO NOT CHANGE THIS PART.
    BSTNode<T> *root;
};

#endif //BST_HPP

template <class T>
BST<T>::BST() {
    
    //root=new BSTNode<T>;
    root=NULL;
    //root -> left= NULL;
    //root -> right=NULL; //root=NULL?????


    /* TODO */
}
template <class T>
void BST<T>::copyhelper(BSTNode<T>* &to,const BSTNode<T> *obje) const //helperrrr
{
    if(obje==NULL)
    {
        to=NULL;
    }
    else
    {
        to = new BSTNode<T>;
        to->data = obje->data;
        copyhelper(to->left,obje->left);
        copyhelper(to->right,obje->right);
        //copyhelper(to->root,obje->root);
    }
}
    

template <class T>
BST<T>::BST(const BST<T> &obj) {

    copyhelper(this->root,obj.root);
   
}
template <class T>
void BST<T>::removeall(BSTNode<T>* r)
{
    if(r)
    {
        removeall(r->right);
        removeall(r->left);
        delete r;
        r=NULL;
    }
}
template <class T>
BST<T>::~BST() {
    
    removeall(root);

    /* TODO */
}

template <class T>
BSTNode<T> *BST<T>::getRoot() {

    if(root==NULL) return NULL;
    return root;
   
}
template<class T>
void BST<T>::inserthelper(BSTNode<T>* &r,const T &data) //helperrrr
{
    if(r==NULL)
    {
        r=new BSTNode<T>;
        r->data=data;
        
    }
    else if(r->data == data) return;
    else if(r->data < data){
        if(r->right != NULL) inserthelper(r->right,data);
        else r->right=new BSTNode<T>(data,NULL,NULL);
                            }
    else if(r->data > data){
        if(r->left!=NULL) inserthelper(r->left,data);
        else r->left=new BSTNode<T>(data,NULL,NULL);
                            }
    else{
        return;
}
    
}
template <class T>
void BST<T>::insert(const T &data) {

    inserthelper(this->root,data);

    /* TODO */
}
template <class T>
void BST<T>::removehelper(BSTNode<T>* &r,const T &data)
{
    if(r==NULL) return;
    else if(r->data < data) removehelper(r->right,data);
    else if(r->data > data) removehelper(r->left,data);
    else
    {
        if(r->left != NULL && r->right != NULL){
            r->data=getmin(r->right);
            removehelper(r->right,r->data);
            }
        else{
            BSTNode<T>* temp=r;
            if(r->left!=NULL) r=r->left;
            else r=r->right;
            delete temp;
            temp=NULL;
            }
    }
}
template <class T>
void BST<T>::remove(const T &data) {
    removehelper(root,data);

    /* TODO */
}
template<class T>
BSTNode<T> *BST<T>::findhelper(BSTNode<T>* &r,const T &data){
    if(r==NULL) return NULL;
    else if(r->data==data) return r;
    else if(r->data > data) findhelper(r->left,data); //sonrdan return ekledim
    else if(r->data < data) findhelper(r->right,data); //sonradan return ekledim
    else return NULL;

}

template <class T>
BSTNode<T> *BST<T>::find(const T &data) {
    findhelper(this->root,data); // ** sonradan return ekledim
    /* TODO */
}

template <class T>
void BST<T>::printInorder() {

    if (root == NULL) {
        std::cout << "{}" << std::endl;
    } else {
        std::cout << "{" << std::endl;
        printInorder(root);
        std::cout << std::endl << "}" << std::endl;
    }
}

template <class T>
void BST<T>::printInorder(BSTNode<T> *node) {

    if (node == NULL)
        return;

    printInorder(node->left);
    if (node->left) {
        std::cout << "," << std::endl;
    }
    std::cout << "\t" << node->data;
    if (node->right) {
        std::cout << "," << std::endl;
    }
    printInorder(node->right);
}
template<class T>
void BST<T>::equalhelper(BSTNode<T> *n1)
{
    if(n1 != NULL)
    {
        this->insert(n1->data);
        equalhelper(n1->left);
        equalhelper(n1->right);
    }
}
template <class T>
BST<T> &BST<T>::operator=(const BST<T> &rhs) {

    if(this != &rhs)
    {
        removeall(root);
        BSTNode<T> *curr=rhs.root;
        equalhelper(curr);
    }
    return *this;

    /* TODO */
}
