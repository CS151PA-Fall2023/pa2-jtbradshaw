/**
 * @file functions.cpp
 * @author Justin Bradshaw
 * @brief File containing all of the functions for main.cpp for CS151 PA2.
 * @version 0.1
 * @date 2023-09-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "functions.h"

/**
 * @brief Construct a new Student:: Student object
 * 
 */
Student::Student(){
    id = -1; //Student ID
    last = " "; //Student last name
    first = " "; //Student first name
    ssn = " "; //Student SSN
    test1 = 0.0, test2 = 0.0, test3 = 0.0, test4 = 0.0, final = 0.0; //Student test scores
    grade = " ";

}


/**
 * @brief Opens the file, loads it into the array, and then closes the file. 
 * 
 * @param array Array that is full of the Student struct data
 */
void loadArray(Student array[SIZE]){

    //opens grades.csv file
    ifstream file("grades.csv");
    if(!file){
        cout<<"Error opening file. Exiting program."<<endl;
        exit(1);
    }
    Student temp;   
    string firstLine; //To store the first row as a string to get it out of the way
    getline(file, firstLine);
    

    //do while loop to read contents of file into vector until it reaches the end of file
    for(int i = 0; i < SIZE; i++){

        char hold;
        file>>temp.id;
        file>>hold;
        getline(file, temp.last, ',');

        getline(file, temp.first, ',');

        getline(file, temp.ssn, ',');

        file>>temp.test1;
        file>>hold;

        file>>temp.test2;
        file>>hold;

        file>>temp.test3;
        file>>hold;

        file>>temp.test4;
        file>>hold;

        file>>temp.final;
        file>>hold;

        file>>temp.grade;

        array[i] = temp;

        
    }
    //closes file
    file.close();
}

/**
 * @brief Points the pointer at the array
 * 
 * @param array Array that is full of the Student struct data
 * @param ptr pointer that is full of addresses of array
 */
void loadPtr(Student array[], Student **ptr){
    for(int i = 0; i < SIZE; i++){
        ptr[i] = &array[i];
    }
}

/**
 * @brief Sorts the pointer by last name
 * 
 * @param ptr pointer that is full of addresses of array
 */
void sortLN(Student *ptr[], int num){
    bool madeAswap = true;
    int lastIndex = SIZE-1;
    Student temp, temp1, hold[SIZE];
    int holdCount = 0; //to count the number of holds that are needed for last names
    //Checks if it should change the lowercase last name to uppercase based on if it needs to do a binary search or not
    if(num == 1){
        /*To take last names that start with lowercase and change the first letter of the last name to an uppercase
        this allows it to be sorted properly.*/
        for(int i = 0; i < SIZE; i++){
            temp = *ptr[i];
            if(islower(temp.last[0])){
                temp.last[0] = toupper(temp.last[0]);
                *ptr[i] = temp;
                hold[holdCount] = temp;
                holdCount++;
            }
        }    
    }

    while(madeAswap){
        
        madeAswap = false;
        for (int count = 0; count < lastIndex; count++){
            temp = *ptr[count];
            temp1 = *ptr[count+1];
            if(temp.last > temp1.last)
            {
            Student *temp3 = ptr[count];
            ptr[count] = ptr[count + 1];
            ptr[count + 1] = temp3;
            madeAswap = true;
            }
            }
            --lastIndex;
    }
    //To turn any last names that became uppercase back into lowercase
    if(num == 1){
        for(int i = 0; i < SIZE; i++){
            temp = *ptr[i];
            for(int count = 0; count < (int)size(hold); count++){
                if(temp.last == hold[count].last){
                temp.last[0] = tolower(temp.last[0]);
                *ptr[i] = temp;
                }
            }
        }    
    }

}

/**
 * @brief Sorts the pointer by SSN
 * 
 * @param ptr pointer that is full of addresses of array
 */
