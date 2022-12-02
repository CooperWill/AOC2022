#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>


int calculateWin(char a, char b);


int main(int argc, char *argv[]){


    std::string line;
    std::ifstream myfile;
    int totalScore = 0;

    myfile.open(argv[1], std::ios::in);

    if (myfile.is_open()){
        while ( getline (myfile,line)){
            totalScore += calculateWin(line.at(0), line.at(2));
        }
        myfile.close();
    }

    std::cout<<"Total Score: "<<totalScore<<std::endl;
    return 0;
}

int calculateWin(char a, char b){
    int total = 0;
    if (b == 'X'){
        total += 0;                
    }
    if (b == 'Y'){
        total += 3;
    }
    if (b == 'Z'){
        total += 6;
    }

    if (a == 'A'){
        if (b == 'X'){
            total += 3;
        }
        if (b == 'Y'){
            total += 1;
        }
        if (b == 'Z'){
            total +=2;
        }
    }
   if (a == 'B'){
        if (b == 'X'){
            total += 1;
        }
        if (b == 'Y'){
            total += 2;
        }
        if (b == 'Z'){
            total +=3;
        }
    }
    if (a == 'C'){
        if (b == 'X'){
            total += 2;
        }
        if (b == 'Y'){
            total += 3;
        }
        if (b == 'Z'){
            total +=1;
        }
    }
    return total;

}

//

