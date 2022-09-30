#include "Pathfinder.h"

Pathfinder::Pathfinder()
{
    srand(time(NULL));

    for (int depth = 0; depth < DEPTH_SIZE; depth++)
    {
        for (int row = 0; row < ROW_SIZE; row++)
        {
            for (int column = 0; column < COLUMN_SIZE; column++)
            {
                maze_grid[depth][row][column] = 1;
            }
        }
    }
}

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
            for (int column = 0; column < COLUMN_SIZE; column++)
            {
                // Print maze
                ss << maze_grid[depth][row][column];

                if (column < COLUMN_SIZE - 1)
                {
                    ss << " ";
                }
            }

            ss << std::endl;
        }

        if (depth < DEPTH_SIZE - 1)
        {
            ss << std::endl;
        }
    }

    // Return maze
    return ss.str();
}

void Pathfinder::createRandomMaze()
{
    // Iterate through depth
    for (int depth = 0; depth < DEPTH_SIZE; depth++)
    {
        // Iterate through rows
        for (int row = 0; row < ROW_SIZE; row++)
        {
            // Iterate through columns
            for (int column = 0; column < COLUMN_SIZE; column++)
            {
                // Fill maze
                maze_grid[depth][row][column] = rand() % 2;
            }
        }
    }

    // Set entrance
    maze_grid[0][0][0] = 1;

    // Set exit
    maze_grid[4][4][4] = 1;
}

bool Pathfinder::importMaze(std::string file_name)
{
    // Delcare variables
    std::ifstream file(file_name.c_str());
    std::string line;
    int value;
    int temp_maze[DEPTH_SIZE][ROW_SIZE][COLUMN_SIZE];

    // Print status message
    std::cout << "Import maze from " << file_name << std::endl;

    // If file is open
    if (file.is_open())
    {
        if (checkImport(file_name))
        {
            // Iterate through depth
            for (int depth = 0; depth < DEPTH_SIZE; depth++)
            {
                // Iterate through rows
                for (int row = 0; row < ROW_SIZE; row++)
                {
                    // Read line
                    getline(file, line);
                    std::stringstream ss(line);

                    // Iterate through columns
                    for (int column = 0; column < COLUMN_SIZE; column++)
                    {
                        // Fill grid
                        ss >> value;
                        maze_grid[depth][row][column] = value;
                    }
                }

                // Skip next line
                getline(file, line);
            }
        }
    }

    return true;
}

std::vector<std::string> Pathfinder::solveMaze()
{
    // Clear previous solutions
    solution.clear();

    // Call find maze path function
    findMazePath(maze_grid, 0, 0, 0);

    // Iterate through solution
    // for (auto s : solution)
    // {
    //     // Print solution
    //     std::cout << s << std::endl;
    // }

    // Return solution
    return solution;
}

bool Pathfinder::findMazePath(int grid[DEPTH_SIZE][ROW_SIZE][COLUMN_SIZE], int depth, int row, int column)
{
    // Print status
    // std::cout << "Find maze path: [" << depth << "][" << row << "][" << column << "]" << std::endl;
    // std::cout << this->toString();

    // If cell is out of bounds
    if (depth < 0 ||
        row < 0 ||
        column < 0 ||
        depth >= DEPTH_SIZE ||
        row >= ROW_SIZE ||
        column >= COLUMN_SIZE)
    {
        return false;
    }
    // If cell is at a dead end or wall
    else if (grid[depth][row][column] != OPENING)
    {
        return false;
    }
    else if (depth == DEPTH_SIZE - 1 &&
             row == ROW_SIZE - 1 &&
             column == COLUMN_SIZE - 1)
    {
        // Cell is exit
        //grid[depth][row][column] = OPENING;

        // Add to solution
        solution.push_back("(" + to_string(depth) + ", " + to_string(row) + ", " + to_string(column) + ")");

        return true;
    }
    else
    {
        // Tentatively mark cell on path
        //grid[depth][row][column] = PATH;

        if (findMazePath(grid, depth - 1, row, column) || // up
            findMazePath(grid, depth + 1, row, column) || // down
            findMazePath(grid, depth, row - 1, column) || // forward
            findMazePath(grid, depth, row + 1, column) || // backword
            findMazePath(grid, depth, row, column - 1) || // left
            findMazePath(grid, depth, row, column + 1))   // right
        {
            // Add to solution
            solution.push_back("(" + to_string(depth) + ", " + to_string(row) + ", " + to_string(column) + ")");

            //grid[depth][row][column] = OPENING;

            return true;
        }
        else
        {
            // Dead end
            //grid[depth][row][column] = WALL;

            return false;
        }
    }
}

bool Pathfinder::checkImport(std::string file_name)
{
    // Delcare variables
    std::ifstream file(file_name.c_str());
    std::string line;
    int value;
    int count = 0;
    int temp_grid[DEPTH_SIZE][ROW_SIZE][COLUMN_SIZE];

    // If file is open
    if (file.is_open())
    {
        // Iterate through depth
        for (int depth = 0; depth < DEPTH_SIZE; depth++)
        {
            // Iterate through rows
            for (int row = 0; row < ROW_SIZE; row++)
            {
                // Read line
                getline(file, line);
                std::stringstream ss(line);

                // Iterate through columns
                for (int column = 0; column < COLUMN_SIZE; column++)
                {
                    if (!file.eof())
                    {
                        // Fill grid
                        ss >> value;

                        // If value doesn't equal "1" or "0"
                        if ((int)value != 0 && (int)value != 1)
                        {
                            return false;
                        }

                        // Fill maze
                        temp_grid[depth][row][column] = value;
                    }
                }
            }

            // Skip next line
            getline(file, line);
        }

        // If there isn't an entrance and exit
        if (temp_grid[0][0][0] != 1 && temp_grid[4][4][4] != 1)
        {
            return false;
        }
    }

    return true;
}