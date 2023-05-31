//Sina Asghari

//LU decomposition 
#include<iostream>
#include<iomanip>
using namespace std;
int Size;
float A[1000][1000];
float B[1000][2];
float U[1000][1000];
float L[1000][1000];
float D[1000][2];
float X[1000][2];
class LU{
    public:
    void getmarixZarayeb(int size){
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                cin >> A[i][j];
            }
        }
    }
    void getmatrixJavab(int size){
        for(int i = 0; i < size; i++){
            cin >> B[i][0];
        }
    }
    void saveU(int size){
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                U[i][j] = A[i][j]; 
            }
        }
    }
    void saveL(int size){
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                L[i][j] = A[i][j]; 
            }
        }
    }
    void ReadyL(int size){
        saveL(size);
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                if(i == j){
                    L[i][j] = 1;
                }
                else{
                    L[i][j] = 0;
                }
            }
    }

}
    void ConvertToUL(int size){
        saveU(size);
        ReadyL(size);
        int cnt = 0;
        int start = 1;
        for(int i = start; i < size; i++){
            float t = U[i][cnt] / U[cnt][cnt];
            L[i][cnt] = t;
                for(int k = 0; k < size; k++){
                    U[i][k] -= t * U[cnt][k];
            }
            if(i == size - 1){
                start++;
                i = start - 1;
                if(start == size){
                    break;
                }
                cnt++;
            }
            

        }

    }
    void creatD(){
        int cc = 1;
        D[0][0] = B[0][0];
        cout << B[0][0] << endl << endl;
        for(int i = 1; i < Size; i++){
            float sum = 0;
            for(int j = 0; j < i; j++){
                sum += D[j][0] * L[i][j];
                cc++;
            }
            D[i][0] = B[i][0] - sum;
            sum = 0.0;
        }
    }
    void findX(){
        X[Size - 1][0] = D[Size - 1][0] / U[Size - 1][Size - 1];
        for(int i = Size - 2; i >=0; i--){
           float sum = 0;
           for(int j = i + 1; j < Size; j++){
            sum += U[i][j] * X[j][0];
           }
           X[i][0] =  (D[i][0] - sum) / U[i][i];
           sum = 0.0;  
        }
    }
};

int main(){
    LU test;
    cout << "Enter Matrix Size: " << endl;
    cin >> Size;
    cout << "Enter Elements of Matrix of coefficients:" << endl;
    test.getmarixZarayeb(Size);
    cout << "Enter Elements of Matrix Javab =): " << endl;
    test.getmatrixJavab(Size);
    test.ConvertToUL(Size);
    test.creatD();
    test.findX();
    cout <<"Answer:  " << endl;
    for(int i = 0; i < Size; i++){
        cout <<  fixed << setprecision(3) << X[i][0] << " "<< endl;
    }
    return 0;
}






/*
3
3 -0.1 -0.2
0.1 7 -0.3
0.3 -0.2 10
7.85
-19.3
71.4
*/