#include <iostream>
#include "bigint.h"

using namespace std;

int main()
{
	BigInt first("123");
	BigInt second("456");
	first.add(second);
	cout << first.num[1] << endl;
	return 0;
}