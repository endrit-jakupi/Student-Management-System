#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
using namespace std;
class Faculty{ //Abstract class
public:
    virtual void printStudentData()=0; //Pure virtual function to print students data
};
class Course{ //Class that provides information about student's courses
protected:
    string courseName1;
    string courseName2;
    string courseName3;
    string courseName4;
    string courseName5;
    int grade1;
    int grade2;
    int grade3;
    int grade4;
    int grade5;
public:
    Course(string cn1="Course Name 1", int gr1=10, string cn2="Course Name 2", int gr2=10, string cn3="Course Name 3", int gr3=10, string cn4="Course Name 4", int gr4=10, string cn5="Course Name 5", int gr5=10){ //Constructor for all 5 student's courses
        courseName1=cn1;
        grade1=gr1;
        courseName2=cn2;
        grade2=gr2;
        courseName3=cn3;
        grade3=gr3;
        courseName4=cn4;
        grade4=gr4;
        courseName5=cn5;
        grade5=gr5;
    }
    
    //All needed set functions
    void setCourseName1(string cn1);
    void setGrade1(int gr1);
    void setCourseName2(string cn2);
    void setGrade2(int gr2);
    void setCourseName3(string cn3);
    void setGrade3(int gr3);
    void setCourseName4(string cn4);
    void setGrade4(int gr4);
    void setCourseName5(string cn5);
    void setGrade5(int gr5);
    
    //All needed get functions
    string getCourseName1();
    int getGrade1();
    string getCourseName2();
    int getGrade2();
    string getCourseName3();
    int getGrade3();
    string getCourseName4();
    int getGrade4();
    string getCourseName5();
    int getGrade5();
    
};
class Student : public Course{ //Class that provides information about student's personal data and also inherits class Course
private:
    int id;
    string name;
    string surname;
    string country;
    string city;
    string faculty;
    double gpa;
public:
    Student(int i=0, string n="Name", string s="Surname", string c="Country", string ct="City", string f="Faculty", string cn1="Course Name 1", int gr1=10, string cn2="Course Name 2", int gr2=10, string cn3="Course Name 3", int gr3=10, string cn4="Course Name 4", int gr4=10, string cn5="Course Name 5", int gr5=10, double g=10) : Course (cn1, gr1, cn2, gr2, cn3, gr3, cn4, gr4, cn5, gr5){ //Constructor for both Student and Course class
        id=i;
        name=n;
        surname=s;
        country=c;
        city=ct;
        faculty=f;
        gpa=g;
    }
    
    //All needed set functions
    void setID(int i);
    void setName(string n);
    void setSurname(string s);
    void setCountry(string c);
    void setCity(string ct);
    void setFaculty(string f);
    void setGPA(double g);
    
    //All needed get functions
    int getID();
    string getName();
    string getSurname();
    string getCountry();
    string getCity();
    string getFaculty();
    double getGPA();
    
    //Operator overloading function that compares whether two students have the same GPA or not
    bool operator==(Student s){
        if(getGPA()==s.getGPA()){
            return true;
        }
        else{
            return false;
        }
    }
    
    virtual void printStudentData(); //Virtual function
    
};
class University : public Student{ //Class that provides information about university and also inherits class Student
private:
    string universityName;
    int year;
    Student student[50];
    int numberOfStudents=3;
public:
    University(string un="University Name", int y=2022, int nof=0){ //Constructor for class University
        universityName=un;
        year=y;
        numberOfStudents=nof;
    }
    
    //All needed set functions
    void setUniversityName(string un);
    void setYear(int y);
    void setNumberOfStudents(int nof);
    
    //All needed get functions
    string getUniversityName();
    int getYear();
    int getNumberOfStudents();
    
    //Functions that will be displayed in the main program
    void addStudentData(); //Function to add students in the program
    void updateStudentData(); //Function to update or change student data in the program
    void searchStudentData(); //Function to search a specific student in the program
    void displayStudentTranscript(); //Function to display a specific student;s transcript
    void highestgpa(); //Function to find the highest GPA from all the students
    void compareGPAs(); //Function to compare student's GPA using operator overloading function
    void studentFile(); //Function to display student's data in the file
    
    virtual void printStudentData(); //Virtual function
    
