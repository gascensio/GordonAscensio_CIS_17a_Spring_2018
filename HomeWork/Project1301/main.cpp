/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: Gordon
 *
 * Created on March 30, 2018, 8:43 AM
 */
#include <iostream>
#include <cstdlib>

using namespace std;

#include "Date.h"

/*
 *
 */
int main(int argc, char** argv)
{
	Date d;
	d.set_date();
    cout << endl;
    d.print_date_std();
    cout << endl;
    d.print_date_long();
    cout << endl;
    d.print_date_euro();
    return 0;
}

