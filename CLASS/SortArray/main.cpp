/* 
 * File:   main.cpp
 * Author: YOUR NAME HERE
 * Created on DATE AND TIME HERE
 * Purpose:  Sorting a 2-D array of characters if row and columns match
 * Note:  This time you create the strcmp() function that takes into
 * account the new sort order.
 */

//System Libraries Here
#include <iostream>//cin,cout
#include <cstring> //strlen(),strcmp(),strcpy()
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Allowed like PI, e, Gravity, conversions, array dimensions necessary
const int COLMAX=80;//Only 20 required, and 1 for null terminator

//Function Prototypes Here
int  read(char [][COLMAX],int &);//Outputs row and columns detected from input
void sort(char [][COLMAX],int,int,const char[],const char[]);//Sort by row using strcmp();
void print(const char [][COLMAX],int,int);//Print the sorted 2-D array
//int strcmp(char a[],char b[],char replace[],char with[]){
//int strcmp(char [],char [],const char [],const char []);//Replace sort order

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Declare all Variables Here
    const int ROW=30;             //Only 20 required
    char array[ROW][COLMAX];      //Bigger than necessary 
    int colIn,colDet,rowIn,rowDet;//Row, Col input and detected
    char replace[COLMAX],with[COLMAX];//New sort order
    
    //Input the new sort order then sort
    cout<<"Modify the sort order by swapping these characters."<<endl;
    cin>>replace;
    cout<<"With the following characters"<<endl;
    cin>>with;
    cout<<"Read in a 2 dimensional array of characters and sort by Row"<<endl;
    cout<<"Input the number of rows <= 20"<<endl;
    cin>>rowIn;
    cout<<"Input the maximum number of columns <=20"<<endl;
    cin>>colIn;
    
    //Now read in the array of characters and determine it's size
    rowDet=rowIn;
    cout<<"Now input the array."<<endl;
    colDet=read(array,rowDet);
    
    //Compare the size input vs. size detected and sort if same
    //Else output different size
    if(rowDet==rowIn&&colDet==colIn){
        sort(array,rowIn,colIn,replace,with);
        cout<<"The Sorted Array"<<endl;
        print(array,rowIn,colIn);
    }else{
        if(rowDet!=rowIn)
        cout<<(rowDet<rowIn?"Row Input size less than specified.":
            "Row Input size greater than specified.")<<endl;
        if(colDet!=colIn)
        cout<<(colDet<colIn?"Column Input size less than specified.":
            "Column Input size greater than specified.")<<endl;
    }
    //Exit
    return 0;
}
/*
 *
 */
int read(char array[][COLMAX],int &rowSize)
{
	int c = 0, count, colSize = 0;
	char *line = new char[80];

	do{
		cin >> line;
        count = 0;
        while(line[count] != '\0'){
            count++;
        }
        if(colSize < count) 
            colSize = count;
            
		strcpy(&array[c][0],line);
	}while(c++ < rowSize - 1);
    delete line;
	return colSize;
}
/*
 *
 */
void sort(char array[][COLMAX],int rowIn,int colIn,const char replace[],const char with[])
{
	bool swap;
	char *temp = new char[80];
	char *a, *b;
	int c;

	do{
		swap = false;
		for(c = 0; c < (rowIn - 1); c++){
			a = &array[c][0];
			b = &array[c+1][0];
			if (strcmp(a,b) < 0){
				strcpy(temp,a);
				strcpy(a,b);
				strcpy(b,temp);
				swap = true;
			}
		}
	}while(swap);
	return;
}
/*
 *
 */
void print(const char array[][COLMAX],int rowIn,int colIn)
{
	int c;

	for(c = 0;c < rowIn;c++)
		cout << &array[c][0] << endl;
}