#include "Date.h"
#include <iostream>

Date defaultDate(1,1,1);

Date::Date(int day, int month, int year) {
  arr[1] = 31;
  arr[2] = 28;
  arr[3] = 31;
  arr[4] = 30;
  arr[5] = 31;
  arr[6] = 30;
  arr[7] = 31;
  arr[8] = 31;
  arr[9] = 30;
  arr[10] = 31;
  arr[11] = 30;
  arr[12] = 31;
  setMonth(month);
  setYear(year);
  setDay(day);
}

//Date::Date(){
//  *this = defaultDate;
//}

namespace {

bool leap(int year) {
  if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
    return true;
  }
  return false;
}
} // namespace

void Date::setYear(int aYear) {
  if (aYear > 0) {
    if (leap(aYear)) {
      arr[2] = 29;
    }
    year = aYear;
  } else {
    std::cerr << "It isn't allowed" << std::endl;
  }
}
void Date::setMonth(int aMonth) {
  if (aMonth >= 1 && aMonth <= 12) {
    month = aMonth;
  } else {
    std::cerr << "It isn't allowed" << std::endl;
  }
}

void Date::setDay(int aDay) {
  if (0 < aDay && aDay < arr[month]) {
    day = aDay;
  } else {
    std::cerr << "The day is out of range" << std::endl;
  }
}

void Date::addDay(int aDay) {
  int dum = this->day + aDay;
  for (;dum > arr[month];) {
    if (month == 12) {
      year++;
      // leap year check
      if (leap(year))
        arr[2] = 29;
      else
        arr[2] = 28;
      dum -= arr[month];
      month = 1;
    } else {
      dum -= arr[month];
      month++;
    }
  }
  day = dum;
}

void Date::addMonth(int aMonth) {
  if (aMonth < 0) {
    std::cerr << "Months can't be neg" << std::endl;
  }
  // Egde case before month adding

  bool beforeFeb = false;
  if (month == 2 && (day == 29 || day == 28)) {
    beforeFeb = true;
  }
  bool endMonth = false;
  if (day == arr[month]) {
    endMonth = true;
  }

  // Month adding
  if (aMonth >= 12) {
    year += aMonth / 12;
    if (aMonth != 12)
      month = aMonth % 12;
    // leap year check
    if (leap(year)) {
      arr[2] = 29;
    } else {
      arr[2] = 28;
    }
  } else {
    if (month + aMonth > 12) {
      year++;
      month = aMonth % 12;
    }
    //month = month + aMonth;
    // leap year check
    if (leap(year)) {
      arr[2] = 29;
    } else {
      arr[2] = 28;
    }
  }

  // Edge Cases
  if (beforeFeb && month == 2) {
    if (leap(year)) {
      day = 29;
    }
    day = 28;
  } else if (endMonth) {
    day = arr[month];
  }
}

void Date::addYear(int aYear) {
  if (aYear > 0) {
    if (leap(year + aYear)) {
      arr[2] = 29;
    }
    this->year += aYear;
  }
}

void Date::show(){
  std::cout << "The date is: " << day << "-" << month << "-" << year;
}
//static void setDefault(int day, int month, int year);

