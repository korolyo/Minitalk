#include "ft_minitalk.h"

void	handler_s1(int num, siginfo_t *info, void *context)
{
	(void)context;
    static int	count;
    static char	c;
	int 		cpid;

	cpid = info->si_pid;
	if (!count)
	{
		c = 0;
		count = 1;
	}
    if (count != 256)
	{
		if (num == SIGUSR2)
			c |= count;
		count *= 2;
	}
	if (count == 256)
	{
		ft_putchar_fd(c, 1);
		if (c == '\n')
			kill(cpid, SIGUSR1);
		c = 0;
		count = 1;
	}
}

int main(void)
{
	struct sigaction	sa;
	int					pid;

	sa.sa_sigaction = handler_s1;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	while (42)
	{
		sleep (1);
	}
	return (0);
}
