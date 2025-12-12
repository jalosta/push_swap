make bonus -s

ARG="6 1 8 2 4"; valgrind -s --leak-check=full --log-file="valgrind_push_swap.txt" ./push_swap $ARG | ./checker $ARG | cat -e

make -s fclean