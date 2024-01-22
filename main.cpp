#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string fishName = "";
    string fishFromRiver = "";
    string answer = "y";
    int fishCount = 0;
    int total = 0;

    ofstream fileOut ("C:\\develop\\test\\build\\modul_20_task_3\\basket.txt", ios::app);
    if (!fileOut.is_open())
    {
        cerr << "Error, basket file is not open";
        return 1;
    }
    ifstream fileIn ("C:\\develop\\test\\build\\modul_20_task_3\\river.txt");
    if (!fileIn.is_open())
    {
        cerr << "Error, river file is not open";
        return 1;
    }

    while (answer == "y")
    {
        fishCount = 0;
        cout << "Enter fish name: ";
        getline (cin, fishName);

        do
        {
            fileIn >> fishFromRiver;
            if (fishName == fishFromRiver)
            {
                fileOut << fishName << endl;
                fishCount++;
            }
        } while (!fileIn.eof());

        fileIn.clear();
        fileIn.seekg(0);

        if (fishCount == 0)
        {
            cout << "No such fish in the river! Continue? (y/n)" << endl;
            cin >> answer;
            cin.get();
        }
        else
        {
            cout << "Fish caught: " << fishCount << ". Continue? (y/n)" << endl;
            cin >> answer;
            cin.get();
        }

        total += fishCount;
    }

    cout << "Total fish caught: " << total << endl;

    fileIn.close();
    fileOut.close();
}