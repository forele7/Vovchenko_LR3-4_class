#include <ctime>
#include <M:\\Program\\Vovchenko_LR3-4_class\\Vovchenko_LR3-4_ClassCell.cpp>

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
        {1, {"Create vector Aeroflot", createAeroflotFromFile(AEROFLOT1)}},
        {2, {"Show vector Aeroflot", ShowAeroflot}},
        {3, {"Add vector Aeroflot", addAeroflotToData}},
        {4, {"Find Arrival", ShowByArrival}},
        {5, {"Find Day", ShowByDay}},
        {6, {"Find Day and Time", ShowByDayAndTime}},
    };

    int choice = 0;

    cout << "Menu: " << endl;
    for (const auto& item : menu)
    {
        cout << "Task: " <<item.first << ". " << item.second.title << endl;
    }

    cout << "0. Quit." << endl;

    while (true)
    {
    Enter_Number(choice, "Enter Number: ")();
    if (choice == 0)
    {
        cout << "Aeroflot." << endl;
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