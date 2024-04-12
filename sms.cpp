#include <iostream>
using namespace std;
/*#include"User.h"
#include"Admin.h"
#include"Teacher.h"
#include"Class.h"
#include"Student.h"
*/
#define CLEAR        \
    system("pause"); \
    system("cls");

int studentindex = -1;
int teacherindex = -1;
class Class;
class School;
class User
{
protected:
    string name;
    string username;
    int password;

public:
    User();
    User(string, string, int);
    string getName();
    int getPassword();
    void setName(string);
    void setPassword(int);
    void setUsername(string);
    string getUsername();
    void display();
};

User::User()
{
}

User::User(string name, string username, int password)
{
    this->name = name;
    this->username = username;
    this->password = password;
}

string User::getName()
{
    return name;
}

string User::getUsername()
{
    return username;
}

int User::getPassword()
{
    return password;
}

void User::setName(string name)
{
    this->name = name;
}

void User::setUsername(string username)
{
    this->username = username;
}

void User::setPassword(int password)
{
    this->password = password;
}

void User::display()
{
    cout << "Name: " << name << endl;
    cout << "Username: " << username << endl;
    cout << "Password: " << password << endl;
}

class Student : public User
{
    int studentID;
    int gradeLevel;
    Class *enrolledClass;
    bool isEnrolled;

public:
    Student();
    Student(string, string, int, int, int);
    void setStudentID(int);
    int getStudentID();

    void setGradeLevel(int);
    int getGradeLevel();
    void setEnrolledClasses(Class *); // admin class pass krega;
    Class getEnrolledClass();
    void displayStudent();
    void updateEnrolled(bool e)
    {
        isEnrolled = e;
    }
    bool getEnrolled()
    {
        return isEnrolled;
    }
};

Student::Student()
{
    isEnrolled = false;
}
Student::Student(string name, string username, int studentID, int password, int gradeLevel)
{
    this->name = name;
    this->username = username;
    this->studentID = studentID;
    this->password = password;
    this->gradeLevel = gradeLevel;
    isEnrolled = false;
}
void Student::setStudentID(int studentID)
{
    this->studentID = studentID;
}

int Student::getStudentID()
{
    return studentID;
}

void Student::setGradeLevel(int gradeLevel)
{
    this->gradeLevel = gradeLevel;
}

int Student::getGradeLevel()
{
    return gradeLevel;
}

/*void Student::setEnrolledClasses(Class *enrolledClass){
    *(this->enrolledClass) = *enrolledClass;
}*/

/*Class Student::getEnrolledClass(){
    return *enrolledClass;
}*/

class Teacher : public User
{
    int teacherID;
    Class *classRoster;
    int numofclasses;

public:
    Teacher();
    Teacher(string, string, int, int);
    void displayTeacher();

    void setTeacherID(int);
    int getTeacherID();
    void setClassRoster(Class *);
    Class *getClassRoster();
    void addClassToRoster(Class *);
    void allocateMemoryForClass();
    int getnumClasses()
    {
        return numofclasses;
    }
    void displayClasse();
    void AddAssignment();
};

Teacher::Teacher()
{
}

Teacher::Teacher(string name, string username, int password, int id)
{
    this->name = name;
    this->username = username;
    this->password = password;
    this->teacherID = id;
    numofclasses = 0;
    allocateMemoryForClass();
}

void Teacher::setTeacherID(int id)
{
    this->teacherID = id;
}

int Teacher::getTeacherID()
{
    return teacherID;
}

void Teacher::setClassRoster(Class *classRoster)
{
    this->classRoster = classRoster; // move this function to end , increase size dynamically
}

Class *Teacher::getClassRoster()
{
    return classRoster;
}

class Class
{
    int classID;
    string className;
    int gradeLevel;
    string subjectName;
    Teacher *assignedTeacher;
    Student *studentRoster;
    int numStudents;
    string assignment;

public:
    Class();
    Class(int, string, int, string);
    Class(int classID, string className, int gradeLevel, string subjectName, Teacher assignedTeacher);
    void setAssignment(string a){
          assignment = a;
          
    }
    void getAssignment(){
        cout<<assignment<<endl;
    }
    void setClassID(int classID);
    int getClassID();
    void setClassName(string className);
    string getClassName();
    void setGradeLevel(int gradeLevel);
    void displayClass();
    int getGradeLevel()
    {
        return gradeLevel;
    };
    void setSubjectName(string subjectName);
    string getSubjectName();
    void setAssignedTeacher(Teacher *assignedTeacher);
    Teacher getAssignedTeacher()
    {
        return *assignedTeacher;
    };
    void addStudenttoRoster(Student *student); // dynamically size increase krna hai student roster ka
    Student *getStudentRoster()
    {
        return studentRoster;
    };
    int getnumStudents()
    {
        return numStudents;
    }
};