void sortSSN(Student *ptr[]){
    bool madeAswap = true;
    int lastIndex = SIZE-1;
    Student temp, temp1;
    while(madeAswap){
        
        madeAswap = false;
        for (int count = 0; count < lastIndex; count++){
            temp = *ptr[count];
            temp1 = *ptr[count+1];
            if(temp.ssn > temp1.ssn)
            {
            Student *temp3 = ptr[count];
            ptr[count] = ptr[count + 1];
            ptr[count + 1] = temp3;
            madeAswap = true;
            }
            }
            --lastIndex;
    }
}

/**
 * @brief Sorts the pointer by First Name
 * 
 * @param ptr pointer that is full of addresses of array
 */
void sortFN(Student *ptr[]){
    bool madeAswap = true;
    int lastIndex = SIZE-1;
    Student temp, temp1;
    while(madeAswap){
        
        madeAswap = false;
        for (int count = 0; count < lastIndex; count++){
            temp = *ptr[count];
            temp1 = *ptr[count+1];
            if(temp.first > temp1.first)
            {
            Student *temp3 = ptr[count];
            ptr[count] = ptr[count + 1];
            ptr[count + 1] = temp3;
            madeAswap = true;
            }
            }
            --lastIndex;
    }
}

/**
 * @brief Prints the data that is sent to it
 * 
 * @param vector that is full of the Student struct data
 */
void print(Student *ptr[], int num){
    if(num != -1){ //print single line of vector at place num
        Student temp = *ptr[num];
        cout<<"ID: "<<temp.id<<"\n"<<
            "Last Name: "<<temp.last<<"\n"<<
            "First Name: "<<temp.first<<"\n"<<
            "SSN: "<<temp.ssn<<"\n"<<
            "Grade: "<<temp.grade<<"\n\n"<<endl;
    } else { //print sorted vector
        cout<<left<<setw(3)<<"ID"<<setw(11)<<"Last Name"<<setw(12)<<"First Name"<<setw(12)<<"SSN"<<"Grade"<<endl; 
        for(int i = 0; i < SIZE; i++){
            Student temp = *ptr[i];
            cout<<right<<setw(2)<<temp.id<<" "<<left<<setw(11)<<temp.last<<setw(12)<<temp.first<<setw(12)<<temp.ssn<<temp.grade<<endl;
        }
        cout<<"\n\n";
    }
}

/**
 * @brief prints the menu to the terminal
 * 
 */
bool menu(Student *lastN[], Student *firstN[], Student *ssn[]){
    int menuNum;
    //runs as long as there is not a valid menu input, such as >=8 or <=0
    do{
        cout<<"1. Print data in ascending order by last name\n"<<
            "2. Print data in ascending order by SSN\n"<<
            "3. Search by last name\n"<<
            "4. Search by SSN\n"<<
            "5. Print data in ascending order by first name\n"<<
            "6. Search by first name\n"<<
            "7. Exit\n\nSelect a Menu: ";

        cin>>menuNum;
        if(!validMenuInput(menuNum)){
            cout<<"Incorrect input\n";
        }

    }while(!validMenuInput(menuNum));
    //Calls function based on menu input    
    switch (menuNum)
    {
    case 1:
        ascLastName(lastN);
        return true;
        break;
    case 2:
        ascSSN(ssn);
        return true;
        break;
    case 3:
        searchLN(lastN);
        return true;
        break;
    case 4:
        searchSSN(ssn);
        return true;
        break;
    case 5:
        ascFirstName(firstN);
        return true;
        break;
    case 6:
        searchFN(firstN);
        return true;
        break;
    case 7:
        return false;
        break;
    
    default:
    return false;
        break;
    }
    return false;
}

/**
 * @brief Checks in menu input from user is within the valid range of 1 - 5
 * 
 * @param num is menuNum from menu function
 * @return true num is within range
 * @return false num is not within range
 */
bool validMenuInput(int num){
    if(num >= 1 && num <= 7){
        return true;
    } else {
        return false;
    }
}

/**
 * @brief Calls function that sorts the pointer according to last name and then calls function that prints the list of students in that order.
 * 
 * @param ptr pointer that is full of the Student struct data
 */
void ascLastName(Student *ptr[]){
    sortLN(ptr, 1);//Tells it to sort the lowercase name into correct position based on alphabetical order
    print(ptr, -1);
}

