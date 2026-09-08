#ifndef DATE_H
#define DATE_H

class Date {
private:
    int day;
    int month;
    int year;
    static Date defaultDate;
    int arr[13];
    
public:
    Date(int day, int month, int year);
    Date();
    void setDay(int aDay);
    void setMonth(int aMonth);
    void setYear(int aYear);
    void addDay(int aDay);
    void addMonth(int aMonth);
    void addYear(int aYear);
    static void setDefault(int day, int month, int year);
    void show();
};


#endif // DATE_H