void Teacher :: AddAssignment(){
    
        cout<<"Enter the ID of your class you want to give assignment"<<endl;
        int id;
        cin>>id;
        for(int i=0;i<numofclasses;i++)
        {
            if(classRoster[i].getClassID()==id){
                 cout<<"Enter the name of assignment: ";
                 string name;
                 cin>>name;
                 classRoster[i].setAssignment(name);
                 cout<<"Assignment Added Successfully"<<endl;
                 
            }
        }
    
}

void Teacher ::displayTeacher()
{
    cout << "Teacher Name: " << name << endl;
    cout << "Teacher ID: " << teacherID << endl;
    cout << "Number of Classes: " << numofclasses << endl;
    cout << "Classes: " << endl;
    for (int i = 0; i < numofclasses; i++)
    {
        cout << classRoster[i].getClassID() << endl;
    }
}

void Teacher::displayClasse()
{

    cout << "Classes Information: " << endl;
    for (int i = 0; i < numofclasses; i++)
    {
        classRoster[i].displayClass();
    }
}
void Class::displayClass()
{
    cout << "==================================================" << endl;
    cout << "Class Name: " << className << endl;
    cout << "Class ID: " << classID << endl;
    cout << "Subject Name: " << subjectName << endl;
    cout << "Grade Level: " << gradeLevel << endl;
    cout << "Teacher Assigned: " << assignedTeacher->getName() << endl;
    cout << "Number of Students: " << numStudents << endl;
    cout << "Students: " << endl;
    for (int i = 0; i < numStudents; i++)
    {
        cout << "Student " << i << " Name" << studentRoster[i].getName() << endl;
    }
}
void Class::addStudenttoRoster(Student *s)
{
    Student *temp;
    temp = new Student[numStudents + 1];
    for (int i = 0; i < numStudents; i++)
    {
        temp[i] = studentRoster[i];
    }
    temp[numStudents] = *s;
    delete[] studentRoster;
    studentRoster = temp;
    numStudents++;
}

void Teacher ::allocateMemoryForClass()
{
    classRoster = new Class[numofclasses];
}

Class Student ::getEnrolledClass()
{
    return *enrolledClass;
}

Class::Class()
{
}
Class::Class(int classID, string className, int gradeLevel, string subjectName)
{
    this->classID = classID;
    this->className = className;
    this->gradeLevel = gradeLevel;
    this->subjectName = subjectName;
    numStudents = 0;
    studentRoster = new Student[numStudents];
    assignedTeacher=new Teacher;
}

void Student::displayStudent()
{
    cout << "Student Name: " << name << endl;
    cout << "Student ID: " << studentID << endl;
    cout << "Student Grade Level: " << gradeLevel << endl;
    cout << "Student Class ID: " << enrolledClass->getClassID() << endl;
}

void Class::setAssignedTeacher(Teacher *assignedTeacher)
{
    *(this->assignedTeacher) = *assignedTeacher;
}

int Class::getClassID()
{
    return this->classID;
}

void Class::setClassID(int classID)
{
    this->classID = classID;
}

string Class::getClassName()
{
    return this->className;
}

void Student::setEnrolledClasses(Class *c)
{
    enrolledClass = c;
}

void Teacher::addClassToRoster(Class *c)
{
    Class *temp;
    temp = new Class[numofclasses + 1];
    for (int i = 0; i < numofclasses; i++)
    {
        temp[i] = classRoster[i];
    }
    temp[numofclasses] = *c;
    numofclasses++;
    delete[] classRoster;
    classRoster = temp;
}

class Admin : public User
{
public:
    Admin();
    Admin(string, string, int);
    Student addStudent();
    Teacher addTeacher();
    Class addClass();
    int deleteStudent(Student *, int);
    int deleteTeacher(Teacher *, int);
    int deleteClass(Class *, int);
    
    int assignTeacherToClass();
    void enrollStudentToClass(Student *, Class *, int, int);
};

Admin::Admin()
{
}

