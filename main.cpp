#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int random(){
    return rand() % 8 + 2;
}

bool check1(int cek_x, int cek_y, int bdk1_x, int bdk1_y, int bdk2_x, int bdk2_y, int px, int py,int ex, int ey, int sx, int sy, int wx, int wy, int mx, int my){
    if((cek_x != bdk1_x && cek_y != bdk1_y) || (cek_x != bdk2_x && cek_y != bdk2_y) || (cek_x != px && cek_y != py) || (cek_x != ex && cek_y != ey) || (cek_x != sx && cek_y != sy) || (cek_x != wx && cek_y != wy) || (cek_x != mx && cek_y != my)){
        return true;
    }else{
        return false;
    }
}

bool check2(int cek_x, int cek_y, int bdk1_x, int bdk1_y, int bdk2_x, int bdk2_y, int bdk3_x, int bdk3_y, int px, int py, int eat1x, int eat1y, int eat2x,int eat2y, int eat3x, int eat3y){
    if((cek_x != bdk1_x && cek_y != bdk1_y) || (cek_x != bdk2_x && cek_y != bdk2_y) || (cek_x != bdk3_x && cek_y != bdk3_y) || (cek_x != px && cek_y != py) || (cek_x != eat1x && cek_y != eat1y) || (cek_x != eat2x && cek_y != eat2y) || (cek_x != eat3x && cek_y != eat3y)){
        return true;
    }else{
        return false;
    }
}

