make -s
valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file="valgrind_push_swap.txt" ./push_swap 2 1 3
make -s fclean