Admin::Admin(string name, string username, int password)
{
    this->name = name;
    this->username = username;
    this->password = password;
}

int Admin::assignTeacherToClass()
{

    cout << "Enter the ID of the class to assign a teacher to: " << endl;
    int classID;
    cin >> classID;
    return classID;
}

Student Admin::addStudent()
{
    string name, username;
    int password, id, gradeLevel;
    cin.ignore();
    cout << "Enter Student Name: " << endl;
    getline(cin, name);
    cout << "Enter Student Username: " << endl;
    getline(cin, username);
    cout << "Enter Student Password: " << endl;
    cin >> password;
    cout << "Enter Student ID: " << endl;
    cin >> id;
    cout << "Enter the grade level of the student: " << endl;
    cin >> gradeLevel;
    Student student(name, username, password, id, gradeLevel);
    return student;
}

Teacher Admin::addTeacher()
{
    string name, username;
    int password, id;
    cin.ignore();
    cout << "Enter Teacher Name: " << endl;
    getline(cin, name);
    cout << "Enter Teacher Username: " << endl;
    getline(cin, username);
    cout << "Enter Teacher Password: " << endl;
    cin >> password;
    cout << "Enter Teacher ID: " << endl;
    cin >> id;
    Teacher teacher(name, username, password, id);
    return teacher;
}

Class Admin ::addClass()
{
    int id, gradeLevel;
    string name, subjectName;
    cin.ignore();
    cout << "Enter Class Name: " << endl;
    getline(cin, name);
    cout << "Enter Class ID: " << endl;
    cin >> id;
    cout << "Enter the grade level of the class: " << endl;
    cin >> gradeLevel;
    cout << "Enter the subject name of the class: " << endl;
    getline(cin, subjectName);
    Class class1(id, name, gradeLevel, subjectName);
    return class1;
}

int Admin::deleteStudent(Student *s, int n)
{
    int id;
    cout << "Enter the id of the student you want to remove: " << endl;
    cin >> id;
    for (int i = 0; i < n; i++)
    {
        if (s[i].getStudentID() == id)
        {
            cout << "Student Found: " << s[i].getStudentID() << endl;
            return s[i].getStudentID();
        }
        cout << "Student Not Found" << endl;
        return -1;
    }
}
int Admin::deleteTeacher(Teacher *t, int n)
{
    int id;
    cout << "Enter the id of the teacher you want to remove: " << endl;
    cin >> id;
    for (int i = 0; i < n; i++)
    {
        if (t[i].getTeacherID() == id)
        {
            cout << "Teacher Found: " << t[i].getTeacherID() << endl;
            
            return t[i].getTeacherID();
        }
        cout << "Teacher Not Found" << endl;
        
        
        return -1;
    }
}
int Admin::deleteClass(Class *c, int n)
{
    int id;
    cout << "Enter the id of the class you want to remove: " << endl;
    cin >> id;
    for (int i = 0; i < n; i++)
    {
        if (c[i].getClassID() == id)
        {
            cout << "Class Found: " << c[i].getClassID() << endl;
            ;
            return c[i].getClassID();
        }
        cout << "Class Not Found" << endl;
        
        return -1;
    }
}

class School
{
private:
    Admin admin;
    Class *classes;
    int numClasses;
    Student *students;
    int numStudents;
    Teacher *teachers;
    int numTeachers;

public:
    Class *getClasses() { return classes; }
    Student *getStudent()
    {
        return students;
    }
    Teacher *getTeacher()
    {
        return teachers;
    }
    int getNumClasses() { return numClasses; }
    int getNumStudents() { return numStudents; }
    int getNumTeachers() { return numTeachers; }

