#include <iostream>
#include <fstream>
#include <string>

void writeToFile(const std::string& filename, const std::string& content) 
{
    std::ofstream outFile(filename);  
    if (!outFile) 
    {
        std::cerr << "Error opening file for writing.\n";
        return;
    }
    outFile << content << std::endl;
    std::cout << "Data written successfully.\n";
}

void appendToFile(const std::string& filename, const std::string& content) 
{
    std::ofstream outFile(filename, std::ios::app);
    if (!outFile) 
    {
        std::cerr << "Error opening file for appending.\n";
        return;
    }
    outFile << content << std::endl;
    std::cout << "Data appended successfully.\n";
}

void readFromFile(const std::string& filename) 
{
    std::ifstream inFile(filename);
    if (!inFile) 
    {
        std::cerr << "Error opening file for reading.\n";
        return;
    }
    std::string line;
    while (getline(inFile, line)) {
        std::cout << line << std::endl;
    }
}

int main() 
{
    std::string filename = "example.txt";

    writeToFile(filename, "Hello, this is a sample text written to the file.\nWriting another line...");
    readFromFile(filename);

    appendToFile(filename, "Appending a new line to the file.");
    readFromFile(filename);  

    return 0;
}
