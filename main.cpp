#include "functions.h"

int main(){
    vector<Grade> gradeVect;
    loadVector(gradeVect);

    cout<<"Last name of first student for vector "<<gradeVect[0].last<<endl;
    cout<<"Last name of second student for vector "<<gradeVect[1].last<<endl;


    return 0;
}