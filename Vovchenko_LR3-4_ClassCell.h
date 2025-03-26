#ifndef _CELL_H
#define _CELL_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

const double pi = 3.14;

class Cell
{
    string type =""; // тип клетки
    vector<string> org {""}; // список органелл
    vector<double> size {0.0}; // размер клетки по 3-м измерениям

    //vector<double> r {0.0}; // радиус клетки

    public:
        Cell(); // конструктор по умолчанию
        Cell (const string& type); // параметризованный конструктор
        // параметризованный конструктор с заданным массивом списка органелл
        Cell(const string& type, vector<string>& org, vector<double>& size); 
        Cell(const Cell& ob); // конструктор копирования

        ~Cell() // деструктор
        { }

        //set
        void setType(string t){ type = t; };
        void setOrg(const vector<string>& org)
        {
            this->org = org;
        }
        void setSize(string s, vector<double> size)
        {
            this->size = size;
        }
        // void setR(string t, vector<double> r)
        // {
        //     this->r = r;
        // }

        //get
        string getType() const { return type; };
        const vector<string> getOrg() const { return org;}
        const vector<double> getSize() const { return size;}
        //const vector<double> getR() const { return r;}

        // вычисление объема клетки
        void Volume(double v);

        // перегрузка
        Cell operator+(const Cell& other) const;

        const Cell& operator = (const Cell& other)
        {
            if (&other == this) return *this;
            type = other.type;
            org = other.org;
            size = other.size;
            //r = other.r;
            return *this;
        }

        friend ostream& operator<<(ostream& mystream, const Cell &obj);
        friend istream& operator>>(istream& mystream, Cell &obj);
};
#endif