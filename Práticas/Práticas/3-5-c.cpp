using namespace std;

int gcd(int a, int b) {
	int q = 0, r = 0;

	do {
		q = b / a;
		r = b % a;

		b = a;
	} while (r);

	return a;
}

void reduceFracc(int &numerator, int &denominator) {
	numerator = numerator / gcd(numerator, denominator);
	denominator = denominator / gcd(numerator, denominator);
}