#include <stdio.h>

#define MAX_LENGTH 9999

int ins[MAX_LENGTH];
int cls[MAX_LENGTH];

FILE *stream, *fopen();

int main(int argc, char **argv)
{
	if (argc < 2) {
		puts("Usage: <executable> <file name/path>");
		return 1;
	}

	int ilen = 0;		// Length of the ins array.
	int *ptr = cls;		// Pointer to the current active cell.
	int *iptr = ins;	// Pointer to the current instruction.

	stream = fopen(argv[1], "r");

	// Read the brainfuck to execute from the given file.
	while (ilen < MAX_LENGTH && (ins[ilen] = getc(stream)) != EOF)
		ilen++;

	fclose(stream);

        memset(cls, 0, MAX_LENGTH);

	int blc = 0;		// Keep count of open bracket pairs.

	while ((iptr - ins) < ilen) {
		switch (*iptr) {
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
			if (*ptr != 0)
				break;

			++iptr;
			// Jump forwards to matching closing brace.
			while (blc > 0 || *iptr != ']') {
				blc += *iptr == '[' ? 1 : *iptr == ']' ? -1 : 0;

				++iptr;
			}
			break;
		case ']':
			if (*ptr == 0 && ptr++)
				break;

			--iptr;
			// Jump backwards to matching opening brace.
			while (blc > 0 || *iptr != '[') {
				blc -= *iptr == '[' ? 1 : *iptr == ']' ? -1 : 0;

				--iptr;
			}

			--iptr;
			break;
		}

		iptr++;
	}
	
	putchar('\n');

	return 0;
}