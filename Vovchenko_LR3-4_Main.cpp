#include <ctime>
#include "Vovchenko_LR3-4_ClassCell.cpp"


using namespace std;

struct Menu1
{
    string title;
    function<void()> action;
};

int main()
{
    srand(time(NULL));

    map<int, Menu1> menu =
    {
        {1, {"Create Cell Constructor default", createCellDefault}},
        {2, {"Create Cell Constructor with organells", createCellOrg}},
        {3, {"Create Cell Constructor with organells and size", createCellOrgSize}},
        {4, {"Create Cell with console", createCellCons}},
        {5, {"Show array of Cell", showArrayCell}},
        {6, {"Calculate Volume", calValCell}},
        // {7, {"Add of Cells", addCells}},
        {8, {"Sum Volumes", sumAllCells}},
        {9, {"Compare Volumes", compVolumes}},
    };

    int choice = 0;

    cout << "Menu: " << endl;
    for (const auto& item : menu)
    {
        cout << "Task: " << item.first << ". " << item.second.title << endl;
    }

    cout << "0. Quit." << endl;

    while (true)
    {
    Enter_Number(choice, "Enter Number: ")();
    if (choice == 0)
    {
        cout << "Cell." << endl;
        break;
    }

    cout << endl;

    if (menu.find(choice) != menu.end())
    {
        menu[choice].action();
    }
    else
    {
        cout << "Invalid input.";
    }

    cout << endl << endl;
    }
    return 0;
}