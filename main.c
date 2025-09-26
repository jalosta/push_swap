#include "header.h"
 
void swap(t_stack *stack)
{
    t_list *first;
    t_list *second;

    first = stack->top;
    second = first->next;
    first->next = second->next;
    second->next = first;
    stack->top = second;
}

void error_msg()
{
    write(2, "Error\n", 6);
}

int main(int argc, char **argv)
{
    if (argc > 1 && argc <= INT_MAX)
    {
        int i = 1;
        int j = 0;
        t_stack *a;

        while (argv[i])
        {
            while (argv[i][j])
            {
                a = argv[i][j];
                j++;
            }
            i++;
        }
    }
    else
        return 0;
    write(1, "\n", 1);
}
