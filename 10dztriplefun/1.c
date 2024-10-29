/*
Данные о пересечениях по графику

f h -2.033
    1.2262

g h 0.1884
    0.8292

f g 1.9571
    1.5671

будем уточнять в интервале
-+ 0.005
на 100 000 шагах

f = lambda x: 3 / (1 + (x-1)**2)
g = lambda x: np.sqrt(x + 0.5)
h = lambda x: np.exp(-x)

*/
#include <math.h>


double f(double);
double g(double);
double h(double);
//double root//(f, g, a, b, eps1, x),

int main(){
    return 0;
}

double f(double x){
    return 3 / ( 1 + pow((x-1), 2) );
};

double g(double x){
    return sqrt(x + 0.5);
};

double h(double x){
    return exp(-x);
};
