#include <iostream>
#include <fstream>
#include <queue>

int main(int argc, char *argv[]) {
    if (argc == 3) {
        std::cout << "Using data from " << argv[1] << " with a " << argv[2] << " day rolling average" << std::endl;

        //Delcare variables
        std::string line;
        std::ifstream file ("cases.txt");

	    //If file is open
        if (file.is_open()) {
		    //While not at the end of the file
            while(getline(file, line)) {
			    //Print line to console
                std::cout << line << std::endl;
            }

		    //Close the file
            file.close();
        }
        else {
		    //Error handling
            std::cout << "Cannot open file" << std::endl;
        }
    }
    else {
        std::cout << "Invalid arguments. Try again";
    }

    return 0;
}