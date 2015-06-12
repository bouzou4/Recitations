//
//  main.cpp
//  rec04
//
//  Created by Adam Bouzourene on 2/20/15.
//  Copyright (c) 2015 Adam Bouzourene. All rights reserved.
//  CS1124
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

struct Complex {
    double real;
    double img;
};

class SpeakerSystem {
public:
    void vibrateSpeakerCones( unsigned signal ) const {
        
        cout << "Playing: " << signal << "Hz sound..." << endl;
        cout << "Buzz, buzzy, buzzer, bzap!!!\n";
    }
};

class Person {
public:
    Person( const string& name ) : name(name) {}
    void movesInWith( Person& newRoomate ) {
        roomie = &newRoomate;
        newRoomate.roomie = this;
    }
    string getName() const { return name; }
    string getRoomiesName() const { return roomie->getName(); }
private:
    Person* roomie;
    string name;
};

class Amplifier {
public:
    Amplifier( ) : attachedSpeakers( NULL ) {}
    void attachSpeakers( const SpeakerSystem& spkrs )
    {
        if( attachedSpeakers )
            cout << "already have speakers attached!\n";
        else
            attachedSpeakers = &spkrs;
    }
    void detachSpeakers()
    { attachedSpeakers = NULL; }
    void playMusic( ) const {
        if( attachedSpeakers )
            attachedSpeakers -> vibrateSpeakerCones( 440 );
        else
            cout << "No speakers attached\n";
    }
private:
    const SpeakerSystem* attachedSpeakers;
};

class PlainOldClass {
public:
    PlainOldClass() : x(-72) {}
    int getX() const { return x; }
    void setX( int x )  { this->x = x; }
private:
    int x;
};

class Colour {
public:
    Colour( const string& name, unsigned r, unsigned g, unsigned b )
    : name(name), r(r), g(g), b(b) {}
    void display() const
    {
        cout << name << " (RBG: " << r << "," << g<< "," << b << ")";
    }
private:
    string name;
    unsigned r, g, b;
};

int main()
{
    int x;
    x = 10;
    cout << "x = " << x << endl;
    int* p;
    p = &x;
    cout << "p = " << p << endl;
    cout << "p points to where " << *p << " is stored\n";
    cout << "*p contains " << *p << endl;
    *p = -2763;
    cout << "p points to where " << *p << " is stored\n";
    cout << "*p now contains " << *p << endl;
    cout << "x now contains " << x << endl;
    int y(13);
    cout << "y contains " << y << endl;
    p = &y;
    cout << "p now points to where " << *p << " is stored\n";
    cout << "*p now contains " << *p << endl;
    *p = 980;
    cout << "p points to where " << *p << " is stored\n";
    cout << "*p now contains " << *p << endl;
    cout << "y now contains " << y << endl;
    
    int* q;
    q = p;
    cout << "q points to where " << *q << " is stored\n";
    cout << "*q contains " << *q << endl;
    
    double d(33.44);
    double* pD(&d);
    *pD = *p;
    *pD = 73.2343;
    *p  = *pD;
    *q  = *p;
    //pD  = p;
     
    Complex c = {11.23,45.67};
    Complex* pC(&c);
    cout << "real: " << pC->real << "\nimaginary: " << pC->img << endl;
    
    PlainOldClass poc;
    PlainOldClass* ppoc( &poc );
    cout << ppoc->getX() << endl;
    ppoc->setX( 2837 );
    cout << ppoc->getX() << endl;
    
    int* pDyn = new int(3);
    *pDyn = 17;
    cout << "The " << *pDyn << " is stored at address " << pDyn<< " which is in the heap\n";
    
    cout << pDyn << endl;
    delete pDyn;
    cout << pDyn << endl;
    
    cout << "The 17 might STILL stored at address " << pDyn<< " even though we deleted pDyn\n";
    cout << "But can we dereference pDyn?  We can try.  This might crash... " << *pDyn << ".  Still here?\n";
    
    pDyn = NULL;
    
    double* pDouble( NULL );
    cout << "Can we dereference NULL?  " << *pDyn << endl;
    cout << "Can we dereference NULL?  " << *pDouble << endl;
     
    vector< Colour* > colours;
    string inputName;
    unsigned inputR, inputG, inputB;
    while ( cin >> inputName >> inputR >> inputG >> inputB )
    {
        colours.push_back( new Colour(inputName, inputR, inputG, inputB) );
    }
    for ( size_t ndx = 0; ndx < colours.size(); ++ndx ) {
        colours[ndx]->display();
        cout << endl;
    }
    
    Person joeBob("Joe Bob"), billyJane("Billy Jane");
    joeBob.movesInWith( billyJane );
    cout << joeBob.getName() << " lives with " << joeBob.getRoomiesName() << endl;
    cout << billyJane.getName() << " lives with " << billyJane.getRoomiesName() << endl;
    return 0;
}
