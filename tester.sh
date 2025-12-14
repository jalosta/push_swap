make bonus -s
NUM_TESTS=100         
STACK_SIZE=500        
LIMIT=5500            
CHECKER="./checker"   
GREEN="\033[32m"
RED="\033[31m"
RESET="\033[0m"
min=100000
max=0
sum=0
count=0
echo "Testing push_swap with stack size $STACK_SIZE for $NUM_TESTS iterations..."
echo "----------------------------------------------------------------"
for ((i=1; i<=NUM_TESTS; i++))
do
    if command -v ruby &> /dev/null; then
        ARG=$(ruby -e "puts (1..$STACK_SIZE).to_a.shuffle.join(' ')")
    else
        ARG=$(shuf -i 1-$STACK_SIZE -n $STACK_SIZE | tr '\n' ' ')
    fi
    MOVES=$(./push_swap $ARG | wc -l)
    RESULT=$(./push_swap $ARG | $CHECKER $ARG)
    sum=$((sum + MOVES))
    if [ "$MOVES" -lt "$min" ]; then min=$MOVES; fi
    if [ "$MOVES" -gt "$max" ]; then max=$MOVES; fi
    if [ "$RESULT" == "KO" ]; then
        echo -e "${RED}FAIL (KO)${RESET} | Moves: $MOVES | Args saved to 'fail_ko.txt'"
        echo "$ARG" >> fail_ko.txt
        exit 1
    elif [ "$MOVES" -gt "$LIMIT" ]; then
        echo -e "${RED}FAIL (Limit)${RESET} | Moves: $MOVES | Args saved to 'fail_limit.txt'"
        echo "$ARG" >> fail_limit.txt
    else
        echo -n "."
    fi
    count=$((count + 1))
done
avg=$((sum / NUM_TESTS))
echo ""
echo "----------------------------------------------------------------"
echo "Tests Run: $NUM_TESTS"
echo "Min Moves: $min"
echo -e "Max Moves: $max"
if [ "$avg" -le "$LIMIT" ]; then
    echo -e "Average:   ${GREEN}$avg${RESET}"
else
    echo -e "Average:   ${RED}$avg${RESET}"
fi
echo "----------------------------------------------------------------"
make -s fclean