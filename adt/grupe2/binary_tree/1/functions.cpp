//
//  functions.cpp
//  binary_tree
//
//  Created by Matas Kaminskas on 19/02/2017.
//  Copyright © 2017 Matas Kaminskas. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "header.h"

using namespace std;

struct balanced_node{
    int start, end;
    node *leaf;
};

bool search(int data, node *leaf){
    if(leaf == NULL) return 0;
    while(leaf->data != data){
        if(leaf != NULL) {
            if(leaf->data > data) leaf = leaf->leftChild;
            else leaf = leaf->rightChild;
            if(leaf == NULL) return 0; //if new child is NULL then the value doesn't exists
        }			
    }
    return 1;
}

void balance(node *&root, vector<int> arr)
{
    vector<balanced_node> queue;
    balanced_node current;
    int mid, start = 0, end = (int)arr.size()-1;
    queue.push_back({start, end, root});
    for(int i = 0; i < queue.size(); i++){
        current = queue[i];
        mid = (current.start + current.end + 1) / 2; //find the position of the element in the middle
        current.leaf->data = arr[mid]; //assign the value
        
        if(current.start <= mid - 1){ //if data exists
            current.leaf->leftChild = new node;
            queue.push_back({current.start, mid-1, current.leaf->leftChild}); //push back new left child
        } else{
            delete current.leaf->leftChild;
            current.leaf->leftChild = NULL; //there won't be a child
        }
        
        if(mid+1 <= current.end){
            current.leaf->rightChild = new node;
            queue.push_back({mid+1, current.end, current.leaf->rightChild}); //push back new right child
        } else{
            delete current.leaf->rightChild;
            current.leaf->rightChild = NULL; //there won't be a child
        }
    }
}

void balance_tree(node *&root){
    vector <struct node> list;
    vector <int> list_values;
    list.push_back(*root);
    for(int i = 0; i < list.size(); i++){ //iterate through values
        list_values.push_back(list[i].data); //push values
        if(list[i].leftChild != NULL)
            list.push_back(*list[i].leftChild);
        if(list[i].rightChild != NULL)
            list.push_back(*list[i].rightChild);
    }
    sort(list_values.begin(), list_values.end()); //sort values
    balance(root, list_values); //balance the tree
}

void delete_node(node *leaf, node *parent, bool right){
    node *temp, *true_leaf = NULL; //true_leaf - a leaf for parent
    if(leaf->leftChild == NULL && leaf->rightChild == NULL){ //has no child
        delete leaf;
        leaf = NULL;
    } else if (leaf->leftChild == NULL){ // has 1 child
        temp = leaf;
        leaf = leaf->rightChild;
        delete temp;
        temp = NULL;
        true_leaf = leaf;
    } else if (leaf->rightChild == NULL){ // has 1 child
        temp = leaf;
        leaf = leaf->leftChild;
        delete temp;
        temp = NULL;
        true_leaf = leaf;
    } else{ // has 2 childs
        temp = leaf->rightChild; //move to the right side tree
        right = 1;
        parent = leaf;
        if(temp->rightChild != NULL && temp->leftChild == NULL){
            true_leaf = temp->rightChild;
        }
        while(temp -> leftChild != NULL){ parent = temp; temp = temp->leftChild; right = 0;} //go to the left while it's possible
        leaf->data = temp->data; //change data
        delete temp; //delete node
        temp = NULL;
    }
    if(parent != NULL){ //change the child of a parent
        if(right) parent->rightChild = true_leaf;
        else parent->leftChild = true_leaf;
    }
}

void delete_data (int data, node *&root){
    node *leaf, *parent = NULL;
    bool right; //left = 0, right - 1
    if(root->data == data){
        if(root->leftChild == NULL && root->rightChild == NULL){
            delete root;
            root = NULL;
        }
        else delete_node(root, parent, right);
    } else {
        leaf = root;
        while(leaf->data != data){ //while the leaf with data is not found
            parent = leaf; //save parent's position
            if(leaf->data > data){
                leaf = leaf->leftChild;
                right = 0;
            } else{
                leaf = leaf->rightChild;
                right = 1;
            }
            if(leaf == NULL) //value doesn't exits
                return;
        }
        delete_node(leaf, parent, right);
    }
}

void insert(int data, node *&root) {
    bool found = false;
    if(root == NULL){ //create new node
        root = new node;
        root->data = data;
        root->leftChild = NULL;
        root->rightChild = NULL;
    } else{
        node *leaf = root;
        while(!found){
            if(data < leaf->data) { //insert to left
                if(leaf->leftChild != NULL){ //move to left
                    leaf = leaf->leftChild;
                } else{ //insert to the left child
                    leaf->leftChild = new node;
                    leaf->leftChild->data=data;	
                    leaf->leftChild->leftChild=NULL;
                    leaf->leftChild->rightChild=NULL;
                    found = true;
                }
            } else if(data >= leaf->data) { //insert to right
                if(leaf->rightChild != NULL)
                    leaf = leaf->rightChild;
                else { //insert to the right child
                    leaf->rightChild = new node;
                    leaf->rightChild->data=data;
                    leaf->rightChild->leftChild=NULL;
                    leaf->rightChild->rightChild=NULL;
                    found = true;
                }
            }
        }
    }
}
