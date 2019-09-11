#include<stdio.h>
#include <dirent.h>
#include <string.h>
int		main(int argc,char **argv)
{
	DIR *dirp;
	struct dirent *dpath;
	dirp = opendir(argv[1]);   
	
	if(dirp!=NULL)
	{
		while ((dpath = readdir(dirp))!=NULL)
		{
			if((strcmp(dpath -> d_name, ".") == 0 || strcmp(dpath -> d_name, "..") == 0 || (*dpath -> d_name) == '.' ))
            {
				
            }
			else
			{
				printf("%s", dpath -> d_name);
				printf("\t\n");
			}
		}
	}
	closedir(dirp);
}
