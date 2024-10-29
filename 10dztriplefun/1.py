import numpy as np
import matplotlib.pyplot as plt

"""
Данные о пересечениях по графику

f h -2.033 x
    1.2262 y

g h 0.1884 x
    0.8292 y

f g 1.9571 x
    1.5671 y

будем уточнять в интервале
-+ 0.005
на 100 000 шагах

f = lambda x: 3 / (1 + (x-1)**2)
g = lambda x: np.sqrt(x + 0.5)
h = lambda x: np.exp(-x)

//double root//(f, g, a, b, eps1, x),
double root (double (*f)(double),double a, double b, double eps);
"""
def root11(f,g, a,b, eps1 = 0.0001):#ne to
    #-0.20333500
    #0.18741100
    #1.95615300
    res = a
    minimaldifference = abs(b-a)
    i = eps1
    while (1):
        
        if (a+i > b) :
            break
        difference = abs(f(a+i)-g(a+i) )
        if difference<minimaldifference:
            minimaldifference = difference
            res = a+i
        i+=eps1

    return res

def root(f,g, a,b, eps1 = 0.0001):#ne to
    #-0.20333500
    #0.18741100
    #1.95615300
    c = (a+b)/2

    
    
    return f(c)

def main():

    f = lambda x: 3 / (1 + (x-1)**2)
    g = lambda x: np.sqrt(x + 0.5)
    h = lambda x: np.exp(-x)
    
    #print(root(f,h,-2.033-0.005,-2.033+0.005):.8f)
    """
    result = root(f,h,-2.033-10,-2.033+10)
    print(f"{result:.8f}")
    result = root(g,h,-0.1884-10,-0.1884+10)
    print(f"{result:.8f}")
    result = root(f,g,1.9571-10,1.9571+10)
    print(f"{result:.8f}")
    """
    result = root(f,h,-0.20330000 - 0.5, -0.20330000 + 0.5, 0.000001)
    print(f"{result:.8f}")
    result = root(g,h,0.18740000 - 0.5, 0.18740000 + 0.5, 0.000001)
    print(f"{result:.8f}")
    result = root(f,g,1.95620000 - 0.5, 1.95620000 + 0.5, 0.000001)
    print(f"{result:.8f}")

    #return
    x = np.linspace(-5, 5, 100)

    y_f = f(x)
    y_g = g(x)
    y_h = h(x)

    plt.figure(figsize=(12, 6))

    plt.plot(x, y_f, label='f(x)')
    plt.plot(x, y_g, label='g(x)')
    plt.plot(x, y_h, label='h(x)')

    plt.title('Plot of f, g, and h')
    plt.xlabel('x')
    plt.ylabel('y')

    plt.legend()
    plt.show()


main()