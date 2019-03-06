#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
#include "MT.h"

int genrand(int min,int max);

int main(int argc, char const* argv[]){
}

/*
名前 : genrand(min,max)
引数 : min - 最小値
       max - 最大値
説明 : 最小値から最大値までのランダムな整数を返す
 */
int genrand(int min,int max){
    return genrand_int32()%(max-min+1)+min;
}

/*
 * 名前   : float pi(long long int r, long long int repeat, float seed)
 * 引数   : r      計算に使う円の円周率
 *          repeat 計算回数
 *          seed   乱数の種
 * 帰り値 : 円周率の近似値
 * 説明   : MT.hのgenrand_int32()を使ってモンテカルロ法により円周率の近似値を求める。
 */

float pi(long long int r, long long int repeat, float seed){

    init_genrand((unsigned)time(NULL));

    //繰り返し回数
    long long int deef_repeat=0;
    //円に入った回数
    long long int inCircle=0;
    //点の座標
    long long int x=0;
    long long int y=0;
    //円の円周
    long long int def_r=atoi(r);
    long long int r2=r*r;
    //計算によって求まった円周率
    double pi;

    while (1){
        for (int i = 0; i < 100000000; i++) {
            x=genrand(0,r)-1;
            y=genrand(0,r)-1;
            if (x*x+y*y<=r2) {
                inCircle++;
            }
            repeat++;
        }
        if (repeat < 0){
            return 0;
        }
        pi=4.0*((double)inCircle/(double)repeat);
        printf("repeat:%lld inCircle:%lld pi:%lf\n", repeat, inCircle, pi);
        fflush(stdout);
    }
    return 0;
}
