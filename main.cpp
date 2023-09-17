/**
 * @file main.cpp
 * @author Justin Bradshaw
 * @brief main file for CS151 PA2. This program takes a .csv file and loads it into a vector of a structure.
 * Then points several pointers to that vector and sorts the data in the pointers and outputs the data based on an 
 * input from the user.
 * @version 0.1
 * @date 2023-09-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "functions.h"

int main(){

    Student gradeVect[SIZE];
    
    
    loadArray(gradeVect);

    Student *lastName[20];
    Student *ssn[20];
    Student *firstName[20];

    loadPtr(gradeVect, lastName);

    loadPtr(gradeVect, ssn);

    loadPtr(gradeVect, firstName);


    bool run = true;
    while(run){
        run = menu(lastName, firstName, ssn);
    }


    return 0;
}