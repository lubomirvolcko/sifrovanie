#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



int main()
{
 
  FILE *fr, *fw;
  fr=fopen("sifrovany_text.txt","r");
  if(fr==NULL){
     printf("ERROR! I cannot open the file !");
     return 1;
  }
  fw=fopen("text.txt","w");
  if(fw==NULL){
     printf("ERROR! I cannot open the file !");
     fclose(fr);
     return 1;
  }
  


  
  char z;
  while( (z=fgetc(fr)) != EOF ){
    putchar(z);
    
     	if((z)=='%'){
	      fputc (' ',fw);
	}
	
	else if((z=='y'||z=='Y')){
		fputc ('i', fw);
	}
	else if (z>='a'&&z<='z'||z>='A'&&z<='Z')
    	fputc(z-1,fw);
	
	else if((z=='i'||z=='I'))
		fputc('y',fw);
	
	else
	     fputc ( z ,fw); 
	
	}
 

  
  fclose(fr);
  fclose(fw);
  
  
  return 0;
}
