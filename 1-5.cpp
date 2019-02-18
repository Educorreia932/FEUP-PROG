#include <iostream>
using namespace std;

int main() {
	int tempo1_hor;
	int tempo1_min;
	int tempo1_seg;
	int tempo2_hor;
	int tempo2_min;
	int tempo2_seg;
	int soma_dia = 0;
	int soma_hor;
	int soma_min;
	int soma_seg;

	cout << "Tempo 1 (horas minutos segundos) ? ";
	cin >> tempo1_hor >> tempo1_min >> tempo1_seg;
	cout << "Tempo 2 (horas minutos segundos) ? ";
	cin >> tempo2_hor >> tempo2_min >> tempo2_seg;

	soma_hor = tempo1_hor + tempo2_hor;

	if (soma_hor > 60) {
		soma_dia ++ 
		soma_hor -= 60;
	}

	cout << "Soma dos tempos:";

	return 0;
}