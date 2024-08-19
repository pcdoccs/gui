#include<stdio.h>
#include<string.h>
#define DLE 16
#define STX 2
#define ETX 3

int main(){

	char ch,array[100]={DLE,STX};
	int i=2,j;
	
	printf("\nEnter the data to be transmitted(@-DLE,#-STX,$-ETX):");
	
	do{
	scanf("%c",&ch);
	if(ch=='\n')
	break;
	else if(ch=='@')
	ch=DLE;
	else if(ch=='#')
	ch=STX;
	else if(ch=='$')
	ch=ETX;
	array[i++]=ch;
	if(ch==DLE)
	array[i++]=DLE;
	}while(ch!='\n');
	
	array[i++]=DLE;
	array[i++]=ETX;
	printf("\nThe transmitted bit stream is:");
	
	for(j=0;j<i;j++){
	if(array[j]==DLE)
	printf("DLE");
	else if(array[j]==STX)
	printf("STX");
	else if(array[j]==ETX)
	printf("ETX");
	else 
	printf("%c",array[j]);
	}
	
	printf("\nRecieved bit stream is:");

	for(j=2;j<i-2;j++){
	if(array[j]==DLE){
	printf("DLE");
	j++;}
	else if(array[j]==STX)
	printf("STX");
	else if(array[j]==ETX)
	printf("ETX");
	else
	printf("%c",array[j]);
	}
	
	return 0;	
}
