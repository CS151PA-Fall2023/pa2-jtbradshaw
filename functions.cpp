#include "functions.h"

/**
 * @brief Opens the file, loads it into the vector, and then closes the file. 
 * 
 * @param vector Vector that is full of the Student struct data
 */
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
    while(file.peek()!=EOF){

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
        
    }
    vector.pop_back(); //for some reason it is scanning the final row into the vector twice.

    //closes file
    file.close();

}

/**
 * @brief Prints the data that is sent to it
 * 
 * @param vector that is full of the Student struct data
 */
void print(const vector<Student> &vector, int num){
    if(num != -1){ //print single line of vector at place num
        cout<<"ID: "<<vector[num].id<<"\n"<<
            "Last Name: "<<vector[num].last<<"\n"<<
            "First Name: "<<vector[num].first<<"\n"<<
            "SSN: "<<vector[num].ssn<<"\n"<<
            "Grade: "<<vector[num].grade<<"\n\n"<<endl;
    } else { //print sorted vector
        cout<<left<<setw(3)<<"ID"<<setw(11)<<"Last Name"<<setw(12)<<"First Name"<<setw(12)<<"SSN"<<"Grade"<<endl; 
        for(int i = 0; i < (int)vector.size(); i++){
            cout<<right<<setw(2)<<vector[i].id<<" "<<left<<setw(11)<<vector[i].last<<setw(12)<<vector[i].first<<setw(12)<<vector[i].ssn<<vector[i].grade<<endl;
        }
        cout<<"\n\n";
    }
}

/**
 * @brief prints the menu to the terminal
 * 
 */
bool menu(vector<Student> &vector){
    int menuNum;
    do{
        cout<<"1. Print data in ascending order by last name\n"<<
            "2. Print data in ascending order by SSN\n"<<
            "3. Search by last name\n"<<
            "4. Search by SSN\n"<<
            "5. Exit\n\nSelect a Menu: ";

        cin>>menuNum;
        if(!validMenuInput(menuNum)){
            cout<<"Incorrect input\n";
        }

    }while(!validMenuInput(menuNum));
        
    switch (menuNum)
    {
    case 1:
        ascLastName(vector);
        return true;
        break;
    case 2:
        ascSSN(vector);
        return true;
        break;
    case 3:
        searchLN(vector);
        return true;
        break;
    case 4:
        searchSSN(vector);
        return true;
        break;
    case 5:
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
    if(num >= 1 && num <= 5){
        return true;
    } else {
        return false;
    }
}

/**
 * @brief Sorts the vector according to last name and then prints the list of students in that order.
 * 
 * @param vector Vector that is full of the Student struct data
 */
void ascLastName(vector<Student> &vector){
    for (int startScan = 1; startScan < (int)vector.size(); ++startScan)
    {
        string key = vector[startScan].last;
        Student temp = vector[startScan];
        int index = startScan - 1;
        while (index >= 0 && vector[index].last > key)
        {
            vector[index+1] = vector[index];
            --index;
        }
        vector[index+1] = temp;
    }
    print(vector, -1);
}

/**
 * @brief Sorts the vector according to SSN and then prints the list of students in that order.
 * 
 * @param vector Vector that is full of the Student struct data
 */
void ascSSN(vector<Student> &vector){
        for (int startScan = 1; startScan < (int)vector.size(); ++startScan)
    {
        string key = vector[startScan].ssn;
        Student temp = vector[startScan];
        int index = startScan - 1;
        while (index >= 0 && vector[index].ssn > key)
        {
            vector[index+1] = vector[index];
            --index;
        }
        vector[index+1] = temp;
    }
    print(vector, -1);
}

/**
 * @brief Searches list of students for one matching the last name input by user and then prints that students information.
 * 
 * @param vector Vector that is full of the Student struct data
 */
void searchLN(vector<Student> &vector){
    string name;
    bool nameInVect = false;
    while(!nameInVect){
        cout<<"Please enter the last name of the person you are looking for: ";
        cin>>name;
        for(int i = 0; i < (int)vector.size(); i++){
            if(name == vector[i].last){
                print(vector, i);
                nameInVect = true;
                break;
                break;
            }
        }
        if(!nameInVect){
            cout<<"Name not found."<<endl;
        }
    }
}

/**
 * @brief Searches list of students for one matching the SSN input by user and then prints that students information.
 * 
 * @param vector Vector that is full of the Student struct data
 */
void searchSSN(vector<Student> &vector){
    string ssn;
    bool ssnInVect = false;
    while(!ssnInVect){
        cout<<"Please enter the SSN of the person you are looking for: ";
        cin>>ssn;
        for(int i = 0; i < (int)vector.size(); i++){
            if(ssn == vector[i].ssn){
                print(vector, i);
                ssnInVect = true;
                break;
                break;
            }
        }
        if(!ssnInVect){
            cout<<"Name not found."<<endl;
        }
    }
}