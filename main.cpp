#include "functions.h"

int main(){
    vector<Student> gradeVect;
    loadVector(gradeVect);
    bool run = true;
    while(run){
        run = menu(gradeVect);
    }

    //print(gradeVect,0);


    return 0;
}