bool check3(int cek_x, int cek_y, int bdk1_x, int bdk1_y, int bdk2_x, int bdk2_y, int bdk3_x, int bdk3_y, int eat1x, int eat1y, int eat2x,int eat2y, int eat3x, int eat3y){
    if((cek_x != bdk1_x || cek_y != bdk1_y) && (cek_x != bdk2_x || cek_y != bdk2_y) && (cek_x != bdk3_x || cek_y != bdk3_y) && (cek_x != eat1x || cek_y != eat1y) && (cek_x != eat2x || cek_y != eat2y) && (cek_x != eat3x || cek_y != eat3y)){
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

void arena(int px, int py, int eat1x, int eat1y, int eat2x, int eat2y, int eat3x, int eat3y, int time, int score, int ex, int ey, int sx, int sy, int wx, int wy, int mx, int my, int time_s, int time_w, int time_m, bool cek_s, bool cek_w, bool cek_m, bool muncul_s, bool muncul_w, bool muncul_m){
    cout << "==All You Can Eat==" << endl;
    cout << "Time : " << time << endl;
    cout << "Score : " << score << endl;
    for(int i = 1; i <= 10; i++){
        for(int j = 1; j <= 10; j++){
            if(i == 1 || j == 1 || i == 10 || j == 10){cout << "* ";
            }else if(i == py && j == px){cout << "P ";
            }else if((i == eat1y && j == eat1x) || (i == eat2y && j == eat2x) || (i == eat3y && j == eat3x)){cout << "o ";
            }else if(i == ey && j == ex){cout << "e ";
            }else if((i == sy && j == sx) && muncul_s){cout << "S ";
            }else if((i == wy && j == wx) && muncul_w){cout << "W ";
            }else if((i == my && j == mx) && muncul_m){cout << "M ";
            }else{cout << "  ";
            }
        }
        cout << endl;
    }
    if(cek_s){cout << "SPEED remaining time: " << time_s << "s" << endl;}
    if(cek_w){cout << "WALL remaining time: " << time_w << "s" << endl;}
    if(cek_m){cout << "MAGNET remaining time: " << time_m << "s" << endl;}
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
    int rank1 = 0, rank2 = 0, rank3 = 0;
    int loop1, loop2, sleep, time_s = 5, time_w = 3, time_m = 5;
    char gerak;
    do{
        cout << "Welcome to All You Can Eat" << endl;
        cout << "1. Play" << endl;
        cout << "2. Highscore" << endl;
        cout << "0. Exit" << endl;
        cout << ">> "; cin >> input;

        int eat1x = random(), eat1y = random();
        int eat2x = random(), eat2y = random();
        int eat3x = random(), eat3y = random();
        int px = random(), py = random();
        int ex = random(), ey = random();
        int sx = random(), sy = random();
        int wx = random(), wy = random();
        int mx = random(), my = random();
        int time = 30, score = 0;
        bool cek_s = 0, cek_w = 0, cek_m = 0;
        bool muncul_s = 0, muncul_w = 0, muncul_m = 0;
        bool status = true;

        if(input == 1){
            system("cls");
            arena(px,py,eat1x,eat1y,eat2x,eat2y,eat3x,eat3y,time,score,ex,ey,sx,sy,wx,wy,mx,my,time_s,time_w,time_m,cek_s,cek_w,cek_m,muncul_s,muncul_w,muncul_m);
            while(time != 0 && status){
                if((rand() % 100 + 1 <= 20) && !cek_s && !muncul_s){muncul_s = 1;}
                if((rand() % 100 + 1 <= 40) && !cek_w && !muncul_w){muncul_w = 1;}
                if((rand() % 100 + 1 <= 50) && !cek_m && !muncul_m){muncul_m = 1;}

                loop1 = 10;
                while(loop1 != 0 && status){
                    if(cek_s && time_s != 0){
                        loop2 = 2;
                        sleep = 50;
                    }else if(time_s == 0){
                        cek_s = 0;
                        time_s = 5;
                    }else{
                        loop2 = 1;
                        sleep = 100;
                    }
                    if(time_w == 0){
                        cek_w = 0;
                        time_w = 3;
                    }
                    if(time_m == 0){
                        cek_m = 0;
                        time_m = 5;
                    }

                    switch(rand() % 4){
                        case 0: if((ex != 9) && (check3(ex+1,ey,sx,sy,wx,wy,mx,my,eat1x,eat1y,eat2x,eat2y,eat3x,eat3y))){ex++;} break;
                        case 1: if((ex != 2) && (check3(ex-1,ey,sx,sy,wx,wy,mx,my,eat1x,eat1y,eat2x,eat2y,eat3x,eat3y))){ex--;} break;
                        case 2: if((ey != 9) && (check3(ex,ey+1,sx,sy,wx,wy,mx,my,eat1x,eat1y,eat2x,eat2y,eat3x,eat3y))){ey++;} break;
                        case 3: if((ey != 2) && (check3(ex,ey-1,sx,sy,wx,wy,mx,my,eat1x,eat1y,eat2x,eat2y,eat3x,eat3y))){ey--;} break;
                    }

                    while(loop2 != 0 && status){
                        system("cls");
                        if(!check1(eat1x,eat1y,eat2x,eat2y,eat3x,eat3y,px,py,ex,ey,sx,sy,wx,wy,mx,my)){
                            eat1x = random();
                            eat1y = random();
                        }
                        if(!check1(eat2x,eat2y,eat1x,eat1y,eat3x,eat3y,px,py,ex,ey,sx,sy,wx,wy,mx,my)){
                            eat2x = random();
                            eat2y = random();
                        }
                        if(!check1(eat3x,eat3y,eat1x,eat1y,eat2x,eat2y,px,py,ex,ey,sx,sy,wx,wy,mx,my)){
                            eat3x = random();
                            eat3y = random();
                        }
                        if(!check2(ex,ey,sx,sy,wx,wy,mx,my,px,py,eat1x,eat1y,eat2x,eat2y,eat3x,eat3y)){
                            ex = random();
                            ey = random();
                        }
                        if(!check2(sx,sy,ex,ey,wx,wy,mx,my,px,py,eat1x,eat1y,eat2x,eat2y,eat3x,eat3y)){
                            sx = random();
                            sy = random();
                        }
                        if(!check2(wx,wy,ex,ey,sx,sy,mx,my,px,py,eat1x,eat1y,eat2x,eat2y,eat3x,eat3y)){
                            wx = random();
                            wy = random();
                        }
                        if(!check2(mx,my,ex,ey,sx,sy,wx,wy,px,py,eat1x,eat1y,eat2x,eat2y,eat3x,eat3y)){
                            mx = random();
                            my = random();
                        }

                        if(kbhit()){
                            gerak = getch();
                            if(!cek_w){
                                if(gerak == 'w'){if(py != 2){py--;}
                                }else if(gerak == 'a'){if(px != 2){px--;}
                                }else if(gerak == 's'){if(py != 9){py++;}
                                }else if(gerak == 'd'){if(px != 9){px++;}
                                }
                            }else{
                                if(gerak == 'w'){if(py != 2){py--;}else{py = 9;}
                                }else if(gerak == 'a'){if(px != 2){px--;}else{px = 9;}
                                }else if(gerak == 's'){if(py != 9){py++;}else{py = 2;}
                                }else if(gerak == 'd'){if(px != 9){px++;}else{px = 2;}
                                }
                            }
                        }

                        arena(px,py,eat1x,eat1y,eat2x,eat2y,eat3x,eat3y,time,score,ex,ey,sx,sy,wx,wy,mx,my,time_s,time_w,time_m,cek_s,cek_w,cek_m,muncul_s,muncul_w,muncul_m);

                        if(!cek_m){
                            if(px == eat1x && py == eat1y){
                                do{
                                    eat1x = random();
                                    eat1y = random();
                                }while(!check1(eat1x,eat1y,eat2x,eat2y,eat3x,eat3y,px,py,ex,ey,sx,sy,wx,wy,mx,my));
                                score += 5;
                            }
                            if(px == eat2x && py == eat2y){
                                do{
                                    eat2x = random();
                                    eat2y = random();
                                }while(!check1(eat2x,eat2y,eat1x,eat1y,eat3x,eat3y,px,py,ex,ey,sx,sy,wx,wy,mx,my));
                                score += 5;
                            }
                            if(px == eat3x && py == eat3y){
                                do{
                                    eat3x = random();
                                    eat3y = random();
                                }while(!check1(eat3x,eat3y,eat1x,eat1y,eat2x,eat2y,px,py,ex,ey,sx,sy,wx,wy,mx,my));
                                score += 5;
                            }
                        }else{
                            if((px+1 == eat1x && py+1 == eat1y) || (px == eat1x && py+1 == eat1y) || (px-1 == eat1x && py+1 == eat1y) || (px+1 == eat1x && py == eat1y) || (px == eat1x && py == eat1y) || (px-1 == eat1x && py == eat1y) || (px+1 == eat1x && py-1 == eat1y) || (px == eat1x && py-1 == eat1y) || (px-1 == eat1x && py-1 == eat1y)){
                                do{
                                    eat1x = random();
                                    eat1y = random();
                                }while(!check1(eat1x,eat1y,eat2x,eat2y,eat3x,eat3y,px,py,ex,ey,sx,sy,wx,wy,mx,my));
                                score += 5;
                            }
                            if((px+1 == eat2x && py+1 == eat2y) || (px == eat2x && py+1 == eat2y) || (px-1 == eat2x && py+1 == eat2y) || (px+1 == eat2x && py == eat2y) || (px == eat2x && py == eat2y) || (px-1 == eat2x && py == eat2y) || (px+1 == eat2x && py-1 == eat2y) || (px == eat2x && py-1 == eat2y) || (px-1 == eat2x && py-1 == eat2y)){
                                do{
                                    eat2x = random();
                                    eat2y = random();
                                }while(!check1(eat2x,eat2y,eat1x,eat1y,eat3x,eat3y,px,py,ex,ey,sx,sy,wx,wy,mx,my));
                                score += 5;
                            }
                            if((px+1 == eat3x && py+1 == eat3y) || (px == eat3x && py+1 == eat3y) || (px-1 == eat3x && py+1 == eat3y) || (px+1 == eat3x && py == eat3y) || (px == eat3x && py == eat3y) || (px-1 == eat3x && py == eat3y) || (px+1 == eat3x && py-1 == eat3y) || (px == eat3x && py-1 == eat3y) || (px-1 == eat3x && py-1 == eat3y)){
                                do{
                                    eat3x = random();
                                    eat3y = random();
                                }while(!check1(eat3x,eat3y,eat1x,eat1y,eat2x,eat2y,px,py,ex,ey,sx,sy,wx,wy,mx,my));
                                score += 5;
                            }
                        }
                        if((px == sx && py == sy) && muncul_s){
                            do{
                                sx = random();
                                sy = random();
                            }while(!check2(sx,sy,ex,ey,wx,wy,mx,my,px,py,eat1x,eat1y,eat2x,eat2y,eat3x,eat3y));
                            muncul_s = 0;
                            cek_s = 1;
                        }
                        if((px == wx && py == wy) && muncul_w){
                            do{
                                wx = random();
                                wy = random();
                            }while(!check2(wx,wy,ex,ey,sx,sy,mx,my,px,py,eat1x,eat1y,eat2x,eat2y,eat3x,eat3y));
                            muncul_w = 0;
                            cek_w = 1;
                        }
                        if((px == mx && py == my) && muncul_m){
                            do{
                                mx = random();
                                my = random();
                            }while(!check2(mx,my,ex,ey,sx,sy,wx,wy,px,py,eat1x,eat1y,eat2x,eat2y,eat3x,eat3y));
                            muncul_m = 0;
                            cek_m = 1;
                        }
                        if(px == ex && py == ey){status = false;}
                        Sleep(sleep);
                        loop2--;
                    }
                    loop1--;
                }
                if(cek_s){time_s--;}
                if(cek_w){time_w--;}
                if(cek_m){time_m--;}
                time--;
            }
            ranking(score,rank1,rank2,rank3);
        }else if(input == 2){
            leaderboard(rank1,rank2,rank3);
        }
    }while(input != 0);
    return 0;
}
