#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2) {
        cout << "Provide your name on the command line" << endl;
        return 1;
    }
    //prints out name from command line
    cout << "Hello World!" << endl;
    cout << "Welcome to CS103, " << argv[1] << endl;
    return 0;
};
