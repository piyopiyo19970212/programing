/*
    implementation of discrete Toda equation
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define m 3
void run();

int main()
{
    run();
    return EXIT_SUCCESS;
}

void run()
{
    double e[m+1][MAX]={{1}}; //下付き，上付き
    double q[m+1][MAX]={{1}};
    int k,n;
    for(k=0; k<=m; k++){
        for(n=0;n<MAX; n++){
            q[k][n] = 1;
            if(k==0 || k%m==0){ e[k][n] = 0;}
            else e[k][n] = 1;
//            printf("q[%d][%d]=%.10lf\n",k,n,q[k][n]);
//            printf("e[%d][%d]=%.10lf\n",k,n,e[k][n]);
        }
    }
    for(n=0;n<50;n++){
        for(k=1;k<=m;k++){
            q[k][n+1] = q[k][n]+e[k][n]-e[k-1][n+1];
            e[k][n+1] = (q[k+1][n]/q[k][n+1])*e[k][n];
        }
    }
    
    for(n=1;n<=50;n++){
        for(k=1;k<=m;k++){
            printf("q[%d][%d]=%.10lf\n",k,n,q[k][n]);
            printf("e[%d][%d]=%.10lf\n",k,n,e[k][n]);
        }
    }
    return;
}
