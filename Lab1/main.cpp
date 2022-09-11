#include "TodoList.h"

#include <iostream>
#include <fstream>

void TodoList::add(std::string _duedate, std::string _task) {
		//Declare variables
    std::ofstream ofs ("TODO-List.txt", std::ios::app);

		//If file is open
    if(ofs.is_open()) {
				//Write to file
        ofs << _duedate;
        ofs << "\n";
        ofs << _task;
        ofs << "\n";

				//Close file
        ofs.close();
    }
    else {
				//Error handling
        std::cout << "Cannot open file" << std::endl;
    }
}

int TodoList::remove(std::string _task) {
  std::string line;
	std::ifstream file ("TODO-List.txt");
	std::ofstream tempFile ("Temp.txt");

	std::cout << "Variables declared" << endl;
	
	if (file.is_open() && tempFile.is_open()) {

		std::cout << "Files open" << endl;
		
		while (getline(file, line)) {
			
			if (line.compare(_task) != 0) {
         tempFile << line << std::endl;
				}
		}

		tempFile.close();
		file.close();

		std::cout << "Files closed" << std::endl;
		
		remove("TODO-List.txt");
		rename("Temp.txt", "TODO-List.txt");

		std::cout << "Files removed" << std::endl;
	}
	else {
		return 0;
	}

	return 1;
}

void TodoList::printTodoList() {
		//Delcare variables
    std::string line;
    std::ifstream file ("TODO-List.txt");

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

void TodoList::printDaysTasks(std::string _date) {
    //Delcare variables
    std::string line;
		int lineNumber = 0;
    std::ifstream file ("TODO-List.txt");

		//If file is open
    if (file.is_open()) {
				//While not at the end of the file
        while(getline(file, line)) {
					
						//If line matches the date
						if(line.compare(_date) == 0) {
							
							//Print next line to console
							getline( file, line);
							std::cout << line << std::endl;
        		}
					}
			
					//Close the file
        	file.close();
			}
    else {
				//Error handling
        std::cout << "Cannot open file" << std::endl;
    }
}

int main(int argc, char *argv[]) {
    //Init class
    TodoList list;

    std::string command(argv[1]);

    if(command.compare("add") == 0) {
        std::string date(argv[2]);
        std::string task(argv[3]);

        list.add(date, task);
    }
    else if (command.compare("remove") == 0) {
        std::string task(argv[2]);

        list.remove(task);
    }
    else if (command.compare("printList") == 0) {
        list.printTodoList();
    }
    else if (command.compare("printDay") == 0) {
        std::string date(argv[2]);

        list.printDaysTasks(date);
    }

    return 0;
}