    void hireFromCode(int id, string name, string surname, string country, string city, string faculty, string cn1, int gr1, string cn2, int gr2, string cn3, int gr3, string cn4, int gr4, string cn5, int gr5, double gpa); //Function to display students as a test from the main program
};
int main()
{
    University seeu("South East European University",2022,0);
    //Test students from the main program
    seeu.hireFromCode(1, "Gramos", "Jakupi", "Kosovo", "Prishtina", "Computer Sciences", "Programming", 10, "Linear Algebra", 8, "Technologies", 9, "English 4", 9, "IT Skills", 10, 9.2);
    seeu.hireFromCode(2, "Drin", "Shahini", "Kosovo", "Gjilan", "Architecture", "Archicad", 10, "Geometry", 8, "Conception", 9, "English 4", 10, "Arch Skills", 10, 9.4);
    seeu.hireFromCode(3, "Edin", "Rama", "Macedonia", "Tetovo", "Dentistry", "Anatomy I", 7, "Chemistry", 8, "Physics", 10, "English 3", 10, "Biology", 6, 8.2);
    
    
    
    int option;
    
    bool repeat(true);
    
    while((repeat=true)){ //The menu will appear constantly after a function is finished
        //Program's main menu
        cout<<"―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――"<<endl;
        cout<<"SEE University Students Record"<<endl;
        cout<<"―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――"<<endl;
        cout<<"Main Menu"<<endl;
        cout<<"―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――"<<endl;
        cout<<"Press 1 to Print Student Data"<<endl;
        cout<<"Press 2 to Add Student Data"<<endl;
        cout<<"Press 3 to Display Student Transcript"<<endl;
        cout<<"Press 4 to Search Student Data"<<endl;
        cout<<"Press 5 to Change Student Data"<<endl;
        cout<<"Press 6 to Find Highest GPA"<<endl;
        cout<<"Press 7 to Compare Student GPA"<<endl;
        cout<<"Press 8 to Open Student File"<<endl;
        cout<<"―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――"<<endl;
        cout<<"Press here: ";
        cin>>option;
    
    
    switch (option) {
        case 1:
            seeu.printStudentData(); //Print Student's Data Function
            cin.get(); cin.get();
            break;
            
        case 2:
            seeu.addStudentData(); //Add Student's Data Function
            cin.get(); cin.get();
            break;
            
        case 3:
            seeu.displayStudentTranscript(); //Display Student's Data Function
            cin.get(); cin.get();
            break;
            
        case 4:
            seeu.searchStudentData(); //Search Student's Data Function
            cin.get(); cin.get();
            break;
            
        case 5:
            seeu.updateStudentData(); //Update Student's Data Function
            cin.get(); cin.get();
            break;
            
        case 6:
            seeu.highestgpa(); //Highest Student's GPA Function
            cin.get(); cin.get();
            break;
            
        case 7:
            seeu.compareGPAs(); //Compare Student's GPA Function
            cin.get(); cin.get();
            break;
            
        case 8:
            seeu.studentFile(); //Display File Function
            cin.get(); cin.get();
            break;
            
        case 9:
            repeat=false;
            break; //Quit
        }
    }
    
    cin.get(); cin.get();
    return 0;
}

//Course Class Definitions

void Course::setCourseName1(string cn1){
    courseName1=cn1;
}
void Course::setGrade1(int gr1){
    grade1=gr1;
}
void Course::setCourseName2(string cn2){
    courseName2=cn2;
}
void Course::setGrade2(int gr2){
    grade2=gr2;
}
void Course::setCourseName3(string cn3){
    courseName3=cn3;
}
void Course::setGrade3(int gr3){
    grade3=gr3;
}
void Course::setCourseName4(string cn4){
    courseName4=cn4;
}
void Course::setGrade4(int gr4){
    grade4=gr4;
}
void Course::setCourseName5(string cn5){
    courseName5=cn5;
}
void Course::setGrade5(int gr5){
    grade5=gr5;
}
string Course::getCourseName1(){
    return courseName1;
}
int Course::getGrade1(){
    return grade1;
}
string Course::getCourseName2(){
    return courseName2;
}
int Course::getGrade2(){
    return grade2;
}
string Course::getCourseName3(){
    return courseName3;
}
int Course::getGrade3(){
    return grade3;
}
string Course::getCourseName4(){
    return courseName4;
}
int Course::getGrade4(){
    return grade4;
}
string Course::getCourseName5(){
    return courseName5;
}
int Course::getGrade5(){
    return grade5;
}

