#include<iostream>
#define M 20
#define Time 1
#define dt 0.01
#define dx 0.1
#define D 0.1

using namespace std;

void DHB2(float *T, float *dT){
    int i;
    float c, l, r;
    for(i = 0; i < M-1; i++){
        c = *(T+i);
        l = (i == 0) ? 100 : *(T+i-1);
        r = (i == M-1) ? 25 : *(T+i+1);
        *(dT+i) = D * (l-2*c+r)/(dx*dx);
    }
}


void printT(float * arr){
    for(int i = 0; i < M; i++){
        cout << arr[i] <<  " ";
    }
    cout<<endl;
}

int main(){
    float *T = new float[1000];
    for(int i = 0; i < M; i++)
        T[i] = 25;
    printT(T);
    float *dT = new float[1000];
    int Ntime = Time / dt;
    for(int t = 0; t <= Ntime; t++){
        DHB2(T, dT);
        for(int i = 0; i< M; i++)
            *(T+i) = *(T+i) + *(dT+i)*dt*D;
        // t = t+dt;
        printT(T);
    }
    
    // return 0;
}