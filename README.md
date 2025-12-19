*This project has been created as part of the 42 curriculum by jalosta-* 

# push_swap
## Description
Push_swap (old common core) is a data sorting project about the development of a C program that uses an algorithm that calculates the shortest sequence of operations to sort data in a stack using a limited set of instructions, aiming to achieve the lowest possible number of actions.

Input: stack a formatted as a list of integers.
Output: displays the shortest sequence of instructions needed to sort the integers received as arguments.

Cost Average for 100 integers (1000 runs of random combinations): 5109
### Bonus part
The project offers a bonus part wherein an accompanying program must be developed that checks if push_swap came up with a list of instructions that sort the numbers.

Input: stack a formatted as a list of integers and stdin, where from the binary recieves its instructions.
Output: displays "OK" if instructions sort the numbers, or "KO" if otherwise.
## Instructions
The project includes a Makefile that compiles the source files to the required outputusing the flags -Wall, -Wextra, and -Werror.

To compile the mandatory part:
```
make
```
To compile the bonus part (checker):
```
make bonus
```
Other available rules: clean, fclean, re.
### Instruction set
    sa (swap a): Swap the first 2 elements at the top of stack a.
    Do nothing if there is only one element or none.

    sb (swap b): Swap the first 2 elements at the top of stack b.
    Do nothing if there is only one element or none.

    ss : sa and sb at the same time.

    pa (push a): Take the first element at the top of b and put it at the top of a.
    Do nothing if b is empty.

    pb (push b): Take the first element at the top of a and put it at the top of b.
    Do nothing if a is empty.

    ra (rotate a): Shift up all elements of stack a by 1.
    The first element becomes the last one.

    rb (rotate b): Shift up all elements of stack b by 1.
    The first element becomes the last one.

    rr : ra and rb at the same time.

    rra (reverse rotate a): Shift down all elements of stack a by 1.
    The last element becomes the first one.

    rrb (reverse rotate b): Shift down all elements of stack b by 1.
    The last element becomes the first one.

    rrr : rra and rrb at the same time.
## Resources
push_swap : a performant sorting algorithm using 2 stacks (100-630 moves | 500-5470 moves) - Oceano

https://www.youtube.com/watch?v=OaG81sDEpVk

All you need to know about linked lists, Libft - Oceano

https://www.youtube.com/watch?v=mkZYMKwKkvI

Push_Swap: The least amount of moves with two stacks - Jamie Robert Dawson

https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a

Push Swap — A journey to find most efficient sorting algorithm - Yigit Ogun

https://medium.com/@ayogun/push-swap-c1f5d2d41e97

How To Write a README? - Reddit

https://www.reddit.com/r/learnprogramming/comments/vxfku6/how_to_write_a_readme/

Make a README

https://www.makeareadme.com/
### Role of AI in the development of this project
I used Gemini https://gemini.google.com/app with a student subscription in spotting less obvious causes of segfault, determined redundancies in the code, and generating a tester script which runs numerous tests with randomized combinations of any number of integers and displays some statistics, such as the average number of moves.

Gemini also provided tips on debugging my program, affecting my regular use of Valgrind. It also introduced me to Visual Studio built-in debuggers which I'd avoided so far. In the complexity of strategizing methods for handling certain cases of high-cost input, no amount of typing helped force innovation out of the chatbot and I recognized that the new field of AI prompting had a difficulty of its own.