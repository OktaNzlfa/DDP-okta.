#include <iostream>
#include <stdlib.h>
using namespace std;

char papan[3][3] = {{'1','2','3'},
                    {'4','5','6'},
					{'7','8','9'}};
int pilih;
int baris,kolom;
char turn = 'X';
bool draw = false;

void display_papan(){
    cout<<"\nPEMAIN - 1 [X]\t PEMAIN - 2 [O]"<<endl;
    cout<<"\t\t     |     |     "<<endl;
    cout<<"\t\t  "<<papan[0][0]<<"  |  "<<papan[0][1]<<"  |  "<<papan[0][2]<<" "<<endl;
    cout<<"\t\t_____|_____|_____"<<endl;
    cout<<"\t\t     |     |     "<<endl;
    cout<<"\t\t  "<<papan[1][0]<<"  |  "<<papan[1][1]<<"  |  "<<papan[1][2]<<" "<<endl;
    cout<<"\t\t_____|_____|_____"<<endl;
    cout<<"\t\t     |     |     "<<endl;
    cout<<"\t\t  "<<papan[2][0]<<"  |  "<<papan[2][1]<<"  |  "<<papan[2][2]<<" "<<endl;
    cout<<"\t\t     |     |     "<<endl;
}

void player_turn(){
    if(turn == 'X'){
        cout<<"\n\tPemain - 1 [X] pilih kotak : ";
    }
    else if(turn == 'O'){
        cout<<"\n\tPemain - 2 [O] pilih kotak : ";
    }

    cin>> pilih;
    cout<<endl;

    switch(pilih){
        case 1: baris=0; kolom=0; break;
        case 2: baris=0; kolom=1; break;
        case 3: baris=0; kolom=2; break;
        case 4: baris=1; kolom=0; break;
        case 5: baris=1; kolom=1; break;
        case 6: baris=1; kolom=2; break;
        case 7: baris=2; kolom=0; break;
        case 8: baris=2; kolom=1; break;
        case 9: baris=2; kolom=2; break;
        default:
            cout<<"\tSalah langkah!\n";
    }

    if(turn == 'X' && papan[baris][kolom] != 'X' && papan[baris][kolom] != 'O'){
        papan[baris][kolom] = 'X';
        turn = 'O';
    }else if(turn == 'O' && papan[baris][kolom] != 'X' && papan[baris][kolom] != 'O'){
        papan[baris][kolom] = 'O';
        turn = 'X';
    }else {
        cout<<"\tKotak sudah terisi\n \tSilahkan pilih kotak yang lain!!\n\n";
        player_turn();
    }
    display_papan();
}

bool gameover(){
    for(int i=0; i<3; i++)
    if(papan[i][0] == papan[i][1] && papan[i][0] == papan[i][2] || papan[0][i] == papan[1][i] && papan[0][i] == papan[2][i])
    return false;

    if(papan[0][0] == papan[1][1] && papan[0][0] == papan[2][2] || papan[0][2] == papan[1][1] && papan[0][2] == papan[2][0])
    return false;

    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    if(papan[i][j] != 'X' && papan[i][j] != 'O')
    return true;

    draw = true;
    return false;
}

int main(){
    cout<<"\t\tGAME--TICK--TAC--TOE";
    cout<<"\n\t\tUNTUK 2 PEMAIN\n";
    while(gameover()){
        display_papan();
        player_turn();
        gameover();
    }
    if(turn == 'X' && draw == false){
        cout<<"\n\nSelamat!! Pemain dengan simbol 'O' telah memenangkan game!!";
    }
    else if(turn == 'O' && draw == false){
        cout<<"\n\nSelamat!! Pemain dengan simbol 'X' telah memenangkan game!!";
    }
    else
    cout<<"\n\nGAME DRAW!!!\n\n";
} 
