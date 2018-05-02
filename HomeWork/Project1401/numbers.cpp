/*
 * numbers.cpp
 *
 *  Created on: May 1, 2018
 *      Author: Gordon
 */

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <iostream>
#include <string>
#include "numbers.h"
using namespace std;


string Numbers::lessThen20[20] = {"zero","one","two","three","four","five","six",
                            "seven","eight","nine","ten","eleven","twelve",
                            "thirteen","fourteen","fifteen","sixteen",
                            "seventeen","eighteen","nineteen"};
string Numbers::hundred = "hundred";
string Numbers::thousand = "thousand";
string Numbers::TentoNinety[10] = {"blank","teen", "twenty","thirty","forty",
                                "fifty","sixty","Seventy","eighty","ninety"};


Numbers::Numbers(int num)
{
    if(num > 9999 || num < 0){
        cout << "Invalid number";
        number = 0;
        return;
    }
    number = num;
}
void Numbers::print()const
{
    string str;
    string space = " ";
    int number = this->number;
    int thousands = number / 1000;
    number -= thousands * 1000;
    int hundreds = number /100;
    number -= hundreds * 100;
    int decades = number / 10;

    if(thousands > 0)
        cout << this->lessThen20[thousands] << " " << this->thousand << " ";
    if(hundreds > 0)
        cout << this->lessThen20[hundreds] << " " << this->hundred << " ";
    if(decades < 2)
        if(this->number > 99){
            if(number > 0)
                cout << this->lessThen20[number] << " ";
        }else
            cout << this->lessThen20[number] << " ";
    else if(decades > 1){
        number -= decades * 10;
        cout << this->TentoNinety[decades] << " ";
        if(number > 0)
        	cout << this->lessThen20[number];
    }
}
