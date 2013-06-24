#include <stdio.h>
#include <stdlib.h>

// Constants
#define		MAX_STRLEN	1024

/*
  diffString(original_string, modified_string)
  
  Compares two strings and give the index of the character at which they differ
  
  Parameters:
    original_string = The original string by the Letterman
    modified_string = The modified string by Spellbinder
  
  Returns:
    The index at which characters in the two strings first differ from each other
    Returns -1 for no mismatch between the two strings
*/
int diffString(char* org, char* mod)
{
	int		i;
	
	// Match the characters of the two strings, one by one, till they differ,
	// or when any one string ends
	for(i = 0; org[i] && mod[i]; i++)
		if(org[i] != mod[i]) return(i);
		
	// Return -1 if all characters match
	return(-1);
}


/*
  main(no. of arguments, string array of arguments)
  
  Parameters:
    original_string = The original string by the Letterman
    modified_string = The modified string by Spellbinder
  
  Returns:
    The index at which characters in the two strings first differ from each other
    Returns -1 for no mismatch between the two strings
*/
int main(int argc, char* argv[])
{
	int		diff;
	char	org[MAX_STRLEN], mod[MAX_STRLEN], *font;
	FILE	*inp, *out;

	if(argc < 3) return(0);
	inp = fopen(argv[1], "r");
	out = fopen(argv[2], "w");
	while(fscanf(inp, "%s %s", org, mod) > 0)
	{
		diff = diffString(org, mod);
		if(diff >= 0)
		{
			if((org[diff] >= 'A') && (org[diff] <= 'Z')) font = "upper";
			else font = "lower";
			fprintf(out, "Ripping the %s-case \"%c\" from his shirt, Letterman \nchanges \"%s\" back to \"%s\".\n",
            font, org[diff], mod, org);
		}
		fscanf(inp, "%c", org);
	}
	fclose(inp);
	fclose(out);
	return(0);
}
