/*
 /*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   numbers.h
 * Author: Gordon
 *
 * Created on May 1, 2018, 2:16 PM
 */

#ifndef NUMBERS_H
#define NUMBERS_H

#include <string>
using namespace std;

class Numbers
{
private:
    int number;
    static string lessThen20[20];
    static string hundred;
    static string thousand;
    static string TentoNinety[10];
public:
    Numbers(int num);
    void print()const;
    void operator=(const int number){
        if(number < 0 || number > 9999)
            this->number = 0;
        else
            this->number = number;
    }
};

#endif /* NUMBERS_H */