    School()
    {
        numClasses = 0;
        numStudents = 0;
        numTeachers = 0;
    }
    School(int numTeachers, int numStudents, int numClasses)
    {

        admin.setUsername("admin");
        admin.setPassword(123);
        this->numTeachers = numTeachers;
        this->numStudents = numStudents;
        this->numClasses = numClasses;
        classes = new Class[numClasses];
        students = new Student[numStudents];
        teachers = new Teacher[numTeachers];
    }
    void addClassToArray(Class c)
    {
        Class *tempclasss;
        tempclasss = new Class[numClasses + 1];
        for (int i = 0; i < numClasses; i++)
        {
            tempclasss[i] = classes[i];
        }
        tempclasss[numClasses] = c;
        numClasses++;
        delete[] classes;
        classes = tempclasss;
    }
    void addStudentToArray(Student s)
    {

        Student *tempstudents;
        tempstudents = new Student[numStudents + 1];
        for (int i = 0; i < numStudents; i++)
        {
            tempstudents[i] = students[i];
        }
        tempstudents[numStudents] = s;
        numStudents++;
        delete[] students;
        students = tempstudents;
    }
    void addTeacherToArray(Teacher t)
    {
        Teacher *tempteachers;
        tempteachers = new Teacher[numTeachers + 1];
        for (int i = 0; i < numTeachers; i++)
        {
            tempteachers[i] = teachers[i];
        }
        tempteachers[numTeachers] = t;
        numTeachers++;
        delete[] teachers;
        teachers = tempteachers;
    }
    void deleteTeacherFromArray(int id)
    {

        Teacher *tempteachers;
        for (int i = 0; i < numTeachers; i++)
        {
            if (teachers[i].getTeacherID() == id)
            {
                tempteachers = new Teacher[numTeachers - 1];
                for (int j = 0; j < i; j++)
                {
                    tempteachers[j] = teachers[j];
                }
                for (int j = i + 1; j < numTeachers; j++)
                {
                    tempteachers[j - 1] = teachers[j];
                }
                numTeachers--;
                delete[] teachers;
                teachers = tempteachers;
                break;
            }
        }
    }
    void deleteStudentFromArray(int id)
    {
        Student *templateStudent;
        for (int i = 0; i < numStudents; i++)
        {
            if (students[i].getStudentID() == id)
            {
                templateStudent = new Student[numStudents - 1];
                for (int j = 0; j < i; j++)
                {
                    templateStudent[j] = students[j];
                }
                for (int j = i + 1; j < numStudents; j++)
                {
                    templateStudent[j - 1] = students[j];
                }
                numStudents--;
                delete[] students;
                students = templateStudent;
                break;
            }
        }
    }
    void deleteClassFromArray(int id)
    {
        Class *templateClass;
        for (int i = 0; i < numClasses; i++)
        {
            if (classes[i].getClassID() == id)
            {
                templateClass = new Class[numClasses - 1];
                for (int j = 0; j < i; j++)
                {
                    templateClass[j] = classes[j];
                }
                for (int j = i + 1; j < numClasses; j++)
                {
                    templateClass[j - 1] = classes[j];
                }
                numClasses--;
                delete[] classes;
                classes = templateClass;
                break;
            }
        }
    }
    void displaySchoolInformation()
    {
        cout << "School Information" << endl;
        cout << "Number of Teachers: " << numTeachers << endl;
        cout << "Number of Students: " << numStudents << endl;
        cout << "Number of Classes: " << numClasses << endl;
    }
    Admin getAdmin()
    {
        return admin;
    }

    void assignTeacher(int id)
    {
        for (int i = 0; i < numClasses; i++)
        {
            if (classes[i].getClassID() == id)
            {
                int teacherID;
                cout << "Enter the Id of the Teacher you want to assign to this class:" << endl;
                cin >> teacherID;
                for (int j = 0; j < numTeachers; j++)
                {
                    if (teachers[j].getTeacherID() == teacherID)
                    {
                        classes[i].setAssignedTeacher(&teachers[j]);
                        teachers[j].addClassToRoster(&classes[i]);
                        cout << "Teacher Assigned to Respective Class" << endl;
                        break;
                    }
                }
            }
            break;
        }
    }

    void displayAllStudents()
    {
        cout << "All Students In The School" << endl;
        for (int i = 0; i < numStudents; i++)
        {
            cout << "================================================================" << endl;
            cout << "Student " << i << " Information" << endl;
            cout << "Student Name: " << students[i].getName() << endl;
            cout << "Student ID:" << students[i].getStudentID() << endl;
            cout << "Student Grade Level: " << students[i].getGradeLevel() << endl;
            if (students[i].getEnrolled())
                cout << "Student Class ID: " << students[i].getEnrolledClass().getClassID() << endl;
        }
    }

    void displayAllTeachers()
    {
        cout << "All Teachers In The School" << endl;

        for (int i = 0; i < numTeachers; i++)
        {
            cout << "================================================================" << endl;
            cout << "Teacher " << i << " Information" << endl;
            cout << "Teacher Name: " << teachers[i].getName() << endl;
            cout << "Teacher ID: " << teachers[i].getTeacherID() << endl;
            cout << "Classes Assigned To Teacher: " << endl;
            for (int j = 0; j < teachers[i].getnumClasses(); j++)
            {
                cout << "Class " << j << " ID: " << teachers[i].getClassRoster()[j].getClassID() << endl;
            }
        }
    }

