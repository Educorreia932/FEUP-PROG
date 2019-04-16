#include <iostream>
#include <string>

using namespace std;

class Student {
	public:
		Student();
		Student(const string& code, const string& name);
		void setGrades(double shortExam, double project, double exam);
		string getCode() const;
		string getName() const;
		int getFinalGrade() const;
		bool isApproved() const; // is the student approved or not ?
		static int weightShortExam, weightProject, weightExam; // weights in percentage (ex:20,30,50)
	private:
		string code; // student code
		string name; // student complete name
		double shortExam, project, exam; // grades obtained by the student in the different components
		int finalGrade;
};

Student::Student(const string& code, const string& name) {
	this->code = code;
	this->name = name;
}

Student readStudentData() {
	string code, name;
	double shortExam, project, exam;

	cout << "Student code? ";
	getline(cin, code);
	cout << endl << "Student name? ";
	getline(cin, name);
	cout << endl <<" Short exam grade? ";
	cin >> shortExam;
	cout << endl << "Project grade? ";
	cin >> project;
	cout << endl << "Exam grade? " << endl;
	cin >> exam;

	Student auxStudent = Student(code, name);

	auxStudent.setGrades(shortExam, project, exam);

	return auxStudent;
}

void Student::setGrades(double shortExam, double project, double exam) {
	this->shortExam = shortExam;
	this->project = project;
	this->exam = exam;

	weightShortExam = 20;
	weightProject = 30;
	weightExam = 50;

	double auxFinalGrade = shortExam * (weightShortExam / 100) + project * (weightProject / 100) + exam * (weightExam / 100);

	finalGrade = floor(auxFinalGrade + 0.5);
}

string Student::getCode() const {
	return code;
}

string Student::getName() const {
	return name;
}

int Student::getFinalGrade() const {
	return finalGrade;
}

bool Student::isApproved() const {
	if (finalGrade >= 10)
		return true;
	else
		return false;
}

int main() {
	return 0;
}