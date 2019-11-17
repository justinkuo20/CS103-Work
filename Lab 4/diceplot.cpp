#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int roll() {
    int diceRoll;
    diceRoll = rand() % 6 + 1;
    return diceRoll;
 }

void printHistogram(int counts [21]) {
    for(int i=0;i<21;i++){
        cout << i + 4 << ":";
        for(int j=0;j<counts[i];j++){
           cout << "X";
        }
         cout << endl;
    }
}

/*
int main () {
    srand(time(NULL));
    cout << roll() << endl;
    return 0;
}
*/

/*
int main() {
    
    //cout << roll() << endl;
    int testCounts[21];
    for(int i=0;i<21; i++) {
        testCounts[i] = i/2;
    }
    printHistogram(testCounts);
    
    
    
    
    return 0;
}
*/

int main() {
    srand(time(NULL));
    
    cout << "Enter a number: ";
    int n;
    cin >> n;
    int testCounts[21] = {0};
    int sum;
    int r1, r2, r3, r4;
    for(int i=0;i<n;i++) {

    r1 = roll();
    r2 = roll();
    r3 = roll();
    r4 = roll();
    
    sum = r1 + r2 + r3 + r4;
    
    
    testCounts[sum-4]++;
    
        
    }
    
    printHistogram(testCounts);
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
    
}

