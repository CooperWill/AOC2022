#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iomanip>

int calculateWin(char a, char b);


int main(int argc, char *argv[]){


    std::string line;
    std::ifstream myfile;
    const int rockScore = 1;  //A, X
    const int paperScore = 2;//B, Y
    const int scissorScore = 3;//C, Z
    char elfCoice;
    char myChoice;
    int totalScore = 0;

    myfile.open(argv[1], std::ios::in);

    if (myfile.is_open()){
        while ( getline (myfile,line)){
            // std::cout<<"First: "<<line.at(0)<<std::endl;
            // std::cout<<"Second: "<<line.at(2)<<std::endl;
            if (line.at(2) == 'X'){
                totalScore += 1;
                
            }
            if (line.at(2) == 'Y'){
                totalScore += 2;
                
            }
            if (line.at(2) == 'Z'){
                totalScore += 3;
                
            }
            totalScore += calculateWin(line.at(0), line.at(2));
            

            

        }
        myfile.close();
    }


    std::cout<<"Total Score: "<<totalScore<<std::endl;
    return 0;
}

int calculateWin(char a, char b){
    int total = 0;
    if (a == 'A'){
        if (b == 'X'){
            total += 0;
        }
        if (b == 'Y'){
            total += 3;
        }
        if (b == 'Z'){
            total +=6;
        }
    }
        if (a == 'B'){
        if (b == 'X'){
            total += 0;
        }
        if (b == 'Y'){
            total += 3;
        }
        if (b == 'Z'){
            total +=6;
        }
    }
        if (a == 'C'){
        if (b == 'X'){
            total += 0;
        }
        if (b == 'Y'){
            total += 3;
        }
        if (b == 'Z'){
            total +=6;
        }
    }
    return total;

}

//
