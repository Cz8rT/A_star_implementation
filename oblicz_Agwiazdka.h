#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

// Funkcja liczaca dystans pomiedzy Nodami
float odleglosc(Node* a, Node* b){
    return sqrtf(pow((a->x - b->x), 2) + pow((a->y - b->y), 2));
}

// Funkcja stosujaca algorytm A_gwiazdki
list<Node*> oblicz_Agwiazdka(int wymiar, Node *tabN){

    Node *nodeStart = &tabN[380];
    Node *nodeMeta = &tabN[19];

    // Inicjalizacja punktu startowego
    nodeStart->kosztL = odleglosc(nodeStart, nodeMeta);
    nodeStart->kosztG = 0;
    Node *nodeCurrent = nodeStart;

    // listy (otwarta i zamknieta)
    list<Node*> listaOtwarta;
    list<Node*> listaZamknieta;
    listaOtwarta.push_back(nodeCurrent);

    while(!listaOtwarta.empty()){

        // Sortowanie listy wzgledem calkowitego kosztu
        listaOtwarta.sort([](const Node* A, const Node* B){ return A->kosztL > B->kosztL; } );
        nodeCurrent = listaOtwarta.back();

        // Przerwij petle jesli odnalezione mete
        if(nodeCurrent == nodeMeta) {nodeMeta->isAncestor = true; break;}

        // Usun ostatniego Noda z listy otwartej
        listaOtwarta.pop_back();

        // Dodaj aktualnego Noda do listy zamknietej
        listaZamknieta.push_back(nodeCurrent);

        for (Node* nodeSasiad : nodeCurrent->vecSasiedzi){

            // Oznacz sasiada jako odwiedzony Node
            // dla wygody malowania mapy
            nodeSasiad->beenVisited = true;

            // Jesli sasiad jest przeszkoda to go pomin
            if (nodeSasiad->isObstacle) continue;

            // Sprawdzenie czy sasiad jest na liscie zamknietej
            bool inClosedList = (std::find(listaZamknieta.begin(), listaZamknieta.end(), nodeSasiad) != listaZamknieta.end());
            if(inClosedList) continue; // Jesli sasiad jest na zamknietej liscie, to go pomin

            float pot_G_score = nodeCurrent->kosztG + 1;

            // Sprawdzenie czy sasiad jest na liscie zamknietej
            bool inOpenList = (std::find(listaOtwarta.begin(), listaOtwarta.end(), nodeSasiad) != listaOtwarta.end());
            if(!inOpenList) listaOtwarta.push_back(nodeSasiad); // Jesli sasiad nie jest na liscie otwartej, to go dodaj

            // Jesli potencjalny kosztG do sasiada jest wiekszy lub rowny to go pomin
            else if (pot_G_score >= nodeSasiad->kosztG) continue;

            nodeSasiad->rodzic = nodeCurrent;
            nodeSasiad->kosztG = nodeCurrent->kosztG + 1; // Koszt przeskoku do sasiada to zawsze 1
            nodeSasiad->kosztL = nodeSasiad->kosztG + odleglosc(nodeSasiad, nodeMeta);
        }
    }
    // Oznaczanie Nodow nalezacych do koncowej trasy,
    // jako jeden z przodkow dla wygody malowania mapy
    Node* przodek = listaZamknieta.back();
    while(przodek){
        przodek->isAncestor = true;
        przodek = przodek->rodzic;
    }
    return listaZamknieta;
}
