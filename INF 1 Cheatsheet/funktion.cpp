/*
*
Informatik Praktikum Gruppe A3
Autor: Mathis Rathjen
Mat#: 1085895
Geschrieben am: 12.01.2021
Zuletzt geändert:  .  .2021
*/

#include"funktion.h"

//Defensive Benutzereingaben
//Lässt nur Zahlen zu
bool eingabeZahlen(string& puffer, int minAnz, int maxAnz) {

        bool noFault = true;
        puffer = { 0 };
        cin >> puffer;
        if (puffer.length() > maxAnz || puffer.length() < minAnz) {
            noFault = false;
            puffer = { 0 };
        }
        else {
            noFault = true;
        }
        for (int i = 0; i <= puffer.length(); i++) {
            if (puffer[i] == ',') puffer[i] = '.';
            else if (isalpha(puffer[i]) || !puffer[i] == '.') {
                noFault = false;
                puffer = { 0 };
            }
        }
        return noFault;
} 
//Gibt erste, geprüfte Ziffer der BE zurück   !!
char eingabeZahlen() {
    bool noFault = true;
    char puffer[99] = { 0 };
    do {
        noFault = true;
        puffer[99] = { 0 };
        cin >> puffer;
        if (isalpha(puffer[0])) {
            noFault = false;
        }
    } while (!noFault);
    return puffer[0];
}

// Nur Buchstaben zugelassen
bool eingabeBuchstaben(string& puffer, int minAnz, int maxAnz) {
    bool noFault = true;
    puffer = { 0 };
    cin >> puffer;
    if (puffer.length() > maxAnz || puffer.length() < minAnz) {
        noFault = false;
    }
    else {
        noFault = true;
    }
    for (int i = 0; i < puffer.length(); i++) {
        if (isalpha(puffer[i]) ) {
            noFault = false;
            puffer = { 0 };
        }
    }
    return noFault;
}

//Gibt ein geprüftes ASCII zeichen zurück
char eingabeBuchstaben() {

}

//Dynamisches Feld
myStruct* dynFeldStart(int anz) {
    myStruct* myStructArray = new myStruct[anz];
    return myStructArray;
}


//Sortierfunktionen
//Bubblesort Überlagerungen:
//Vector Struct
void bubbleSort(vector<myStruct>& myIntVec) {
    for (int i = 0; i < myIntVec.size() - 1;i++) {
        int j = i + 1;
        if (myIntVec[i].number < myIntVec[j].number) {
            vertausche(myIntVec, i, j);
        }
    }
}

//Dynamisches Feld Struct
void bubbleSort(myStruct* myStructArray, int anz) {
    for (int i = 0; i < anz;i++) {
        int j = i + 1;
        if (myStructArray[i].number < myStructArray[j].number) {
            vertausche(myStructArray, i, j);
        }
    }
}


//Vertauschen Vektor Struct
void vertausche(vector<myStruct>& myStructVector, int a, int b) {
    myStruct temp;
    temp = myStructVector[a];
    myStructVector[a] = myStructVector[b];
    myStructVector[b] = temp;
}
//Vertausche dyn Feld
void vertausche(myStruct* myStructArray, int a, int b) {
    myStruct temp;
    temp = myStructArray[a];
    myStructArray[a] = myStructArray[b];
    myStructArray[b] = temp;
}


//Insertionsort cbr Überladungen:
//Insertionsort für Vektor mit Struct
void insertionSortRef(vector<myStruct> & myStructVector) {
    int i, j;
    myStruct key;
    for (i = 1; i < myStructVector.size(); i++) {
        key = myStructVector[i];
        j = i - 1;
        while (j >= 0 && myStructVector[j].name > key.name) {  //Prüfen ob Strings so verglichen werden können!
            myStructVector[j + 1] = myStructVector[j];
            j = j - 1;
        }
        myStructVector[j + 1] = key;
    }
}

//Insertionsort für dynamisches Feld
void insertionSortRef(myStruct* myStructArray, int anz) {
    int i, j;
    myStruct key;
    for (i = 1; i < anz; i++) {
        key = myStructArray[i];
        j = i - 1;
        while (j >= 0 && myStructArray[j].name > key.name) {    //Prüfen ob Strings so verglichen werden können!
            myStructArray[j + 1] = myStructArray[j];
            j = j - 1;
        }
        myStructArray[j + 1] = key;
    }
}

