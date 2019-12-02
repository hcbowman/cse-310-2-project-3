#include<fstream>
#include<limits>

#include <sstream>
#include <iomanip>

#include <cmath> 
#include <cstdlib>

#include"adjacency_list.hpp"

//#define DATA_SIZE sizeof(float)
#define FILE_SIZE 3969 //In number of floating point values

std::string to_format(const int number) {
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << number;
    return ss.str();
}

void get_contents(float (&sic_array)[3969][832], int &total, int &ice, int &land, int &missing) {

    int year = 1990; //1990 through 2005, so 0 to 15
    int week = 1; //1 through 52




    // 16 years times 52 weeks = 832 
    for (int t = 0; t < 832; t++) {

        float temp = 0;
        int file_pos = 0;

        if (week > 52) {
            year++;
            week = 1;
        }


        std::ifstream file("CS310_project_subregion/" + std::to_string(year) + "/Beaufort_Sea_diffw" + to_format(week) + "y" + std::to_string(year) + "+landmask", std::ios::in);

        for(int i = 0; i < FILE_SIZE; i++) {

            if (file_pos == FILE_SIZE) {
                break;
            }

            file.read( (char*)&temp, sizeof(temp) );

            //std::cout << "data:" << temp << "\n";

            if (temp < (float)100) {
                sic_array[i][t] = temp;
                ice++;
            }
            else if (temp > (float)167 && temp < (float)169) {
                i--;
                land++;
            }
            else if (temp > (float)156 && temp < (float)158) {
                i--;
                missing++;
            }


            total++;

            file_pos++;
        }

        file.close();

        week++;
    }

}

int main() {

    //Disable synchronization between the C and C++ standard streams daisea
	std::ios::sync_with_stdio(false);

    int total;
    int ice;
    int land;
    int missing;

    int edges_95 = 0;
    int edges_925 = 0;
    int edges_90 = 0;
    int total_r_values = 0;

    float x_mean[3969];
    float s_xx[3969];
    static float sic_array[3969][832]; //[63*63][16*52] 0...62 is row 1

    adjacency_list graph95;
    adjacency_list graph925;
    adjacency_list graph90;


    //get_contents(sic_array,total,ice,land,missing);


    //############################################

    int year = 1990; //1990 through 2005, so 0 to 15
    int week = 1; //1 through 52


    // 16 years times 52 weeks = 832 
    for (int t = 0; t < 832; t++) {

        float temp = 0;
        int file_pos = 0;

        if (week > 52) {
            year++;
            week = 1;
        }


        std::ifstream file("CS310_project_subregion/" + std::to_string(year) + "/Beaufort_Sea_diffw" + to_format(week) + "y" + std::to_string(year) + "+landmask", std::ios::in);

        for(int i = 0; i < FILE_SIZE; i++) {

            if (file_pos == FILE_SIZE) {
                break;
            }

            file.read( (char*)&temp, sizeof(temp) );

            //std::cout << "data:" << temp << "\n";

            if (temp < (float)100) {
                sic_array[i][t] = temp;
                ice++;
            }
            else if (temp > (float)167 && temp < (float)169) {
                i--;
                land++;
            }
            else if (temp > (float)156 && temp < (float)158) {
                i--;
                missing++;
            }


            total++;

            file_pos++;
        }

        file.close();

        week++;
    }


    //##############################################

    //get means(x bar)
    for (int i = 0; i < 3969; i++) {

        float sum = 0;

        for (int t = 0; t < 832; t++) {

            sum += sic_array[i][t];
        }

        x_mean[i] = (sum / 832);
        
    }

    //get s_xx
    for (int i = 0; i < 3969; i++) {
        float sum = 0;

        for (int t = 0; t < 832; t++) {
            float var = 0;
            float var2 = 0;

            var = (sic_array[i][t] - x_mean[i]);

            var2 = (var*var);

            sum += var2;
        }
        
        s_xx[i] = sum;

    }

    //get Pearson Correlation Coecient
    for (int xx = 0; xx < 3186 ; xx++) {


        for (int yy = (xx + 1); yy < 3186 ; yy++) {

            float r = 0;
            float sqrt_val = 0;
            float var = 0;
            float s_xy_sum = 0;


            for (int t = 0; t < 832; t++) {

                float var = 0;

                var = (sic_array[xx][t] - x_mean[xx])*(sic_array[yy][t] - x_mean[yy]) ;

                s_xy_sum += var;
            }

            sqrt_val= std::sqrt( (s_xx[xx] * s_xx[yy]) ) ;

            r =  std::abs( (s_xy_sum / sqrt_val) );
            total_r_values++;


            if ( r > (float).95) {
                edges_95++;
                graph95.add_edge(xx, yy);
            }

            if ( r > (float).925) {
                edges_925++;
                graph925.add_edge(xx, yy);
            }

            if ( r > (float).90) {
                edges_90++;
                graph90.add_edge(xx, yy);
            }

        }

    }




    std::cout << "Histogram for .95" << "\n";
    graph95.print_histogram(23);

    std::cout << "Histogram for .925" << "\n";
    graph925.print_histogram(38);

    std::cout << "Histogram for .90" << "\n";
    graph90.print_histogram(59);

    std::cout << "###########" << "\n";

    std::cout << "components for .95" << "\n";
    graph95.dfs();
    graph95.print_components();

    std::cout << "components for .925" << "\n";
    graph925.dfs();
    graph925.print_components();

    std::cout << "components for .90" << "\n";
    graph90.dfs();
    graph90.print_components();

    /* std::ofstream fileX1;

    fileX1.open("X1.csv", std::ios::out);
    for (int t = 0; t < 832; t++) {

        for (int n = 0; n < 3969; n++) {
            fileX1 << sic_array[n][t] << ",";

        }
        fileX1 <<"\n";

    }
    fileX1.close(); */
    


    return 0;
}