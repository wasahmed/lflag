#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include "libft/libft.h"

int main(int argc, char* argv[])
{
    DIR *thedirectory;
    struct dirent *thefile;
    struct stat thestat;
    struct passwd *tf; 
    struct group *gf;
    char buf[1000];
	
    thedirectory = opendir(argv[1]);
	if (argc == 2)
	{ 
    	while((thefile = readdir(thedirectory)) != NULL) 
    	{
        	sprintf(buf, "%s/%s", argv[1], thefile->d_name);// strjoin
	    	stat(buf, &thestat);
        	// [file type]
			if ((thestat.st_mode & S_IFMT) == S_IFDIR)
				printf("%s", "d");
			else
				printf("%s", "-");
        	//[permissions]
        	printf( (thestat.st_mode & S_IRUSR) ? "r" : "-");
        	printf( (thestat.st_mode & S_IWUSR) ? "w" : "-");
        	printf( (thestat.st_mode & S_IXUSR) ? "x" : "-");
        	printf( (thestat.st_mode & S_IRGRP) ? "r" : "-");
        	printf( (thestat.st_mode & S_IWGRP) ? "w" : "-");
        	printf( (thestat.st_mode & S_IXGRP) ? "x" : "-");
        	printf( (thestat.st_mode & S_IROTH) ? "r" : "-");
        	printf( (thestat.st_mode & S_IWOTH) ? "w" : "-");
        	printf( (thestat.st_mode & S_IXOTH) ? "x" : "-");

        	// [number of hard links]
        	printf(" %d ", thestat.st_nlink);

        	//[owner] 
        	tf = getpwuid(thestat.st_uid);
        	printf(" %s ", tf->pw_name);

        	//[group]
        	gf = getgrgid(thestat.st_gid);
        	printf(" %s ", gf->gr_name);

        	//[size in bytes] [time of last modification] [filename]
        	printf("%lld",thestat.st_size);
        	printf(" %s", ctime(&thestat.st_mtime));

        	printf(" %s", thefile->d_name);
    	}
		closedir(thedirectory);
	}
}
