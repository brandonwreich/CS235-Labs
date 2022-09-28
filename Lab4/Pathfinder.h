#pragma once

// Imports
#include "PathfinderInterface.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

// Global Variables
const int ROW_SIZE = 5;
const int COLUMN_SIZE = 5;
const int BACKGROUND = 1;
const int WALL = 0;
const int TEMPORARY = 2; // Used to show this path has been explored
const int PATH = 3;

class Pathfinder : public PathfinderInterface {
public:
    // Constructors
    Pathfinder() {}
    ~Pathfinder() {}

    // Member functions
    std::string toString();
    void createRandomMaze();
    bool importMaze(std::string file_name);
    std::vector<std::string> solveMaze();

protected:
    bool findMazePath(int grid[ROW_SIZE][COLUMN_SIZE], int r, int c);
    int maze_grid[ROW_SIZE][COLUMN_SIZE];
    std::vector<std::string> solution;
};