/* 
 * File:   main.cpp
 * Author: YOUR NAME HERE
 * Created on DATE AND TIME HERE
 * Purpose:  Searching for multiple occurrence of patterns
 * Note:  cout proceeds to null terminator, cin reads to end of line
 *        for character arrays
 * 
 */

//System Libraries Here
#include <iostream>//cin,cout,getline()
#include <cstring> //strlen()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//PI, e, Gravity, or conversions

//Function Prototypes Begins Here
//srch1 utility function Input->start position, Output->position found or not
//srch1 is a simple linear search function, repeat in srchAll till all found
//srch1 Input->sentence, pattern, start position Output-> position found
//Remember arrays start at index/position 0
//srchAll Input->sentence, pattern Output->position array
int  srch1(const char [],const char [],int);//Search for 1 occurrence
void srchAll(const char [],const char [],int []);//Search for all occurrences
void print(const char []);//Print the character arrays
void print(const int []); //Print the array of indexes where the pattern found

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int LINE=81;               //Size of sentence or pattern to find
    char sntnce[LINE],pattern[LINE]; //80 + null terminator
    int match[LINE];                 //Index array where pattern was found
    
    //Input a sentence and a pattern to match
    cout<<"Match a pattern in a sentence."<<endl;
    cout<<"Input a sentence"<<endl;
    cin.getline(sntnce,LINE);
    cout<<"Input a pattern."<<endl;
    cin.getline(pattern,LINE);
    
    //Search for the pattern
    //Input the sentence and pattern, Output the matching positions
    //Remember, indexing starts at 0 for arrays.
    srchAll(sntnce,pattern,match);
    
    //Display the inputs and the Outputs
    cout<<endl<<"The sentence and the pattern"<<endl;
    print(sntnce);
    print(pattern);
    cout<<"The positions where the pattern matched"<<endl;
    print(match);
    
    //Exit
    return 0;
}
/**************************************************************
 * The srch1() function finds the first occurrence after i
 * of a match for the pattern;
 */
int srch1(const char sntnce[],const char pattern[],int i)
{
	unsigned int index = 0;
	unsigned int patternSize = strlen(pattern);
	int count = 0, offset = 0;

	if(sntnce[i] == '\0')
		return -1;
	while((unsigned)count < patternSize){
		if(patternSize > strlen(&sntnce[i+offset]))
			return -1;
		while(sntnce[i+offset] != pattern[0] && sntnce[i+offset] != '\0')
			offset++;
		for(index = 0, count = 0;index < patternSize;index++)
			if (sntnce[i+offset+index] == pattern[index])
				count++;
		if((unsigned int)count == patternSize){
			return i + offset;
		}
		offset = offset + count;
	}
return -1;
}
/**************************************************************
 *
 */
void srchAll(const char sntnce[],const char pattern[],int match[])
{
	int i = 0;
	int a = 0;
	unsigned int patternSize = strlen(pattern);

	match[i] =  srch1(sntnce,pattern, 0);
	while(match[i] > -1){
		i++;
		match[i] = srch1(sntnce,pattern, match[i - 1]  + (int)patternSize );
	}

}
/**************************************************************
 *
 */
void print(const char array[])
{
	cout << array << endl;
}
/**************************************************************
 *
 */
void print(const int array[])
{
	int index = 0;
    
    if(array[0] == -1)
        cout << "None";
	while(array[index] > -1){
		cout << array[index] << endl;
		index++;
	}
    
}

