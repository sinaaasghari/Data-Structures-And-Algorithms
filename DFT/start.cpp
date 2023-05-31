//Sina Asghari
//DFT Project
#include <unistd.h>
#include<bits\stdc++.h>
using namespace std;

int N;
vector<complex<double> > input, output, Omega;
complex<double> sum;
double INPUTS_real, INPUTS_img;
double Omg_real , Omg_img;
int main(){
    cout << "Enter Polynomial length: ";
    cin >> N;
    cout <<"Ex for 2 Number (4 + 3i) and (2 + 1i) :\n4 3\n2 1" << endl;
    sleep(4);
    system("cls");
    cout << "Enter " << N << " Complex Number:\n";
    for(int i = 0; i < N; i++){
        cin >> INPUTS_real >> INPUTS_img;
        input.push_back(complex<double> (INPUTS_real, INPUTS_img));
        Omg_real = cos(2 * M_PI * i / N);
        Omg_img = -sin(2 * M_PI * i / N);
        Omega.push_back(complex<double> (Omg_real, Omg_img));
    }
    for(int i = 0; i < N; i++){
        sum = (0, 0);
        for(int j = 0; j < N ; j++){
            sum += input[j] * pow(Omega[i], j);
        }
        output.push_back(sum);
    }
    for(int i = 0; i < N; i++){
        cout << output[i];
    }
    return 0;
}