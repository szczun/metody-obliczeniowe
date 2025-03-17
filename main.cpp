#include <cmath>
#include <fstream>
#include <gnuplot-iostream/gnuplot-iostream.h>


constexpr double L1 = 1;
const double L2 = 1/sqrt(8);

double calculatePhi(const double&);
void calculateDifferential(const double&, const double&, double&); 

void Euler(){

    double diff = 0.0;
    double delta_t = 0.00001;
    double delta_x = 0.001;

    const int sim_time = 100;
    const int N = static_cast<int>(sim_time/delta_t);


    size_t size = static_cast<size_t>(N);


    std::vector<double> x_pos(size);
    std::vector<double> velocity(size);
    std::vector<double> time(size);

    std::ofstream time_file("time.dat");
    std::ofstream x_file("euler_x.dat");
    std::ofstream v_file("euler_v.dat");

    x_pos[0] = 2.8;
    velocity[0] = 0.0;

    for(size_t i = 0; i < size - 1; i++){
        x_pos[i+1] = x_pos[i] + velocity[i]*delta_t;
        calculateDifferential(delta_x, x_pos[i], diff);
        velocity[i+1] = velocity[i] -(diff*delta_t);
        time[i] = i*delta_t;

        time_file << time[i] << "\n";
        x_file << x_pos[i] << "\n";
        v_file << velocity[i] << "\n";
    }
    time_file.close();
    x_file.close();
    v_file.close();
}

int main(){
    Euler();
}

double calculatePhi(const double& x){
    return -exp(-(x*x)/(L1*L1)) -8*exp(-((x-2)*(x-2))/(L2*L2));
}

void calculateDifferential(const double& delta_x, const double& x_n, double& diff){
    diff = (calculatePhi(x_n + delta_x) - calculatePhi(x_n - delta_x))/(2*delta_x);
} 
