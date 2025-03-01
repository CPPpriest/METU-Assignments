\documentclass[12pt]{article}
\usepackage[utf8]{inputenc}

\usepackage{float}
\usepackage{amsmath}
\usepackage{fullpage}
\usepackage{amsfonts, amsmath, pifont}
\usepackage{amsthm}
\usepackage{graphicx}
\usepackage{float}

\usepackage{listings}

\usepackage{tkz-euclide}
\usepackage{tikz}
\usepackage{pgfplots}
\pgfplotsset{compat=1.13}


\usepackage[hmargin=3cm,vmargin=6.0cm]{geometry}
%\topmargin=0cm
\topmargin=-2cm
\addtolength{\textheight}{6.5cm}
\addtolength{\textwidth}{2.0cm}
%\setlength{\leftmargin}{-5cm}
\setlength{\oddsidemargin}{0.0cm}
\setlength{\evensidemargin}{0.0cm}

%misc libraries goes here




\begin{document}

\section*{Student Information } 
%Write your full name and id number between the colon and newline
%Put one empty space character after colon and before newline
Full Name : Ömer Kılınç \\
Id Number : 2448603 \\

% Write your answers below the section tags
\section*{Answer 1}
\[ z = \frac{ \sqrt{2} +  \sqrt{2}i }{2+2\sqrt{3}i} \]
\[= \frac{1}{\sqrt{2}} * \frac{1+i}{1 + \sqrt{3}i}\]

\[ \text{Exponential Representation of (1+i):}\]
\[ r = \sqrt{1^2 + 1^2} = \sqrt{2} \]
\[ \theta = arctan(\frac{1}{1}) = \frac{\pi}{4} \]
\[ 1+i = \sqrt{2}e^{i\frac{\pi}{4}  }\]
\[ \text{Similarly, Exponential Representation of } 1 + \sqrt{3}i \text{:}\]
\[ r = \sqrt{1^2 + \sqrt{3}^2} = 2 \]
\[ \theta = arctan(\frac{\sqrt{3}}{1}) = \frac{\pi}{3} \]
\[ 1+\sqrt{3}i  = 2e^{i\frac{\pi}{3}  }\]
\[ \text{Using these representations:}\]
\[z =  \frac{1}{ \sqrt{2} } *  \frac{\sqrt{2} e^{i \frac{\pi}{4}}}{ 2 e^{i \frac{\pi}{3}} } \]
\[z =  \frac{1}{ 2 } e^{-i\frac{\pi}{12}} \textbf{  (*)}\]
\[= \frac{1}{ 2 } (cos(-\frac{\pi}{12} ) + i*sin(-\frac{\pi}{12} ) )\]
\[z = 0.483 - 0.1294i\textbf{  (**)}\]


\subsection*{a)} 
\[\textbf{By equation (**):} \]
\[ Re{z} = 0.483\]
\[ Im{z} = -0.1294\]
\subsection*{b)} 
\[\textbf{By equation (*):} \]
\[ Magnitude : r = 0.5\]
\[ Phase : \theta = -\pi/12\]

\section*{Answer 2}


\begin{figure}[h!]
    \centering
        \begin{tikzpicture}[scale=1.0]
           \begin{axis}[
          axis lines=middle,
          xlabel={$t$},
          ylabel={$\boldsymbol{x(\frac{1}{2}t-2)}$},
          xtick={-1, ..., 10},
          ytick={-4,-3,-2, -1, ..., 4},
          ymin=-4, ymax=4,
          xmin=-1, xmax=10,
          every axis x label/.style={at={(ticklabel* cs:1.05)}, anchor=west,},
          every axis y label/.style={at={(ticklabel* cs:1.05)}, anchor=south,},
          grid,
        ]
           \path[draw,line width=4pt] (0,0) -- (2,0) -- (2,1) -- (6,1) -- (8,0);
           \end{axis}
        \end{tikzpicture}
        \caption{$t$ vs. $x(\frac{1}{2}t-2) $.}
        \label{fig:q2}
    \end{figure}



\section*{Answer 3}
\subsection*{a)}
\[ \sum_{k=-3}^3 {x[k]  \delta [n-k]} \]
\[ = \delta [n+3] - \delta [n+2] - \delta [n+1] -  \delta [n] + \delta [n-1] + 2\delta [n-2] + \delta [n-3]   \]

\[\]\[\] 
 
\subsection*{b) }
\[\]

\begin{filecontents}{q5.dat}
 n   xn 
 -2  0
 -1  1  
 0   3
 1  -1
 2  -1
 3  -1
 4  1
\end{filecontents}

\begin{figure} [h!]
    \centering
    \begin{tikzpicture}[scale=1.0] 
      \begin{axis}[
          axis lines=middle,
          xlabel={$n$},
          ylabel={$\boldsymbol{x[2n+2] + x[-n+1]}$},
          xtick={-3, -2, -1, 0, 1 , 2, ..., 5},
          ytick={-4, -3, -2, -1, ..., 4},
          ymin=-4, ymax=4,
          xmin=-3, xmax=5,
          every axis x label/.style={at={(ticklabel* cs:1.05)}, anchor=west,},
          every axis y label/.style={at={(ticklabel* cs:1.05)}, anchor=south,},
          grid,
        ]
        \addplot [ycomb, black, thick, mark=*] table [x={n}, y={xn}] {q5.dat};
      \end{axis}
    \end{tikzpicture}
    \caption{$n$ vs. $x[2n+2] + x[-n+1]$.}
    \label{fig:q3}
