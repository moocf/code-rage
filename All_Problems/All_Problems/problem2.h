#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define		NULL		0
#define		MAX_STRLEN	1024


char	**cross, **cross_n, **cross_t;
char	word[MAX_STRLEN];
int		row, col, count;
int		rows, cols;

char **allocCross()
{
	int		i;
	char	**crs;

	crs = (char**) malloc(rows * sizeof(char*));
	for(i=0; i<rows; i++)
		crs[i] = (char*) malloc(cols * sizeof(char));
	return(crs);
}

void clearString(char *str)
{
	while(str)
	{
		*str = '\0';
		str++;
	}
}

void stringizeCross()
{
	int  i, j;

	for(i=0; i<rows; i++)
		for(j=0; j<cols; j++)
			if((cross[i])[j] == '*') (cross[i])[j] = NULL;
}

void copyCross()
{
	int		i, j;

	for(i=0; i<rows; i++)
		for(j=0; j<cols; j++)
			(cross_t[i])[j] = (cross[i])[j];
}

void transposeCross()
{
	int		i, j;

	for(i=0; i<rows; i++)
		for(j=0; j<cols; j++)
			(cross_t[j])[i] = (cross[i])[j];
}

bool nextStep()
{
	col++;
	if(col >= cols)
	{
		col -= cols;
		row++;
		if(row >= rows) return(false);
	}
	return(true);
}

bool searchString()
{
	int		i, j;

	while(1)
	{
		if((cross[row])[col] == '\0')
		{
			if(nextStep()) continue;
			return(false);
		}
		i = strlen((cross_t[row])+col);
		if(i > 0) count++;
		if(i >= 2)
		{
			strcpy(word, (cross_t[row])+col);
			clearString((cross_t[row])+col);
		}
		return(nextStep());
	}
}

void exec(int argc, char* argv[])
{
	int		i;
	char	c;
	FILE	*inp, *out;

	if(argc < 3) return;
	inp = fopen(argv[1], "r");
	out = fopen(argv[2], "w");
	fscanf(inp, "%d %d", &rows, &cols);
	fscanf(inp, "%c", &c);
	cross = allocCross();
	cross_t = allocCross();
	// Accept Input
	for(i=0; i<rows; i++)
	{
		fscanf(inp, "%s", cross[i]);
		fscanf(inp, "%c", &c);
	}
	stringizeCross();

	// Horizontal Search
	copyCross();
	row = 0;
	col = 0;
	count = 0;
	fprintf(out, "Across\n");
	while(searchString())
	{
		fprintf(out, "%d. %s\n", count, word);
	}

	// Vertical Search
	transposeCross();
	row = 0;
	col = 0;
	count = 0;
	fprintf(out, "Down\n");
	while(searchString())
	{
		fprintf(out, "%d. %s\n", count, word);
	}
	fclose(inp);
	fclose(out);
}