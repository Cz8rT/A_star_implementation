#include <iostream>

using namespace std;

// Funkcja wypisujaca w konsoli sasiadow podanego Noda
void wypisz_sasiadow(Node node){
    cout<<"Sasiedzi Noda:"<<endl;
    int licznik = 1;
    for (auto n : node.vecSasiedzi){
        cout<<" Sasiad nr "<< licznik<<": ("<< n->x <<","<< n->y <<")"<<endl;
        licznik++;
    }
}

// Funkcja wyswietlajaca aktualne parametry podanego Noda
void wyswietl_noda(Node node){

    string obstacle, visited, path;

    obstacle = (node.isObstacle) ? "Tak" : "Nie";
    visited = (node.beenVisited) ? "Tak" : "Nie";
    path = (node.isAncestor) ? "Tak" : "Nie";

    cout<<"\nWYBRANY NODE"<<endl;
    cout<<"Pozycja: ("<<node.x<<","<<node.y<<")"<<endl;
    cout<<"Aktualny koszt: "<<node.kosztL<<endl;
    cout<<"Jest przeszkoda?: "<<obstacle<<endl;
    cout<<"Zostal odwiedzony?: "<<visited<<endl;
    cout<<"Nalezy do wyznaczonej trasy?: "<<path<<endl;
    cout<<"Rodzic wybranego Noda?: ";
    if(node.rodzic){
        int x = node.rodzic->x;
        int y = node.rodzic->y;
        cout<<"("<< x <<","<< y <<")"<<endl;
    } else cout<<"Brak"<<endl;
    wypisz_sasiadow(node);
}
