#include <iostream>

#include <string.h>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iomanip>

int priority(std::string line);


int main(int argc, char *argv[]){


    std::string line;
    std::ifstream myfile;
    std::string currentLine;
    int total = 0;


    myfile.open(argv[1], std::ios::in);

    if (myfile.is_open()){
        while ( getline (myfile,line)){
            currentLine = line;
            total += priority(currentLine);            

        }
        myfile.close();
    }


    std::cout<<"Total: "<<total<<std::endl;
    return 0;
}

int priority(std::string line){
    std::string firstHalf = line.substr(0, line.length()/2);
    std::string secondHalf = line.substr(line.length()/2);
    std::cout<<firstHalf<<" "<<secondHalf<<std::endl;
    int sum = 0;

    for (int i = 0; i < firstHalf.length(); i++){
        for (int j = 0; j <secondHalf.length(); j++){
            if (firstHalf.at(i) == secondHalf.at(j)){
               if (int(firstHalf.at(i)) < 91){
                sum = int(firstHalf.at(i)) - 38;
                std::cout<<"sum "<<sum<<std::endl;

               }else{
                sum = int(firstHalf.at(i)) - 96;
                  std::cout<<"sum "<<sum<<std::endl;

               }
              // std::cout<<int(firstHalf.at(i)) << " " <<int(secondHalf.at(j))<<std::endl;

            }
        }
    }
    return sum;
}


