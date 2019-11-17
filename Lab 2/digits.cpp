#include <iostream>
using namespace std;

int main() {
    
  int value;
  cout << "Choose a number between 0 and 999: " << flush;
  cin >> value;
  cout << "Value chosen: " << value << endl;
    
  double onesDigit = value % 10;
  cout << "1's digit is: " << onesDigit << endl;
  
  double tensDigit = (value % 100) / 10;
  cout << "10's digit is: " << tensDigit << endl;
    
  double hundredsDigit = (value / 100);
  cout << "100's digit is: " << hundredsDigit << endl;
    
  
    
    
    
    
    
    
    
return 0;
}