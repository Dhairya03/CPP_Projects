#include<iostream>

struct Date{
    int day;
    int month;
    int year;
    void printDate(){
    std::cout<<day<<"/"<<month<<"/"<<year<<std::endl;
}
};

// void printDate(Date &date){
//     std::cout<<date.day<<"/"<<date.month<<"/"<<date.year<<std::endl;
// }

int main(){
    Date date{};
    date.printDate();
    std::cout<<&date<<std::endl;
    std::cout<<&(date.day)<<std::endl;
    std::cout<<&(date.month)<<std::endl;
    std::cout<<&(date.year)<<std::endl;
    return 0;

}
