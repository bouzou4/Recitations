//
//  main.cpp
//  rec01
//
//  Created by Adam Bouzourene on 1/30/15.
//  Copyright (c) 2015 Adam Bouzourene. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>


using namespace std;

ifstream getFile()
{
    string fileName;
    bool valid = false;
    
    cout << "enter your filename" << endl;
    cin >> fileName;
    ifstream tfile(fileName);
    
    if((tfile.is_open()))
        valid = true;
    
    while (!valid)
    {
        tfile.close();
        cout << "not a valid file in directory" << endl;
        cout << "enter your filename" << endl;
        cin >> fileName;
        ifstream tfile(fileName);
        
        if((tfile.is_open()))
            valid = true;
    }
    return tfile;
}

vector<string> readFile(ifstream tfile)
{
    string tline;
    vector<string> text;
    while (getline(tfile,tline))
    {
        text.push_back(tline);
    }
    tfile.close();
    return text;
}

void printVector(vector<string> text)
{
    for(string x:text)
        cout << x << endl;
    
}

void readByWord(vector<string> text)
{
    int count = 0;
    for (int x = 0; x <= text.size(); x++)
    {
        istringstream iss(text[x]);
        string word;
        while(iss >> word)
        {
            cout << word << " " << count <<endl;
            count++;
        }
    }
    count--;
    cout << "total words: " << count;
}

int main()
{
    vector<string> text = readFile(getFile());
    printVector(text);
    readByWord(text);
    return 0;
}
