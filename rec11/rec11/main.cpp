//
//  main.cpp
//  rec11
//
//  Created by Adam Bouzourene on 4/17/15.
//  Copyright (c) 2015 Adam Bouzourene. All rights reserved.
//

#include <iostream>
#include <cstdlib> // To allow NULL if no other includes

using namespace std;

struct Node {
    Node(int data = 0, Node* link = NULL) : data(data), link(link) {}
    int data;
    Node* link;
};

void listInsertHead(int entry, Node*& headPtr)
{
    headPtr = new Node(entry, headPtr);
}

void listDisplay(Node* headPtr) {
    Node* p = headPtr;
    while(p != nullptr) {
        cout << p->data << ' ';
        p = p->link;
    }
    cout << endl;
}

void listAdd(Node* priorPtr, int data)
{
    Node* p = new Node(data, priorPtr->link);
    priorPtr->link = p;
}

Node*& findFstNode(int x, Node*& head)
{
    Node* b = head;
    while (b != nullptr && b->data != x)
    {
        b = b->link;
    }
    if (b->data == x)
    {
        return b;
    }
    else
    {
        b = nullptr;
        return b;
    }
}

void splice(Node*& inslst, Node* target)
{
    Node* b = target;
    Node* i = nullptr;
    Node* a = nullptr;

    i = inslst;
    a = b->link;
    while(i->link != nullptr)
    {
        b->link = i;
        b = i;
        i = i->link;
    }
    i->link = a;
}

Node*& subList(Node*& headPtr, Node*& subHead)
{
    Node* b = headPtr;
    Node* c = subHead;
    Node* ret = nullptr;
    while (b != nullptr)
    {
        if (b->data == c->data)
        {
            ret = b;
            while(b->data == c->data)
            {
                b = b->link;
                c = c->link;
                if (c == nullptr)
                {
                    return ret;
                }
                if (b == nullptr)
                {
                    ret = nullptr;
                    return ret;
                }
            }
        }
        b = b->link;
    }
    ret = nullptr;
    return ret;
}

int main(int argc, const char * argv[])
{
    cout << "Splicing" << endl;
    
    Node* list = nullptr;
    list = new Node(17);
    listAdd(list, 45);
    listAdd(list, 23);
    listAdd(list, 94);
    listAdd(list, 15);
    listAdd(list, 56);
    
    Node* list2 = nullptr;
    list2 = new Node(96);
    listAdd(list2, 36);
    listAdd(list2, 15);
    listAdd(list2, 35);
    
    cout << "L1: ";
    listDisplay(list);
    cout << "L2: ";
    listDisplay(list2);
    
    cout << "Splicing L2 into L1 after 23" << endl;
    splice(list2, findFstNode(23, list));
    cout << "L1: ";
    listDisplay(list);
    cout << "L2: ";
    listDisplay(list2);
    
    cout << endl << "Sublists:" << endl;
    Node* list3 = nullptr;
    list3 = new Node(67);
    listAdd(list3, 27);
    listAdd(list3, 34);
    //listAdd(list3, 27);
    listAdd(list3, 93);
    listAdd(list3, 94);
    listAdd(list3, 55);
    listAdd(list3, 29);
    
    Node* list4 = nullptr;
    list4 = new Node(94);
    listAdd(list4, 27);
    listAdd(list4, 34);
    listAdd(list4, 93);
    
    cout << "L3: ";
    listDisplay(list3);
    cout << "L4: ";
    listDisplay(list4);
    
    cout << "checking if L4 is a sublist of L3" << endl;
    if (subList(list3, list4) == nullptr)
    {
        cout << "Doesnt match" << endl;
    }
    else
        cout << (subList(list3, list4)->data);
    

    
    return 0;
}
