#ifndef _METHODS_H
#define _METHODS_H

#include "Vovchenko_LR3-4_ClassCell.h"

// создать конструктор
vector<Cell> Data_Cell;

void createCellDefault()
{
    Cell cell1;
    cout << "Cell1: " << cell1 << endl;
    Data_Cell.emplace_back(cell1);
    cout << "Cell1 was created." << endl;
}

// ввод списка органелл
void createCellOrg() {
    int num_org;
    Enter_Number(num_org, "Enter number of organells: ")();

    vector<double> sizee;
    vector<string> org(num_org);
    for (int i = 0; i < num_org; ++i) {
        Enter_String(org[i], "Enter organells: ")();
    }

    srand(static_cast<unsigned int>(std::time(0)));
    for (int i = 0; i < 3; ++i) 
    {
        double random_value = static_cast<double>(rand()%2500 + 1)/100;
        sizee.push_back(random_value);
    }

    Cell cell2("unknown", org, sizee);
    cout << "Cell2: " << cell2 << endl;
    Data_Cell.emplace_back(cell2);
    cout << "Cell2 was created." << endl;
}

// ввод списка органелл и размера клетки
void createCellOrgSize() {
    int num_org;
    Enter_Number(num_org, "Enter number of organells: ")();

    vector<string> org(num_org);
    for (int i = 0; i < num_org; ++i) {
        Enter_String(org[i], "Enter organells: ")();
    }

    vector<double> sizee(3);
    for (int i = 0; i < 3; ++i) {
        double d;
        Enter_NumberD(d, "Enter size: ")();
        sizee[i] = d;
    }

    Cell cell3("unknown", org, sizee);
    cout << "Cell3: " << cell3 << endl;
    Data_Cell.emplace_back(cell3);
    cout << "Cell3 was created.\n";
}

// консольный ввод
void createCellCons()
{
    string type;
    Enter_String(type, "Enter type: ")();

    int num_org;
    Enter_Number(num_org, "Enter number of organells: ")();

    vector<string> org(num_org);
    for (int i = 0; i < num_org; ++i) 
    {
        Enter_String(org[i], "Enter organells: ")();
    }

    vector<double> sizee(3);
    for (int i = 0; i < 3; ++i) 
    {
        double d;
        Enter_NumberD(d, "Enter size: ")();
        sizee[i] = d;
    }

    Cell cell4(type, org, sizee);
    cout << "Cell4: " << cell4 << endl;
    Data_Cell.emplace_back(cell4);
    cout << "Cell4 was created." << endl;
}

// вектор клеток
void showArrayCell()
{
    if (Data_Cell.empty()) {
        cout << "Array is empty.\n";
        return;
    }

    for (size_t i = 0; i < Data_Cell.size(); ++i) {
        cout << "Cell " << i + 1 << ":\n";
        cout << Data_Cell[i] << endl;
    }

    vector<Cell> vectorOfAllCell = Data_Cell;
}

// вычисление объема выбранной клетки
void calValCell()
{
    vector<Cell> vectorOfAllCell = Data_Cell;
    int choice;
    Enter_Number(choice, "Enter number of Cell: ")();

    if (choice < 1 || choice > Data_Cell.size()) {
        cout << "Invalid input.";
        return;
    }
    cout << "Volume of Cell " << choice << ": " << Data_Cell[choice - 1].Volume() << endl;
    
    //cout << "Volume: " << Data_Cell[choice].Volume() << endl;
}

// сложение клеток
void addCells()
{

}

//вычисление суммарного объема массива клеток.
void sumAllCells() 
{
    double totalV = 0.0;
    for (const auto& cell : Data_Cell) 
    {
        totalV += cell.Volume();
    }
   cout << "Sum of all Cell Volumes: " << totalV;
}

// сравнение объемов клеток
void compVolumes() 
{
    if (Data_Cell.size() < 4) {
        cout << "4 Cells are required for comprasion!" << endl;
        return;
    }

    double V1 = Data_Cell[0].Volume();
    double V2 = Data_Cell[1].Volume();
    double V3 = Data_Cell[2].Volume();
    double V4 = Data_Cell[3].Volume();

    cout << "Volumes:\n";
    cout << "Cell 1: " << V1 << endl;
    cout << "Cell 2: " << V2 << endl;
    cout << "Cell 3: " << V3 << endl;
    cout << "Cell 4: " << V4 << endl;

    // наибольший объем
    double maxV = max({V1, V2, V3, V4});
    cout << endl;

    if (V1 == maxV) 
        cout << "Cell 1's Volume is the largest." << endl;
    if (V2 == maxV) 
        cout << "Cell 2's Volume is the largest." << endl;
    if (V3 == maxV) 
        cout << "Cell 3's Volume is the largest." << endl;
    if (V4 == maxV) 
        cout << "Cell 4's Volume is the largest." << endl;

    // наименьший объем
    double minV = min({V1, V2, V3, V4});
    cout << endl;

    if (V1 == minV) 
        cout << "Cell 1's Volume is the smallest." << endl;
    if (V2 == minV) 
        cout << "Cell 2's Volume is the smallest." << endl;
    if (V3 == minV) 
        cout << "Cell 3's Volume is the smallest." << endl;
    if (V4 == minV) 
        cout << "Cell 4's Volume is the smallest." << endl;
}

#endif