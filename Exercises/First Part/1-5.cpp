#include <iostream>
using namespace std;

int main() {
	int tempo1_hor, tempo1_min, tempo1_seg, tempo2_hor, tempo2_min, tempo2_seg;
	int soma_dia = 0;
	int soma_hor = 0;
	int soma_min = 0;
	int soma_seg = 0;

	cout << "tempo 1 (horas minutos segundos) ? ";
	cin >> tempo1_hor >> tempo1_min >> tempo1_seg;
	cout << "tempo 2 (horas minutos segundos) ? ";
	cin >> tempo2_hor >> tempo2_min >> tempo2_seg;

	soma_hor = tempo1_hor + tempo2_hor;
	soma_min = tempo1_min + tempo2_min;
	soma_seg = tempo1_seg + tempo2_seg;

	while (soma_seg >= 60) {
		soma_min++;
		soma_seg -= 60;
	}

	while (soma_min >= 60) {
		soma_hor++;
		soma_min -= 60;
	}

	while (soma_hor >= 24) {
		soma_dia++;
		soma_hor -= 24;
	}

	cout << "soma dos tempos: " << soma_dia << " dia, " << soma_hor << " horas, " << soma_min << " minutos e " << soma_seg << " segundos";

	return 0;
}