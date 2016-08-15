#include "pixutils.h"

int main(int argc, char *argv[]){
  char *inputfile=0,*outputfile=0;
  float degrees=0;
  char grayFlag=0;
  char bmpFlag=0;
  char sortFlag=0;
  int i=1;
  while (i<argc){
			//check for flags -i -o -f -d -b
			if(strcmp(argv[i],"-r") == 0){ 
				degrees=atof(argv[i+1]);
				i+=2;
			}
			else if(strcmp(argv[i],"-g") == 0){ 
				grayFlag=1;
				i++;
			}
			else if(strcmp(argv[i],"-i") == 0){
				inputfile=argv[i+1];
				i+=2;
			}	
	  else if(strcmp(argv[i],"-o")==0){
				outputfile=argv[i+1];
			 i+=2;
			}
			else if (strcmp(argv[i],"-b")==0){
				bmpFlag=1;
				i++;
			}
			else if (strcmp(argv[i],"-s")==0){
				sortFlag=1;
				i++;
			}
			else{
				fprintf(stderr,"pngPlay -g -r degrees -i inputfile -o outputfile  ");
				exit(0);
			}	
		}		
  pixMap *p=pixMap_init_filename(inputfile);
  if(sortFlag)pixMap_sort(p);
  if(degrees)pixMap_rotate(p,degrees);
  if(grayFlag)pixMap_gray(p);
  if(bmpFlag)pixMap_write_bmp16(p,outputfile);
  else pixMap_write(p,outputfile);
  pixMap_destroy(p);
  return 0;
}

