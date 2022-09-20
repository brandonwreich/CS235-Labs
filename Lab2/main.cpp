#include <iostream>
#include <fstream>
#include <queue>

void printQueue(std::queue<int> queue) {

    while(!queue.empty()) {
        std::cout << queue.front() << ", ";
        queue.pop();
    }

    std::cout << std::endl;
}

int findAverage(std::queue<int> queue) {
    int average = 0;
    int count = 0;

    while(!queue.empty()) {
        average += queue.front();
        queue.pop();
        count++;
    }

    average /= count;

    return average;
}

int main(int argc, char *argv[]) {
    std::queue<int> averages;
    std::queue<int> temp;
    int count = 0;
    

    if (argc == 3) {
        std::cout << "Using data from " << argv[1] << " with a " << argv[2] << " day rolling average" << std::endl;

            //Delcare variables
            std::string line;
            int number;
            std::ifstream file (argv[1]);

	        //If file is open
            if (file.is_open()) {
		        //While not at the end of the file
                for(int i = 0; i < atoi(argv[2]); i++) {
			        getline(file, line);
                    number = stoi(line);
                    averages.push(number);
                }

                printQueue(averages);
                std::cout << "Average " << findAverage(averages) << std::endl;

                while(getline(file, line)) {
                    averages.pop();
                    number = stoi(line);
                    averages.push(number);

                    printQueue(averages);
                    std::cout << "Average " << findAverage(averages) << std::endl;
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