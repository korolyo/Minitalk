#include "ft_minitalk.h"

int	main(int argc, char **argv)
{
	int					pid;
	int					i;
	int                 bits[8];
	int                 j;

	pid = 0;
	i = 0;
	j = 7;
	pid = ft_atoi(argv[1]);
	while(argv[2][i])
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
			usleep(100);
		}
		i++;
		j = 7;
	}
	return 0;
}
