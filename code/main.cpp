#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<limits>

#define DATA_SIZE sizeof(float)

void get_contents() {



}

int main() {

    float data;

    std::ifstream file("CS310_project_subregion/1990/Beaufort_Sea_diffw01y1990+landmask", std::ios::in);
    //std::ifstream file("CS310_project_subregion/recitationExercise", std::ios::in);


    file.ignore( std::numeric_limits<std::streamsize>::max() );
    std::streamsize length = file.gcount();
    file.clear();   //  Since ignore will have set eof.
    file.seekg( 0, std::ios_base::beg );

    std::cout << "length=" << length << "\n";

    for(int i = 0; i < (length/DATA_SIZE); i++) {

        file.read( (char*)&data, sizeof(data) );
        std::cout << "data: "<< data << "\n";

    }


    file.close();


    return 0;
}