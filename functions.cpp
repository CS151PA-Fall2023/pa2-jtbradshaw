#include "functions.h"


void loadVector(vector<Student> &vector){

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
    do{

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

        vector.push_back(temp); //puts temp into vector
        
    } while(file.peek()!=EOF);


    //closes file
    file.close();

}

/**
 * @brief Prints the data that is sent to it
 * 
 * @param vector that is full of the Grade struct data
 */
void print(const vector<Student> &vector, int num){
    if(num > 0){ //print single line of vector at place num
        cout<<"ID: "<<vector[num].id<<"\n"<<
            "Last Name: "<<vector[num].last<<"\n"<<
            "First Name: "<<vector[num].first<<"\n"<<
            "SSN: "<<vector[num].ssn<<"\n"<<
            "Grade: "<<vector[num].grade<<endl;
    } else { //print sorted vector
        cout; 
    }

}

/**
 * @brief prints the menu to the terminal
 * 
 */
void menu(vector<Student> &vector){
    int menuNum;
    do{
        cout<<"1. Print data in ascending order by last name\n"<<
            "2. Print data in ascending order by SSN\n"<<
            "3. Search by last name\n"<<
            "4. Search by SSN\n"<<
            "5. Exit\n\nSelect a Menu: ";

        cin>>menuNum;

    }while(!validMenuImput(menuNum));
        
    switch (menuNum)
    {
    case 1:
        ascLastName(vector);
        break;
    case 2:
        ascSSN(vector);
        break;
    case 3:
        searchLN(vector);
        break;
    case 4:
        searchSSN(vector);
        break;
    case 5:
        exit(1);
        break;
    
    default:
        break;
    }
}

/**
 * @brief Checks in menu input from user is within the valid range of 1 - 5
 * 
 * @param num is menuNum from menu function
 * @return true num is within range
 * @return false num is not within range
 */
bool validMenuImput(int num){
    if(num >= 1 && num <= 6){
        return true;
    } else {
        return false;
    }
}


void ascLastName(vector<Student> &vector){

}


void ascSSN(vector<Student> &vector){

}


void searchLN(vector<Student> &vector){

}


void searchSSN(vector<Student> &vector){

}