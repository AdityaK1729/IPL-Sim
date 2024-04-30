#include<iostream>
#include<fstream>
#include<string>
using namespace std;

const string teams[10]={"CSK","DC","GT","KKR","LSG","MI","PBKS","RR","RCB","SRH"};
int main(){
    // struct Data{
    //     int CSK,DC,GT,KKR,LSG,MI,PBKS,RR,RCB,SRH;
    // };

    ifstream din("results.txt");
    int sims[10][10000];
    for(int i=0;i<10000;i++){
        for(int j=0;j<10;j++){
            din>>sims[j][i];
        }
    }
    ofstream dout("prob.csv");
    dout<<"Team,T2psbl,T4psbl\n";
    for(int i=0;i<10;i++){
        dout<<teams[i]<<",";
        int T2=0,T4=0;
        for(int j=0;j<10000;j++){
            if(sims[i][j]<=2) T2++;
            if(sims[i][j]<=4) T4++;
        }
        dout<<T2/100.0<<"%,"<<T4/100.0<<"%\n";
    }
}