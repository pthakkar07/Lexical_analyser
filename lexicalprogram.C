#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
int iskeyword(char buffer[]){
    char keywords[7][10] = {"int","printf","scanf","void","main","include","stdio.h"};
    int i, flag = 0;

    for(i = 0; i < 7; ++i){
	if(strcmp(keywords[i], buffer) == 0){
	    flag = 1;
	    break;
	}
    }

    return flag;
}

int isconstant(char buffer[]){
int i,flag=0;
for(i=0;i<strlen(buffer);i++){
	if(!isdigit(buffer[i])){
		flag=1;
		break;
	}
}
return(flag);
}
//to check under braket constant;
int isunderbrac(char buffer[]){
int i,flag=1;

if(buffer[0]=='"'&&buffer[strlen(buffer)-1]=='"'){
	flag=0;
	for(i=0;i<strlen(buffer)-1;i++){
		buffer[i]=buffer[i+1];
	}
	buffer[i-1]='\0';
}
return(flag);
}
//function for keyword
void main(){
FILE *fp;
char ch,operator[]="&+-*/%=";
char scharacter[]="#();<>";
int i,j=0;
char buffer[10];
char constant[10];
clrscr();
fp=fopen("sampleprogram.c","r");
if(fp==NULL){
printf("There is a problem while opening file");
}
else {
while((ch=fgetc(fp))!=EOF){
 for(i=0;i<7;i++){  //function to check operator
	if(ch==operator[i]){
     // printf("%c is an operator\n",ch);
	}
 }
 for(i=0;i<7;i++){
	if(ch==scharacter[i]){
       //		printf("%c is an special character\n",ch);
	}
	}
 if(isalnum(ch)||ch=='.'||ch=='"'||ch=='%'){
	buffer[j++]=ch;
 }
 if((ch==' '||ch=='\n'|| ch=='('|| ch=='<'||ch=='='||ch==';'||ch==',')&&(j!=0))
	{
		buffer[j]='\0';
	      //	printf("buffer for checking is %s\n",buffer);
		j=0;
		if(iskeyword(buffer)==1){  //function to keyword
	    //	printf("%s is an keyword\n",buffer);
								}
		else {if((isconstant(buffer)==0)|| (isunderbrac(buffer)==0)){
		  //	printf("%s is a constant\n",buffer);
		}
		else {
		//	printf("%s is an identifier\n",buffer);
		}
		}


}
}

}
getch();
}

/*
#include<stdio.h>
void main()
{
	int a,b;
	int c=10;
	printf("hey");
	scanf("%d",&a);
	printf("%d",a);
}

*/
