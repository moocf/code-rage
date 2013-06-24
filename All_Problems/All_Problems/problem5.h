#include <stdio.h>
#include <stdlib.h>

#define		NULL		0
#define		MAX_STRLEN	1024

int diffString(char* org, char* mod)
{
	int		i;
	for(i = 0; org[i] && mod[i]; i++)
		if(org[i] != mod[i]) return(i);
	return(-1);
}


void exec(int argc, char* argv[])
{
	int		diff;
	char	*org, *mod, *font;
	FILE	*inp, *out;

	if(argc < 3) return;
	org = (char*) malloc(MAX_STRLEN);
	mod = (char*) malloc(MAX_STRLEN);
	inp = fopen(argv[1], "r");
	out = fopen(argv[2], "w");
	while(fscanf(inp, "%s %s", org, mod) > 0)
	{
		diff = diffString(org, mod);
		if(diff >= 0)
		{
			if((org[diff] >= 'A') && (org[diff] <= 'Z')) font = "upper";
			else font = "lower";
			fprintf(out, "Ripping the %s-case \"%c\" from his shirt, Letterman \nchanges \"%s\" back to \"%s\".\n", font, org[diff], mod, org);
		}
		fscanf(inp, "%c", org);
	}
	fclose(inp);
	fclose(out);
}