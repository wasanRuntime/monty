#include "monty.h"
#include "montycontext.h"

/**
 *  main -  interpreter for Monty ByteCodes files
 *  @argc: Number of paramethers
 *  @argv: Pointer to all the paramethers
 *
 *  Return: Always 0
 */
int main(int argc, char **argv)
{
	MontyContext var;
	size_t line_buf_size = 0;

	var.getl_info = NULL;
	var.stack_head = NULL;
	var.n_lines = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	var.fp_struct = fopen(argv[1], "r");
	if (!var.fp_struct)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&var.getl_info, &line_buf_size, var.fp_struct) != EOF)
	{
		var.n_lines++;
		if (line_validator(var.getl_info) == 1)
			continue;
		/*Pass the MontyContext instance to the function*/
		execute_opcode(split_str(var.getl_info), &var);
	}
	free(var.getl_info);
	handle_dlist_head(var.stack_head);
	fclose(var.fp_struct);
	return (EXIT_SUCCESS);
}
