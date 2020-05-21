
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int wc=0;
int cc=0;
char c;
int main(int argc,char *argv[])
{
	int i=0,j=0;
	char str[10000];
	FILE *fp;
	if((fp=fopen(argv[2],"r"))==NULL)
	{
		printf("读取文件失败!\n");
		exit(0);
	}
	if(strcmp(argv[1],"-c")==0)
	{
		while((c=fgetc(fp))!=EOF)
			cc++;
		fclose(fp);
		printf("字符数:%d\n",cc);
	}
	else if(strcmp(argv[1],"-w")==0)
	{
		while(fgets(str,10000,fp)!=NULL)
		{
			j=strlen(str);
			for(i=0;i<j;i++)
			{
				if(str[i]==' '&&str[i+1]!=' ')
					wc++;
				else if(str[i]==','&&str[i+1]!=' ')
					wc++;
				else if(i==j-1)
					break;
			}
		} 
		printf("单词个数:%d\n",wc);
	}
	return 0;
}
