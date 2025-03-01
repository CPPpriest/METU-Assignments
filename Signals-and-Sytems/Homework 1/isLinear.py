from sympy import symbols, Function

# Define symbolic variables
n = symbols('n', integer=True)
x = Function('x')(n)  # Input signal x[n]

# Constants (coefficients) for the linear combination and seperate outputs
c1, c2 = symbols('c1 c2')

# Define two different input signals
x1 = Function('x1')(n)
x2 = Function('x2')(n)


def isLinear(system):
    if(  system(c1*x1 + c2*x2)  == ( c1*system(x1) + c2*system(x2) ) ) :
        print("The given system is a Linear system. \n")
    else:
        print("The given system is a Non-Linear system. \n")


# Test

# y[n] = n*x[n]
def test1(x):
    return n * x

isLinear( test1 )


# y[n] = x[n]**2
def test2(x):
    return x**2

isLinear(test2 ) 