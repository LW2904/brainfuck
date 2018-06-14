#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_LENGTH 9999

int ins[MAX_LENGTH];

FILE *stream, *fopen();

int main(int argc, char **argv)
{
	int ilen = 0, c;

	char *inp = 0;
	char *out = 0;

	while ((c = getopt(argc, argv, "i:o:")) != -1) {
		switch (c) {
		case 'i':
			inp = optarg;
			break;
		case 'o':
			out = optarg;
			break;
		}
	}

	stream = fopen(inp, "r");

	while (ilen < MAX_LENGTH && (ins[ilen] = getc(stream)) != EOF)
		ilen++;

	fclose(stream);

	puts("");
}