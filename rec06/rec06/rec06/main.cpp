//
//  main.cpp
//  rec06
//
//  Created by Adam Bouzourene on 3/6/15.
//  Copyright (c) 2015 Adam Bouzourene. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class PrintedMaterial
{
public:
    PrintedMaterial(unsigned numPages) : numPages(numPages) {}
    
    virtual void displayNumPages() const = 0;
    
    unsigned getPages() const
    {
        return numPages;
    }
protected:
private:
    unsigned numPages;
};

class Magazine : public PrintedMaterial
{
public:
    Magazine(unsigned numPages) : PrintedMaterial(numPages) {}
    
    void displayNumPages() const
    {
        cout << "Im a magazine with ";
        cout << PrintedMaterial::getPages();
        cout << " pages" << endl;
    }
protected:
private:
};

class Book : public PrintedMaterial
{
public:
    Book(unsigned numPages) : PrintedMaterial(numPages) {}
    
    void displayNumPages() const
    {
        cout << "Im a book with ";
        cout << PrintedMaterial::getPages();
        cout << " pages" << endl;
    }
protected:
private:
};

class TextBook : public Book
{
public:
    TextBook(unsigned numPages, unsigned numIndexPages) : Book(numPages), numIndexPages(numIndexPages) {}
    
    void displayNumPages() const
    {
        cout << "Pages: ";
        cout << PrintedMaterial::getPages();
        cout << endl << "Index pages: ";
        cout << numIndexPages << endl;
    }
    
protected:
private:
    unsigned numIndexPages;
};

class Novel : public Book
{
public:
    Novel(unsigned numPages) : Book(numPages) {}
protected:
private:
};


void displayPages(const PrintedMaterial& PM)
{
    PM.displayNumPages();
}


int main()
{
    TextBook t(5430, 23);
    Novel n(213);
    Magazine m(6);
    
    t.displayNumPages();
    n.displayNumPages();
    m.displayNumPages();
    
    cout << endl << "storing in a container" << endl;
    vector< PrintedMaterial* > allPrinted;
    allPrinted.push_back(&t);
    allPrinted.push_back(&n);
    allPrinted.push_back(&m);
    for(size_t x = 0; x < allPrinted.size(); x++)
    {
        allPrinted[x]->displayNumPages();
        cout << endl;
    }
    
}
