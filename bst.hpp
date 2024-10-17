/**
 * @file lab8.cpp
 * @author Sadaf Habib
 * @description BST Tree implementation in C++
 * @date 2022-11-03
 */
#pragma once
#include<iostream>
#include<cstdlib>
#include<sstream>
#include<iomanip>
#include<math.h>
#include<queue>
#include<vector>
#include <algorithm>
#include "hotel.hpp"



using namespace std;
template <typename T1, typename T2>
class Node
{
    private:
        T1 key;                 //city name
        vector<T2> value;       //list of hotels in the city
        Node<T1,T2>* left;      //left child
        Node<T1,T2>* right;     //right child
        Node<T1,T2>* parent;    //pointer to the parent node
    public:
        Node(T1 key): key(key),left(nullptr),right(nullptr), parent(nullptr)
        {}
        void print(string stars="") //print all or only those hotels with specific stars.
        {
            int counter=0;
            cout<<std::left<<setw(50)<<"Name"<<" "<<setw(10)<<"City"<<" "<<setw(5)<<"Stars"<<" "<<setw(10)<<"Price"<<" "<<setw(20)<<"Country"<<" "<<"Address"<<endl;
            cout<<"------------------------------------------------------------------------------------------------------------"<<endl;

            for(auto it:value)
                if(stars=="" or stars==it->getStars())
                {
                    it->print2();
                    counter++;
                }
            
            cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
            cout<<counter<<" records found."<<endl;
        }
        
        template<typename,typename> friend class BST;
};
//=============================================================================
template <typename T1, typename T2>
class BST
{
    private:
        Node<T1,T2> *root;
        void postOrderDelete(Node<T1, T2>* ptr);
    public:
        BST();                                  //constructor
        ~BST();                                 //destructor
        Node<T1,T2>* getRoot();                     //returns the root of the Tree
        void insert(Node<T1, T2>* ptr, T1 key, T2 value);           //Insert key into tree/subtree with root ptr
        int height(Node<T1,T2> *ptr);                   //Find the height of a tree/subtree with root ptr
        Node<T1,T2>* find(Node<T1,T2> *ptr,T1 key,string stars);        //Find and returns the node with key
        Node<T1,T2>* findMin(Node<T1,T2> *ptr);             //Find and return the Node<T1,T2> with minimum key value from a tree/subtree with root ptr
        void remove(Node<T1, T2>* ptr, T1 key, const T2 value);         //Remove a node with key from the tree/subtree with root
};

//=====================================================================
//write implementation of all methods below


//constructor for bst
template <typename T1, typename T2>
BST<T1, T2>::BST() : root(nullptr) {}

// destructor for bst
template <typename T1, typename T2>
BST<T1, T2>::~BST() {
    // helper function for post-order traversal from the root
    postOrderDelete(root);
}

// post-order traversal and deletion of nodes in the BST
template <typename T1, typename T2>
void BST<T1, T2>::postOrderDelete(Node<T1, T2>* ptr) {
    // check if the current node is not nullptr
    if (ptr != nullptr) {
        // Recursively delete left and right subtrees
        postOrderDelete(ptr->left);
        postOrderDelete(ptr->right);

        // if vector 'value' contains pointers, delete them too
        for (T2 hotel : ptr->value) {
            delete hotel;
        }

        // Delete the current node
        delete ptr;
    }
}

// get root of bst
template <typename T1, typename T2>
Node<T1, T2>* BST<T1, T2>::getRoot() {
    return root;
}

// insert a new node with key and value into bst
template <typename T1, typename T2>
void BST<T1, T2>::insert(Node<T1, T2>* ptr, T1 key, T2 value) {
    // if the tree is empty, create a new node 
    if (root == nullptr) {
        root = new Node<T1, T2>(key);
        root->value.push_back(value);
        return;
    }

    // if the key to be inserted is less than the current node's key, then it goes to the left subtree
    if (key < ptr->key) {
        // if the left child is null, create a new node and insert the key and value
        if (ptr->left == nullptr) {
            ptr->left = new Node<T1, T2>(key);
            ptr->left->parent = ptr;
            ptr->left->value.push_back(value);
        } else {
            // recursively insert into the left subtree
            insert(ptr->left, key, value);
        }
    }
    // If the key to be inserted is greater than the current node's key, then it goes to the right subtree
    else if (key > ptr->key) {
        // if the right child is null, create a new node and insert the key and value
        if (ptr->right == nullptr) {
            ptr->right = new Node<T1, T2>(key);
            ptr->right->parent = ptr;
            ptr->right->value.push_back(value);
        } else {
            // recursively insert into the right subtree
            insert(ptr->right, key, value);
        }
    }
    // If the key already exists, add the value to the existing node
    else {
        ptr->value.push_back(value);
    }
}



template <typename T1, typename T2>
int BST<T1, T2>::height(Node<T1, T2> *ptr) {
    // if the node is null, its height is 0
    if (ptr == nullptr) {
        return 0;
    }

    // recursively calculate the height of the left and right subtrees
    int leftHeight = height(ptr->left);
    int rightHeight = height(ptr->right);

    // return the maximum of the left and right subtree heights, plus 1 for the current node to calculate height 
    return 1 + max(leftHeight, rightHeight);
}


template <typename T1, typename T2>
Node<T1, T2>* BST<T1, T2>::find(Node<T1, T2>* ptr, T1 key, string stars) {
    // check if the current node is null or if its key matches the target key
    if (ptr == nullptr || ptr->key == key) {
        if (ptr != nullptr) {
            ptr->print(stars); // call a print function of the node if it exists
        }
        return ptr; // return node if found or nullptr if not found
        
    }
    // if the target key is less than the current node's key, search in the left subtree
    if (key < ptr->key) {
        return find(ptr->left, key, stars); // recursively go through the left subtree
    }
    // if the target key is greater than the current node's key, search in the right subtree
    return find(ptr->right, key, stars); // recursively through the right subtree
    


}


//to find node with the minimum key value in a subtree with root ptr
template <typename T1, typename T2>
Node<T1, T2>* BST<T1, T2>::findMin(Node<T1, T2>* ptr) {
    // keep moving to the left until the leftmost node is found
    while (ptr != nullptr && ptr->left != nullptr) {
        ptr = ptr->left;
    }

    // return the leftmost node 
    return ptr;
}

template <typename T1, typename T2>
void BST<T1, T2>::remove(Node<T1, T2>* ptr, T1 key, const T2 value) {
    //check if current node is empty 
    if (ptr == nullptr){
        return;
    }

    //if current key is equal to target key
    if (ptr->key == key){
        //iterate through it to find specific hotel
        for (auto it = ptr->value.begin(); it != ptr->value.end(); ++it){
            //if hotel found
            if ((*it) == value){
                //erase the hotel
                ptr->value.erase(it);
                return; //exit function 
            }
        }

    }
    //if the target key is less than the current node's key, search in the left subtree
    if (ptr->key > key) {
        remove(ptr->left, key, value); // recursively go through the left subtree
    }
    // if the target key is greater than the current node's key, search in the right subtree
    else {
        remove(ptr->right, key, value); // recursively through the right subtree
    }    

}