    void displayAllClasses()
    {
        cout << "All Classes In The School" << endl;
        for (int i = 0; i < numClasses; i++)
        {
            cout << "================================================================" << endl;
            cout << "Class " << i << " Information" << endl;
            cout << "Class Name: " << classes[i].getClassName() << endl;
            cout << "Grade Level: " << classes[i].getGradeLevel() << endl;
            cout << "Assigned Teacher: " << classes[i].getAssignedTeacher().getName() << endl;
            cout << "Students In Class: " << endl;
            for (int j = 0; j < classes[i].getnumStudents(); j++)
            {
                cout << "Student " << j << " Name: " << classes[i].getStudentRoster()[j].getName() << endl;
            }
        }
    }
};

void Admin::enrollStudentToClass(Student *s, Class *c, int numStudent, int numClass)
{

    cout << "Enter the id of the student you want to enroll" << endl;
    cout << "Num classes: " << numClass << endl;
    int id;
    cin >> id;
    for (int i = 0; i < numStudent; i++)
    {
        if (s[i].getStudentID() == id)
        {

            for (int j = 0; j < numClass; j++)

            {

                if (c[j].getGradeLevel() == s[i].getGradeLevel())
                {

                    c[j].addStudenttoRoster(&s[i]);
                    s[i].setEnrolledClasses(&c[j]);

                    s[i].updateEnrolled(1);
                    cout << "Student Enrolled Successfully" << endl;
                }
            }
        }
    }
}

int adminMenu()
{
    int choice;
    cout << "Admin Menu" << endl;
    cout << "1.Add Teacher" << endl;
    cout << "2.Add Student" << endl;
    cout << "3.Add Class" << endl;
    cout << "4.Delete Teacher" << endl;
    cout << "5.Delete Student" << endl;
    cout << "6.Delete Class" << endl;
    cout << "7.Assign a teacher to a class" << endl;
    cout << "8.Enroll a student to class" << endl;
    cout << "9.Display all Students" << endl;
    cout << "10.Display all Classes" << endl;
    cout << "11.Display all Teachers" << endl;
    cout << "12.Exit" << endl;

    cin >> choice;
    return choice;
}

int studentMenu()
{
    int choice;
    cout << "Student Menu" << endl;
    cout << "1.Display Student Information" << endl;
    cout << "2.Display Class Information" << endl;
    cout << "3.Check Given Assignment" << endl;
    cout << "4.Exit" << endl;
    cin >> choice;
    return choice;
}

int teacherMenu()
{
    int choice;
    cout << "Teacher Menu" << endl;
    cout << "1.Display Teacher Information" << endl;
    cout << "2.Check My Classes" << endl;
    cout << "3.Add Assignments" << endl;
    cout << "4.Exit" << endl;
    cin >> choice;
    return choice;
}

int loginMenu()
{
    int choice;
    cout << "1. Login as Administrator" << endl;
    cout << "2. Login as Student" << endl;
    cout << "3. Login as Teacher" << endl;
    cout << "4. Quit" << endl;
    cin >> choice;
    return choice;
}

