# Gomoku-in-the-Mist
Gomoku in the Mist is a new game based on Gomoku. It inherits all the rules from Gomoku and it
introduces a game component called Mist. Mist blocks the visibility of both players and it covers the
whole board except a 7 × 7 square hole (See Figure 3). Players can only see through the hole that
is not covered by the Mist, however, the placement of stone is not blocked by the Mist at all. If the
centre of the hole is so close to the border of the board that the hole cannot fit into the board, simply
ignore the part that cannot fit.
Initially, the hole of the Mist locates at the centre of the board before the first move. The Mist (hole) changes after every placement of a stone. The position of hole depends on the previous placement of a stone. If a numerical coordinate system is used, the following rules apply:

Xmist = 1 + (5X^2stone + 3Xstone + 4) % 19,
Ymist = 1 + (4Y^2stone + 2Ystone − 4) % 19.
% is the modulo operator.

(Xmist, Ymist) denotes the position of the hole’s centre, and (Xstone, Ystone) denotes the position of the previous placed stone.
To denote position on the board, a coordinate <C><R> can be specified. While it is natural to utilise
a 19 × 19 purely numerical coordinate system, the Go style system is preferred. In particular, for a
Go coordinate <C><R>, <C> is a column character ranging from A (the first English upper letter) to
S (the nineteenth English upper letter); <R> is a row number ranging from 1 to 19.
In a numerical coordinate system, columns are denoted by numbers instead of characters. In particular, the n-th English upper letter is equivalent to a number n. E.g. Column character A is equivalent to column number 1.
  
The Game Controller is a command prompt that supports the following commands:
who
term
resign
view
place <C><R>
history
  
19 . . . . . . . . . . . . . . . . . . .
18 . . . . . . . . . . . . . . . . . . .
17 . . . . . . . . . . . . . . . . . . .
16 . . . . . . . . . . . . . . . . . . .
15 . . . . . . . . . . . . . . . . . . .
14 . . . . . . . . . . . . . . . . . . .
13 . . . . . . . . . . . . . . . . . . .
12 . . . . . . . . . . . . . . . . . . .
11 . . . . . . . . . . . . . . . . . . .
10 . . . . . . . . . . . . . . . . . . .
9 . . . . . . . . . . . . . . . . . . .
8 . . . . . . . . . . . . . . . . . . .
7 . . . . . . . . . . . . . . . . . . .
6 . . . . . . . . . . . . . . . . . . .
5 . . . . . . . . . . . . . . . . . . .
4 . . . . . . . . . . . . . . . . . . .
3 . . . . . . . . . . . . . . . . . . .
2 . . . . . . . . . . . . . . . . . . .
1 . . . . . . . . . . . . . . . . . . .
A B C D E F G H I J K L M N O P Q R S
numerical: 1 2 3 4 5 6 7 8 9 ...................
Figure 1: An ASCII art of the Go board grid points with axes numbering

19 @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @
18 @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @
17 @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @
16 @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @
15 @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @
14 @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @
13 @ @ @ @ @ @ . . . . . . . @ @ @ @ @ @
12 @ @ @ @ @ @ . . . . . . . @ @ @ @ @ @
11 @ @ @ @ @ @ . . . . . . . @ @ @ @ @ @
10 @ @ @ @ @ @ . . . A . . . @ @ @ @ @ @
9 @ @ @ @ @ @ . . . . . . . @ @ @ @ @ @
8 @ @ @ @ @ @ . . . . . . . @ @ @ @ @ @
7 @ @ @ @ @ @ . . . . . . . @ @ @ @ @ @
6 @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @
5 @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @
4 @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @
3 @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @
2 @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @
1 @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @ @
A B C D E F G H I J K L M N O P Q R S
Figure 3: An ASCII art of the Go board covered by the Mist except the 7 × 7 hole, where @,.,A
represents the Mist, the hole and the centre of the hole.
