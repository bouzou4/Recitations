//
//  Registrar.cpp
//  rec08
//
//  Created by Adam Bouzourene on 3/27/15.
//  Copyright (c) 2015 Adam Bouzourene. All rights reserved.
//

#include "Registrar.h"

namespace BrooklynPoly
{
    void Registrar::purge()
    {
        for (size_t x = 0; x < body.size(); x++)
        {
            delete &body[x];
        }
        body.clear();
        for (size_t x = 0; x < courses.size(); x++)
        {
            delete &courses[x];
        }
        courses.clear();
    }
    
    void Registrar::addStudent(std::string name)
    {
        Student* temp = new Student(name);
        Registrar::body.push_back(temp);
    }
    
    void Registrar::addCourse(std::string name)
    {
        Course* temp = new Course(name);
        Registrar::courses.push_back(temp);
    }
    
    void Registrar::enrollStudentInCourse(std::string sname, std::string cname)
    {
        Student* stud = NULL;
        Course* cour = NULL;
        for (int x = 0; x < body.size(); x++)
        {
            if ((body[x] -> getName()) == sname)
            {
                stud = body[x];
            }
        }
        for (int x = 0; x < courses.size(); x++)
        {
            if ((courses[x] -> getName()) == cname)
            {
                cour = courses[x];
            }
        }
        
        if (stud != NULL && cour != NULL)
        {
            stud -> addCourse(cour);
            cour -> addStudent(stud);
        }
    }
    
    void Registrar::cancelCourse(std::string name)
    {
        for (int x = 0; x < courses.size(); x++)
        {
            if ((courses[x] -> getName()) == name)
            {
                delete courses[x];
                courses.erase(courses.begin() + x);
            }
        }
    }
    
    void Registrar::removeStudent(std::string name)
    {
        for (int x = 0; x < body.size(); x++)
        {
            if ((body[x] -> getName()) == name)
            {
                delete body[x];
                body.erase(body.begin() + x);
            }
        }
    }
    
    void Registrar::dropStudentFromCourse(std::string sname, std::string cname)
    {
        Student* stud = NULL;
        Course* cour = NULL;
        for (int x = 0; x < body.size(); x++)
        {
            if ((body[x] -> getName()) == sname)
            {
                stud = body[x];
            }
        }
        for (int x = 0; x < courses.size(); x++)
        {
            if ((courses[x] -> getName()) == cname)
            {
                cour = courses[x];
            }
        }
        
        if (stud != NULL && cour != NULL)
        {
            stud -> dropCourse(cour);
            cour -> dropStudent(stud);
        }
    }
    
    void Registrar::changeStudentName(std::string oname, std::string nname)
    {
        Student* stud = NULL;
        for (int x = 0; x < body.size(); x++)
        {
            if ((body[x] -> getName()) == oname)
            {
                stud = body[x];
            }
        }
        stud -> changeName(nname);
    }
    
    std::ostream& operator<<(std::ostream& os, const Registrar& reg)
    {
        os << "This semester: " << std::endl;
        os << "Courses: " << std::endl;
        for (size_t x = 0; x < reg.courses.size(); x++)
        {
            reg.courses[x]->display();
        }
        
        return os;
    }
}
