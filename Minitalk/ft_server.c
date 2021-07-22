#include "ft_minitalk.h"
#include <stdio.h>

void	handler_s1(int num)
{
    char    *str;
    int     i;

    i = 7;
    str = (char *)malloc(sizeof (char) * 9);
    str[8] = '\n';
    while (i >= 0)
    {
        if (num == SIGUSR1)
            str[i] = '0';
        if (num == SIGUSR2)
            str[i] = '1';
        i--;
    }
}

int main(void)
{
	struct sigaction	sa;

	sa.sa_handler = handler_s1;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	printf("%d\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		sleep (1);
	}
	return (0);
}
