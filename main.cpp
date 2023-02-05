#include <iostream>
#include <fstream>
#include <math.h>
#include "node.h"
#include "pokaz_mape.h"
#include "oblicz_Agwiazdka.h"
#include "wyswietl_noda.h"

using namespace std;

int main()
{
    int wymiarMapy=20;

    // deklaracja tablicy przechowujacej dane typu klasy Node
    // i przypisanie poszczegolnym Nodom ich wspolrzednych
    Node *tabNodes = new Node[wymiarMapy * wymiarMapy];
    for (int x = 0; x < wymiarMapy; x++){
        for (int y = 0; y < wymiarMapy; y++){
            tabNodes[wymiarMapy*x+y].x = x;
            tabNodes[wymiarMapy*x+y].y = y;
        }
    }

	string nazwaPliku="grid.txt";
    cout<<"\nNacisnij ENTER aby wczytac tablice o nazwie "<< nazwaPliku;
    getchar();

    cout<<"Wczytywanie danych z pliku...\n";
    std::ifstream plik(nazwaPliku.c_str()); // ifstream domyslnie pomija spacje w pliku

    // zapisywanie danych z pliku do tablicy
    char znak;
    for (int x = 0; x < wymiarMapy; x++){
        for (int y = 0; y < wymiarMapy; y++){
            plik >> znak;
            if(znak == '5') tabNodes[wymiarMapy*x+y].isObstacle = true; // sprawdzenie czy Node jest przeszkoda
            // dodawanie do vectora sasiadow dla kazdego Noda
            if(x>0) // Dodawanie sasiada z gory
                tabNodes[wymiarMapy*x+y].vecSasiedzi.push_back(&tabNodes[wymiarMapy*(x-1)+y]);
            if(x<wymiarMapy-1) // Dodawanie sasiada z dolu
                tabNodes[wymiarMapy*x+y].vecSasiedzi.push_back(&tabNodes[wymiarMapy*(x+1)+y]);
            if(y>0) // Dodawanie sasiada z lewej
                tabNodes[wymiarMapy*x+y].vecSasiedzi.push_back(&tabNodes[wymiarMapy*x+y-1]);
            if(y<wymiarMapy-1) // Dodawanie sasiada z prawej
                tabNodes[wymiarMapy*x+y].vecSasiedzi.push_back(&tabNodes[wymiarMapy*x+y+1]);
        }
    }
    plik.close();

    pokaz_mape(wymiarMapy, tabNodes);

    Node nodeStart = tabNodes[380]; // Wskazanie Noda startu (19,0)
	Node nodeMeta = tabNodes[19];   // Wskazanie Noda mety (0,19)

    // Wypisanie pozycji staru i mety na ekranie
    zmien_kolor(11);
    cout<<"\nStart (Node nr 380) pozycja: ";
    cout<<"("<<nodeStart.x<<","<<nodeStart.y<<")"<<endl;
    zmien_kolor(12);
    cout<<"Meta (Node nr 19) pozycja: ";
    cout<<"("<<nodeMeta.x <<","<< nodeMeta.y<<")"<<endl;
    zmien_kolor(15);

    oblicz_Agwiazdka(wymiarMapy, tabNodes);

    pokaz_mape(wymiarMapy, tabNodes);

    wyswietl_noda(tabNodes[38]);

    delete[] tabNodes;  //czyscimy pamiec po naszej tablicy

    cout<<"\n\nNacisnij ENTER aby zakonczyc";
    getchar();
    return (0);
}
