#include "libft.h"
#include "push_swap.h"

void print_instruction(const char *instr)
{
	write(1, instr, ft_strlen(instr));
	write(1, "\n", 1);
}
