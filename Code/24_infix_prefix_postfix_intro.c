/*
Infix, Prefix and Postfix Expressions

What are these?

The three terms, infix prefix, and postfix will be dealt with individually later. In general, these are the notations to write an expression. Mathematical expressions have been taught to us since childhood. Writing expressions to add two numbers for subtraction, multiplication, or division. They were all expressed through certain expressions. That's what we're learning today: different expressions.

Infix:

This is the method we have all been studying and applying for all our academic life. Here the operator comes in between two operands. And we say, two is added to three. For eg: 2 + 3, a * b, 6 / 3 etc.

< operand 1 >< operator >< operand2 >

Prefix:

This method might seem new to you, but we have vocally used them a lot as well. Here the operator comes before the two operands. And we say, Add two and three. For e.g.:  + 6 8, * x y, -  3 2 etc.

< operator >< operand 1 >< operand2 >

Postfix:

This is the method that might as well seem new to you, but we have used even this in our communication. Here the operator comes after the two operands. And we say, Two and three are added. For e.g.:  5 7 +, a  b *,  12 6 / etc.

< operand 1 >< operand2 >< operator >


To understand the interchangeability of these terms, please refer to the table below.

 	Infix       Prefix      Postfix

1.  a * b       * a b       a b *

2.  a - b       -  a b      a b - 


Why these methods?

When we evaluate a mathematical expression, we have a rule in mind, named BODMAS, where we have operators’ precedence in this order; brackets, of, division, multiplication, addition, subtraction. But what would you do when you get to evaluate a 1000 character long-expression, or even longer one? You will try to automate the process. But there is one issue. Computers don’t follow BODMAS; rather, they have their own operator precedence. And this is where we need these postfix and prefix notations. In programming, we use postfix notations more often, likewise, following the precedence order of machines. 

Consider the expression a* ( b + c ) * d; since computers go left to right while evaluating an expression, we’ll convert this infix expression to its postfix form.

Its postfix form is, a b c + * d *.  You must be wondering how we got here. Refer to the illustration below.

            1.    abc+*d*
                  --->
            2.    a(b+c)*d*
                   ----->
            3.    (a*(b+c))d*
                      ----->
            4.    (a*(b+c))*d

Converting infix to prefix:

    Consider the expression, x - y * z.

    1. Parentheses the expression. The infix expression must be parenthesized by following the operator precedence and associativity before converting it into a prefix expression. Our expression now becomes ( x - ( y * z ) ).

    2. Reach out to the innermost parentheses. And convert them into prefix first, i.e.  ( x - ( y * z ) ) changes to ( x - [ * y z ] ).

    3. Similarly, keep converting one by one, from the innermost to the outer parentheses.  ( x - [ * y z ] )  → [ - x * y z ]. 

    4. And we are done.

Converting infix to postfix:

    Consider the same expression, x - y * z.

    5. Parentheses the expression as we did previously. Our expression now becomes ( x - ( y * z ) ).

    6. Reach out to the innermost parentheses. And convert them into postfix first, i.e.  ( x - ( y * z ) ) changes to ( x - [ y z * ] ).

    7. Similarly, keep converting one by one, from the innermost to the outer parentheses.  ( x - [ y z * ] )  → [ x y z * - ]. 

    8. And we are done.

Similarly the expression p - q -  r / a, follows the following conversions to become a prefix expression:

    prefix : p - q -  r / a  →  ( ( p - q ) -  ( r / a ) ) →  ( [ - p q ] - [ / r a ]  )  →  - - p q / r a
    postfix: p - q -  r / a  →  ( ( p - q ) -  ( r / a ) ) →  ( [ p q - ] - [ r a / ]  )  →  p q - r a / -


Note: You cannot change the expression given to you. For eg. ( p - q ) * ( m - n ) cannot be changed to something like ( p - ( q * m ) - n ).

    Let’s change this to its postfix equivalent.

    postfix: ( p - q ) * ( m - n ) →  ( ( p - q ) * ( m - n ) ) →  ( [p q - ]*[m n - ] )  → p q-m n - *
    prefix:  ( p - q ) * ( m - n ) →  ( ( p - q ) * ( m - n ) ) →  ( [ - p q ]*[ - m n ] )  →  * - p q - m n

*/

#include<stdio.h>
#include<stdlib.h>


int main(){
    printf("Hello World, This is just intro about infix, prefix, and postfix\n");
    return 0;
}