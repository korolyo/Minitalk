#include "ft_minitalk.h"

void	handler_s1(int num, siginfo_t *siginfo, void *context)
{
    static int	count;
    static char	c;

	if (!count)
	{
		c = 0;
		count = 1;
	}
    if (count != 256)
	{
		if (num == SIGUSR2)
			c = c | count;
		count *= 2;
	}
	if (count == 256)
	{
		ft_putchar_fd(c, 1);
		c = 0;
		count = 1;
	}
}

int main(void)
{
	struct sigaction	sa;
	int 				cpid;

	sa.sa_sigaction = handler_s1;
	sa.sa_flags = SA_SIGINFO;
	cpid = si_pid.siginfo_t;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("%d\n", getpid());
	while (1)
	{
		sleep (1);
	}
	return (0);
}
