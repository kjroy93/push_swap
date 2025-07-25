#include "libft.h"
#include "push_swap.h"

static int instruction_counter = 0;

void print_instruction(const char *instr)
{
	instruction_counter++;
	write(1, instr, ft_strlen(instr));
	write(1, "\n", 1);
}

int get_instruction_count(void)
{
	return instruction_counter;
}
