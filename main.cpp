//Exam 1 Periodic Table by 

#include<iostream>
#include<iomanip>
#include<cctype>
#include "input.h"
using namespace std;

void advancedBinaryFile();
void dynamicArray();
void vector();
void xtraCredit();





int main()
{
    do
    {
        system("cls");


        //Space for Periodic Table


        cout << "\n\tCMPR121:  Exam#1: Implementation using  Dynamic Array, string/C-string, struct, and Binary File (3-19-2025) ";
        cout << "\n\t" << string(80, char(205));
        cout << "\n\t A) Advance Binary Data File (Chapter#12)";
        cout << "\n\t B) Dynamic Array (Chapter#9)";
        cout << "\n\t C) Vector (Chapter#7)";
        cout << "\n\t X) Xtra credits (5 pts)";
        cout << "\n\t" << string(80, char(196));
        cout << "\n\t Q) Quit";
        cout << "\n\t" << string(80, char(205));

        switch (inputInteger("\n\tOption: ", 0, 20))
        {
        case 'Q': exit(0);
        //case 'A': advancedBinaryFile(); 
        //  break;
        //case 'B': dynamicArray(); 
        //  break;
        //case 'C': vector(); 
        //  break;
        //case 'X': xtraCredit(); 
        //  break;
        }

        cout << "\n\n";
        system("pause");
    } while (true);

    return 0;

}