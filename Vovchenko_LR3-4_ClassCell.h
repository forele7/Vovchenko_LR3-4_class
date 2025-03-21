#ifndef _CELL_H
#define _CELL_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Cell
{
    string type =""; // тип клетки
    vector<string> org {""}; // список органелл

    vector<double> r {0.0}; // радиус клетки

    public:
        Cell(); // конструктор по умолчанию
        Cell (const string& type); // параметризованный конструктор
        // // параметризованный конструктор с заданным массивом списка органелл
        // Cell(unsigned o, vector<string> arr); 
        // Cell(const Cell &ob); // конструктор копирования

        // ~Cell() // деструктор
        // { }

        // void setCell(unsigned o, const vector<string>& arr)
        // {
        //     if (o <= arr.size())
        //     {
        //         type = o;
        //         org.resize(o);
        //         org.assign(arr.begin(), arr.begin() + k);
        //     }
        //     else
        //     {
        //         cerr << "Error!" << endl;
        //     }
        // }

        // void setType(unsigned o){ type = o; };

        // unsigned getType() const { return type; };

        // const vector<string> getOrg() const { return org;}

        // // вычисление объема клетки
        // void Volume(double x);

        // // перегрузка
        // Cell operator+(const Cell& other) const;

        // const Cell& operator = (const Cell& other)
        // {
        //     if (&other == this) return *this;
        //     type = other.type;
        //     org = other.org;
        //     return *this;
        // }

        // friend ostream& operator<<(ostream& mystream, const Cell &obj);
        // friend istream& operator>>(istream& mystream, Cell &obj);
};
#endif