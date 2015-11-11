#ifndef AVL_HPP
#define AVL_HPP
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

template<typename T>
struct AVLTreeNode
{
    T data;
    AVLTreeNode* left;
    AVLTreeNode* right;
    int balanceFactor;

    AVLTreeNode() : left(NULL), right(NULL)
    { }

    ~AVLTreeNode(){
        delete left;
        delete right;
    }
    #if 0
    void print(int indent)
    {
        for(int i = 0; i < indent; ++i)
            cout << "\t";
        cout << data << endl;

        left->print(indent + 1);
        right->print(indent + 1);
    }
    #endif
};


template <typename T>
class AVL {
private:
  // put your private functions here (you will probably have quite a few)
    AVLTreeNode<T>* root;
public:
    std::vector<std::string> List;
    AVL() : root(NULL)
    {}

    ~AVL();


    // Insert a node into the AVL with a given data value
    // The tree must be balanced after every insert
    void insert(const T&);
    void insertNode(AVLTreeNode<T>* newNode, AVLTreeNode<T>* parent);
    void fillList(AVLTreeNode<T>* node);
    AVLTreeNode<T>* findNodebyvalue(T n);


//    void Delete(int key);  // Not implemented yet

  // remove a node from the AVL with a specific data value
  // you MUST use the in order predecessor to replace the removed node
    void remove(AVLTreeNode<T>& n);


    // return a std::vector<std::string> of the serialized AVL tree
    // you WILL need to have template specialization for AVL<int> and AVL<std::string>
    // std::to_string(int) can be used to convert an integer to a string
    std::vector<std::string> preorder_serialize();
    void preorder_serialize(AVLTreeNode<T>*);
};

//template <class T>
//AVL<T>::AVL()
//{
//    root = NULL;
//}

template <typename T>
AVL<T>::~AVL()
{
    delete root;
}

template <typename T>
void AVL<T>::insert(const T& data)
{
    if(root == NULL){
        root = new AVLTreeNode<T>();
        root->data = data;

    }
    else{
        AVLTreeNode<T>* newNode = new AVLTreeNode<T>;
        newNode->data = data;
        insertNode(newNode, root);

    }
}
    //if not empty search for a spot to put it
template <typename T>
void AVL<T>::insertNode(AVLTreeNode<T>* newNode, AVLTreeNode<T>* node)
{
    //placing on right side of parent
    if(newNode->data >= node->data)
    {
        if(node->right == NULL)
        {
            node->right = newNode;
        }
        else
        {
            insertNode(newNode, node->right);
        }
    }
    else
    {
        if(node->left == NULL)
        {
            node->left = newNode;
        }
        else
        {
            insertNode(newNode, node->left);
        }
    }

}

template<typename T>
void AVL<T>::preorder_serialize(AVLTreeNode<T> * node_ptr){
    if(node_ptr != NULL){
        std::stringstream ss;
        ss << node_ptr->data;
        List.push_back(ss.str());
        preorder_serialize(node_ptr->left);
        preorder_serialize(node_ptr->right);
    }
    else{
        List.push_back("/");
    }
}

template<typename T>
std::vector<std::string> AVL<T>::preorder_serialize()
{
    if(root != NULL){
        std::stringstream ss;
        ss << root->data;
        List.push_back(ss.str());
        preorder_serialize(root->left);
        preorder_serialize(root->right);
    }
    else{
        List.push_back("/");
    }

    return List;

}



template<typename T>
void AVL<T>::fillList(AVLTreeNode<T>* node)
{
    //string str;
    //itoa(5, List, 10 );
    //std:vector<string> string_vec;
    //for(auto i : List){
    //    string_vec.push_back(to_string(node->data));
    //}
    //List.push_back(str);
}







#endif
