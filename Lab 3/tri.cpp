#include <iostream>
#include <cmath>
using namespace std;

char star = 42;

int main() {

	int theta;

	cout << "Enter the angle theta in degrees: " << flush;
	cin >> theta;

	double radian = (M_PI / 180) * theta;
	cout << radian << endl;

	for (int y = 0; y <= 30; y++) {
		double xAxis = floor(tan(radian) * y);

		if (xAxis < 20 || xAxis > 30) {
			for (int x = 0; x < xAxis; x++) {
				cout << star;
			}
		}
		if (xAxis >= 20 && xAxis <= 30) {
			for (int x = 0; x < 20; x++) {
				cout << star;
			}
		}

		cout << endl;
	}

	return 0;
}
