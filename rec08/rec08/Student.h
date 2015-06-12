//
//  Student.h
//  rec08
//
//  Created by Adam Bouzourene on 3/27/15.
//  Copyright (c) 2015 Adam Bouzourene. All rights reserved.
//

#ifndef rec08_Student_h
#define rec08_Student_h

#include <iostream>
#include <string>
#include <vector>
#include "Course.h"

namespace BrooklynPoly
{
    class Course;
    
    class Student
    {
    private:
        std::vector<Course*> schedule;
        std::string name;
    public:
        Student(std::string name) : name(name) {}
        
        std::string getName()
        {
            return name;
        }
        void addCourse(Course* nclass);
        
        void dropCourse(Course* nclass);
        
        void changeName(std::string nname);
        
        void display();
        
    };
    
}

#endif
