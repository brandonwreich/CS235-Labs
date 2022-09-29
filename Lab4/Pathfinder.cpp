#include "Pathfinder.h"

std::string Pathfinder::toString() const
{
    // Declare variables
    std::stringstream ss;

    // Iterate through depth
    for (int depth = 0; depth < DEPTH_SIZE; depth++)
    {
        // Iterate through rows
        for (int row = 0; row < ROW_SIZE; row++)
        {
            // Iterate through columns
            for (int col = 0; col < COLUMN_SIZE; col++)
            {
                // Print maze
                ss << maze_grid[depth][row][col];
            }

            ss << std::endl;
        }

        ss << std::endl;
    }

    // Return maze
    return ss.str();
}

void Pathfinder::createRandomMaze()
{
}

bool Pathfinder::importMaze(std::string file_name)
{
    // Delcare variables
    std::ifstream file(file_name.c_str());
    std::string line;
    int value;

    // Print status message
    std::cout << "Import maze from " << file_name << std::endl;

    // If file is open
    if (file.is_open())
    {
        // Iterate to fill depth
        for (int depth = 0; depth < DEPTH_SIZE; depth++)
        {
            // Iterate to fill rows
            for (int row = 0; row < ROW_SIZE; row++)
            {
                // Read line
                getline(file, line);
                std::stringstream ss(line);
                // Iterate to fill columns
                for (int col = 0; col < COLUMN_SIZE; col++)
                {
                    // Fill grid
                    ss >> value;
                    std::cout << "[" << depth << "][" << row << "][" << col << "]=" << value << std::endl;
                    maze_grid[depth][row][col] = value;
                }
            }

            // Skip next line
            getline(file, line);
        }
    }
    else
    {
        // Print error message
        std::cout << file_name << " failed to open" << std::endl;

        return false;
    }

    return true;
}

std::vector<std::string> Pathfinder::solveMaze()
{
    // Call find maze path function
    findMazePath(maze_grid, 0, 0);

    // Iterate through solution
    for (auto s : solution)
    {
        // Print solution
        std::cout << s << std::endl;
    }

    // Return solution
    return solution;
}

bool Pathfinder::findMazePath(int grid[DEPTH_SIZE][ROW_SIZE][COLUMN_SIZE], int r, int c)
{

    return true;
}