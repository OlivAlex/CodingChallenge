#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>


void recursive(const char *file)
{
    DIR *dr;
    struct dirent *de;

    if (!(dr = opendir(file)))
        return;

    while ((de = readdir(dr)) != NULL) {
        if (de->d_type == DT_DIR) {
	    if (strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0)
                continue;
       	} 
        printf(" %s", de->d_name);
        printf("\n");
    }
	
    closedir(dr);
}



void lsOneParam(struct dirent *de, DIR *dr, int option){
	struct stat fileData;  
	struct passwd *pw = getpwuid(fileData.st_uid);
 	struct group  *gr = getgrgid(fileData.st_gid);
	while ((de = readdir(dr)) != NULL){
        	printf(" %s ", de->d_name);
  		
		if(option == 1){
			stat(de->d_name, &fileData);

			printf(" %ld ", fileData.st_size/1000);
  			

			mode_t permissionsBits = fileData.st_mode;
			
			if(permissionsBits & S_IRUSR){
				printf("r");
			}else{
				printf("-");

			}
			if(permissionsBits & S_IWUSR){
				printf("w");
			}else{
				printf("-");

			}
			if(permissionsBits & S_IXUSR){
				printf("x");
			}else{
				printf("-");

			}
			if(permissionsBits & S_IRGRP){
				printf("r");
			}else{
				printf("-");

			}
			if(permissionsBits & S_IWGRP){
				printf("w");
			}else{
				printf("-");

			}
			if(permissionsBits & S_IXGRP){
				printf("x");
			}else{
				printf("-");

			}
			if(permissionsBits & S_IROTH){
				printf("r");
			}else{
				printf("-");

			}
			if(permissionsBits & S_IWOTH){
				printf("w");
			}else{
				printf("-");

			}
			if(permissionsBits & S_IXOTH){
				printf("x");
			}else{
				printf("-");

			}
		printf(" %ld",fileData.st_nlink);
		printf(" %s\n", ctime(&fileData.st_mtime));
		struct passwd *pw = getpwuid(fileData.st_uid);
 		struct group  *gr = getgrgid(fileData.st_gid);
		printf(" %p ", pw->pw_name); 
		printf(" %p ", gr->gr_name);
		}  
		printf("\n");
	 } 
	
}
void lsNoParam(struct dirent *de, DIR *dr){
	struct stat fileData;  
	while ((de = readdir(dr)) != NULL){
 	       printf("%s ", de->d_name); 
	} 
	printf("\n ");
}


int main(int rgcm, char ** argv){ 
  struct dirent *de; 
  DIR *dr = opendir("."); 
  
  // opendir returns NULL if couldn't open directory
  if (dr == NULL)   
    { 
        printf("NOT AVAILABLE" ); 
        return 0; 
    } 
	if(rgcm > 1){
		if(strcmp(argv[1], "-1")== 0){

			if(strcmp(argv[2], "-s")== 0){
				lsOneParam(de, dr, 1);
			}else{
				lsOneParam(de, dr, 0);
			}
		}
		if(strcmp(argv[1], "-R")== 0){
			
			recursive(".");// Sends files in current directory
 		}
		
		
	}else{
 	 	lsNoParam(de, dr);
	} 

}