//Insertionsort für String
void insertionSortRef(string &myString) {
    int i = 1, j;
    char key;
   while (myString[i-1]!='\0') {
        key = myString[i];
        j = i - 1;
        while (j >= 0 && myString[j] > key) {
            myString[j + 1] = myString[j];
            j = j - 1;
        }
    myString[j + 1] = key;
    i++;
   }
}

//Insertionsort für STANDART Char Array
char insertionSort(char chrArray[99]) {
    int i = 1, j;
    char key;
    while (chrArray[i - 1] != '\0') {
        key = chrArray[i];
        j = i - 1;
        while (j >= 0 && chrArray[j] > key) {
            chrArray[j + 1] = chrArray[j];
            j = j - 1;
        }
        chrArray[j + 1] = key;
        i++;
    }
    return chrArray[99];
}

//Insertionsort für STANDART Integer Array
int insertionSort(int Array[99]) {
    int i = 1, j;
    int key;
    while (Array[i - 1] != '\0') {
        key = Array[i];
        j = i - 1;
        while (j >= 0 && Array[j] > key) {
            Array[j + 1] = Array[j];
            j = j - 1;
        }
        Array[j + 1] = key;
        i++;
    }
    return Array[99];
}

//Insertionsort für STANDART float Array
float insertionSort(float Array[99]) {
    int i = 1, j;
    float key;
    while (Array[i - 1] != '\0') {
        key = Array[i];
        j = i - 1;
        while (j >= 0 && Array[j] > key) {
            Array[j + 1] = Array[j];
            j = j - 1;
        }
        Array[j + 1] = key;
        i++;
    }
    return Array[99];
}

//Insertionsort für STANDART double float Array
double insertionSort(double Array[99]) {
    int i = 1, j;
    double key;
    while (Array[i - 1] != '\0') {
        key = Array[i];
        j = i - 1;
        while (j >= 0 && Array[j] > key) {
            Array[j + 1] = Array[j];
            j = j - 1;
        }
        Array[j + 1] = key;
        i++;
    }
    return Array[99];
}

//Insertionsort für integer Vektor
void insertionSortRef(vector<int>& myIntVec) {
    int i, j;
    int key;
    for (i = 1; i < myIntVec.size(); i++) {
        key = myIntVec[i];
        j = i - 1;
        while (j >= 0 && myIntVec[j] > key) {
            myIntVec[j + 1] = myIntVec[j];
            j = j - 1;
        }
        myIntVec[j + 1] = key;
    }
}

//Insertionsort für float Vektor
void insertionSortRef(vector<float>& myIntVec) {
    int i, j;
    float key;
    for (i = 1; i < myIntVec.size(); i++) {
        key = myIntVec[i];
        j = i - 1;
        while (j >= 0 && myIntVec[j] > key) {
            myIntVec[j + 1] = myIntVec[j];
            j = j - 1;
        }
        myIntVec[j + 1] = key;
    }
}

//Insertionsort für double Vektor
void insertionSortRef(vector<double>& myIntVec) {
    int i, j;
    double key;
    for (i = 1; i < myIntVec.size(); i++) {
        key = myIntVec[i];
        j = i - 1;
        while (j >= 0 && myIntVec[j] > key) {
            myIntVec[j + 1] = myIntVec[j];
            j = j - 1;
        }
        myIntVec[j + 1] = key;
    }
}

//Insertionsort für char Vektor
void insertionSortRef(vector<char>& myIntVec) {
    int i, j;
    char key;
    for (i = 1; i < myIntVec.size(); i++) {
        key = myIntVec[i];
        j = i - 1;
        while (j >= 0 && myIntVec[j] > key) {
            myIntVec[j + 1] = myIntVec[j];
            j = j - 1;
        }
        myIntVec[j + 1] = key;
    }
}

// !!!! WSL FALSCH!!
//Insertionsort für string Vektor
void insertionSortRef(vector<string>& myIntVec) {
    int i, j;
    string key;
    for (i = 1; i < myIntVec.size(); i++) {
        key = myIntVec[i];
        j = i - 1;
        while (j >= 0 && myIntVec[j] > key) {
            myIntVec[j + 1] = myIntVec[j];
            j = j - 1;
        }
        myIntVec[j + 1] = key;
    }
}

