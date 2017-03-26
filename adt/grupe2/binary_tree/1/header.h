//
//  header.h
//  binary_tree
//
//  Created by Matas Kaminskas on 19/02/2017.
//  Copyright © 2017 Matas Kaminskas. All rights reserved.
//

#ifndef header_h
#define header_h

struct node {
    int data;
    struct node *leftChild;
    struct node *rightChild;
};

bool search(int data, node *leaf);
void delete_data (int data, node *&leaf);
void insert(int data, node *&leaf);
void balance_tree(node *&root);

#endif /* header_h */
