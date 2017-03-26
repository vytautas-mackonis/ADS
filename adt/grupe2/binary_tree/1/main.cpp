//
//  main.cpp
//  binary_tree
//
//  Created by Matas Kaminskas on 19/02/2017.
//  Copyright © 2017 Matas Kaminskas. All rights reserved.
//

#include <iostream>
#include "header.h"
#include <vector>

using namespace std;

void represent_tree(node *node){
    vector <struct node> list;
    int lygis = 1, dydis;
    if(node != NULL){
        list.push_back(*node);
        for(int i = 0; i < list.size(); ){
            dydis = list.size();
            for(int j = 0; j < lygis; j++, i++){
                cout << list[i].data<<" ";
                if(list[i].leftChild != NULL)
                    list.push_back(*list[i].leftChild);
                if(list[i].rightChild != NULL)
                    list.push_back(*list[i].rightChild);
            }
            lygis = list.size() - dydis;
            cout<<endl;
        }
    }
}

int main(int argc, const char * argv[]) {
    node *head = NULL;
    insert(5, head);
    insert(10, head);
    insert(15, head);
    insert(2, head);
    insert(7, head);
    insert(6, head);
    insert(4, head);
    insert(12, head);
    insert(30, head);
    insert(8, head);
    insert(31, head);
//    delete_data(10, head);
//    delete_data(12, head);
//    delete_data(15, head);
//    delete_data(23, head);
//    delete_data(5, head);
//    delete_data(31, head);
    represent_tree(head);
    cout<<search(78, head)<<endl;
    balance_tree(head);
    cout <<"----------"<<endl;
    represent_tree(head);

    return 0;
}
