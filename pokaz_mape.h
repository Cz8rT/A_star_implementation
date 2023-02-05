#include <iostream>
#include <windows.h>

using namespace std;

// Funkcja zmieniajaca kolor czcionki w konsoli
void zmien_kolor(int num){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),num);
}

//Funkcja wyswietlajaca mape w konsoli
void pokaz_mape(int wymiar, Node *tabN){
    cout<<"\nWYGENEROWANA MAPA\n";
    zmien_kolor(13);
    for (int x = 0; x < wymiar; x++){
        for (int y = 0; y < wymiar; y++){
            if(tabN[wymiar*x+y].isObstacle){
                zmien_kolor(14);
                cout<<" 5";
                zmien_kolor(13);
            } else if((wymiar*x+y)==19){    // 19 to numer Noda mety
                zmien_kolor(12);
                cout<<" M";
                zmien_kolor(13);
            } else if((wymiar*x+y)==380){   // 380 to numer Noda startu
                zmien_kolor(11);
                cout<<" S";
                zmien_kolor(13);
            } else if(tabN[wymiar*x+y].isAncestor){
                zmien_kolor(2);
                cout<<" T";
                zmien_kolor(13);
            } else if(tabN[wymiar*x+y].beenVisited){
                zmien_kolor(1);
                cout<<" 3";
                zmien_kolor(13);
            } else cout<<" 0";
        }
        cout<<endl;
    }
    zmien_kolor(15);
    cout<<"\nLEGENDA"<<endl;
    zmien_kolor(11);
    cout<<" S ";
    zmien_kolor(15);
    cout<<"- Start"<<endl;
    zmien_kolor(12);
    cout<<" M ";
    zmien_kolor(15);
    cout<<"- Meta"<<endl;
    zmien_kolor(14);
    cout<<" 5 ";
    zmien_kolor(15);
    cout<<"- Przeszkoda"<<endl;
    zmien_kolor(2);
    cout<<" T ";
    zmien_kolor(15);
    cout<<"- Wyznaczona Trasa"<<endl;
    zmien_kolor(1);
    cout<<" 3 ";
    zmien_kolor(15);
    cout<<"- Odwiedzone Punkty"<<endl;
    zmien_kolor(13);
    cout<<" 0 ";
    zmien_kolor(15);
    cout<<"- Punkt na Mapie"<<endl;
}

