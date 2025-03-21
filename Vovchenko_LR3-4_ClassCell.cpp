#include <cmath>
#include <iomanip>
#include <M:\\Program\\Vovchenko_LR3-4_class\\Vovchenko_LR3-4_ClassCell.h>

Cell::Cell():type{""}, org{""}, r{0.0}
{   
}

Cell::Cell(const string& type): Cell()
{
    this->type = type;
}

Cell::Cell(const string& type, vector<string> org,  vector<double> r): Cell(type)
{
    this->org = org;    
    this->r = r;
}

// копирование
Cell::Cell(const Cell& other): type(other.type), org(other.org) {}

void Volume(double v = 1.0)
{
    double s;
    int i;
    for (s = r[0], i <= 10; i++)
    {
        v = (4*pi*s*s*s)/3;
    }
    cout << "Объем клетки = " << v << endl;
}

// Cell Cell::operator+(const Cell &other) const
// {
//     Cell result;
//     result.type = max(type, other.type);
//     result.org.resize(result.type + 1, 0.0);

//     for 
// }

// ostream& operator<<(ostream& mystream, const Cell &obj)
// {
//     bool first = true;

//     for (size_t i = 0; i < obj.org.size(); i++)
//     {
//         double 
//     }
// }

// istream& operator>>(istream& mystream, Cell &obj)
// {
    
// }