#include<iostream>
#include<fstream>
#include<ctime>
#include<random>
#include<string>
#include<algorithm>
using namespace std;
const string teams[10]={"CSK","DC","GT","KKR","LSG","MI","PBKS","RR","RCB","SRH"};
int teamInv(string team){
    if(team=="CSK") return 0;
    if(team=="DC") return 1;
    if(team=="GT") return 2;
    if(team=="KKR") return 3;
    if(team=="LSG") return 4;
    if(team=="MI") return 5;
    if(team=="PBKS") return 6;
    if(team=="RR") return 7;
    if(team=="RCB") return 8;
    if(team=="SRH") return 9;
    else return -1;
}
void pointsTable(int points[10],int sortPoints[10],int posn[10]){
    for(int i=0;i<10;i++){
        sortPoints[i]=points[i];
    }
    sort(sortPoints,sortPoints+10,greater<int>());
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(points[i]==sortPoints[j]){
                posn[i]=j+1;
                break;
            }
        }
    
    }
}
void printTable(int position[10],int points[10]){
    for(int i=1;i<=10;i++){
        for(int j=0;j<10;j++){
            if (position[j]==i){
                cout<<position[j]<<" "<<teams[j]<<" ("<<points[j]<<")\n";
            }
        }
    }
}
struct Match{
    string team1, team2;
    bool winner;
    Match(){
        team1="";
        team2="";
        winner=false;
    }
    Match(string t1, string t2, bool w){
    team1 = t1;
    team2 = t2;
    winner = w;
    }
};
// struct Position{
//     string Team;
//     int position,points;
//     Position(){
//         Team="";
//         position=0;
//         points=0;
//     }
// };
int main(){
    srand(time(NULL));
    Match Matches[70];
    ifstream fin("IPL.txt");
    int startGame=48;
    for(int i=0;i<70;i++){
        fin>>Matches[i].team1>>Matches[i].team2;
    }
    ofstream fout("results.csv");
    ofstream fout1("results.txt");
    for(int i=0;i<10;i++){
        fout<<teams[i]<<",";
    }
    fout<<endl;
    for(int st=0;st<10000;st++){
    ifstream fin2("points.txt");
    int points[10];
    for(int i=0;i<10;i++){
        fin2>>points[i];
    }
    for(int i=startGame-1;i<70;i++){
        int x=rand();
        Matches[i].winner=rand()%2;
        if(Matches[i].winner){
            points[teamInv(Matches[i].team1)]+=2;
        }
        else{
            points[teamInv(Matches[i].team2)]+=2;
        }
    }
    int sortPoints[10],posn[10];

    pointsTable(points,sortPoints,posn);
    // for(int i=0;i<10;i++){
    //     cout<<posn[i]<<":"<<teams[i]<<" "<<points[i]<<endl;
    // }
    
    // printTable(posn,points);
    // cout<<endl<<endl;
    for(int i=0;i<10;i++){
        fout<<posn[i]<<",";
        fout1<<posn[i]<<" ";
    }
    fout<<endl;
    fout1<<endl;
    }
}