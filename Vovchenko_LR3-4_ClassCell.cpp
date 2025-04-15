#include <cmath>
#include <iomanip>
#include <map>
#include <sstream>
#include <fstream>
#include <numeric>
#include <functional>
#include <random>
#include <ctime>


#include "Vovchenko_LR3-4_Methods.h"
// по умолчанию
Cell::Cell():type{"unknown"}, org{"qq ww tt"}
{  
    srand(static_cast<unsigned int>(std::time(0)));

    for (int i = 0; i < 3; ++i) 
    {
        double random_value = static_cast<double>(rand()%2500 + 1)/100;
        sizee.push_back(random_value);
    }
}

Cell::Cell(const string& type): Cell()
{
    this->type = type;
}

// параметризованный
Cell::Cell(const string& type, vector<string>& org,  vector<double>& sizee): Cell(type)
{
    // this->type = type;
    this->org = org;    
    this->sizee = sizee;
}

// копирование
Cell::Cell(const Cell& other): type(other.type), org(other.org), sizee(other.sizee) {}

// присваивание
Cell& Cell::operator = (const Cell& other) 
{
    if (this != &other) {
        type = other.type;
        org = other.org;
        sizee = other.sizee;
    }
    return *this;
}

// вычисление объема клетки
double Cell:: Volume() const
{
    return 4.0/3.0 * pi * sizee[0] * sizee[1] * sizee[2];
}

// сложение объемов клеток
double Cell::operator+(const Cell& other) const
{
    return  this->Volume() + other.Volume();
}

// префиксный инкремент
Cell& Cell::operator++()
{
    for (auto &s : sizee)
    s += 0.5;
    return *this;
}

// постфиксный инкремент
Cell Cell::operator++(int)
{
    Cell c(*this);
    ++(*this);
    return c;
}

ostream& operator<<(ostream& os, const Cell &obj){
    os << "Type: " << obj.type << ", organells: ";
    for (auto & o : obj.org)
    {
        os << o << " ";
    }
    os << endl;
    cout << "size: ";
    for (const double& value : obj.sizee) 
    {
        cout << value << " ";
    }
    os << endl;
    return os;
}


istream& operator>>(istream& is, Cell& obj) 
{
        string str;
        Enter_String(str, "Enter type: ")();

        int num_org;
        Enter_Number(num_org, "Enter number of organells: ")();

        obj.org.resize(num_org);
        for (int i = 0; i < num_org; ++i) {
            Enter_String(str, "Enter organells: ")();
        }

        double d;
        obj.sizee.resize(3);
        for (int i = 0; i < 3; ++i) 
        {
            Enter_NumberD(d, "Enter size: ")();
        }

        return is;
};