class Login
{
    static string username;
    static int password;

public:
    static void takeInput()
    {
        cout << "Enter Username: " << endl;
        cin >> username;
        cout << "Enter Password: " << endl;
        cin >> password;
    }
    static void reset()
    {
        username = "";
        password = 0;
    }
    bool static adminLogin(Admin a)
    {
        takeInput();
        if (username == a.getUsername() && password == a.getPassword())
        {
            reset();
            cout << "Logged In Successfully" << endl;
            return true;
        }
        reset();
        cout<<"Login Failed" << endl;
        CLEAR
        return false;
    }
    bool static studentLogin(Student *s, int num)
    {
        takeInput();
        for (int i = 0; i < num; i++)
        {
            if (s[i].getUsername() == username && s[i].getPassword() == password)
            {
                reset();
                studentindex = i;
                cout << "Logged In Successfully" << endl;
                return true;
            }
        }
        reset();
        cout << "Wrong Password or Username" << endl;
        return false;
    }
    bool static TeacherLogin(Teacher *t, int num)
    {
        takeInput();
        for (int i = 0; i < num; i++)
        {
            if (t[i].getUsername() == username && t[i].getPassword() == password)
            {
                reset();
                teacherindex = i;
                cout << "Logged In Successfully" << endl;
                
                return true;
            }
        }
        cout<<"Login Failed" << endl;
        system("pause");
        reset();
        return false;
    }
};
int Login::password = 0;
string Login::username = "";
int main()
{

    int loginChoice;
    int adminChoice = 7;
    int studentChoice;
    int teacherChoice;
    
    School school(0, 0, 0);
    do
    {
        system("cls");
        loginChoice = loginMenu();
        system("cls");

        if (loginChoice == 1)
        {
            if (Login::adminLogin(school.getAdmin()))
            
            {
                system("cls");
                do
                {
                    adminChoice = adminMenu();
                    switch (adminChoice)
                    {

                    case 1:

                        school.addTeacherToArray(school.getAdmin().addTeacher());
                        CLEAR
                        break;
                    case 2:
                        school.addStudentToArray(school.getAdmin().addStudent());
                        CLEAR
                        break;
                    case 3:
                        school.addClassToArray(school.getAdmin().addClass());
                        CLEAR
                        break;
                    case 4:
                        school.deleteTeacherFromArray(school.getAdmin().deleteTeacher(school.getTeacher(), school.getNumStudents()));
                        break;
                    CLEAR case 5:
                        school.deleteStudentFromArray(school.getAdmin().deleteStudent(school.getStudent(), school.getNumStudents()));
                        break;
                        CLEAR
                    case 6:
                        school.deleteClassFromArray(school.getAdmin().deleteClass(school.getClasses(), school.getNumClasses()));
                        CLEAR break;
                    case 7:
                        school.assignTeacher(school.getAdmin().assignTeacherToClass());
                        CLEAR
                        break;
                    case 8:
                        school.getAdmin().enrollStudentToClass(school.getStudent(), school.getClasses(), school.getNumStudents(), school.getNumClasses());
                        CLEAR
                        break;
                    case 9:
                        school.displayAllStudents();
                        CLEAR
                        break;
                    case 10:
                        school.displayAllClasses();
                        CLEAR
                        break;
                    case 11:
                        school.displayAllTeachers();
                        CLEAR
                        break;
                    case 12:
                    

                    default:
                        break;
                    }

                } while (adminChoice != 12);
            }
        }
        else if (loginChoice == 2)
        {
            string a;
            if (Login::studentLogin(school.getStudent(), school.getNumStudents()))
            {
                system("cls");
                do
                {
                    studentChoice = studentMenu();
                    CLEAR
                    switch (studentChoice)
                    {
                    case 1:
                        school.getStudent()[studentindex].displayStudent();
                        CLEAR
                        break;
                    case 2:
                           
                        school.getStudent()[studentindex].getEnrolledClass().displayClass();
                        CLEAR
                        break;
                    case 3:
                    
                    cout<<"Following is the assignment given to you: "<<endl;
                    school.getStudent()[studentindex].getEnrolledClass().getAssignment();
                    
                     

                    break;
                    default:
                    break;
                    }

                } while (studentChoice != 4);
            }
        }
        else if(loginChoice==3){
            if(Login::TeacherLogin(school.getTeacher() , school.getNumTeachers())){
                system("cls");
                do{
                    system("cls");
                    teacherChoice=teacherMenu();
                    switch(teacherChoice){
                        case 1:
                            school.getTeacher()[teacherindex].displayTeacher();
                            CLEAR
                            break;
                        case 2:
                            if(school.getTeacher()[teacherindex].getnumClasses()>0){
                                for(int i=0 ; i<school.getTeacher()[teacherindex].getnumClasses() ; i++){
                            school.getTeacher()[teacherindex].getClassRoster()[i].displayClass();}
                            }
                            else
                            cout<<"Teacher is not assigned to any class."<<endl;
                            CLEAR
                            break;
                         
                        case 3:
                        if(school.getTeacher()[teacherindex].getnumClasses()>0){
                            school.getTeacher()[teacherindex].AddAssignment();
                        }
                        else
                        cout<<"Teacher is not assigned to any class."<<endl;
                        CLEAR
                        break;
                      default:
                      break;
                    }
                 } while (teacherChoice!=4);
            }
        }

     } while (loginChoice != 4);
}