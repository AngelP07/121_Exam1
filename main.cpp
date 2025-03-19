//Exam #1 Periodic Table 

#include<iostream>
#include<iomanip>
#include<cctype>
#include "input.h"
using namespace std;

void advancedBinaryFile();
//void dynamicArray();
//void vector();
//void xtraCredit();





int main()
{
    int j = 0;
    do
    {
        system("cls");


        //Space for Periodic Table

        cout << "\n\t" << char(201);
        while (j < 160)
        {
            cout << char(205);
            j++;
        }
        cout << char(187);
        cout << "\n\t" << char(186) << "                                       Periodic Table of Elements by Atomic Number & Symbol(colors 5 pts Xtra credits)                                          " << char(186);
        cout << "\n\t" << char(186) << "       [  1-H ]                                                                                                                                  [  2-He]       " << char(186);
        cout << "\n\t" << char(186) << "       [  3-Li][  4-Be]                                                                                  [  5-B ][  6-C ][  7-N ][  8-O ][  9-F ][ 10-Ne]       " << char(186);
        cout << "\n\t" << char(186) << "       [ 11-Na][ 12-Mg]                                                                                  [ 13-Al][ 14-Si][ 15-P ][ 16-S ][ 17-Cl][ 18-Ar]       " << char(186);
        cout << "\n\t" << char(186) << "       [ 19-K ][ 20-Ca][ 21-Sc]  [ 22-Ti][ 23-V ][ 24-Cr][ 25-Mn][ 26-Fe][ 27-Co][ 28-Ni][ 29-Cu][ 30-Zn][ 31-Ga][ 32-Ge][ 33-As][ 34-Se][ 35-Br][ 36-Kr]       " << char(186);
        cout << "\n\t" << char(186) << "       [ 37-Rb][ 38-Sr][ 39-Y ]  [ 40-Zr][ 41-Nb][ 42-Mo][ 43-Tc][ 44-Ru][ 45-Rh][ 46-Pd][ 47-Ag][ 48-Cd][ 49-In][ 50-Sn][ 51-Sb][ 52-Te][ 53-I ][ 54-Xe]       " << char(186);
        cout << "\n\t" << char(186) << "       [ 55-Cs][ 56-Ba][ 57-La]"<< char(196) << char(191) <<"[ 72-Hf][ 73-Ta][ 74-W ][ 75-Re][ 76-Os][ 77-Ir][ 78-Pt][ 79-Au][ 80-Hg][ 81-Tl][ 82-Pb][ 83-Bi][ 84-Po][ 85-At][ 86-Rn]       " << char(186);
        cout << "\n\t" << char(186) << "       [ 87-Fr][ 88-Ra][ 89-Ac]" << char(191) << char(179) << "[104-Rf][105-Db][106-Sg][107-Bh][108-Hs][109-Mt][110-Ds][111-Rg][112-Cn][113-Nh][114-Fl][115-Mc][116-Lv][117-Ts][118-Og]       " << char(186);
        cout << "\n\t" << char(186) << "                               " << char(179) << char(179) <<"                                                                                                                               " << char(186);
        cout << "\n\t" << char(186) << "                               " << char(179) << char(192) << "[ 58-Ce][ 59-Pr][ 60-Nd][ 61-Pm][ 62-Sm][ 63-Eu][ 64-Gd][ 65-Tb][ 66-Dy][ 67-Ho][ 68-Er][ 69-Tm][ 70-Yb][ 71-Lu]               " << char(186);
        cout << "\n\t" << char(186) << "                               " << char(192) << "[ 90-Th][ 91-Pa][ 92-U ][ 93-Np][ 94-Pu][ 95-Am][ 96-Cm][ 97-Bk][ 98-Cf][ 99-Es][100-Fm][101-Md][102-No][103-Lr]                " << char(186);
        cout << "\n\t" << char(200);
        
        j = 0;
        while (j < 160)
        {
            cout << char(205);
            j++;
        }
        cout << char(188);

        cout << "\n\n\t" << string(162, char(205));
        cout << "\n\tCMPR121:  Exam#1: Implementation using  Dynamic Array, string/C-string, struct, and Binary File (3-19-2025) ";
        cout << "\n\t" << string(162, char(205));
        cout << "\n\t A) Advance Binary Data File (Chapter#12)";
        cout << "\n\t B) Dynamic Array (Chapter#9)";
        cout << "\n\t C) Vector (Chapter#7)";
        cout << "\n\t X) Xtra credits (5 pts)";
        cout << "\n\t" << string(162, char(196));
        cout << "\n\t Q) Quit";
        cout << "\n\t" << string(162, char(205));

        switch (inputInteger("\n\tOption: ", 0, 20))
        {
        case 'Q': exit(0);
        case 'A': advancedBinaryFile(); 
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

struct Element
{
    char symbol[3] = "un";
    char name[25] = "unk";
    float mass = 0.0;
    char state = 'x';
    short groupNum = 0;
    short periodNum = 0;
    short blockType = 0;
    float meltingPt = 0;
    float boilPt = 0;
    short discoveryYr = 0;
    char scientist[100] = "unk";
};



void advancedBinaryFile()
{
    do 
    {
        system("cls");
        cout << "\n\n\t" << string(80, char(205));
        cout << "\n\tOption: Advanced Binary File Menu";
        cout << "\n\t" << string(80, char(205));
        cout << "\n\t 1. Retrieve and display ALL the element(s) from a binary data file";
        cout << "\n\t 2. Add a new element to the binary data file";
        cout << "\n\t 3. Update an existing element from the binary data file";
        cout << "\n\t 4. Search for an element by atomic # from the binary data file";
        cout << "\n\t" << string(80, char(196));
        cout << "\n\t 0. Return to main menu";
        cout << "\n\t" << string(80, char(205));

        switch (inputInteger("\n\tOption: ", 0, 20))
        {
        case 0: main();
        //case 1: readFile();
            break;
        //case 2: addElem(); 
            break;
        //case 3: updateElem(); 
            break;
        //case 4: searchElem(); 
            break;
        }

        cout << "\n\n";
        system("pause");
        
    } while (true);
}
