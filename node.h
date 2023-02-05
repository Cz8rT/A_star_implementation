#include <iostream>
#include <vector>

using namespace std;

class Node{                         // definicja klasy Node
public:
    int x;							// Pozycja Noda (x,y)
    int y;
    float kosztG = 999;				// Aktualny koszt G (koszt dotarcia do punktu ze startu)
    float kosztL = 999;				// Aktualny koszt L (koszt G + heurystyka)
    bool isObstacle = false;		// Czy Node jest przeszkoda?
    bool beenVisited = false;		// Czy Node byl wczesniej odwiedzony
    bool isAncestor = false;		// Czy Node jest jednym z przodkow nalezacych do najkrotszej sciezki
    vector<Node*> vecSasiedzi;	    // Vector przechowujacy polaczenia z sasiednimi Nodami
    Node* rodzic = nullptr;         // Poczatkowo Node nie ma rodzica
};
