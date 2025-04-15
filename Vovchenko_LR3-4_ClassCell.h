#ifndef _CELL_H
#define _CELL_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const double pi = 3.14;

class Cell
{
    string type =""; // тип клетки
    vector<string> org {""}; // список органелл
    vector<double> sizee; // размер клетки по 3-м измерениям

    public:
        Cell(); // конструктор по умолчанию
        Cell (const string& type); // параметризованный конструктор

        // параметризованный конструктор с заданным массивом списка органелл
        Cell(const string& type, vector<string>& org, vector<double>& sizee); 
        Cell(const Cell& ob); // конструктор копирования
        // присваивание
        Cell& operator = (const Cell& other);
        ~Cell() // деструктор
        { }

        //set
        void setType(string t){ type = t; };
        void setOrg(const vector<string>& org)
        {
            this->org = org;
        }
        void setSize(vector<double> size)
        {
            this->sizee = sizee;
        }

        //get
        string getType() const { return type; };
        const vector<string> getOrg() const { return org;}
        const vector<double> getSize() const { return sizee;}

        // void input();

        // void show() const;

        // вычисление объема клетки
        double Volume() const;

        // перегрузка
        double operator+(const Cell& other) const;
        Cell& operator++(); // префиксный инкремент
        Cell operator++(int); // постфиксный инкремент

        friend ostream& operator<<(ostream& mystream, const Cell &obj);
        friend istream& operator>>(istream& mystream, Cell &obj);

};

bool CellInput (string input)
{
    if (input.empty()) 
    {
        return false;
    }
    try
    {
        int number = stoi(input);
        if (number < 0)
        {
            return false;
        }
    }
    catch (...)
    {
        return false;
    }
    return true;
}

function<void()> Enter_Number(int& varLink, string label)
{
    return [&varLink, label]()
    {
        string get_input;
        cout << label << "= ";
        getline(cin, get_input);
        while (!CellInput(get_input))
        {
            cout << label << "= ";
            getline(cin, get_input);
        }
        varLink = stoi(get_input);
    };
}

function<void()> Enter_NumberD(double& varLink, string label)
{
    return [&varLink, label]()
    {
        string get_input;
        cout << label << "= ";
        getline(cin, get_input);
        while (!CellInput(get_input))
        {
            cout << label << "= ";
            getline(cin, get_input);
        }
        varLink = stod(get_input);
    };
}

function<void()> Enter_String(string& varLink, string label)
{
    return [&varLink, label]()
    {
        cout << label << " = ";
        getline(cin, varLink);
    }; 
}
#endif