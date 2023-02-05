# A_star_implementation
My personal implementation of pathfinding algorithm A*

Program loads a map (grid 20x20) from a .txt file and prints out in console, the shortest way from Start to Finish (avoiding obstacles), using A* algorithm.

class Node - represents vortex (point) on a grid.

Function oblicz_Agwiazdka(int wymiar, Node *tabN) - calculates path, sets parameter 'isAncestor' to true, for Nodes that belong to the shortest path and function returns closed list of Nodes.

Function pokaz_mape(int wymiar, Node *tabN) - prints out grid in console.

Function wyswietl_noda(Node node) -  prints out information in console, about given Node.

Thanks
