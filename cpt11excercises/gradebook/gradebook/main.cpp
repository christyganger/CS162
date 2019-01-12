#include <iostream>

using namespace std;

int main()
{
    int gradearraysize =100;
    int howmanystudents;
    bool donerecord = false;
    bool donereport = false;
    int ArrayGrades[gradearraysize][gradearraysize];
    cout << "How many students? (up to 100)" << "\n";
    cin >> howmanystudents;


            for(int i =0; i< howmanystudents; i++)
        {
            cout << "please enter the grade";
            cin >> ArrayGrades[i][i];

        }
for(int j = 0; j<howmanystudents; j++)
{
    cout << ArrayGrades[j][j];
}



    return 0;
}
