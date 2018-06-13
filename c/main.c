#include <stdio.h>

#define MAX_LENGTH 9999

int cls[MAX_LENGTH];
int ins[MAX_LENGTH];

int pc, args, xc, prog_len, l = 0;

FILE *stream, *fopen();

int main(int argc, char **argv)
{
	if (argc < 2) {
		puts("expected arguments");
		return 1;
	}

	// int iind = 0;
	int ilen = 0;
	int *ptr = cls;
	int *iptr = ins;

	// Open file provided in first argument with read permissions.
	stream = fopen(argv[1], "r");

	while (ilen < MAX_LENGTH && (ins[ilen] = getc(stream)) != EOF)
		ilen++;

	fclose(stream);

	for (int i = 0; i < MAX_LENGTH; i++)
		cls[i] = 0;

	int blc = 0;

	while ((iptr - ins) < ilen) {
		printf("(ilen: %d) ins[%d]: %c - cls[%d]: %d\n", ilen, (int)(iptr - ins), (char)*iptr, (int)(ptr - cls), *ptr);

		switch (*iptr++) {
		case '+':
			++*ptr;
			break;
		case '-':
			--*ptr;
			break;
		case '>':
			++ptr;
			break;
		case '<':
			--ptr;
			break;
		case '.':
			putchar(*ptr);
			break;
		case ',':
			*ptr = getchar();
			break;
		case '[':
			printf("opening %c %d\n", (char)*iptr, blc);

			if (*ptr != 0)
				break;

			++iptr;
			while (blc > 0 || *iptr != ']') {
				if (*iptr == '[')
					++blc;
				if (*iptr == ']')
					--blc;

				++iptr;
			}
			break;
		case ']':
			printf("closing %c %d\n", (char)*iptr, blc);		

			--iptr;
			while (blc > 0 || *iptr != ']') {
				if (*iptr == ']')
					++blc;
				if (*iptr == '[')
					--blc;

				--iptr;
			}
			
			--iptr;
			break;
		}
	}
	
	putchar('\n');

	return 0;
}