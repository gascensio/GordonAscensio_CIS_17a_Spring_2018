/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   dealer.h
 * Author: Gordon
 *
 * Created on May 30, 2018, 9:14 AM
 */

#ifndef DEALER_H
#define DEALER_H
#include <iostream>
#include "hand.h"
using namespace std;

class dealer : public Hand
{
    public:
        print_one_card(){cout << this->cards[0].rank()
                << this->cards[0].suit();}
};


#endif /* DEALER_H */

