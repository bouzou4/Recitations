//
//  main.cpp
//  rec12
//
//  Created by Adam Bouzourene on 4/24/15.
//  Copyright (c) 2015 Adam Bouzourene. All rights reserved.
//

#include <iostream>

#include <iostream>

#include <iostream>

using namespace std;

struct Node
{
    Node (int data = 0, Node* next = nullptr) : data(data), next(next) {}
    int data;
    Node* next;
};

class Sequence
{
private:
    Node* current;
    Node* head;
    
public:
    Sequence() : head(nullptr), current(nullptr) {}
    
    Sequence(const Sequence& seq)
    {
        if (seq.head == nullptr)
        {
            head = nullptr;
            current = nullptr;
        }
        else
        {
            Node* tmp = new Node(seq.head->data,nullptr);
            head = tmp;
            current = tmp;
            while (tmp != nullptr)
            {
                current->next = new Node(tmp->next->data, nullptr);
                current = current->next;
                tmp = tmp->next;

            }
        }
    }
    
    Sequence& operator=(Sequence& other)
    {
        if (this != &other)
        {
            Sequence* seq = new Sequence();
            Node* tmp = seq->head;
            head = tmp;
            while (tmp != nullptr)
            {
                current = new Node(tmp->data, nullptr);
                current = current->next;
                tmp = tmp->next;
            }
            return *seq;
        }
        return other;
    }
    
    bool valid()
    {
        return current != nullptr;
    }
    
    int data()
    {
        return current->data;
    }
    
    void reset()
    {
        current = head;
    }
    
    void display(ostream& os = cout, const string& sep=" ")
    {
        Node* tmp = head;
        while (tmp != nullptr)
        {
            os << tmp->data << sep;
            tmp = tmp->next;
        }
        os << endl;
    }
    
    void add(int data)
    {
        if (current != nullptr)
        {
            Node* next = new Node(data);
            next->next = current->next;
            current->next = next;
            current = current->next;
        }
        else
        {
            head = new Node(data);
            current = head;
        }
    }
    
    void remove()
    {
        if (current != nullptr) {
            Node* last = head;
            while (last->next != nullptr && last->next != current) {
                last = last->next;
            }
            Node* next = current->next;
            delete current;
            last->next = next;
        }
    }
    
    void next()
    {
        if (current != nullptr)
        {
            current = current->next;
        }
    }
    
    void clear()
    {
        Node* cur = head;
        Node* next = nullptr;
        while (next != nullptr) {
            next = cur->next;
            delete cur;
            cout << cur->data << endl;
            cur = next;
        }
        head = nullptr;
        current = nullptr;
    }
    
};

int main() {
    Sequence s;
    for (int i = 0; i < 6; ++i) s.add(i);
    s.display();
    cout << "==========\n";
    s.reset();
    for (int i = 0; i < 3; ++i) s.next();
    s.add(42);
    s.display();
    cout << "==========\n";
    s.reset();
    for (int i = 0; i < 2; ++i) s.next();
    s.remove();
    s.display();
    cout << "==========\n";
    //s.clear();
    s.display();
    cout << "==========\n";
    Sequence s2(s);
    s2.display();
    cout << "==========\n";
    Sequence s3;
    s3 = s;
    s3.display();
    
}