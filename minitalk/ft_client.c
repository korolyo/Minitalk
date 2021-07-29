#include "ft_minitalk.h"

void	handler(int num)
{
	if (num == SIGUSR1)
		write(1, &"Message received!\n", 18);
}

void ft_send(char **argv, int pid, int bits[8])
{
	int i;
	int j;

	i = 0;
	j = 7;
	while (argv[2][i])
	{
		while (j >= 0)
		{
			bits[j] = argv[2][i] & 1;
			argv[2][i] = argv[2][i] >> 1;
			if (bits[j] == 0)
				kill(pid, SIGUSR1);
			if (bits[j] == 1)
				kill(pid, SIGUSR2);
			j--;
			usleep(80);
		}
		i++;
		j = 7;
	}
}

void ft_eof(int pid, int bits[8])
{
	char	c;
	int 	j;

	j = 7;
	c = '\n';
	while (j >= 0)
	{
		bits[j] = c & 1;
		c = c >> 1;
		if (bits[j] == 0)
			kill(pid, SIGUSR1);
		if (bits[j] == 1)
			kill(pid, SIGUSR2);
		j--;
		usleep(80);
	}

}
int	main(int argc, char **argv)
{
	struct sigaction	sa;
	int				pid;
	int				bits[8];

	sa.sa_handler = handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	pid = 0;
	pid = ft_atoi(argv[1]);
	sigaction(SIGUSR1, &sa, NULL);
	if (argc == 3)
	{
		ft_send(argv, pid, bits);
		ft_eof(pid, bits);
	}
	return 0;
}
