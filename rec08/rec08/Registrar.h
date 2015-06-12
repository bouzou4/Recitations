//
//  Registrar.h
//  rec08
//
//  Created by Adam Bouzourene on 3/27/15.
//  Copyright (c) 2015 Adam Bouzourene. All rights reserved.
//

#ifndef rec08_Registrar_h
#define rec08_Registrar_h

#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
#include "Course.h"


namespace BrooklynPoly
{
    class Course;
    
    class Student;
    
    class Registrar
    {
    private:
        std::vector<Student*> body;
        std::vector<Course*> courses;
    public:
        void purge();
        
        void addCourse(std::string name);
        
        void addStudent(std::string name);
        
        void enrollStudentInCourse(std::string sname, std::string cname);
        
        void cancelCourse(std::string name);
        
        void removeStudent(std::string name);
        
        void dropStudentFromCourse(std::string sname, std::string cname);
        
        void changeStudentName(std::string oname, std::string nname);
        
        friend std::ostream& operator<<(std::ostream& os, const Registrar& reg);
        
    };
}

#endif
