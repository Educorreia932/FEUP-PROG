#include <iostream>
#include <set> 

using namespace std;

float average(const int grades[], int numStudents) { //Exercise 3.a1)
	float sum = 0;

	for (int i = 0; i < sizeof(grades) / sizeof(const int); i++)
		sum += grades[i];

	return sum / numStudents;
}

void readGrades(int grades[], int numStudents);

void showAverage() { //Exercise 3.a2)
	int grades[50];
	int numStudents;

	//readGrades(grades, numStudents);

	cout << average(grades, numStudents);

	//Não percebi como é para fazer este https://i.kym-cdn.com/photos/images/original/001/387/435/7b3.jpg
}

struct Position {
	int lin, col;
};

int main() {
	set<Position> edubbuska;
	return 0;
}