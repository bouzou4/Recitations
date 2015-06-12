//
//  main.cpp
//  rec13
//
//  Created by Adam Bouzourene on 5/1/15.
//  Copyright (c) 2015 Adam Bouzourene. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    Node(int data = 0, Node* link = NULL) : data(data), link(link) {}
    int data;
    Node* link;
};

struct TNode {
    TNode(int data = 0, TNode *left = nullptr, TNode *right = nullptr)
    : data(data), left(left), right(right) {}
    int data;
    TNode *left, *right;
};

Node* addLists (Node* head1, Node* head2)
{
    Node* sumh = new Node(head1->data + head2->data);
    if (head1->link != nullptr)
        sumh->link = addLists(head1->link, head2->link);
    return sumh;
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

void binary(int number)
{
    int remainder= 0;
    
    if(number <= 1)
    {
        cout << number;
        return;
    }
    
    
    remainder = number%2;
    binary(number >> 1);
    cout << remainder;
}

int max(TNode* root)
{
    int maxn = root->data;
    if (root->left != nullptr)
    {
        if (max(root->left) > maxn && max(root->left) > max(root->right))
        {
            maxn = max(root->left);
        }
    }
    if (root->right != nullptr)
    {
        if (max(root->right) > maxn && max(root->right) > max(root->left))
        {
            maxn = max(root->right);
        }
    }
    return maxn;
}

int ssum(char* cstr)
{
    int sum;
    if (*cstr + 1 != NULL)
    {
        sum = (int) *cstr + ssum(cstr + 1);
    }
    else
    {
        sum = (int) *cstr;
    }
    return sum;
}

bool ssearch(char* cstr, char ch,int start, int end)
{
    
    if (start == end)
    {
        return false;
    }
    if (cstr[(start + end)/2] == ch)
    {
        return true;
    }
    if (cstr[(start + end)/2] > ch)
    {
        end = (start + end)/2;
        return ssearch(cstr, ch, start, end-1);
    }
    if (cstr[(start + end)/2] < ch)
    {
        start = (start + end)/2;
        return ssearch(cstr, ch, start+1, end);
    }
    return false;
}

void foo(int n)
{
    if (n > 1)
    {
        cout << 'a';
        foo(n/2);
        
        cout << 'b';
        foo(n/2);
    }
    cout << 'c';
}

int main(int argc, const char * argv[])
{
    int x = 0;
    cout << "enter your int: ";
    //cin >> x;
    cout << endl << "binary: ";
    binary(x);
    cout << endl << "--------------------------" << endl;
    
    Node* list = nullptr;
    list = new Node(17);
    listAdd(list, 45);
    listAdd(list, 23);
    listAdd(list, 94);
    listAdd(list, 15);
    listAdd(list, 56);
    
    Node* list2 = nullptr;
    list2 = new Node(45);
    listAdd(list2, 32);
    listAdd(list2, 29);
    listAdd(list2, 98);
    listAdd(list2, 15);
    listAdd(list2, 65);
    
    cout << "L1: ";
    listDisplay(list);
    cout << "L2: ";
    listDisplay(list2);
    
    cout << "L3: ";
    listDisplay(addLists(list, list2));
    
    cout << endl << "--------------------------" << endl;
    
    TNode a(1), b(2), c(4), d(8, &a, &b), e(16, &c), f(32, &d, &e);
    cout << "max value of tree is: " << max(&f) << endl;
    
    cout << endl << "--------------------------" << endl;
    
    char cstr[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
    cout << ssum(cstr);
    
    cout << endl << "--------------------------" << endl;
    
    char cha;
    char cstr2[] = { 'A', 'A', 'B', 'E', 'J', '\0' };
    cout << "char to search for: ";
    cin >> cha;
    cout << endl << ssearch(cstr2, cha, 0, 5);
    
    cout << endl << "--------------------------" << endl;
    
    int z;
    cout << "Int: ";
    cin >> z;
    foo(z);
    
    
    return 0;
}