\end{figure}


\subsection*{c)}
\[ \sum_{k=-2}^4 {y[k]  \delta [n-k]} \]
\[ = \delta [n+1] + 3\delta [n] - \delta [n-1] - \delta [n-2] - \delta [n-3]  + \delta [n-4]  \]
\[\]
\section*{Answer 4}
\subsection*{a)}
\[ x_{1}[n] = cos(\frac{5\pi}{2}n)\]
\[cos(\frac{5\pi}{2}n) = cos(\frac{5\pi}{2}n + \frac{5\pi}{2}N_{0})\]
\[\frac{5\pi}{2}N_{0} = 2\pi k \]

\[ \text{ for k=5, } N_{0} = 4  \]
\subsection*{b)} 
\[ x_{2}[n] = sin(5n)\]
\[sin(5n) = sin(5n + 5N_{0})\]
\[ 5N_{0} = 2\pi k \]
\[ \text{ There is no integer } N_{0}  \text{ for any integer value k} \]
\subsection*{c)} 
\[ x_{3}(t) = 5sin(4t+ \frac{\pi}{3})\]
\[ 5sin(4t+ \frac{\pi}{3}) = 5sin(4t + 4T_{0} + \frac{\pi}{3})\]
\[ 4T_{0} + \frac{\pi}{3} = 2\pi \]
\[ T_{0} = \frac{5\pi}{12} \]

\section*{Answer 5}
\[\delta (at) = \frac{1}{|a|}\delta(t)\]
\[|a| \delta(at) = \delta(t)\]
\[ \text{Step impulse function property:} 
\int_{-\infty}^{\infty} \delta(t) dt = \delta(t)\]
\[|a|  \int_{-\infty}^{\infty} \delta(at) dt = \int_{-\infty}^{\infty} \delta(t) dt = \delta(t)\]
\[ \text{On the left side, replace parameter t with } \frac{t}{a} \]
\[|a|  \int_{-\infty}^{\infty} \delta(t) \frac{dt}{a} = \int_{-\infty}^{\infty} \delta(t) dt \]
\[ \frac{a}{|a| }  \int_{-\infty}^{\infty} \delta(t) dt = \int_{-\infty}^{\infty} \delta(t) dt \]
\[  1 = 1 \textbf{ (For any positive value a)}  \]


\section*{Answer 6}
\subsection*{a)}
\[ y_1 [n] = S_1(x_1[n]) = 4x_1[n] + 2x_1[n-1] \]
\[ y_2 [n] = S_2(y_1[n]) = y_1[n-2] \]
\[ y_2 [n] = y_1[n-2] = 4x_1[n-2] + 2x_1[n-3] \]
\[ \textbf{Difference equation of the overall system in terms of x[n] and y[n] :} \]
\[ y [n] = S(x[n]) =  4x[n-2] + 2x[n-3] \]

\subsection*{b)} 

\[ S_2(x_1[n]) = x_1[n-2] \]
\[ S_1(x_1[n-2]) = 4x_1[n-2] + 2x_1[n-3] \]
\[ \textbf{Difference equation of this system in terms of x[n] and y[n] :} \]
\[ y [n] = 4x[n-2] + 2x[n-3] \]
\[ \textbf{The series connection of the sub systems is commutative.} \]
\subsection*{c)}
\[ c_1 y_1 [n] = S(c_1 x_1[n]) = 4 c_1 x_1[n-2] + 2 c_1 x_1[n-3] \]
\[ c_2 y_2 [n] = S(c_2 x_2[n]) = 4 c_2 x_2[n-2] + 2 c_2 x_2[n-3]\]
\[ c_1 y_1 [n] + c_2 y_2 [n] = 4(c_1 x_1[n-2] + c_2 x_2[n-2]) + 2(c_1 x_1[n-3] + c_2 x_2[n-3] )\]
\[ = S(c_1 x_1 + c_2 x_2)\]
\[ \textbf{Conclusion: }\]
\[ S(c_1 x_1) + S(c_2 x_2) = c_1 y_1 [n] + c_2 y_2 [n] = S(c_1 x_1 + c_2 x_2)\]
\[ \textbf{Superposition property holds for the system S.}\]
\subsection*{d)}

\[ \textbf{Let } x_3[n] = x[n-n_0] \]
\[ y_3[n] = S(x_3[n]) = 4 x_3[n-2] + 2 x_3[n-3] \]
\[ = 4 x[n - n_0 - 2] + 2 x_3[n - n_0 - 3] \] \[=  y[n - n_0] \]
\[ S(x[n-n_0]) = y[n-n_0]   \text{ for any integer } n_0 \]
\[ \textbf{System S is Time invariant.} \]

\section*{Answer 7}

\begin{lstlisting}
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
def system_a(x):
    return n * x

isLinear( system_a )


# y[n] = x[n]**2
def system_b(x):
    return x**2

isLinear(system_b ) 
\end{lstlisting}

\subsection*{a) \textbf{The given system is a Non-Linear system} }

\subsection*{b) \textbf{The given system is a Non-Linear system}}

\end{document}


