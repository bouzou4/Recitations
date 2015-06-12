//
//  main.cpp
//  rec05
//
//  Created by Adam Bouzourene on 2/27/15.
//  Copyright (c) 2015 Adam Bouzourene. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class TimeSlot
{
private:
    int hour;
    string day;
public:
    TimeSlot(const string& day, int hour): day(day), hour(hour) {}
    
    void display()
    {
        string time;
        if (hour > 12)
            time = to_string(hour - 12) + " PM";
        else
            time = to_string(hour) + " am";
        cout << day << " " << time << "\n";
    }
};

class Student
{
private:
    string name;
    vector<int> grades;
public:
    Student(string name): name(name), grades(13, -1) {}
    
    string getName()
    {
        return name;
    }
    
    void display()
    {
        cout << name << ": ";
        for (size_t x = 0; x < grades.size(); x++)
        {
            cout << grades[x] << " ";
        }
        cout << "\n";
    }
    
    void addGrade(int grade, int week)
    {
        grades[week] = grade;
    }
};

class LabSection
{
private:
    string section;
    string day;
    int hour;
    TimeSlot slot;
    vector<Student*> roster;
public:
    LabSection(const string& section,const string& day, int hour): section(section), day(day), hour(hour), slot(day, hour) {}
    
    void addStudent(string name)
    {
        Student* tempptr = new Student(name);
        roster.push_back(tempptr);
    }
    
    void loadStudentsFromFile(const string& filename)
    {
        string name;
        ifstream filein(filename);
        if((filein.is_open()))
        {
            while (filein>>name)
            {
                addStudent(name);
            }
            filein.close();
        }
    }
    
    void changeGrade(const string& sname, int grade, int week)
    {
        for (size_t x = 0; x < roster.size(); x++)
        {
            if ((roster[x] -> getName()) == sname)
            {
                roster[x] -> addGrade(grade, week);
            }
        }
    }
    
    void display()
    {
        cout << "Section: " << section << "; ";
        slot.display();
        for (size_t x = 0; x < roster.size(); x++)
        {
            if (roster[x] != NULL)
                roster[x] -> display();
        }
    }
    
    void reset()
    {
        for (size_t x = 0; x < roster.size(); x++)
        {
            delete roster[x];
            roster[x] = nullptr;
        }
        roster.clear();
    }
    
};

class LabWorker
{
private:
    string name;
    LabSection* labClass;
public:
    LabWorker(string name): name(name) {}
    
    void setSection (LabSection* labSect)
    {
        labClass = labSect;
    }
    
    void addGrade(const string& sname, int grade, int week)
    {
        labClass -> changeGrade(sname, grade, week);
    }
    
    void displayGrades()
    {
        cout << name << " has ";
        labClass -> display();
    }
};

int main()
{
    LabWorker moe( "Moe" );
    LabWorker jane( "Jane" );
    
    LabSection secA2( "A2", "Tuesday", 16 );
    secA2.loadStudentsFromFile( "A2.txt" );
    cout << "\ntest A2\n";
    secA2.display();
    
    LabSection secB3( "B3", "Thursday", 11 );
    secB3.loadStudentsFromFile( "B3.txt" );
    jane.setSection(&secB3);
    jane.displayGrades();
    
    moe.setSection(&secA2);
    cout << "\nModeling week: 1\n";
    moe.addGrade( "John", 7, 1 );
    moe.addGrade( "Paul", 9, 1 );
    moe.addGrade( "George", 7, 1 );
    moe.addGrade( "Ringo", 7, 1 );
    cout << "End of week one\n";
    moe.displayGrades();
    
    cout << "\ntesting reset()\n";
    secA2.reset();
    secA2.display();
    moe.displayGrades();
    
    /*
    // sections and setup and testing
    Section secA2( "A2", "Tuesday", 16 );
    //secA2.loadStudentsFromFile( "A2.txt" );
    secA2.addStudent("John");
    secA2.addStudent("George");
    secA2.addStudent("Paul");
    secA2.addStudent("Ringo");
    
    cout << "\ntest A2\n";    // here the modeler-programmer checks that load worked
    secA2.display();          // YOU'll DO THIS LATER AS: cout << secA2 << endl;
    moe.addSection( secA2 );
    moe.displayGrades();       // here the modeler-programmer checks that adding the Section worked
    
    Section secB3( "B3", "Thursday", 11 );
    //secB3.loadStudentsFromFile( "B3.txt" );
    secB3.addStudent("Thorin");
    secB3.addStudent("Dwalin");
    secB3.addStudent("Balin");
    secB3.addStudent("Kili");
    secB3.addStudent("Fili");
    secB3.addStudent("Dori");
    secB3.addStudent("Nori");
    secB3.addStudent("Ori");
    secB3.addStudent("Oin");
    secB3.addStudent("Gloin");
    secB3.addStudent("Bifur");
    secB3.addStudent("Bofur");
    secB3.addStudent("Bombur");
    
    cout << "\ntest B3\n";    // here the modeler-programmer checks that load worked
    secB3.display();          // YOU'll DO THIS LATER AS: cout << secB3 << endl;
    jane.addSection( secB3 );
    jane.displayGrades();      // here the modeler-programmer checks that adding Instructor worked
    
    
    // setup is complete, now a real world scenario can be written in the code
    // [NOTE: the modeler-programmer is only modeling joe's actions for the rest of the program]
    
    // week one activities
    cout << "\nModeling week: 1\n";
    moe.addGrade( "John", 7, 1 );
    moe.addGrade( "Paul", 9, 1 );
    moe.addGrade( "George", 7, 1 );
    moe.addGrade( "Ringo", 7, 1 );
    cout << "End of week one\n";
    moe.displayGrades();
    
    // week two activities
    cout << "\nModeling week: 2\n";
    moe.addGrade( "John", 5, 2 );
    moe.addGrade( "Paul", 10, 2 );
    moe.addGrade( "Ringo", 0, 2 );
    cout << "End of week two\n";
    moe.displayGrades();
    
    //test that reset works  // NOTE: can we check that the heap data was dealt with?
    cout << "\ntesting reset()\n";
    secA2.reset();
    secA2.display();
    moe.displayGrades();
    */
    
}
