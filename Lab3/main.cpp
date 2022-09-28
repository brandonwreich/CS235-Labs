#include <set>
#include <vector>
#include <map>
#include <sstream>
#include <fstream>
#include <iostream>
#include <list>

void write_set_to_file(std::set<std::string> printSet, std::string name) {
    // Declare variables
    std::string filename = name + "_set.txt";
    std::ofstream ofs(filename, std::ios::app);

    // Iterate to end of set
    for (std::set<std::string>::iterator it = printSet.begin(); it != printSet.end(); it++) {
        // Write member to file
        ofs << *it << "\n";
    }
}

void write_vector_to_file(std::vector<std::string> printVector, std::string name) {
    // Declare variables
    std::string filename = name + "_vector.text";
    std::ofstream ofs(filename, std::ios::app);

    // Iterate to end of vector
    for (int i = 0; i < printVector.size(); i++) {
        // Write element to file
        ofs << printVector.at(i) << "\n";
    }
}

void write_map_to_file(std::map<std::string, std::string> printMap, std::string name) {
    // Delcare variables
    std::string filename = name + "_map.txt";
    std::ofstream ofs(filename, std::ios::app);
    std::map<std::string, std::string>::iterator it;

    // Iterate to end of map
    for (it = printMap.begin(); it != printMap.end(); it++) {
        // Write to file
        ofs << it->first << ", " << it->second << "\n";
    }
}


int main(int argc, char *argv[]) {
    // Declare variables
    std::vector<std::string> tokens;
    std::set<std::string> unique;
    std::list<std::string> lst;
    std::map<std::list<std::string>, std::vector<std::string> > wordmap;
    std::list<std::string> state;
    std::string filename = argv[1];
    std::string next_line;
    std::ifstream in(filename + ".txt");
    int M = 2;

    // Read to end of file
    while (getline(in, next_line)) {
        // Declare variables
        std::istringstream iss(next_line);
        std::string token;

        while (iss >> token) {
            // Declare variables
            std::string nopunct = "";

            for (auto &c : token) {
                // Remove Punctuation
                if (isalpha(c)) {
                    nopunct += c;
                }
            }

            // Add to data
            tokens.push_back(nopunct);
            lst.push_back(nopunct);
            unique.insert(nopunct);
        }
    }

    write_set_to_file(unique, filename);
    write_vector_to_file(tokens, filename);

    std::cout << "Numnber of words: " << tokens.size() << std::endl;
    std::cout << "Number of unique words: " << unique.size() << std::endl;

    for (int i = 0; i < M; i++) {
        state.push_back("");
    }

    for (std::list<std::string>::iterator it = lst.begin(); it != lst.end(); it++) {
        wordmap[state].push_back(*it);
        state.push_back(*it);
        state.pop_front();
    }

    state.clear();
    srand(time(NULL));

    for (int i = 0; i < M; i++) {
        state.push_back("");
    }
    for (int i = 0; i < 100; i++) {
        int ind = rand() % wordmap[state].size();
        std::cout << wordmap[state][ind] << " ";
        state.push_back(wordmap[state][ind]);
        state.pop_front();
    }

    return 0;
}