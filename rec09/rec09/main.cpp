//
//  main.cpp
//  rec09
//
//  Created by Adam Bouzourene on 4/3/15.
//  Copyright (c) 2015 Adam Bouzourene. All rights reserved.
//

#include <string>
#include <iostream>
using namespace std;

class Position {
public:
    Position(const string& aTitle, double aSalary) : title(aTitle), salary(aSalary) {}
    
    string getTitle() const
    {
        return title;
    }
    
    double getSalary() const
    {
        return salary;
    }
    
    void changeSalaryTo(double d)
    {
        salary = d;
    }
    
private:
    string title;
    double salary;
}; // class Position

class Entry
{
public:
    Entry(const string& aName, unsigned aRoom, unsigned aPhone, Position& aPosition) : name(aName), room(aRoom), phone(aPhone), pos(&aPosition)
    {
    }
    
    string getName()
    {
        return name;
    }
    
    unsigned getNumber()
    {
        return phone;
    }
    friend ostream& operator<<( ostream& os, const Entry& e )
    {
        os << e.name << ' ' << e.room << ' ' << e.phone;
        return os;
    } // operato<<
private:
    string name;
    unsigned room;
    unsigned phone;
    Position* pos;
}; // class Entry

class Directory
{
private:
    Entry** entries;
    size_t size;
    size_t capacity;
public:
    Directory() : capacity(2), size(0), entries(new Entry*[2])
    {
        // Should we do this?  What do you think?
        for (size_t i = 0; i < capacity; i++)
        {
            entries[i] = nullptr;
        } // for
    } // Directory()
    
    Directory(const Directory& dir)
    {
        cout << "Copy constructor for directory is called" << endl;
        size = dir.size;
        capacity = dir.capacity;
        entries = new Entry*[ capacity ];
        for (size_t i = 0; i < dir.capacity; i++)
        {
            entries[i] = dir.entries[i];
        }
    }
    
    ~Directory()
    {
        cout << "Destructor for directory is called" << endl;
        delete [] entries;
    }
    
    Directory& operator=(const Directory& dir)
    {
        cout << "Assignment operator for directory is called" << endl;
        if (this != &dir)
        {
            if (size != dir.size)
            {
                delete [] entries;
                size = dir.size;
                entries = new Entry*[size];
            }
            
            for (size_t i = 0; i < size; i++)
            {
                entries[i] = dir.entries[i];
            }
        }
        
        return *this;
    }
    
    friend ostream& operator<< (ostream& os, const Directory& dir)
    {
        os << "Directory" << endl;
        for (size_t i = 0; i < dir.size; i++)
        {
            os << *(dir.entries[i]) << endl;
        }
        return os;
    }
    
    void add(const string& name, unsigned room, unsigned ph, Position& pos)
    {
        if( size == capacity )
        {
            Entry** tmp = new Entry*[ capacity *= 2 ];
            
            for (size_t i = 0; i < capacity; i++)
            {
                tmp[i] = entries[i];
            }
            
            delete entries;
            entries = tmp;
        } // if
        entries[size] = new Entry(name, room, ph, pos);
        ++size;
    } // add
    
    unsigned operator[] (const string& name)
    {
        for (size_t i = 0; i < size; i++)
        {
            if (entries[i]->getName() == name)
            {
                return entries[i]->getNumber();
            }
        }
        
        return 0;
    }
};

void doNothing(Directory dir) { cout << dir << endl; }

int main()
{
    
    Position boss("Boss", 3141.59);
    Position pointyHair("Pointy Hair", 271.83);
    Position techie("Techie", 14142.13);
    Position peon("Peonissimo", 34.79);
    
    Directory d;
    d.add("Marilyn", 123, 4567, boss);
    cout << d << endl;
    
    Directory d2 = d;
    d2.add("Gallagher", 111, 2222, techie);
    d2.add("Carmack", 314, 1592, techie);
    
    cout << "Calling doNothing\n";
    doNothing(d2);
    cout << "Back from doNothing\n";
    
    Directory d3;
    d3 = d2;
    
    cout << d3 << endl;
    
    cout << "get number number from name" << endl;
    
    cout << d2["Carmack"] << endl;
    cout << d2["Gallagher"] << endl;
    cout << d2["derp"] << endl;
    
}

