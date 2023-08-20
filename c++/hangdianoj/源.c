#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int main()
{
	int n, a, b, x, y, i;
	while (~scanf("%d", &n))
	{
		while (n--)
		{
			scanf("%d%d", &a, &b);
			for (i = 1, x = 0; i < a; i++)
			{
				if (a % i == 0)
				{
					x = x + i;
				}
			}
			for (i = 1, y = 0; i < b; i++)
			{
				if (b % i == 0)
				{
					y = y + i;
				}
			}
			if (x == b && y == a)
			{
				printf("YES\n");
			}
			else
			{
				printf("NO\n");
			}
		}
	}
	return 0;
}


#include <stdio.h>
int main()
{
	int n, x, i, a[40];
	for (i = 0; i < 4; i++)
		a[i] = i;
	for (i = 3; i < 40; i++)
		a[i] = a[i - 1] + a[i - 2];
	while (~scanf("%d", &n))
	{
		while (n--)
		{
			scanf("%d", &x);
			printf("%d\n", a[x - 1]);
		}
	}
	return 0;
}

#include <stdio.h>
int main()
{
	int n, x, i, s;
	while (~scanf("%d", &n))
	{
		while (n--)
		{
			s = 3;
			scanf("%d", &x);
			while (x--)
			{
				s = (s - 1) * 2;
			}
			printf("%d\n", s);
		}
	}
	return 0;
}


# include <stdio.h>
# include <string.h>
int main()
{
	int n, i, x, da, xiao, shu, te;
	char a[50];
	while (~scanf("%d", &n))
	{
		getchar();
		while (n--)
		{
			da = xiao = shu = te = 0;
			gets(a);
			x = strlen(a);
			if (x >= 8 && x <= 16)
			{
				for (i = 0; i < x; i++)
				{
					if ('A' <= a[i] && a[i] <= 'Z')
					{
						da = 1;
					}
					else if ('a' <= a[i] && a[i] <= 'z')
					{
						xiao = 1;
					}
					else if ('0' <= a[i] && a[i] <= '9')
					{
						shu = 1;
					}
					else
					{
						te = 1;
					}
				}
				if (da + xiao + shu + te >= 3)
				{
					printf("YES\n");
				}
				else
				{
					printf("NO\n");
				}
			}
			else
			{
				printf("NO\n");
			}
		}
	}
	return 0;
}


# include <stdio.h>
int main()
{
	int n, i, a, b;
	double s[55];
	s[0] = s[1] = 1;
	for (i = 2; i < 55; i++)
	{
		s[i] = s[i - 1] + s[i - 2];
	}
	while (~scanf("%d", &n))
	{
		while (n--)
		{
			scanf("%d%d", &a, &b);
			printf("%.0f\n", s[b - a]);
		}
	}
	return 0;
}


# include <stdio.h>
int main()
{
	int n, i;
	double a[50], t;
	a[0] = 1;
	a[1] = 2;
	for (i = 2, t = 2; i < 50; i++)
	{
		t = 2 * t;
		a[i] = t - a[i - 1];
	}
	while (scanf("%d", &n) != EOF)
	{
		printf("%.0f\n", 3 * a[n - 1]);
	}
	return 0;
}


# include <stdio.h>
int main()
{
	int n, i;
	double a[55];
	a[0] = a[1] = 1;
	for (i = 2; i < 55; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
	}
	while (scanf("%d", &n) != EOF)
	{
		printf("%.0f\n", a[n]);
	}
	return 0;
}


# include <stdio.h>
int main()
{
	int n, x, i;
	double a[21] = { 0,0,1 }, b[21] = { 0,1,2 };
	for (i = 3; i < 21; i++)
	{
		a[i] = (i - 1) * (a[i - 1] + a[i - 2]);
		b[i] = b[i - 1] * i;
	}
	while (~scanf("%d", &n))
	{
		while (n--)
		{
			scanf("%d", &x);
			printf("%.2f%c\n", (a[x] * 100) / b[x], '%');
		}
	}
	return 0;
}


# include <stdio.h>
int main()
{
	int n, i;
	__int64 a[40];
	a[1] = 3;
	a[2] = 8;
	for (i = 3; i < 40; i++)
	{
		a[i] = 2 * (a[i - 1] + a[i - 2]);
	}
	while (~scanf("%d", &n))
	{
		printf("%I64d\n", a[n]);
	}
	return 0;
}


# include <stdio.h>
int main()
{
	int i, n, m, s;
	__int64 a[25] = { 0,0,1 }, b[25] = { 1,1,2 };
	for (i = 3; i < 25; i++)
	{
		a[i] = (i - 1) * (a[i - 1] + a[i - 2]);
		b[i] = b[i - 1] * i;
	}
	while (~scanf("%d", &s))
	{
		while (s--)
		{
			scanf("%d%d", &n, &m);
			printf("%I64d\n", b[n] / b[n - m] / b[m] * a[m]);
		}
	}
	return 0;
}
