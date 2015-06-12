//
//  Course.cpp
//  rec08
//
//  Created by Adam Bouzourene on 3/27/15.
//  Copyright (c) 2015 Adam Bouzourene. All rights reserved.
//

#include "Course.h"

namespace BrooklynPoly
{
    void Course::addStudent(Student* stud)
    {
        roster.push_back(stud);
    }
    
    void Course::dropStudent(Student *stud)
    {
        for (int x = 0; x < roster.size(); x++)
        {
            if ((roster[x] -> getName()) == stud -> getName())
            {
                roster.erase(roster.begin() + x);
            }
        }
    }
    
    void Course::display()
    {
        std::cout << name << std::endl << "Students: " << std::endl;
        for (int x = 0; x < roster.size(); x++)
        {
            roster[x]->display();
        }
    }
}