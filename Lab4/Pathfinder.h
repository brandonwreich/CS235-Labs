#pragma once

// Imports
#include "PathfinderInterface.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

// Global Variables
const int DEPTH_SIZE = 5;
const int ROW_SIZE = 5;
const int COLUMN_SIZE = 5;
const int OPENING = 1;
const int WALL = 0;
const int DEADEND = 2; 
const int PATH = 3;

class Pathfinder : public PathfinderInterface {
public:
    // Constructors
    Pathfinder();
    ~Pathfinder() {}

    // Member functions
    std::string toString() const;
    void createRandomMaze();
    bool importMaze(std::string file_name);
    std::vector<std::string> solveMaze();
    bool checkImport(std::string file_name);

protected:
    bool findMazePath(int grid[DEPTH_SIZE][ROW_SIZE][COLUMN_SIZE], int depth, int row, int column);
    int maze_grid[DEPTH_SIZE][ROW_SIZE][COLUMN_SIZE];
    std::vector<std::string> solution;
};