/**
 * @brief Calls function that sorts the pointer according to the SSN and then calls function that prints the list of students in that order.
 * 
 * @param ptr pointer that is full of the Student struct data
 */
void ascSSN(Student *ptr[]){
    sortSSN(ptr);
    print(ptr, -1);
}

/**
 * @brief Calls function that sorts the pointer according to the first name and then calls function that prints the list of students in that order.
 * 
 * @param ptr pointer that is full of the Student struct data
 */
void ascFirstName(Student *ptr[]){
    sortFN(ptr);
    print(ptr, -1);
}

/**
 * @brief Calls function to sort pointer. Then searches list of students for one matching the 
 * last name input by user and  calls function that prints that students information.
 * 
 * @param ptr Pointer that is full of Student struct data
 */
void searchLN(Student *ptr[]){
    sortLN(ptr, -1);//Tells it not to change lowercase to uppercase so that binary search works correctly
    int position = -1; // Position of search value
    bool found = false; // Flag
    cin.ignore();
    while(!found){
        string lastName = " ";
        cout<<"Please enter the Last Name of the person you are looking for: ";
        
        getline(cin, lastName);
        
        int first = 0, // First array element
        last = SIZE - 1, // Last array element
        middle; // Midpoint of search
        position = -1;
        Student temp;
        while (!found && first <= last){
            middle = (first + last) / 2; // Calculate midpoint
            temp = *ptr[middle];
            if (temp.last == lastName){ // If value is found at mid
                found = true;
                position = middle;
            }else if (temp.last > lastName){ // If value is in lower half
                last = middle - 1;
            }else{
                first = middle + 1; // If value is in upper half
            }
        }
        if(!found){
            cout<<"Name not found."<<endl;
        }
    }
    print(ptr, position);
}

/**
 * @brief Calls function to sort pointer. Then searches list of students for one matching the 
 * SSN input by user and then calls function that prints that students information.
 * 
 * @param ptr Pointer that is full of Student struct data
 */
void searchSSN(Student *ptr[]){
    sortSSN(ptr);
    int position = -1; // Position of search value
    bool found = false; // Flag
    while(!found){
        string ssn;
        cout<<"Please enter the SSN of the person you are looking for (ie. ###-##-####): ";
        cin>>ssn;

        int first = 0, // First array element
        last = SIZE - 1, // Last array element
        middle; // Midpoint of search
        position = -1;
        Student temp;
        while (!found && first <= last){
            middle = (first + last) / 2; // Calculate midpoint
            temp = *ptr[middle];
            if (temp.ssn == ssn){ // If value is found at mid
                found = true;
                position = middle;
            }else if (temp.ssn > ssn){ // If value is in lower half
                last = middle - 1;
            }else{
                first = middle + 1; // If value is in upper half
            }
        }
        if(!found){
            cout<<"Name not found."<<endl;
        }
    }
    print(ptr, position);
}

/**
 * @brief Calls function to sort pointer. Then searches list of students for one matching the 
 * first name input by user and  calls function that prints that students information.
 * 
 * @param ptr Pointer that is full of Student struct data
 */
void searchFN(Student *ptr[]){
    sortFN(ptr);
    int position = -1; // Position of search value
    bool found = false; // Flag
    while(!found){
        string firstName;
        cout<<"Please enter the First Name of the person you are looking for: ";
        cin.ignore();
        getline(cin, firstName);

        int first = 0, // First array element
        last = SIZE - 1, // Last array element
        middle; // Midpoint of search
        position = -1;
        Student temp;
        while (!found && first <= last){
            middle = (first + last) / 2; // Calculate midpoint
            temp = *ptr[middle];
            if (temp.first == firstName){ // If value is found at mid
                found = true;
                position = middle;
            }else if (temp.first > firstName){ // If value is in lower half
                last = middle - 1;
            }else{
                first = middle + 1; // If value is in upper half
            }
        }
        if(!found){
            cout<<"Name not found."<<endl;
        }
    }
    print(ptr, position);
}



