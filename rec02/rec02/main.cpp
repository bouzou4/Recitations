//
//  main.cpp
//  rec02
//
//  Created by Adam Bouzourene on 2/6/15.
//  Copyright (c) 2015 Adam Bouzourene. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>


using namespace std;

struct compound
{
    vector<string> names;
    int carbon;
    int hydrogen;
};

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


vector<compound> splitData(ifstream tfile)
{
    
    vector<compound> data;
    char c;
    size_t foundIndex;
    string tempNum;
    string name;
    string form;
    string line;
    bool first = true;
    bool found = false;
    while (getline(tfile, line))
    {
        
        istringstream strem(line);
        name = "";
        strem >> name;
        compound temp;
        temp.names.push_back(name);
        tempNum = "";
        strem >> c;
        if (c == 'C')
        {
            strem >> c;
            while (c != 'H')
            {
                tempNum.push_back(c);
                strem >> c;
            }
            temp.carbon = stoi(tempNum);
            tempNum = "";
            while (strem >> c)
            {
                tempNum.push_back(c);
            }
            temp.hydrogen = stoi(tempNum);
        }
        if (!first)
        {
            for (size_t d = 0; d <= data.size() - 1; d++)
            {
                if ((temp.carbon == data[d].carbon) && (temp.hydrogen == data[d].hydrogen))
                {
                    found = true;
                    foundIndex = d;
                }
                else
                    found = false;
            }
            if (found)
            {
                data[foundIndex].names.push_back(temp.names[0]);
            }
            else
            {
                data.push_back(temp);
            }
        }
        else
        {
            
            data.push_back(temp);
        }
        first = false;
        
    }
    tfile.close();
    return data;
}

int getMaxCarbon(vector<compound> &data)
{
    int maxCarbon = 0;
    for (int x = 0; x <= data.size() - 1; x++)
    {
        if (data[x].carbon > maxCarbon)
        {
            maxCarbon = data[x].carbon;
        }
    }
    return maxCarbon;
}

void printData(vector<compound> data, int maxCarbon)
{
    for (int z = 0; z <= maxCarbon; z++)
    {
        for (int x = 0; x <= data.size() - 1; x++)
        {
            if (data[x].carbon == z)
            {
                cout << "C" << data[x].carbon << "H" << data[x].hydrogen << " ";
                for (size_t k = 0; k < data[x].names.size(); k++)
                {
                    cout << data[x].names[k] << " ";
                }
                cout << endl;
            }
        }
    }
}

int main()
{
    vector<compound> data = splitData(getFile());
    int maxC = getMaxCarbon(data);
    printData(data, maxC);
    
    return 0;
}
