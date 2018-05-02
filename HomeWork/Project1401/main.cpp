/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Gordon
 *
 * Created on May 1, 2018, 2:13 PM
 */

#include <string>
#include <cstdlib>
#include <iostream>
#include "numbers.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Numbers N(789);
    int n;
    
    
    cout << "Enter a number form 0 to 9999?";
    cin >> n;
    while(n < 0 || n > 9999)
        cin >> n;
    N = n;
    N.print();
    return 0;
}

