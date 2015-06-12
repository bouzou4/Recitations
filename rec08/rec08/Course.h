//
//  Course.h
//  rec08
//
//  Created by Adam Bouzourene on 3/27/15.
//  Copyright (c) 2015 Adam Bouzourene. All rights reserved.
//

#ifndef rec08_Course_h
#define rec08_Course_h

#include <iostream>
#include <string>
#include <vector>
#include "Student.h"

namespace BrooklynPoly
{
    class Student;
    
    class Course
    {
    private:
        std::string name;
        std::vector<Student*> roster;
    public:
        Course(std::string name) : name(name) {}
        
        std::string getName()
        {
            return name;
        }
        
        void addStudent(Student* stud);
        
        void dropStudent(Student* stud);
        
        void display();
    };
}


#endif
