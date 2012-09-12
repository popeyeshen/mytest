#include "stdio.h"
#include "time.h"

#define popeye(a, b...) printf(b)
static int FindJsonString(char *inputStr, char *token, char *resultStr, int nBufferSize);
char MyStr[] = "{\"name\" : popeye2, \"id\" : \"123 456\"\t, popeye3\t : 5678\n9,}";
char szData[] = "127.0.0.1,00-11-22-33-44-55,19992,0,12,0";
#define ContAB(a, b, c) \
/*popeye*/ \
char a ## b ## c[] = "1234567890"


ContAB(My, 1, Str);

int main(int argc, char *argv[])
{
	 char *str;
   char findStr[128];
#if 0
   //popeye(eeee, "EEEE is %d %s", 1000, "2000");
   if (FindJsonString(MyStr, "popeye", findStr, 128) == 0)
   	printf("Find popeye %s\n", findStr);
   if (FindJsonString(MyStr, "popeye2", findStr, 128) == 0)
   	printf("Find popeye2 %s\n", findStr);
   if (FindJsonString(MyStr, "popeye3", findStr, 128) == 0)
   	printf("Find popeye3 %s\n", findStr);
   if (FindJsonString(MyStr, "popeye4", findStr, 128) == 0)
   	printf("Find popeye4 %s\n", findStr);
	 else
	  printf("Not Found popeye4\n");

		{
			
			str = (char *)strstr(MyStr, "popeye");
			if (str)
			{
				str = str + strlen("popeye");
				if (FindJsonString(str, "id", findStr, 128) == 0)
					printf("id=%s\n", findStr);
			}
			else
			{
				printf("Not Found %s\n", "popeye");
			}
		}
#endif	  
	char *ptr;
	int i;
	char clientBuf[100];
	time_t t;

	t = time(NULL);
	printf("%%time = %d\n", t);
	sprintf(clientBuf, "%%PINFUN=%d", 1);
	printf("%s\n", clientBuf);
	strcpy(clientBuf, szData);
	for (ptr = strtok(clientBuf, ","), i = 0; (i < 6 && ptr); i++, ptr = strtok(NULL, ","))
	{
		printf("%s\n", ptr);
	}
	printf("i = %d\n", i);
	printf("%s\n", My1Str);
}



static int FindJsonString(char *inputStr, char *token, char *resultStr, int nBufferSize)
{
	char *str;
	int i = 0;
	int quot = 0;

	str = (char *)strstr(inputStr, token);
	if (str)
	{
		while(*str != ':' && *str != '\0') str++;
		if (*str == ':')
		{
			str++;
			while(*str == ' ' || *str == '\t') str++;
			if (*str == '\'' || *str == '"')
			{
				str++;
				quot = 1;
			}
			while(*str != '\n' && *str != '\r' && *str != '\0')
			{
				resultStr[i] = *str;
				i++; str++;
				if (i == nBufferSize -1)
					break;
				if (quot == 1)
				{
					if  (*str == '\''  || *str =='"')
						break;
				}
				else
				{
					if (*str == ',' || *str == ' ' || *str =='\t')
						break;
				}
			}
			resultStr[i] = '\0';
		}
	}
	else
		return -1;
	if (i > 0)
		return 0;
	else
		return -1;
}

