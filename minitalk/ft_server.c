#include "ft_minitalk.h"
#include <stdio.h>

void	handler_s1(int num)
{
//    int		i;
    char	c;

    while (i >= 0)
	{
		if (num == SIGUSR1)
		{
			str[i] = '0';
			printf("%s\n", str);
			i--;
		}
		if (num == SIGUSR2)
		{
			str[i] = '1';
			printf("%s\n", str);
			i--;
		}
		if (i == 0)
		{
			c = ft_atoi(str);
			ft_putchar_fd(c, 1);
			i--;
		}
	}
}

int main(void)
{
	struct sigaction	sa;
//	char    *str;
//	int     i;

//	i = 7;
//	str = (char *)malloc(sizeof (char) * 9);
	str[8] = '\0';
	sa.sa_handler = handler_s1;
	sa.sa_flags = 0;
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
