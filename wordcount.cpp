#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	int wordcount=0;
	int signalcount=0;
	int temp;
	int tempt=NULL;
	FILE *pt;
	if(argc==1)
	{
		printf("��ʹ�ø�ʽ:%s",argv[0]);
		exit(0);
	}
	if((pt=fopen(argv[1],"r+"))==NULL)
	{
		printf("%s�ļ���ʧ��\n",argv[1]);
		exit(1);
	}
	else
		printf("yes\n");
	fseek(pt,0L,0);
	while(!feof(pt))
	{
		temp=fgetc(pt);
		printf("h\n");
		if(temp==' '||temp=='\n')
			signalcount++;
		if(temp==' '||temp=='\n'||temp==',')
			wordcount++;
		tempt=temp;
	}
	printf("wordnumber:%d\n",wordcount);
	printf("signalnumber:%d\n",signalcount);
	fclose(pt);
	return 0;
}