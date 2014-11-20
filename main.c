#include <stdio.h>
#include <math.h>


double arcsin(double x) {
    if (x<(-1) || x>1) {
        printf("x not in scope\n");
        return 0;
    }
    double s=x;
    double s_old=x+1;
    double y=s;
    int k=1;
    while(s != s_old) {
        s_old = s;
        s*=(2*k-1)*(2*(k-1)+1)*x*x/(2*k)/(2*k+1);
        y+=s;
        k++;
    }
    return y;
}

double arctan(double x){
    if (x<(-1) || x>1) {
        printf("x not in scope\n");
        return 0;
    }
    double y=x,
    temp=x+1,
    step=x;
    int   k;
    
    for (k=1; step!=temp; k++) {
        temp=step;
        step*=((-1)*x*x);
        y+=step/(2*k+1);
    }
    return y;
}

double ln(double x){
    if (x<=0 || x>2) {
        printf("x not in scope\n");
        return 0;
    }
    double y=x-1,
    temp=x,
    step=x-1;
    int k;
    for (k=1; step!=temp; k++) {
        temp=step;
        step*=(-1)*(x-1);
        y+=step/(k+1);
    }
    return y;
}

float fun(double x, int fun_nr){
    switch (fun_nr) {
        case 1:
            return atan(x);
        case 2:
            return asin(x);
            break;
        case 3:
            return log(x);
            break;
        case 4:
            return sin(x);
            break;
        default:
            printf("fun_nr not in scope\n");
            return 0;
            break;
    }
}

//intervals
#define LEFT 0
#define RIGHT 6
#define UPPER 1.5
#define LOWER -1.5
#define X_MAX 20
#define Y_MAX 50

//plotting funktions
double x_mat(int x_s){
    double x_m;
    double x = x_s;
    x_m=(LEFT+(x*(RIGHT-LEFT))/X_MAX);
    return x_m;
}

double y_mat(int y_s){
    double y = y_s;
    return (UPPER+(y*(LOWER-UPPER))/Y_MAX);
}

int plotfun(int x_s, int y_s, int fun_nr){
    if (x_mat(x_s)==0){
        printf("|");
    }
    else if (y_mat(y_s)==0){
        printf("_");
    }
    else if (y_mat(y_s)>0){
        if (fun(x_mat(x_s), fun_nr)>=y_mat(y_s)){
            printf("+");
        }
        else printf(" ");
    }
    else {
        if (fun(x_mat(x_s), fun_nr)<=y_mat(y_s)){
            printf("-");
        }
        else printf(" ");
    }
    if (x_s==X_MAX) {
        printf("\n");
    }
    return 1;
}

int main(void) {
    
    int x_s, y_s, fun_nr;
    scanf("%d",&fun_nr);

    
    for (y_s=0; y_s<=Y_MAX; y_s++) {
        for (x_s=0; x_s<=X_MAX; x_s++) {
            plotfun(x_s, y_s,fun_nr);
        }
    }
    
    return 0;
}
