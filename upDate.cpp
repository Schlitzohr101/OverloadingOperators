#include"upDate.h"
#include<map>

using namespace std;

void upDate::increaseDate(int N) {
    ptr[0] += N;
    while (ptr[0] > getDaysInMonth(ptr[1])) {
        ptr[0] -= getDaysInMonth(ptr[1]);
        ptr[1]++;
        if (ptr[1] > 12) {
            ptr[2]++;
            ptr[1] = 1;
        }
    }
}

void upDate::decreaseDate(int N) {
    if ((ptr[0] - N) < 1) {
        N -= ptr[0];
        ptr[0] = 0;
        ptr[1]--;
        if (ptr[1] < 1) {
            ptr[1] = 12;
            ptr[2]--;
        }
        while (N > getDaysInMonth(ptr[1]))
        {
            N -= getDaysInMonth(ptr[1]);
            ptr[1]--;
            if (ptr[1] < 1) {
                ptr[1] = 12;
                ptr[2]--;
            }
        }
        ptr[0] = getDaysInMonth(ptr[1]) - N;
    } else {
        ptr[0] -= N;
    }
    // if (day == 0) {
    //     day = 1;
    // }
}



int upDate::getDaysInMonth(int month) {
    map<int,int> daysMonth;
    for (int i = 1; i < 13; i++)
    {
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i== 10 || i==12) {
            daysMonth[i] = 31;
        } else if ( i == 2 ) {
            if ((ptr[2]%4 == 0 && ptr[2]%100 != 0) || (ptr[2]%400 == 0 && ptr[2]%4 == 0))    {
                daysMonth[i] = 29;
            } else {
                daysMonth[i] = 28;
            }
        } else {
            daysMonth[i] = 30;
        }
    }
    return daysMonth[month];
}

upDate::upDate() {
    ptr = new int[3];
    ptr[0] = 11;  //day
    ptr[1] = 5;   //month
    ptr[2] = 1959;//year
    count=1;
}

upDate::upDate(int day, int month, int year) {
    ptr = new int[3];
    ptr[0] = day;
    ptr[1] = month;
    ptr[2] = year;
    count++;
}

upDate::upDate(const upDate &temp) {
    ptr = new int[3];
    ptr[0] = temp.ptr[0];
    ptr[1] = temp.ptr[1];
    ptr[2] = temp.ptr[2];
    count++;
}

upDate::~upDate() {
    delete ptr;
    count--;
}

string upDate::display() {
    return to_string(ptr[1])+"/" + to_string(ptr[0]) + "/" + to_string(ptr[2]);
}

void upDate::setDate(int day,int month, int year) {
    ptr[0] = day;
    ptr[1] = month;
    ptr[2] = year;
}

int upDate::getDay() {
    return ptr[0];
}

int upDate::getMonth() {
    return ptr[1];
}

int upDate::getYear() {
    return ptr[2];
}

int upDate::julian() {
    int J = ptr[0] - 32075+1461 * (ptr[2] + 4800 + (ptr[1]-14)/12)/4+367*(ptr[1]-2-(ptr[1]-14)/12*12)/12-3*((ptr[2] + 4900+(ptr[1]-14)/12)/100)/4;
    return J;
}

int upDate::GetDateCount() {
    return count;
}

string upDate::getMonthName() {
    string myMonth;
    switch (ptr[2])
    {
    case 1: myMonth = "January";
        break;
    case 2: myMonth = "February";
        break;
    case 3: myMonth = "March";
        break;
    case 4: myMonth ="April";
        break;
    case 5: myMonth ="May";
        break;
    case 6: myMonth ="June";
        break;
    case 7: myMonth ="July";
        break;
    case 8: myMonth ="August";
        break;
    case 9: myMonth ="September";
        break;
    case 10: myMonth ="October";
        break;
    case 11: myMonth ="November";
        break;
    case 12: myMonth ="December";
        break;
    default: myMonth ="May";
        break;
    }
    return myMonth;
}

void upDate::operator=(const upDate &temp) {
    ptr[0] = temp.ptr[0];    
    ptr[1] = temp.ptr[1];
    ptr[2] = temp.ptr[2];
    count++;
}

void upDate::operator+=(int num) {
    increaseDate(num);
}

upDate upDate::operator++() {
    increaseDate(1);
    return upDate(ptr[0],ptr[1],ptr[2]);
}

upDate upDate::operator++(int) {
    upDate temp(ptr[0],ptr[1],ptr[2]);
    increaseDate(1);
    return temp;
}

upDate operator+(upDate& x, int num) {
    x.increaseDate(num);
    return upDate(x);
}

upDate operator+(int num, upDate &user) {
    user.increaseDate(num);
    return upDate(user);
}

void upDate::operator-=(int num) {
    decreaseDate(num);
}

upDate operator-(upDate& x, int num) {
    upDate temp = upDate(x);
    temp.decreaseDate(num);
    return temp;
}

upDate operator-(int num, upDate& x) {
    upDate temp = upDate(x);
    temp.decreaseDate(num);
    return temp;
}

upDate upDate::operator-(upDate temp) {
    upDate toReturn = upDate(ptr[0],ptr[1],ptr[2]);
    int daysBetween = julian() - temp.julian();
    if (daysBetween > 0) {
        
    }
}