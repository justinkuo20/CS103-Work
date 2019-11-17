/********************************************************
 * CS 103 PA 1: Commas
 * Name:
 * USC email:
 * Comments (you want us to know):
 *
 * Description:
 *  Displays a 64-bit integer (long long) with
 *   commas for thousands, millions, billions, etc.
 *
 * ** ABSOLUTELY NO ARRAYS, NO `string`, NO `vector` **
 *  usage is allowed.
 *
 * Instead, you may only declare:
 *
 *    bool,
 *    int, or
 *    int64_t (long long)
 *
 *  The only library function allowed is pow(base, exp)
 *    defined in the <cmath> library.
 *
 *
 ********************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	long long n;
	cout << "Enter an integer:" << endl;

	/* Your code here */
	cin >> n;
	int numDigits = 0;
	long long temp = n;
	int firstCase;

	if (n == 0) {
		cout << n << endl;
	}

	if (n < 0) {
		cout << "-";
        n = abs(n);
	}
	while (temp != 0) {
		temp /= 10;
		numDigits++;
	}
	firstCase = numDigits % 3;
	if (firstCase == 0) {
		firstCase = 3;
	}
	//inserts commas based on position of digit
	for (int i = numDigits - 1; i >= 0; i--) {
		temp = n;       
		long long nextDigit = pow(10, i);
		temp /= nextDigit;
		temp = temp % 10;
		if (firstCase > 0) {
			cout << temp;
			firstCase--;
		} else {
			cout << ",";
			cout << temp;
			firstCase = 2;
		}
	}
	/* End of your code */
	return 0;

}
