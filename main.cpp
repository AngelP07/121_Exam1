//Exam #1 Periodic Table 

#include<iostream>
#include<iomanip>
#include<cctype>
#include<fstream>
#include "input.h"
using namespace std;

void advancedBinaryFile();

void dynamicArray();



struct Element
{
    short atomicNum = 0;
    char symbol[3] = "un";
    char name[25] = "unk";
    float mass = 0.0;
    char state = 'x';
    short groupNum = 0;
    short periodNum = 0;
    char blockType = 'u';
    float meltingPt = 0.0;
    float boilPt = 0.0;
    short discoveryYr = 0;
    char scientist[100] = "unk";
};

//Dynamic Array Prototypes
Element* arrayExpander(Element* array, int& size);
Element* fileToArray(string filename, Element* array, int& size);
void displayArray(Element* array, int size);
Element* addElem(Element* array, int& size);
bool checkAtomNum(Element* array, short atomicNum);
Element* updateElem(Element* array, int& size);
bool compareSymbol(Element element1, Element element2);
Element* arrSort(Element* array, int& size);
int binarySearch(Element* array, int size, char* symbol);
void arrayToFile(string filename, Element* array, int& size);



int main()
{
    int j = 0;
    do
    {
        system("cls");


        //Space for Periodic Table

        cout << "\n\t" << char(201);
        cout << string(160, char(205));
        cout << char(187);
        cout << "\n\t" << char(186) << "                                       Periodic Table of Elements by Atomic Number & Symbol(colors 5 pts Xtra credits)                                          " << char(186);
        cout << "\n\t" << char(186) << "       [  1-H ]                                                                                                                                  [  2-He]       " << char(186);
        cout << "\n\t" << char(186) << "       [  3-Li][  4-Be]                                                                                  [  5-B ][  6-C ][  7-N ][  8-O ][  9-F ][ 10-Ne]       " << char(186);
        cout << "\n\t" << char(186) << "       [ 11-Na][ 12-Mg]                                                                                  [ 13-Al][ 14-Si][ 15-P ][ 16-S ][ 17-Cl][ 18-Ar]       " << char(186);
        cout << "\n\t" << char(186) << "       [ 19-K ][ 20-Ca][ 21-Sc]  [ 22-Ti][ 23-V ][ 24-Cr][ 25-Mn][ 26-Fe][ 27-Co][ 28-Ni][ 29-Cu][ 30-Zn][ 31-Ga][ 32-Ge][ 33-As][ 34-Se][ 35-Br][ 36-Kr]       " << char(186);
        cout << "\n\t" << char(186) << "       [ 37-Rb][ 38-Sr][ 39-Y ]  [ 40-Zr][ 41-Nb][ 42-Mo][ 43-Tc][ 44-Ru][ 45-Rh][ 46-Pd][ 47-Ag][ 48-Cd][ 49-In][ 50-Sn][ 51-Sb][ 52-Te][ 53-I ][ 54-Xe]       " << char(186);
        cout << "\n\t" << char(186) << "       [ 55-Cs][ 56-Ba][ 57-La]" << char(196) << char(191) << "[ 72-Hf][ 73-Ta][ 74-W ][ 75-Re][ 76-Os][ 77-Ir][ 78-Pt][ 79-Au][ 80-Hg][ 81-Tl][ 82-Pb][ 83-Bi][ 84-Po][ 85-At][ 86-Rn]       " << char(186);
        cout << "\n\t" << char(186) << "       [ 87-Fr][ 88-Ra][ 89-Ac]" << char(191) << char(179) << "[104-Rf][105-Db][106-Sg][107-Bh][108-Hs][109-Mt][110-Ds][111-Rg][112-Cn][113-Nh][114-Fl][115-Mc][116-Lv][117-Ts][118-Og]       " << char(186);
        cout << "\n\t" << char(186) << "                               " << char(179) << char(179) << "                                                                                                                               " << char(186);
        cout << "\n\t" << char(186) << "                               " << char(179) << char(192) << "[ 58-Ce][ 59-Pr][ 60-Nd][ 61-Pm][ 62-Sm][ 63-Eu][ 64-Gd][ 65-Tb][ 66-Dy][ 67-Ho][ 68-Er][ 69-Tm][ 70-Yb][ 71-Lu]               " << char(186);
        cout << "\n\t" << char(186) << "                               " << char(192) << "[ 90-Th][ 91-Pa][ 92-U ][ 93-Np][ 94-Pu][ 95-Am][ 96-Cm][ 97-Bk][ 98-Cf][ 99-Es][100-Fm][101-Md][102-No][103-Lr]                " << char(186);
        cout << "\n\t" << char(200);
        cout << string(160, char(205));
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


        //check how to use toUpper
        switch (toupper(inputChar("\n\tOption: ", "ABCXQ")))
        {
        case 'Q': exit(0);
        case 'A': advancedBinaryFile();
            break;
        case 'B': dynamicArray();
            break;
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

        switch (inputInteger("\n\tOption: ", 0, 4))
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

//Begining of Angel's work on dynamically allocated arrays: Option B (Chapter 9)
void dynamicArray()
{
    int numElements = 0;
    int result = 0;
    char sym[3] = "un";
    Element* array = nullptr;
    string binaryFileName;

    do
    {
        system("cls");
        cout << "\n\n\t" << string(80, char(205));
        cout << "\n\tOption: Dynamic Array Menu";
        cout << "\n\t" << string(80, char(205));
        cout << "\n\t 1. Read element(s) from the binary data file and store into the dynamic array";
        cout << "\n\t 2. Display element(s) from the dynamic array";
        cout << "\n\t 3. Add a new chemistry element into the dynamic array";
        cout << "\n\t 4. Update an existing chemistry element from the dynamic array";
        cout << "\n\t 5. Sort the dynamic array by Symbol in ascending order";
        cout << "\n\t 6. Binary search an element by Symbol";
        cout << "\n\t 7. Write elements from the dynamic array to the binary data file.";
        cout << "\n\t" << string(80, char(196));
        cout << "\n\t 0. Return to main menu";
        cout << "\n\t" << string(80, char(205));

        switch (inputInteger("\n\tOption: ", 0, 7))
        {
        case 0: main();
            break;

        case 1:
            system("cls");
            cout << "\n\tOption 1B: Read file and store array info";
            cout << "\n\t" << string(80, char(205));
            binaryFileName = inputString("\n\tEnter the binary file to be read from: ", false);
            array = fileToArray(binaryFileName, array, numElements);
            break;

        case 2:
            system("cls");
            cout << "\n\tOption 2B: Display array info";
            cout << "\n\t" << string(80, char(205));
            displayArray(array, numElements);
            break;
        case 3: 
            system("cls");
            cout << "\n\tOption 3B: Add a new Chemical Element";
            cout << "\n\t" << string(80, char(205));
            array = addElem(array, numElements); 
            break;
        case 4: 
            system("cls");
            cout << "\n\tOption 4B: Update a Chemical Element's Info";
            cout << "\n\t" << string(80, char(205));
            array = updateElem(array, numElements);
            break;
        case 5: 
            system("cls");
            cout << "\n\tOption 5B: Sort array";
            cout << "\n\t" << string(80, char(205)); 
            array = arrSort(array, numElements);
            break;
        case 6:
            system("cls");
            cout << "\n\tOption 5B: Sort array";
            cout << "\n\t" << string(80, char(205));
            strncpy_s(sym, inputString("\n\tSymbol :", false).c_str(), sizeof(sym) - 1);
            result = binarySearch(array, numElements, sym);
            if (result == -2)
                cout << "\n\tError: Dynamic array is empty. No info can be displayed.";
            else if (result == -1)
                cout << "\n\tElement (" << sym << ") not present in array";
            else
                cout << "\n\tElement (" << sym <<  ") found at index " << result << ".";
            break;
        case 7: 
            system("cls");
            cout << "\n\tOption 1B: Read file and store array info";
            cout << "\n\t" << string(80, char(205));
            binaryFileName = inputString("\n\tEnter the binary file to write array info into: ", false);
            arrayToFile(binaryFileName, array, numElements);
            main();
            break;
        }

        cout << "\n\n";
        system("pause");

    } while (true);
}


//precondition  : takes in Element ptr, and int& arguements
//postcondition : returns a copy of original ptr array that is one element larger
Element* arrayExpander(Element* array, int& size) {

    //creates a temp array that is one element longer than arguement
    Element* temp = new Element[size + 1];

    //copies elements from array to temp
    for (int i = 0; i < size; i++)
        *(temp + i) = *(array + i);

    //deletes original array
    delete[] array;

    //returns temp as newly expanded array
    return temp;
}


//precondition  : takes in string, Element ptr, and int& arguements
//postcondition : if file exists then returns nothing, otherwise reads the files contents and saves them onto an array
Element* fileToArray(string filename, Element* array, int& size)
{
    fstream file;
    array = nullptr;
    //initialize starting index
    int i = 0;

    //opens file for reading
    file.open(filename, ios::binary | ios::in);

    //if file does not exist then creates error code
    if (!file)
    {
        cout << "\n\tERROR: File not found. Returning to menu...";
    }
    else
    {
        //replaces basic ptr with array ptr with 1 element
        array = arrayExpander(array, size);

        //reads data in binary file until no more data is found
        while (file.read(reinterpret_cast<char*>(&array[i]), sizeof(array[i])))
        {
            //increments size to keep up with index 
            size++;

            //expands array by one element
            array = arrayExpander(array, size);

            //move to next element
            i++;
        }
    }
    //closes binary file
    file.close();

    //returns new array
    return array;
}


//precondition  : takes in Element ptr, and int arguements
//postcondition : prints out data stored in ptr structure
void displayArray(Element* array, int size)
{
    //if array ptr points to nothing then produces error code
    if (array == nullptr)
        cout << "\n\tError: Dynamic array is empty. No info can be displayed.";
    else
        for (int i = 0; i < size; i++)
        {
            cout << "\n\tIndex[" << i << "]";
            cout << "\n\tAtomic #        : " << array[i].atomicNum;
            cout << "\n\tSymbol          : " << array[i].symbol;
            cout << "\n\tName            : " << array[i].name;
            cout << "\n\tMass            : " << array[i].mass << "u";
            cout << "\n\tState of matter : " << array[i].state;
            cout << "\n\tGroup #         : " << array[i].groupNum;
            cout << "\n\tPeriod #        : " << array[i].periodNum;
            cout << "\n\tBlock type      : " << array[i].blockType;
            cout << "\n\tMelting point   : " << array[i].meltingPt;
            cout << "\n\tBoiling Point   : " << array[i].boilPt;
            cout << "\n\tDiscovery year  : " << array[i].discoveryYr;
            cout << "\n\tDiscovered by   : " << array[i].scientist;
            cout << "\n\n";
        }

    cout << "\n\t*Current size of the array: " << size;
}


//precondition  : takes in Element ptr and int& as arguments
//postcondition : appends array with new element's info
Element* addElem(Element* array, int& size)
{
    system("cls");

    if (array == nullptr)
        cout << "No array was found. Creating new array...";

    //expands array by one element
    array = arrayExpander(array, size);
    size++;

    cout << "\n\tEnter new Element info for Index[" << size - 1 << "]";
    cout << "\n\t" << string(80, char(205));

    //asks for new element's atomic number
    array[size - 1].atomicNum = inputInteger("\n\tAtomic # :", 1, 118);

    //asks for new element's symbol
    strncpy_s(array[size - 1].symbol, inputString("\n\tSymbol :", false).c_str(), sizeof(array[size - 1].symbol) - 1);

    //asks for new element's name
    strncpy_s(array[size - 1].name, inputString("\n\tName :", false).c_str(), sizeof(array[size - 1].name) - 1);

    //asks for new element's mass
    array[size - 1].mass = inputDouble("\n\tMass: ", true);

    //asks for new element's state of matter
    array[size - 1].state = toupper(inputChar("\n\tState of matter: "));

    //asks for new element's group number
    array[size - 1].groupNum = inputInteger("\n\tGroup # :", true);

    //period number
    array[size - 1].periodNum = inputInteger("\n\tPeriod # :", true);

    //asks for new element's block type
    array[size - 1].blockType = toupper(inputChar("\n\tBlock Type: "));

    //asks for new element's melting point
    array[size - 1].meltingPt = inputDouble("\n\tMelting point: ");

    //asks for new element's boiling point
    array[size - 1].boilPt = inputDouble("\n\tBoiling point: ");


    //asks for new element's year of discovery
    array[size - 1].discoveryYr = inputInteger("\n\tDiscovery year: ", true);

    //asks who discovered the element
    strncpy_s(array[size - 1].scientist, inputString("\n\tDiscovered by:", false).c_str(), sizeof(array[size - 1].scientist) - 1);

    //returns newly appended array
    return array;
}


//precondition  : takes in Element ptr and short as arguements
//postcondition : returns true if atomic number is found in the array, otherwise returns false
bool checkAtomNum(Element* array, short atomicNum)
{
    bool state = false;

    for (int i = 0; i < sizeof(array) + 1; i++)
    {
        if (atomicNum == array[i].atomicNum)
        {
            state = true;
            break;
        }

    }

    return state;
}


//precondition  : takes in Element ptr and int& as arguments
//postcondition : replace index chosen with new element's info
Element* updateElem(Element* array, int& size)
{
    short atomNum = 0;
    short index = 0;
    //create a temp array to hold edited info
    Element* temp = new Element[size];

    //copies array to temp 
    for (int i = 0; i < size; i++)
        *(temp + i) = *(array + i);

    //if array ptr points to nothing then produces error code and returns
    if (array == nullptr)
    {
        cout << "\n\tError: Dynamic array is empty. No info can be updated. Please select a valid option.";
        return array;
    }
    else
    {

        atomNum = inputInteger("\n\tChoose an atomic # of an existing Element: ", true);

        //if atomic # is not found in array then returns the original array to previous menu
        if (!checkAtomNum(array, atomNum))
        {
            cout << "\n\tERROR: Cannot update an element with Atomic # (" << atomNum << ") that does not existed.Please perform other valid option.";
            return array;
        }
        //if atomic number is found in the array then then block continues
        else
        {
            //gets index where atomic number is held
            for (int i = 0; i < sizeof(array) + 1; i++)
            {
                if (atomNum == array[i].atomicNum)
                {
                    index = i;
                    break;
                }
            }

            do
            {
                system("cls");

                //Shows the element info and updates info if it is changed for user to see
                cout << "\n\tIndex[" << index << "]";
                cout << "\n\tAtomic #        : " << temp[index].atomicNum;
                cout << "\n\tSymbol          : " << temp[index].symbol;
                cout << "\n\tName            : " << temp[index].name;
                cout << "\n\tMass            : " << temp[index].mass << "u";
                cout << "\n\tState of matter : " << temp[index].state;
                cout << "\n\tGroup #         : " << temp[index].groupNum;
                cout << "\n\tPeriod #        : " << temp[index].periodNum;
                cout << "\n\tBlock type      : " << temp[index].blockType;
                cout << "\n\tMelting point   : " << temp[index].meltingPt;
                cout << "\n\tBoiling Point   : " << temp[index].boilPt;
                cout << "\n\tDiscovery year  : " << temp[index].discoveryYr;
                cout << "\n\tDiscovered by   : " << temp[index].scientist;
                cout << "\n\nUpdating Element's info...";
                cout << "\n\n\t" << string(80, char(205));
                cout << "\n\t 1.  Symbol";
                cout << "\n\t 2.  Name";
                cout << "\n\t 3.  Atomic Mass";
                cout << "\n\t 4.  State type";
                cout << "\n\t 5.  Group #";
                cout << "\n\t 6.  Block Type";
                cout << "\n\t 7.  Period Type";
                cout << "\n\t 8.  Melting Point";
                cout << "\n\t 9.  Boiling Point";
                cout << "\n\t 10. Discovery Year";
                cout << "\n\t 11. Discovered By";
                cout << "\n\t" << string(80, char(196));
                cout << "\n\t-1. Return WITHOUT change(s)";
                cout << "\n\t 0. Return WITH committed change(s)";
                cout << "\n\t" << string(80, char(205));

                //switch statement to edit specific info or to return
                switch (inputInteger("\n\tOption: ", -1, 11))
                {
                    //returns array with original info of element
                case -1:
                    cout << "\n\tWARNING: Returning WITHOUT change(s)...";
                    return array;
                    break;
                    //returns array with edited info of element
                case 0:
                    cout << "\n\tWARNING: Returning WITH change(s)...";
                    return temp;
                    break;
                case 1:
                    //asks for new element's symbol
                    strncpy_s(temp[index].symbol, inputString("\n\tSymbol :", false).c_str(), sizeof(temp[index].symbol) - 1);
                    break;
                case 2:
                    //asks for new element's name
                    strncpy_s(temp[index].name, inputString("\n\tName :", false).c_str(), sizeof(temp[index].name) - 1);
                    break;
                case 3:
                    //asks for new element's mass
                    temp[index].mass = inputDouble("\n\tMass: ", true);
                    break;
                case 4:
                    //asks for new element's state of matter
                    temp[index].state = toupper(inputChar("\n\tState of matter: "));
                    break;
                case 5:
                    //asks for new element's group number
                    temp[index].groupNum = inputInteger("\n\tGroup # :", true);
                    break;
                case 6:
                    //period number
                    temp[index].periodNum = inputInteger("\n\tPeriod # :", true);
                    break;
                case 7:
                    //asks for new element's block type
                    temp[index].blockType = toupper(inputChar("\n\tBlock Type: "));
                    break;
                case 8:
                    //asks for new element's melting point
                    temp[index].meltingPt = inputDouble("\n\tMelting point: ");
                    break;
                case 9:
                    //asks for new element's boiling point
                    temp[index].boilPt = inputDouble("\n\tBoiling point: ");
                    break;
                case 10:
                    //asks for new element's year of discovery
                    temp[index].discoveryYr = inputInteger("\n\tDiscovery year: ", true);
                    break;
                case 11:
                    //asks who discovered the element
                    strncpy_s(temp[index].scientist, inputString("\n\tDiscovered by:", false).c_str(), sizeof(temp[index].scientist) - 1);
                    break;
                }

                cout << "\n\n";
                system("pause");

            } while (true);
        }
    }
}


//precondition  : takes in two Element objects
//postcondition : compares the symbols of each element and returns true if the first symbol is less(alphabeticaly) than the other
bool compareSymbol(Element element1, Element element2)
{
    //convert the c_strings to strings to be able to use logical arguement: >
    if (string(element1.symbol) < string(element2.symbol))
        return true;
    else
        return false;
}


//precondition  : takes in Element ptr and int& as arguments
//postcondition : sorts the array by symbol in acscending order
Element* arrSort(Element* array, int& size)
{
    if (array == nullptr)
        cout << "\n\tError: Dynamic array is empty. No info can be displayed.";
    else
    {
        //sort function
        sort(array, array + size, compareSymbol);
        cout << "\n\tArray has been sorted in descending order";
    }
    return array;
}


//precondition  : takes in Element, int, and c_string as arguments
//postcondition : searches the sorted array
int binarySearch(Element* array, int size, char* symbol)
{
    int left = 0;
    int right = size - 1;


    if (array == nullptr)
        return -2;
    else
    {
        // Loop to implement Binary Search 
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int cmp = strcmp(array[mid].symbol, symbol);

            if (cmp == 0) {
                return mid; // Found
            }
            else if (cmp < 0) {
                left = mid + 1; // Target is in the left half
            }
            else {
                right = mid - 1; // Target is in the right half
            }
        }

        return -1;
    }
}


//precondition  : takes in string, Element ptr, and int& arguements
//postcondition : if array exists then writes info onto a new file
void arrayToFile(string filename, Element* array, int& size)
{
    fstream file;
    //index to begin at start of array
    int i = 0;

    //opens file in out to write data onto file
    file.open(filename, ios::binary | ios::out);

    //runs through elements of array and writes info onto data file
    while (i < size)
    {
        file.write(reinterpret_cast<char*>(&array[i]), sizeof(array[i]));
        i++;
    }

    file.close();

    //Confirmation code
    cout << "\n\tCONFRIMATION: array elements have been written onto file: " << filename << ".";
}
