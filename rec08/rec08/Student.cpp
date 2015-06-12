//
//  Student.cpp
//  rec08
//
//  Created by Adam Bouzourene on 3/27/15.
//  Copyright (c) 2015 Adam Bouzourene. All rights reserved.
//

#include "Student.h"

namespace BrooklynPoly
{
    void Student::addCourse(Course* nclass)
    {
        schedule.push_back(nclass);
    }
    
    void Student::dropCourse(Course* nclass)
    {
        for (int x = 0; x < schedule.size(); x++)
        {
            if ((schedule[x] -> getName()) == nclass -> getName())
            {
                schedule.erase(schedule.begin() + x);
            }
        }
    }
    
    void Student::changeName(std::string nname)
    {
        name = nname;
    }
    
    void Student::display()
    {
        std::cout << name << std::endl;
    }
    
}