//
//  main.cpp
//  rec10
//
//  Created by Adam Bouzourene on 4/10/15.
//  Copyright (c) 2015 Adam Bouzourene. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include "Rational.h"


using namespace ratio;
using namespace std;

int main()
{
    RatioNum a, b;
    cout << "Input two rational numbers.\n";
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    RatioNum one = 1;
    
    
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "one = " << one << endl;
    cout << "a += b: " << (a += b) << endl;	             // Implement as member
    cout << "a = " << a << endl;
    cout << "a + one: " << (a + one) << endl;                // Implement as non-member, but not a friend
    cout << "a == one: " << boolalpha << (a == one) << endl;
    //cout << "1 == one: " << boolalpha << (1 == one) << endl; // How does this work?
    cout << "a != one: " << boolalpha << (a != one) << endl; // Implement as non-member, but not a friend
    
    cout << "a = " << a << endl;
    cout << "++a = " << (++a) << endl;   // Implement as member
    cout << "a = " << a << endl;
    cout << "a++ = " << (a++) << endl;   // Implement as member
    cout << "a = " << a << endl;
    cout << "--a = " << (--a) << endl;   // Implement as non-member, but not a friend
    cout << "a = " << a << endl;
    cout << "a-- = " << (a--) << endl;   // Implement as non-member, but not a friend
    cout << "a = " << a << endl;
    
}