//Course Student Definitions

void Student::setID(int i){
    id=i;
}
void Student::setName(string n){
    name=n;
}
void Student::setSurname(string s){
    surname=s;
}
void Student::setCountry(string c){
    country=c;
}
void Student::setCity(string ct){
    city=ct;
}
void Student::setFaculty(string f){
    faculty=f;
}
void Student::setGPA(double g){
    gpa=g;
}
int Student::getID(){
    return id;
}
string Student::getName(){
    return name;
}
string Student::getSurname(){
    return surname;
}
string Student::getCountry(){
    return country;
}
string Student::getCity(){
    return city;
}
string Student::getFaculty(){
    return faculty;
}
double Student::getGPA(){
    return gpa;
}
void Student::printStudentData(){ //Definition of virtual function from class Student
    cout<<"―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――"<<endl;
    cout<<"SEE University Students Record"<<endl;
    cout<<"―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――"<<endl;
    cout<<setw(3)<<"ID"<<setw(1)<<"|"<<setw(12)<<"Name"<<setw(1)<<"|"<<setw(12)<<"Surname"<<setw(1)<<"|"<<setw(12)<<"Country"<<setw(1)<<"|"<<setw(12)<<"City"<<setw(1)<<"|"<<setw(20)<<"Faculty"<<setw(1)<<"|"<<setw(8)<<"GPA"<<setw(1)<<"|"<<endl;
    cout<<"―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――"<<endl;
}

//Course University Definitions

