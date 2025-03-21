#include <cmath>
#include <iomanip>
#include <M:\\Program\\Vovchenko_LR3-4_class\\Vovchenko_LR3-4_ClassCell.h>

Cell::Cell():type{""}, org{""}, r{0.0}
{   
}

Cell::Cell (const string& type): Cell::Cell()
{
    this->type = type;
}

// // копирование
// Cell::Cell(const Cell& other)
//     : type(other.type), org(other.org) {}

// void Cell::Volume(double x = 1.0)
// {

// }

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