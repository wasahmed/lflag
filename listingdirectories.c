//How to use DIR, opendir, readdir, closedir(read manuals for parameters)
//Lists whats in a particular directory given as an argument
#include <stdio.h>
#include <dirent.h>

int main (int argc, char **argv) 
{
	int len;
    struct dirent *pDirent;    //for d_name?
    DIR *dirp;                //data type to hold the directory path

    if (argc == 2) 
	{
    	dirp = opendir (argv[1]);
    	if (dirp == NULL) // error handling
		{
			printf ("Cannot open directory '%s'\n", argv[1]);
				return (1);
    	}
		while ((pDirent = readdir(dirp)) != NULL) //
		{
			printf ("%s\n", pDirent->d_name);
    	}
    	closedir (dirp);
	}
   	return (0);
}
