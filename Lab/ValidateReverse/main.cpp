/*
 * File:   main.cpp
 * Author: Gordon Ascensio
 * Created on 3/8/2018
 * Purpose:  Input something, output it reversed with some modifications
 * Note:Range should be 5 digits, 321 = 00321 reverse = 12300 before subtraction
 *      12300 - 999 = 11301 after subtraction
 *      12300 = 00321 = 321 after reversal and no subtraction
 */

//System Libraries Here
#include <iostream>//cin,cout,endl
#include <cstring> //strlen()
#include <cctype>  //isdigit()

using namespace std;
//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, conversions, or the columns for 2-D arrays

//Function Prototypes Here
bool  inRange(const char [],unsigned short &);//Output true,unsigned or false
int tenpow( int ); // return 10 power int
bool  reverse(unsigned short,signed short &);//Output true,short or false
short subtrct(signed short,int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int SIZE=80;     //More than enough
    char  digits[SIZE];    //Character digits or not
    unsigned short unShort;//Unsigned short
    short snShort;         //Signed short

    //Input or initialize values Here
    cout<<"Reverse a number and subtract if possible."<<endl;
    cout<<"Input a number in the range of an unsigned short"<<endl;
    cin>>digits;

    //Test if it is in the Range of an unsigned short
    if(!inRange(digits,unShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }

    //Reverse and see if it falls in the range of an signed short
    if(!reverse(unShort,snShort)){
        cout<<"No Conversion Possible"<<endl;
        return 0;
    }

    //Now subtract if the result is not negative else don't subtract
    snShort=subtrct(snShort,999);

    //Output the result
    cout<<snShort<<endl;

    //Exit
    return 0;
}

bool  inRange(const char digits[],unsigned short &number)
{
    int length;
    int p, n;
    int count = 0;
    int num;

    length = strlen(digits);
    if(length > 5)
    	return false;
    for(p = 0; p < length; p++){
        if(isdigit(digits[p])){
            count++;
        }
    }
    if(count < length)
        return false;
    else if(count == length){
    	 p = 0;
    	 num = 0;
         for(; length > 0; length--){
               n = digits[p] - 48;
               num += n * tenpow(length - 1);
               p++;
               if (num > 65535 ){
            	   number = (unsigned short)num;
            	   return false;
               }
        }
        number = (unsigned short)num;
        return true;
    }
    return false;
}
int tenpow( int power)
{

	if(power == 0)
		return 1;
	else if(power == 1)
		return 10;
	else if(power > 1){
		int p = 10;
		for(int count = 2; count <= power ; count++){
			p *= 10;
			if(p > 2147483647)
				return 0;
		}
 		return p;
	}
	return power;
}
bool  reverse(unsigned short in ,signed short &out)
{
    unsigned short a = 0, digit, number = in;
    int p = 0;

    for(int count = 4;count >= 0; count--, p++){
    	digit = number / (unsigned short)tenpow(count);
    	number -= digit * (unsigned short)tenpow(count);
    	if( a + digit *tenpow(p) >= 65536)
    		return false;
    	a += digit  * (unsigned short)tenpow(p);
    }
    if(a <= 32768 && a >= 0){
    	out = a;
    	return true;
    } else {
    	out = (signed short)a;
    }
    return false;
}
short subtrct(signed short a,int b)
{
   short output;
    output = a - (short)b;
    return output;
}
