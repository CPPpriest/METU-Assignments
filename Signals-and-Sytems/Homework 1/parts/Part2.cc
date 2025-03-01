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


\subsection*{b)}


\begin{filecontents}{q3.dat}
 n   xn 
 -2  -1
 -1   -1  
 0   2
\end{filecontents}

\begin{figure} [h!]
    \centering
    \begin{tikzpicture}[scale=1.0] 
      \begin{axis}[
          axis lines=middle,
          xlabel={$n$},
          ylabel={$\boldsymbol{x[2n+2]}$},
          xtick={ -4, -3, -2, -1, 0, 1 , 2},
          ytick={-4, -3, -2, -1, ..., 4},
          ymin=-4, ymax=4,
          xmin=-4, xmax=2,
          every axis x label/.style={at={(ticklabel* cs:1.05)}, anchor=west,},
          every axis y label/.style={at={(ticklabel* cs:1.05)}, anchor=south,},
          grid,
        ]
        \addplot [ycomb, black, thick, mark=*] table [x={n}, y={xn}] {q3.dat};
      \end{axis}
    \end{tikzpicture}
    \caption{$n$ vs. $x[2n+2]$.}
    \label{fig:q3}
\end{figure}




 


\begin{filecontents}{q4.dat}
 n   xn 
 -2  1
 -1  2  
 0   1
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
          ylabel={$\boldsymbol{x[-n+1]}$},
          xtick={-3, -2, -1, 0, 1 , 2, ..., 5},
          ytick={-4, -3, -2, -1, ..., 4},
          ymin=-4, ymax=4,
          xmin=-3, xmax=5,
          every axis x label/.style={at={(ticklabel* cs:1.05)}, anchor=west,},
          every axis y label/.style={at={(ticklabel* cs:1.05)}, anchor=south,},
          grid,
        ]
        \addplot [ycomb, black, thick, mark=*] table [x={n}, y={xn}] {q4.dat};
      \end{axis}
    \end{tikzpicture}
    \caption{$n$ vs. $x[-n+1]$.}
    \label{fig:q3}
\end{figure}


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





\end{document}



\begin{document}



\end{document}

