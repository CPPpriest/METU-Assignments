\documentclass[12pt]{article}
\usepackage[utf8]{inputenc}

\usepackage{float}
\usepackage{amsmath}
\usepackage{fullpage}
\usepackage{amsfonts, amsmath, pifont}
\usepackage{amsthm}
\usepackage{graphicx}
\usepackage{float}

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


\end{document}



\begin{document}



\end{document}

