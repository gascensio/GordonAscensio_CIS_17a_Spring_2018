/*
 * Date.h
 *
 *  Created on: Mar 30, 2018
 *      Author: Gordon
 */

/*
 * File:   Date.h
 * Author: Gordon
 *
 * Created on March 30, 2018, 8:47 AM
 */

#ifndef DATE_H_
#define DATE_H_
enum {January = 1, February, March, April, May, June, July, August, September, October, November, December};
class Date {
public:
    void set_date();
    void print_date_std() const;
    void print_date_long() const;
    void print_date_euro() const;
    void print_month() const;
private:
    short month;
    short day;
    short year;
};

#endif /* DATE_H_ */
