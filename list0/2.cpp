// UVa 384

#include <iostream>
#include <cstring>

using namespace std;

int isSlump(char *cand, int initCount)
{
	int count = initCount;
	if(*cand != 'D' && *cand != 'E')
	{
		return 0;
	}

	*cand++;
	count++;

	if(*cand != 'F')
	{
		return 0;
	}

	while(*cand == 'F')
	{
		*cand++;
		count++;
	}

	if(*cand == 'G')
	{
		return count;
	}
	else
	{
		return isSlump(cand, count);
	}
}

int isSlimp(char *cand, int initCount)
{
	int count = initCount;
	if(*cand != 'A')
	{
		return 0;
	}

	*cand++;
	count++;

	if(*cand == 'H')
	{
		return count;
	}

	if(*cand == 'B')
	{
		*cand++;
		count++;
		int slimp = isSlimp(cand, 1);
		if(slimp)
		{
			while(slimp--)
			{
				*cand++;
				count++;
			}
			if(*cand == 'C')
			{
				return count;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
	else
	{
		int slump = isSlump(cand, 1);
		if(slump)
		{
			while(slump--)
			{
				*cand++;
				count++;
			}
			if(*cand == 'C')
			{
				return count;
			}
			else 
			{
				return 0;
			}
		}
		else
		{
			return 0;
		}
	}
}

bool isSlurpy(char *cand)
{
	int slimp = isSlimp(cand, 1);
	for(int i = 0; i < slimp; i++)
	{
		*cand++;
	}
	int slump = isSlump(cand, 1);
	for(int i = 0; i < slump; i++)
	{
		*cand++;
	}	
	return slimp && slump && (*cand == 0);
}

int main()
{
	int count;
	cin>>count;

	cout<<"SLURPYS OUTPUT"<<endl;
	while(count--)
	{
		char cand[1024];
		cin>>cand;
		if(isSlurpy(cand))
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	cout<<"END OF OUTPUT"<<endl;
}
