#include <iostream>
#include "bigint.h"

using namespace std;

//reads string backwards and converts to digits, then puts digits into vector
BigInt::BigInt(string s){
    for(int i=((int)s.length() -1);i>=0;i--){
        digits = (int)s[i] - '0';
        num.push_back(digits);
    }
}
//converst digit to string 
string BigInt::to_string(){
    stringNum = "";
    for(int i=((int)num.size()-1);i>=0;i--){
        stringNum += (char)(num[i] + 48);
    }
    return stringNum;
}

//implementation of add function
void BigInt::add(BigInt b){
    sum = 0;
    carriedNum= 0;
    
   //checks if digits need to be aligned 
   if(num.size() != b.num.size()){
       if(num.size() > b.num.size()){
           while(num.size() > b.num.size()){
               b.num.push_back(0);
           }
       } else {
           while(b.num.size() > num.size()){
               num.push_back(0);
           }
       }
       
   }		
    for(int i=0;i<num.size();i++){      
        sum = num[i] + b.num[i] + carriedNum;
        carriedNum = sum / 10;  
        num[i] = sum % 10;        
    }
    
    if(carriedNum > 0){
        num.push_back(carriedNum);      
    }  
}
