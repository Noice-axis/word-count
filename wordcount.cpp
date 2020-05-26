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
		printf("请使用格式:%s",argv[0]);
		exit(0);
	}
	if((pt=fopen(argv[1],"r+"))==NULL)
	{
		printf("%s文件打开失败\n",argv[1]);
		exit(1);
	}
	fseek(pt,0L,0);
	while(!feof(pt))
	{
		temp=fgetc(pt);
		if(temp==' '||temp=='\n')
			signalcount++;
		if((temp==' '||temp=='\n'||temp==',')&&(tempt!=' ')&&(tempt!=',')&&(tempt!='\n'))
			wordcount++;
		tempt=temp;
	}
	printf("wordnumber:%d\n",wordcount);
	printf("signalnumber:%d\n",signalcount);
	fclose(pt);
	return 0;
}