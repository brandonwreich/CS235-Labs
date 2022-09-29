#include "Pathfinder.h"

int main(int argc, char *argv[]) {

    Pathfinder* pathptr = NULL;

    pathptr = new Pathfinder();
    pathptr->importMaze("Mazes/Solvable1.txt");

    std::cout << pathptr->toString();


    return 0;
}