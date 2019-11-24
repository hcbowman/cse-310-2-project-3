#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<limits>

#define DATA_SIZE sizeof(float)

void get_contents(std::vector<float> &data) {

    float temp;
    int total;
    int ice;
    int land;
    int missing;

    std::ifstream file("CS310_project_subregion/1990/Beaufort_Sea_diffw01y1990+landmask", std::ios::in);
    //std::ifstream file("CS310_project_subregion/recitationExercise", std::ios::in);


    //Gets file length
    file.ignore( std::numeric_limits<std::streamsize>::max() );
    std::streamsize length = file.gcount();
    file.clear();   //Since ignore will have set eof.
    file.seekg( 0, std::ios_base::beg );
    //std::cout << "length=" << length << "\n"; //DEBUG

    for(unsigned int i = 0; i < (length/DATA_SIZE); i++) {



        file.read( (char*)&temp, sizeof(temp) );
        //std::cout << "data: "<< temp << "\n"; //DEBUG

        if (temp < (float)100) {
            data.push_back(temp);
            ice++;
        }
        else if (temp > (float)167 && temp < (float)169) {
            land++;
        }
        else if (temp > (float)156 && temp < (float)158) {
            missing++;
        }


        total++;
    }

    for (auto &&i : data)
    {
        std::cout << "data:" << i << "\n";

    }

    std::cout << "total:" << total << "\n";
    std::cout << "ice:" << ice << "\n";
    std::cout << "land:" << land << "\n";
    std::cout << "missing:" << missing << "\n";


    file.close();

}


int main() {

    std::vector<float> data;

    
    get_contents(data);




    return 0;
}