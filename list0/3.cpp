// UVa 118

/***************** DIRECTIONS:
 *	1
 *  4	    2
 *  	3
 * **************/
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;

struct Robot
{
	int dir;
	int pos_x;
	int pos_y;
	bool lost;

	void move(vector< vector<int> > *map, int max_x, int max_y, char order)
	{
		switch(order)
		{
			case 'R':
				if(!lost)
				{
					dir++;
					if(dir > 4)
					{
						dir = 1;
					}
				}
				break;
			case 'L':
				if(!lost)
				{
					dir--;
					if(dir < 1)
					{
						dir = 4;
					}
				}
				break;
			case 'F':
			{
				int new_x = pos_x;
				int new_y = pos_y;
				switch(dir)
				{
					case 1:
						new_y = pos_y + 1;				
						break;
					case 2:
						new_x = pos_x + 1;				
						break;
					case 3:
						new_y = pos_y - 1;				
						break;
					case 4:
						new_x = pos_x - 1;				
						break;
				}

				// check for world limits
				// set scent is robot is lost
				if(new_y >= max_y || new_x >= max_x || new_y < 0 || new_x < 0)
				{
					if(!lost && !((*map)[pos_x][pos_y] & (1 << dir)))
					{
						lost = true;
						(*map)[pos_x][pos_y] |= (1 << dir);
					}
				}
				if(!lost && !((*map)[pos_x][pos_y] & (1 << dir)))
				{
					pos_x = new_x;
					pos_y = new_y;
				}
			}
		}
	}
};

int main()
{
	int max_x, max_y;
	scanf("%d %d\n", &max_x, &max_y);
	max_x++;
	max_y++;

	vector< vector<int> > map;

	for(int i = 0; i < max_x; i++)
	{
		map.push_back(vector<int>());
		for(int j = 0; j < max_y; j++)
			map[i].push_back(0);
	}

	int init_x, init_y;
	char init_dir;
	while(scanf("%d %d %c\n", &init_x, &init_y, &init_dir) != EOF)
	{
		Robot r;
		r.pos_x = init_x;
		r.pos_y = init_y;
		r.lost = false;
		switch(init_dir)
		{
			case 'N':
				r.dir = 1;
				break;
			case 'E':
				r.dir = 2;
				break;
			case 'S':
				r.dir = 3;
				break;
			case 'W':
				r.dir = 4;
				break;
		}

		char order_string[101];
		scanf("%s", order_string);

		for(int i = 0; i < strlen(order_string); i++)
		{
			r.move(&map, max_x, max_y, order_string[i]);
		}

		printf("%d %d", r.pos_x, r.pos_y);
		switch(r.dir)
		{
			case 1:
				printf(" N");
				break;
			case 2:
				printf(" E");
				break;
			case 3:
				printf(" S");
				break;
			case 4:
				printf(" W");
				break;
		}

		if(r.lost)
		{
			printf(" LOST\n");
		}
		else
		{
			printf("\n");
		}
	}
		
	return 0;
}
