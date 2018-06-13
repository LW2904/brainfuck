#include <stdio.h>

int main(int argc, char **argv)
{
	int pc, args, xc, prog_len, l = 0;
	int x[32768];
	int p[32768];

	FILE *stream, *fopen();

	for (args = 1; args < argc; args++)
	{

		stream = fopen(argv[args], "r");

		prog_len = 0;

		for (pc = 0; pc < 32768 && (p[pc] = getc(stream)) != EOF; pc++)
			prog_len++;

		pc = 0;

		fclose(stream);

		for (xc = 0; xc < 32768; xc++)
			x[xc] = 0;

		xc = 0;

		for (pc = 0; pc < prog_len; pc++)
		{

			// '+'
			if (p[pc] == 43)
				x[xc]++;

			// '-'
			else if (p[pc] == 45)
				x[xc]--;

			// '.'
			else if (p[pc] == 46)
				putchar(x[xc]);

			// ','
			else if (p[pc] == 44)
				x[xc] = getchar();

			// '>'
			else if (p[pc] == 62)
				xc++;

			// '<'
			else if (p[pc] == 60)
				xc--;

			// '['
			else if (p[pc] == 91)
			{
				if (x[xc] == 0)
				{
					pc++;
					while (l > 0 || p[pc] != 93)
					{
						if (p[pc] == 91)
							l++;
						if (p[pc] == 93)
							l--;
						pc++;
					}
				}
			}

			// ']'
			else if (p[pc] == 93)
			{
				pc--;
				while (l > 0 || p[pc] != 91)
				{
					if (p[pc] == 93)
						l++;
					if (p[pc] == 91)
						l--;
					pc--;
				}
				pc--;
			}
		}
	}

	putchar(10);
	return 0;
}