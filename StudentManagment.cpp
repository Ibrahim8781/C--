

#include<iostream>

using namespace std;

class Student
{
private:
	int stdID;
	string Name;
	string* courseCodes;
	int numCourses;
	int* courseGrades;
	float gpa;


public:
	Student(int id, string name);

	// GETTERS	
	int getStdID();// - a getter for the student's ID
	string getName(); //- a getter for the student's first name
	int getNumCourses();// -a getter for the number of courses taken by the student
	string getCourseCode(int i); //- a getter for the course code of the course taken at index i of the courseCodes array
	int getCourseGrade(int i);//- a getter for the grade obtained by the student in the course taken at index i of the courseGrades array
	float getGPA(); //- a getter for the student's GPA

	// SETTERS
	void setStdID(int id); //- a setter for the student's ID
	void setName(string firstName); //- a setter for the student's first name
	void setCourseGrade(string courseCode, int grade); //- a function to set the grade obtained by the student in the course with the given course code
	void addCourse(string courseCode, int grade);//- a function to add a course with the given course code and grade to the student's record
	void calcGPA(); //- a function to calculate the student's GPA
};

Student::Student(int id, string name) {
	this->stdID = id;
	Name = name;
	courseCodes = nullptr;
	courseGrades = nullptr;
	numCourses = 0;
	gpa = 0.0;
}

string Student::getName()
{
	return this->Name;
}

int Student::getStdID()
{
	return this->stdID;
}

int Student::getNumCourses()
{
	return this->numCourses;
}

float Student::getGPA()
{
	return this->gpa;
}

void Student::setName(string firstname)
{
	this->Name = firstname;
}

void Student::setStdID(int id)
{
	this->stdID = id;
}

string Student::getCourseCode(int i) {
	if (i >= 0 && i < this->numCourses) {
		return courseCodes[i];
	}
	else {
		cout << "AT GIVEN INDEX NO COURSE FOUND " << endl;
		return "";
	}
}

int Student::getCourseGrade(int i) {
	if (i >= 0 && i < numCourses) {
		return courseGrades[i];
	}
	else {
		cout << "NO COURSE GRADE FOUND" << endl;
		return 0;
	}
}

void Student::setCourseGrade(string courseCode, int grade) {

	for (int i = 0; i < numCourses; i++) {
		if (courseCodes[i] == courseCode) {
			courseGrades[i] = grade;
			calcGPA();
			return;
		}
	}
	cout << "Error: Course not found." << endl;
}

void Student::addCourse(string courseCode, int grade) {

	string* newCourseCodes = new string[numCourses + 1];
	int* newCourseGrades = new int[numCourses + 1];

	for (int i = 0; i < numCourses; i++)
	{
		newCourseCodes[i] = courseCodes[i];
		newCourseGrades[i] = courseGrades[i];
	}

	newCourseCodes[numCourses] = courseCode;
	newCourseGrades[numCourses] = grade;

	delete[] courseCodes;
	delete[] courseGrades;

	courseCodes = newCourseCodes;
	courseGrades = newCourseGrades;
	numCourses++;

	calcGPA();
}

void Student::calcGPA() {
	float totalGradePoints = 0.0;
	for (int i = 0; i < numCourses; i++) {
		totalGradePoints += courseGrades[i];
	}
	this->gpa = totalGradePoints / numCourses;
}

Student getStudentAt(Student students[], int index)
{
	return students[index];
}

float calcClassGPA(Student students[], int numStudents)
{
	float sum = 0;
	for (int i = 0; i < numStudents; i++)
	{
		students[i].calcGPA();
		sum += students[i].getGPA();
	}
	return sum / numStudents;
}

float getMaxGPA(Student students[], int numStudents) {
	float maxGPA = 0;
	for (int i = 0; i < numStudents; i++) {
		students[i].calcGPA();
		if (students[i].getGPA() > maxGPA) {
			maxGPA = students[i].getGPA();
		}
	}
	return maxGPA;
}

float getMinGPA(Student students[], int numStudents) {
	float minGPA = 4.0;
	for (int i = 0; i < numStudents; i++) {
		if (students[i].getGPA() < minGPA) {
			minGPA = students[i].getGPA();
		}
	}
	return minGPA;
}

void printStudentRecord(Student student) {
	cout << "ID: " << student.getStdID() << endl;
	cout << "Name: " << student.getName() << endl;
	cout << "Courses taken: " << student.getNumCourses() << endl;
	cout << "Course codes and grades: " << endl;
	for (int i = 0; i < student.getNumCourses(); i++) {
		cout << "    " << student.getCourseCode(i) << ": " << student.getCourseGrade(i) << endl;
	}
	cout << "GPA: " << student.getGPA() << endl;
	cout << endl;
}

void printAllStudentRecords(Student students[], int numStudents) {
	for (int i = 0; i < numStudents; i++) {
		cout << "Record for student " << i + 1 << ":" << endl;
		printStudentRecord(students[i]);
	}
}

/*
int main() {
  Student student(12345, "Alice");

  student.addCourse("CS101", 85);
  student.addCourse("MATH201", 90);
  student.addCourse("PHYS101", 80);

	cout << "Student ID: " << student.getStdID() << endl;
	cout << "Student Name: " << student.getName() << endl;
	cout << "Number of Courses: " << student.getNumCourses() << endl;
	cout << "Course Grades: " << endl;


	for (int i = 0; i < student.getNumCourses(); i++)
	{
		cout << student.getCourseCode(i) << ": " << student.getCourseGrade(i) << endl;
	}

	cout << "GPA: " << student.getGPA() << endl;

	  student.setCourseGrade("CS101", 90);

	cout << "Updated Course Grades: " << endl;
	  for (int i = 0; i < student.getNumCourses(); i++) {
		cout << student.getCourseCode(i) << ": " << student.getCourseGrade(i) << endl;
	  }
	cout << "Updated GPA: " << student.getGPA() << endl;
	// gpa calculated as the sum of all course grades divided by the number of courses taken

  return 0;
}
*/