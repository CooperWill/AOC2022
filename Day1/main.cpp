#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>




int main(int argc, char *argv[]){

    int sum = 0;
    int largest = -1;
    std::vector<int> totals;
    std::string line;
    std::ifstream myfile;

    myfile.open(argv[1], std::ios::in);

    if (myfile.is_open()){
        while ( getline (myfile,line)){
            if (line != ""){
                sum += std::stoi(line);
            
            }else{
                totals.push_back(sum);
                if(sum > largest){
                    largest = sum;
                }
            sum = 0;
            }
        }
        myfile.close();
    }

    std::sort(totals.begin(), totals.end());
    int calories = totals.at(totals.size()-1) + totals.at(totals.size()-2) + totals.at(totals.size()-3);
    std::cout<<"Most Calories: "<<largest<<std::endl;
    std::cout<<"Top 3 Calories: "<<calories<<std::endl;

    return 0;
}