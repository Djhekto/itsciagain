/*
Данные о пересечениях по графику

f h -0.2033 x
    1.2262 y

g h 0.1884 x
    0.8292 y

f g 1.9571 x
    1.5671 y

    #-0.20333500
    #0.18741100
    #1.95615300

-0.203408
0.188517
2.959510

f = lambda x: 3 / (1 + (x-1)**2)
g = lambda x: np.sqrt(x + 0.5)
h = lambda x: np.exp(-x)

//double root//(f, g, a, b, eps1, x),
double root (double (*f)(double),double a, double b, double eps);
*/
#include <math.h>
#include <stdio.h>


double fh(double);
double gh(double);
double fg(double);
double f(double);
double g(double);
double h(double);


double integral (double (*f)(double),double a, double b, double eps);
double root (double (*f)(double),double a, double b, double eps);

int main(){
    double temp = 0.0005;
    double eps1 = 0.0001;
    double printres;
    double storedot1;
    double storedot2;
    double storedot3;
    double storeint1;
    double storeint2;
    double storeint3;
    double storeint4;

    storedot1 = printres = root(fh, -0.2033-temp, -0.2033+temp, eps1 );
    printf("dot 1 %lf\n",storedot1);

    storedot2 = printres = root(gh, 0.1884-temp, 0.1884+temp, eps1 );
    printf("dot 2 %lf\n",storedot2);

    storedot3 = printres = root(fg, 1.9571-temp, 1.9571+temp, eps1 );
    printf("dot 3 %lf\n",storedot3);

    printf("dot end\n\n");
    //eps1 = 0.01;

    storeint1 = integral(f, storedot1, storedot3, eps1 );
    printf("int 1 %lf    minus\n",storeint1);

    storeint2 = integral(h, storedot1, storedot2, eps1 );
    printf("int 2 %lf    plus  \n",storeint2);

    //storeint3 = integral(f, storedot2, storedot3, eps1 );
    //printf("int 3 %lf    minus\n",storeint3);

    storeint4 = integral(g, storedot2, storedot3, eps1 );
    printf("int 4 %lf\n",storeint4);

    printf("\n");
//    printf("Final res %lf\n", storeint1 - storeint2 + storeint3 - storeint4);
    printf("Final res %lf\n", storeint1 - storeint2 - storeint4);


    return 0;
}

double integral (double (*f)(double),double a, double b, double eps){
    
    //double h = abs(b-a)*eps;
    double h_half;
    double ca = a;
    double ceps = eps;

    //if (h<0.00001){
     //   h = 0.01 ;
    //}
    double h = 0.001;
    h_half = h*2;

    double res;
    double reshalf;
    while(1){
        res = 0;
        reshalf = 0;
        a = ca;
        eps = ceps;

        while(a<b){
            res += h*( f(a)+ f(a+h))/2; // a+h-a = h
            a+=h;
        }

        while(a<b){
            reshalf += h_half*( f(a)+ f(a+h_half))/2; // a+h-a = h
            a+=h_half;
        }

        //printf("%lf %lf----\n", (fabs( reshalf - res)/3), ceps);
        if ( (fabs( reshalf - res)/3) < eps) {    return res;}
        
        h_half = h;
        h = h/2;
        //printf("%lf %lf\n", h, h_half);
        if (h<0.000005) {break;}

    }

    return res;
}

double root (double (*f)(double),double a, double b, double eps){
    double res  = a;
    double copy =res;

    while(1){
        copy = res;
        res = b - f(b) * (a - b) / (f(a) - f(b));
        a = b;
        b = copy;
        if (abs(res - b) < eps) break;
    }
    return res;
}

double fh(double x){
    return (  3 / ( 1 + pow((x-1), 2) ) )   -    (exp(-x));
};

double gh(double x){
    return (sqrt(x + 0.5))   -   (exp(-x));
};

double fg(double x){
    return (sqrt(x + 0.5))   -   (  3 / ( 1 + pow((x-1), 2) ) );
};

/*f = lambda x: 3 / (1 + (x-1)**2)
g = lambda x: np.sqrt(x + 0.5)
h = lambda x: np.exp(-x)
*/

double f(double x){
    return (  3 / ( 1 + pow((x-1), 2) ) ) ;
}

double g(double x){
    return (sqrt(x + 0.5)) ;
}

double h(double x){
    return (exp(-x)) ;
}

/*double integral (double (*f)(double),double a, double b, double eps){
    double h = abs(b-a)*eps;
    if (h<0.00001){
        h = 0.001 ;
    }
    double res = 0 ;

    while(a<b){
        res += h*( f(a)+ f(a+h))/2; // a+h-a = h
        a+=h;
        //printf("%lf %lf %lf \n",res,a,h);
    }
    return res;
}
 */