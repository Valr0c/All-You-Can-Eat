#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int random(){
    return rand() % 8 + 2;
}

bool cek1(int eat1x, int eat1y, int eat2x, int eat2y, int eat3x, int eat3y, int px, int py){
    if((eat1x != eat2x && eat1y != eat2y) || (eat1x != eat3x && eat1y != eat3y) || (eat1x != px && eat1y != py)){
        return true;
    }else{
        return false;
    }
}
bool cek2(int eat1x, int eat1y, int eat2x, int eat2y, int eat3x, int eat3y, int px, int py){
    if((eat2x != eat1x && eat2y != eat1y) || (eat2x != eat3x && eat2y != eat3y) || (eat2x != px && eat2y != py)){
        return true;
    }else{
        return false;
    }
}
bool cek3(int eat1x, int eat1y, int eat2x, int eat2y, int eat3x, int eat3y, int px, int py){
    if((eat3x != eat1x && eat3y != eat1y) || (eat3x != eat2x && eat3y != eat2y) || (eat3x != px && eat3y != py)){
        return true;
    }else{
        return false;
    }
}

void ranking(int score, int &rank1, int &rank2, int &rank3){
    cout << "Score akhir : " << score << endl;
    if(score > rank1){
        rank1 = score;
        cout << "Masuk ke Leaderboard" << endl << endl;
    }else if(score > rank2){
        rank2 = score;
        cout << "Masuk ke Leaderboard" << endl << endl;
    }else if(score > rank3){
        rank3 = score;
        cout << "Masuk ke Leaderboard" << endl << endl;
    }else{
        cout << "Tidak masuk ke Leaderboard" << endl << endl;
    }
}

void arena(int px, int py, int eat1x, int eat1y, int eat2x, int eat2y, int eat3x, int eat3y, int time, int score){
    cout << "==All You Can Eat==" << endl;
    cout << "Time : " << time << endl;
    cout << "Score : " << score << endl;
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++){
            if(i == 1 || j == 1 || i == 10 || j == 10){
                cout << "* ";
            }else if(i == py && j == px){
                cout << "P ";
            }else if((i == eat1y && j == eat1x) || (i == eat2y && j == eat2x) || (i == eat3y && j == eat3x)){
                cout << "o ";
            }else{
                cout << "  ";
            }
        }
        cout << endl;
    }
}

void leaderboard(int rank1,int rank2,int rank3){
    cout << "== Leaderboard ==" << endl;
    cout << "1. Score : " << rank1 << endl;
    cout << "2. Score : " << rank2 << endl;
    cout << "3. Score : " << rank3 << endl;
    cout << endl;
}

int main()
{
    srand(time(NULL));
    int input;
    int eat1x = random();
    int eat1y = random();
    int eat2x = random();
    int eat2y = random();
    int eat3x = random();
    int eat3y = random();
    int px = random();
    int py = random();
    int rank1 = 0, rank2 = 0, rank3 = 0;
    char gerak;
    bool cek;
    do{
        cout << "Welcome to All You Can Eat" << endl;
        cout << "1. Play" << endl;
        cout << "2. Highscore" << endl;
        cout << "0. Exit" << endl;
        cout << ">> "; cin >> input;

        int time = 30, score = 0;
        if(input == 1){
            while(time != 0){
                system("cls");
                time--;
                if(!cek1(eat1x,eat1y,eat2x,eat2y,eat3x,eat3y,px,py)){
                    eat1x = random();
                    eat1y = random();
                }
                if(!cek2(eat1x,eat1y,eat2x,eat2y,eat3x,eat3y,px,py)){
                    eat2x = random();
                    eat2y = random();
                }
                if(!cek3(eat1x,eat1y,eat2x,eat2y,eat3x,eat3y,px,py)){
                    eat3x = random();
                    eat3y = random();
                }
                arena(px,py,eat1x,eat1y,eat2x,eat2y,eat3x,eat3y,time,score);
                if(kbhit()){
                    gerak = getch();
                    if(gerak == 'w'){
                        if(py != 2){py--;}
                    }else if(gerak == 'a'){
                        if(px != 2){px--;}
                    }else if(gerak == 's'){
                        if(py != 9){py++;}
                    }else if(gerak == 'd'){
                        if(px != 9){px++;}
                    }
                }
                Sleep(100);
                if(px == eat1x && py == eat1y){
                    do{
                        eat1x = random();
                        eat1y = random();
                    }while(!cek1(eat1x,eat1y,eat2x,eat2y,eat3x,eat3y,px,py));
                    score += 5;
                }
                if(px == eat2x && py == eat2y){
                    do{
                        eat2x = random();
                        eat2y = random();
                    }while(!cek2(eat1x,eat1y,eat2x,eat2y,eat3x,eat3y,px,py));
                    score += 5;
                }
                if(px == eat3x && py == eat3y){
                    do{
                        eat3x = random();
                        eat3y = random();
                    }while(!cek3(eat1x,eat1y,eat2x,eat2y,eat3x,eat3y,px,py));
                    score += 5;
                }
            }
            ranking(score,rank1,rank2,rank3);
        }else if(input == 2){
            leaderboard(rank1,rank2,rank3);
        }
    }while(input != 0);
    return 0;
}
