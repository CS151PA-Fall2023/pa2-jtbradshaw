/**
 * @file functions.h
 * @author Justin Bradshaw
 * @brief .h file for CS151 PA2
 * @version 0.1
 * @date 2023-09-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#ifndef FUNCTIONS_h
#define FUNCTIONS_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

const int SIZE = 20;

struct Student{
    Student();
    int id; //Student ID
    string last; //Student last name
    string first; //Student first name
    string ssn; //Student SSN
    float test1, test2, test3, test4, final; //Student test scores
    string grade; //Student end grade
    ~Student(){

    }

};

void loadArray(Student array[SIZE]);
bool menu(Student *lastN[],  Student *firstN[], Student *ssn[]);
bool validMenuInput(int num);
void loadPtr(Student vect[], Student **ptr);

void sortLN(Student *ptr[]);
void sortSSN(Student *ptr[]);
void sortFN(Student *ptr[]);

void print(const Student *ptr[], int num);
void ascLastName(Student *ptr[]);
void ascSSN(Student *ptr[]);
void ascFirstName(Student *ptr[]);
void searchLN(Student *ptr[]);
void searchSSN(Student *ptr[]);



#endif