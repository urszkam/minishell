#include "minishell.h"

void	print_history()
{
	int	i;
	
	i = -1;
	HIST_ENTRY **history = history_list(); //needs to be changed, forbidden function
	while (history[++i]) {
		printf("%d: %s\n", i + 1, history[i]->line);
	}
}

int	is_empty(char *input)
{
	int	i;
	
	i = 0;
	while(input[i] == ' ' || (input[i] >= 9 && input[i] <= 13))
		i++;
	return (input[i] == 0);
}

int	is_valid_input(char *input) {
	if (is_empty(input) || ft_strcmp(input, "exit") == 0) {
		return (0);
	}
	if (ft_strcmp(input, "history") == 0)
	{
            	print_history();
            	add_history(input);
            	return (0);
	}
	add_history(input);
	return (1);
}

void	run_shell()
{
	char	*input;
	int		keep_running;

	keep_running = 1;
	while(keep_running)
	{
		input = readline("\033[31m♥ minishell ♥: \033[0m");
		if(input && is_valid_input(input)) {
			// process input
		}
		keep_running = ft_strcmp(input, "exit");
		free(input);
	}
}

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	run_shell();
	return (0);
}

