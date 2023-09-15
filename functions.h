#ifndef FUNCTIONS_h
#define FUNCTIONS_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Student{
    int id; //Student ID
    string last; //Student last name
    string first; //Student first name
    string ssn; //Student SSN
    float test1, test2, test3, test4, final; //Student test scores
    string grade; //Student end grade

};

void loadVector(vector<Student> &vector);
bool menu(vector<Student> &vector);
bool validMenuInput(int num);

void print(const vector<Student> &vector, int num);
void ascLastName(vector<Student> &vector);
void ascSSN(vector<Student> &vector);
void searchLN(vector<Student> &vector);
void searchSSN(vector<Student> &vector);



#endif