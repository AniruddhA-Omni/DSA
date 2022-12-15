#include <stdio.h>
#include <math.h>

int y[144]={0};
int x[128];
int h[17];

int main(){
    int k, n;
    for(n = 0; n <144; n++){
        if (n<17){
            for(k = 0; k < n; k++){
                y[n] += h[k]*x[n-k];
            }
        }else{
            for(k = 0; k<17; k++){
                y[n] += h[k]*x[n-k];
            }
        }
    }
    printf("y[0] = %d", y[0]);
}