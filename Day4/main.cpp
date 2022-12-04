#include <iostream>
#include <boost/algorithm/string.hpp>
#include <string.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iomanip>

int priority(std::string line);
int partOne(std::string line);
int partTwo(std::string line);


int main(int argc, char *argv[]){


    std::string line;
    std::ifstream myfile;
    std::vector<std::string> numbers;
    int part1 = 0;
    int part2 = 0;


    myfile.open(argv[1], std::ios::in);

    if (myfile.is_open()){
        while ( getline (myfile,line)){
           if (line.size() != 0){
            replace(line.begin(), line.end(), '-', ' ');
            replace(line.begin(), line.end(), ',',' ');   
            part1 += partOne(line);
            part2 += partTwo(line);    
           }    

        }
        myfile.close();
    }
   std::cout<<"Total: "<<part1<<std::endl;
   std::cout<<"part 2: "<<part2<<std::endl;

   return 0;
}

int partOne(std::string line){
    int intValues[4];
    int firstStart, firstEnd, secondStart, secondEnd;    
    std::vector<std::string> values;
    boost::split(values, line, boost::is_any_of("\t "));

    firstStart = stoi(values.at(0));
    firstEnd = stoi(values.at(1));
    secondStart = stoi(values.at(2));
    secondEnd = stoi(values.at(3));

    if((firstStart <= secondStart && firstEnd >= secondEnd) || (firstStart >= secondStart && firstEnd <= secondEnd)){
        return 1;
    }

    return 0;

}

int partTwo(std::string line){

    int firstStart, firstEnd, secondStart, secondEnd;
    
    std::vector<std::string> values;
    boost::split(values, line, boost::is_any_of("\t "));

    firstStart = stoi(values.at(0));
    firstEnd = stoi(values.at(1));
    secondStart = stoi(values.at(2));
    secondEnd = stoi(values.at(3));

    if((firstStart <= secondStart && firstEnd >= secondStart) || (secondStart <= firstStart && secondEnd >= firstStart)){
        return 1;
    }

    return 0; 

}