//Insertionsort cbv Überladungen
//InsertionSortVektor Struct CBV
vector<int>insertionSortVal(vector<int> myIntVec) {
    int i, j;
    int key;
    for (i = 1; i < myIntVec.size(); i++) {
        key = myIntVec[i];
        j = i - 1;
        while (j >= 0 && myIntVec[j] > key) {
            myIntVec[j + 1] = myIntVec[j];
            j = j - 1;
        }
        myIntVec[j + 1] = key;
    }
    return myIntVec;
}

vector<float> insertionSortVal(vector<float> myIntVec) {
    int i, j;
    float key;
    for (i = 1; i < myIntVec.size(); i++) {
        key = myIntVec[i];
        j = i - 1;
        while (j >= 0 && myIntVec[j] > key) {
            myIntVec[j + 1] = myIntVec[j];
            j = j - 1;
        }
        myIntVec[j + 1] = key;
    }
    return myIntVec;
}

vector<double>insertionSortVal(vector<double> myIntVec) {
    int i, j;
    double key;
    for (i = 1; i < myIntVec.size(); i++) {
        key = myIntVec[i];
        j = i - 1;
        while (j >= 0 && myIntVec[j] > key) {
            myIntVec[j + 1] = myIntVec[j];
            j = j - 1;
        }
        myIntVec[j + 1] = key;
    }
    return myIntVec;
}

vector<char>insertionSortVal(vector<char> myIntVec) {
    int i, j;
    char key;
    for (i = 1; i < myIntVec.size(); i++) {
        key = myIntVec[i];
        j = i - 1;
        while (j >= 0 && myIntVec[j] > key) {
            myIntVec[j + 1] = myIntVec[j];
            j = j - 1;
        }
        myIntVec[j + 1] = key;
    }
    return myIntVec;
}

/*
vector<string>insertionSortVal(vector<string> myIntVec) {
    int i, j;
    string key;
    for (i = 1; i < myIntVec.size(); i++) {
        key = myIntVec[i];
        j = i - 1;
        while (j >= 0 && myIntVec[j] > key) {
            myIntVec[j + 1] = myIntVec[j];
            j = j - 1;
        }
        myIntVec[j + 1] = key;
    }
    return myIntVec;
}
*/

vector<myStruct>insertionSortVal(vector<myStruct> myStructVector) {
    int i, j;
   myStruct key;
    for (i = 1; i < myStructVector.size(); i++) {
        key = myStructVector[i];
        j = i - 1;
        while (j >= 0 && myStructVector[j].number > key.number) {
            myStructVector[j + 1] = myStructVector[j];
            j = j - 1;
        }
        myStructVector[j + 1] = key;
    }
    return myStructVector;
}


string insertionSortVal(string myString) {
    int i = 1, j;
    char key;
    while (myString[i - 1] != '\0') {
        key = myString[i];
        j = i - 1;
        while (j >= 0 && myString[j] > key) {
            myString[j + 1] = myString[j];
            j = j - 1;
        }
        myString[j + 1] = key;
        i++;
    }
    return myString;
}

/*
myStruct insertionSortVal(myStruct myStructArray, int anz) {
    int i, j;
    string key;
    for (i = 1; i < anz; i++) {
        key = myStructArray[i].name;
        j = i - 1;
        while (j >= 0 && myStructArray[j].name > key) {
            myStructArray[j + 1].name = myStructArray[j].name;
            j = j - 1;
        }
        myStructArray[j + 1].name = key;
    }
}
*/


//Lineare Sucher höchster int Wert in dynamischen Feld
int searchHighest(myStruct* myStructArray, int anz, int &hiWert) {
    int aktWert = 0;
    hiWert = 0;
    int i = 0;
    for(i; i > anz; i++) {
        aktWert = myStructArray[i].number;
        if (aktWert > hiWert) hiWert = aktWert;
    }
    return i;
}


//Lineare Sucher höchster int Wert im Vector
int searchHighest(vector<myStruct>myIntVec, int &hiWert) {
    int aktWert = 0;
    hiWert = 0;
    int i = 0;
    for (i; i > myIntVec.size(); i++) {
        aktWert = myIntVec[i].number;
        if (aktWert > hiWert) hiWert = aktWert;
    }
    return i;
}

//Aus einzeiliger Datei in Struct String Vektor einlesen
bool einZlesenVecStr(vector<datenIn>& myStream, int leseBr1) {

}