void University::setUniversityName(string un){
    universityName=un;
}
void University::setYear(int y){
    year=y;
}
void University::setNumberOfStudents(int nof){
    numberOfStudents=nof;
}
string University::getUniversityName(){
    return universityName;
}
int University::getYear(){
    return year;
}
int University::getNumberOfStudents(){
    return numberOfStudents;
}
void University::printStudentData(){ //Definition of the main virtual function from class University
    cout<<"―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――"<<endl;
    cout<<"SEE University Students Record"<<endl;
    cout<<"―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――"<<endl;
    cout<<setw(3)<<"ID"<<setw(1)<<"|"<<setw(12)<<"Name"<<setw(1)<<"|"<<setw(12)<<"Surname"<<setw(1)<<"|"<<setw(12)<<"Country"<<setw(1)<<"|"<<setw(12)<<"City"<<setw(1)<<"|"<<setw(20)<<"Faculty"<<setw(1)<<"|"<<setw(8)<<"GPA"<<setw(1)<<"|"<<endl;
    cout<<"―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――"<<endl;
    
    for(int i=0; i<numberOfStudents; i++){
        cout<<setw(3)<<student[i].getID()<<setw(1)<<"|"<<setw(12)<<student[i].getName()<<setw(1)<<"|"<<setw(12)<<student[i].getSurname()<<setw(1)<<"|"<<setw(12)<<student[i].getCountry()<<setw(1)<<"|"<<setw(12)<<student[i].getCity()<<setw(1)<<"|"<<setw(20)<<student[i].getFaculty()<<setw(1)<<setw(1)<<"|"<<setw(8)<<student[i].getGPA()<<setw(1)<<"|"<<endl;
    }
}
void University::addStudentData(){ //Function's Definition
    
    string n, s, c, ct, f, cn1, cn2, cn3, cn4, cn5;
    int gr1, gr2, gr3, gr4, gr5;
    double sum;
    double g;
    
    cout<<"ID: "<<numberOfStudents+1<<endl;
    student[numberOfStudents].setID(numberOfStudents+1);
    cout<<"Name: ";
    cin>>n;
    student[numberOfStudents].setName(n);
    cout<<"Surname: ";
    cin>>s;
    student[numberOfStudents].setSurname(s);
    cout<<"Country: ";
    cin>>c;
    student[numberOfStudents].setCountry(c);
    cout<<"City: ";
    cin>>ct;
    student[numberOfStudents].setCity(ct);
    cout<<"Faculty: ";
    cin>>f;
    student[numberOfStudents].setFaculty(f);
    cout<<"Course Name 1: ";
    cin>>cn1;
    student[numberOfStudents].setCourseName1(cn1);
    cout<<"Grade: ";
    cin>>gr1;
    student[numberOfStudents].setGrade1(gr1);
    cout<<"Course Name 2: ";
    cin>>cn2;
    student[numberOfStudents].setCourseName2(cn2);
    cout<<"Grade: ";
    cin>>gr2;
    student[numberOfStudents].setGrade2(gr2);
    cout<<"Course Name 3: ";
    cin>>cn3;
    student[numberOfStudents].setCourseName3(cn3);
    cout<<"Grade: ";
    cin>>gr3;
    student[numberOfStudents].setGrade3(gr3);
    cout<<"Course Name 4: ";
    cin>>cn4;
    student[numberOfStudents].setCourseName4(cn4);
    cout<<"Grade: ";
    cin>>gr4;
    student[numberOfStudents].setGrade4(gr4);
    cout<<"Course Name 5: ";
    cin>>cn5;
    student[numberOfStudents].setCourseName5(cn5);
    cout<<"Grade: ";
    cin>>gr5;
    student[numberOfStudents].setGrade5(gr5);
    
    sum=student[numberOfStudents].getGrade1()+student[numberOfStudents].getGrade2()+student[numberOfStudents].getGrade3()+student[numberOfStudents].getGrade4()+student[numberOfStudents].getGrade5();

    g=sum/5;
    
    student[numberOfStudents].setGPA(g);
    
    
    numberOfStudents++;
    
    cout<<endl;
    cout<<"Student is addedd successfully!"<<endl;
}
void University::hireFromCode(int id, string name, string surname, string country, string city, string faculty, string cn1, int gr1, string cn2, int gr2, string cn3, int gr3, string cn4, int gr4, string cn5, int gr5, double gpa){ //Function's Definition
    student[id-1].setID(id);
    student[id-1].setName(name);
    student[id-1].setSurname(surname);
    student[id-1].setCountry(country);
    student[id-1].setCity(city);
    student[id-1].setFaculty(faculty);
    student[id-1].setCourseName1(cn1);
    student[id-1].setGrade1(gr1);
    student[id-1].setCourseName2(cn2);
    student[id-1].setGrade2(gr2);
    student[id-1].setCourseName3(cn3);
    student[id-1].setGrade3(gr3);
    student[id-1].setCourseName4(cn4);
    student[id-1].setGrade4(gr4);
    student[id-1].setCourseName5(cn5);
    student[id-1].setGrade5(gr5);
    student[id-1].setGPA(gpa);
    
    numberOfStudents++;
}
void University::displayStudentTranscript(){ //Function's Definition
    int id;
    //Printing all the records first and giving the option to choose a particular student
    printStudentData();
    //Student's ID as an input for the program to search their transcript
    cout<<"\nEnter Student's ID You Want To View Transcript: ";
    cin>>id;
    //Displaying Student's First and Last Name along with their transcript
    cout<<"\n―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――"<<endl;
    cout<<"SEE University Students Record"<<endl;
    cout<<"―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――"<<endl;
    cout<<student[id-1].getName()<<" "<<student[id-1].getSurname()<<"'s Transcript"<<endl;
    cout<<"―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――"<<endl;
    cout<<setw(3)<<"ID"<<setw(1)<<"|"<<setw(12)<<"Name"<<setw(1)<<"|"<<setw(12)<<"Surname"<<setw(1)<<"|"<<setw(13)<<student[id-1].getCourseName1()<<setw(1)<<"|"<<setw(14)<<student[id-1].getCourseName2()<<setw(1)<<"|"<<setw(14)<<student[id-1].getCourseName3()<<setw(1)<<"|"<<setw(14)<<student[id-1].getCourseName4()<<setw(1)<<"|"<<setw(14)<<student[id-1].getCourseName5()<<setw(1)<<"|"<<setw(7)<<"GPA"<<setw(1)<<"|"<<endl;
    cout<<"―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――"<<endl;
    cout<<setw(3)<<student[id-1].getID()<<setw(1)<<"|"<<setw(12)<<student[id-1].getName()<<setw(1)<<"|"<<setw(12)<<student[id-1].getSurname()<<setw(1)<<"|"<<setw(13)<<student[id-1].getGrade1()<<setw(1)<<"|"<<setw(14)<<student[id-1].getGrade2()<<setw(1)<<"|"<<setw(14)<<student[id-1].getGrade3()<<setw(1)<<"|"<<setw(14)<<student[id-1].getGrade4()<<setw(1)<<"|"<<setw(14)<<student[id-1].getGrade5()<<setw(1)<<"|"<<setw(7)<<student[id-1].getGPA()<<setw(1)<<"|"<<endl;
}
void University::searchStudentData(){ //Function's Definition
    string search_name;
    cout<<"Enter Student's Name To Search For It's Data: "<<endl;
    cout<<"Student's Name: ";
    cin>>search_name; //Student's name as an input for the program to search their data
    
    for(int i=0; i<50; i++){
        if(search_name==student[i].getName()){
                cout<<"―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――"<<endl;
                cout<<"SEE University Students Record"<<endl;
                cout<<"―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――"<<endl;
                cout<<setw(3)<<"ID"<<setw(1)<<"|"<<setw(12)<<"Name"<<setw(1)<<"|"<<setw(12)<<"Surname"<<setw(1)<<"|"<<setw(12)<<"Country"<<setw(1)<<"|"<<setw(12)<<"City"<<setw(1)<<"|"<<setw(20)<<"Faculty"<<setw(1)<<"|"<<setw(8)<<"GPA"<<setw(1)<<"|"<<endl;
                cout<<"―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――"<<endl;
                
                    cout<<setw(3)<<student[i].getID()<<setw(1)<<"|"<<setw(12)<<student[i].getName()<<setw(1)<<"|"<<setw(12)<<student[i].getSurname()<<setw(1)<<"|"<<setw(12)<<student[i].getCountry()<<setw(1)<<"|"<<setw(12)<<student[i].getCity()<<setw(1)<<"|"<<setw(20)<<student[i].getFaculty()<<setw(1)<<"|"<<setw(8)<<student[i].getGPA()<<setw(1)<<"|"<<endl;
        }
    }
}
void University::updateStudentData(){ //Function's Definition
    
    string n, s, c, ct, f, cn1, cn2, cn3, cn4, cn5;
    int gr1, gr2, gr3, gr4, gr5;
    double sum=0;
    double g;
    
    printStudentData();
    int search_id;
    cout<<"\nEnter Student's ID To Update It's Data: "<<endl;
    cout<<"Student's ID: ";
    cin>>search_id;
    
    
    cout<<"Enter Student's New Data"<<endl;
    for(int i=0; i<numberOfStudents; i++){
        if(search_id==student[i].getID()){
            cout<<"ID: "<<search_id<<endl;
            student[search_id-1].setID(search_id);
            cout<<"Name: ";
            cin>>n;
            student[search_id-1].setName(n);
            cout<<"Surname: ";
            cin>>s;
            student[search_id-1].setSurname(s);
            cout<<"Country: ";
            cin>>c;
            student[search_id-1].setCountry(c);
            cout<<"City: ";
            cin>>ct;
            student[search_id-1].setCity(ct);
            cout<<"Faculty: ";
            cin>>f;
            student[search_id-1].setFaculty(f);
            cout<<"Course Name 1: ";
            cin>>cn1;
            student[search_id-1].setCourseName1(cn1);
            cout<<"Grade: ";
            cin>>gr1;
            student[search_id-1].setGrade1(gr1);
            cout<<"Course Name 2: ";
            cin>>cn2;
            student[search_id-1].setCourseName2(cn2);
            cout<<"Grade: ";
            cin>>gr2;
            student[search_id-1].setGrade2(gr2);
            cout<<"Course Name 3: ";
            cin>>cn3;
            student[search_id-1].setCourseName3(cn3);
            cout<<"Grade: ";
            cin>>gr3;
            student[search_id-1].setGrade3(gr3);
            cout<<"Course Name 4: ";
            cin>>cn4;
            student[search_id-1].setCourseName4(cn4);
            cout<<"Grade: ";
            cin>>gr4;
            student[search_id-1].setGrade4(gr4);
            cout<<"Course Name 5: ";
            cin>>cn5;
            student[search_id-1].setCourseName5(cn5);
            cout<<"Grade: ";
            cin>>gr5;
            student[search_id-1].setGrade5(gr5);
            sum=student[search_id-1].getGrade1()+student[search_id-1].getGrade2()+student[search_id-1].getGrade3()+student[search_id-1].getGrade4()+student[search_id-1].getGrade5();
            g=sum/5;
            
            student[search_id-1].setGPA(g);
        }
    }
    
    cout<<"\nStudent Data Updated Successfully!"<<endl;
}
void University::highestgpa(){ //Function's Definition
    int max=student[0].getGPA();
    int index=0;
    for(int i=0; i<numberOfStudents; i++){
        if(student[i].getGPA()>max){
            max=student[i].getGPA();
            index=i;
        }
    }
    
    cout<<"―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――"<<endl;
    cout<<"SEE University Students Record"<<endl;
    cout<<"―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――"<<endl;
    cout<<"Highest Student GPA"<<endl;
    cout<<"―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――"<<endl;
    cout<<setw(3)<<"ID"<<setw(1)<<"|"<<setw(12)<<"Name"<<setw(1)<<"|"<<setw(12)<<"Surname"<<setw(1)<<"|"<<setw(8)<<"GPA"<<setw(1)<<"|"<<endl;
    cout<<"―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――"<<endl;
    
        cout<<setw(3)<<student[index].getID()<<setw(1)<<"|"<<setw(12)<<student[index].getName()<<setw(1)<<"|"<<setw(12)<<student[index].getSurname()<<setw(1)<<"|"<<setw(8)<<student[index].getGPA()<<setw(1)<<"|"<<endl;
}
void University::compareGPAs(){ //Function's Definition
    printStudentData();
    
    int search_id1, search_id2;
    
    cout<<"Enter First Student ID: ";
    cin>>search_id1;
    cout<<"Enter Second Student ID: ";
    cin>>search_id2;
    
    cout<<"―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――"<<endl;
    cout<<"SEE University Students Record"<<endl;
    cout<<"―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――"<<endl;
    
    if(student[search_id1-1].getGPA()==student[search_id2-1].getGPA()){
        
        cout<<student[search_id1-1].getName()<<" and "<<student[search_id2-1].getName()<<" have the same GPA."<<endl;
    }
    else{
        cout<<student[search_id1-1].getName()<<" and "<<student[search_id2-1].getName()<<" does not have the same GPA."<<endl;
    }
}
void University::studentFile(){ //Function's Definition
    cout<<"―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――"<<endl;
    cout<<"SEE University Students Record"<<endl;
    cout<<"―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――"<<endl;
    cout<<"Open File To View Student Data!"<<endl;
    fstream studentFile; //studentFile is an object of type fstream
    studentFile.open("studentrecords.txt", ios::out);
    if(studentFile.is_open()){
        studentFile<<"―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――"<<endl;
        studentFile<<"SEE University Students Record"<<endl;
        studentFile<<"―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――"<<endl;
        studentFile<<setw(3)<<"ID"<<setw(1)<<"|"<<setw(12)<<"Name"<<setw(1)<<"|"<<setw(12)<<"Surname"<<setw(1)<<"|"<<setw(12)<<"Country"<<setw(1)<<"|"<<setw(12)<<"City"<<setw(1)<<"|"<<setw(20)<<"Faculty"<<setw(1)<<"|"<<setw(8)<<"GPA"<<setw(1)<<"|"<<endl;
        studentFile<<"―――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――――"<<endl;
        
        for(int i=0; i<numberOfStudents; i++){
            studentFile<<setw(3)<<student[i].getID()<<setw(1)<<"|"<<setw(12)<<student[i].getName()<<setw(1)<<"|"<<setw(12)<<student[i].getSurname()<<setw(1)<<"|"<<setw(12)<<student[i].getCountry()<<setw(1)<<"|"<<setw(12)<<student[i].getCity()<<setw(1)<<"|"<<setw(20)<<student[i].getFaculty()<<setw(1)<<setw(1)<<"|"<<setw(8)<<student[i].getGPA()<<setw(1)<<"|"<<endl;
        }
    }
    else{
        cerr<<"File could not be opened!"<<endl; //Error message in case file can not be opened
    }
}


