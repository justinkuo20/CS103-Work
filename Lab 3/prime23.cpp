#include <iostream>
using namespace std;

int num;
int twoFactors = 0;
int threeFactors = 0;


int main() {
    cout << "Enter a positive integer: " << flush;
	cin >> num;

	if(num % 2 == 0) {
		while(num % 2 == 0){
		twoFactors++;
		num /= 2;
        }
	}

	if(num % 3 == 0) {
		while(num % 3 == 0) {
		threeFactors++;
		num /= 3;
		}
	}

	if(num != 1) {
		cout << "No" << endl;
		return 0;


	}

	if(twoFactors == 0 && threeFactors == 0) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
		cout << "Twos: " << twoFactors << " Threes: " << threeFactors << endl;
	}



	return 0;
}
