/* Author: YOUR NAME HERE
 * Program: color_conv
 * Description: Converts RGB -> CMYK color representation
 */
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
   // Enter your code here
    cout << "Values(Red Green Blue): ";
	int red;
    int green;
    int blue;
	if( !(cin >> red )){
           cout << "error" << endl;
           return -1;
    }
    if(!(cin >> green)) {
        cout << "error" << endl;
        return -1;
    }
    if(!(cin >> blue)){
        cout << "error" << endl;  
        return -1;
    }
	cout << "Values: " << red << " " << green << " " << blue << endl;
    
    double white1 = max((double)red/255, (double)green/255);
    double white2 = max((double)white1, (double)blue/255);
                        
    double cyan = (white2 - (double)red/255)/white2;
    double magenta = (white2 - (double)green/255)/white2;
    double yellow = (white2 - (double)blue/255)/white2;
    double black = 1 - white2;
    
    cout << "cyan: " << cyan << endl;
    cout << "magenta: " << magenta << endl;
    cout << "yellow: " << yellow << endl;
    cout << "black: " << black << endl;
    
    
   
   
   
   
   return 0;
}
