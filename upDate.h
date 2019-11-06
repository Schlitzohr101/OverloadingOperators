#ifndef UPDATE_H
#define UPDATE_H
#include <string>
class upDate {
    private:
        int * ptr;
        static int count;

    protected:
        int getDaysInMonth(int);

    public:
        upDate();
        upDate(int,int,int);
        upDate(const upDate &);
        ~upDate();
        std::string display();
        void setDate(int,int,int);
        int getDay();
        int getMonth();
        int getYear();
        int julian();
        void increaseDate(int);
        void decreaseDate(int);
        static int GetDateCount();
        std::string getMonthName();
        void operator =(const upDate &);
        void operator +=(int);
        upDate operator++(int); //post fix
        upDate operator++();  //pre fix
        upDate friend operator+(upDate&,int);
        upDate friend operator+(int,upDate&);
        void operator -=(int);
        upDate friend operator-(upDate&, int);
        upDate friend operator-(int, upDate&);
        upDate operator-(upDate);
        upDate operator--(int);
        upDate operator--();
        bool operator==(upDate);
        bool operator<(upDate);
        bool operator>(upDate);
        friend std::ostream & operator<<(std::ostream &os,upDate);
};
#endif