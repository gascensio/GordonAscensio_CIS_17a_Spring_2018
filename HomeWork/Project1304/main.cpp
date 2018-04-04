/*
 *  Created on: April 1, 2018
 *      Author: Gordon Ascensio
 *       Class: CIS 17A
 *   Professor: Mark Lehr
 *        Days: MW Time: 12:45p - 2:30
 * 	   Purpose: Demonstrates PersonalInfo Class.
 */

#include <iostream>
#include "PersonalInfo.h"

using namespace std;

int main(void)
{
    PersonalInfo Person[3] = {{ "Gordon Ascensio", "3626 Lillian St. Riverside CA, 92504", 51,"(951)555-1212"},
								{"Patrick McGaugh", "1030 Prince Albert Rd. Riverside CA, 92504",60,"951 345 4567"},
								{"John Doe", "4567 Baltran Rd. Riverside CA, 92508",21,"(951)555-6789"}
    };
    for(int i = 0; i < 3; i++){
	Person[i].prnt_all_info();
	cout << endl;
    }

}
