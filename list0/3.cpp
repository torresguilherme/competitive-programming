// UVa 118

/***************** DIRECTIONS:
 *	1
 *  4	    2
 *  	3
 * **************/
#include <iostream>
#include <cstdio>

using namespace std;

struct Robot
{
	int dir;
	int pos_x;
	int pos_y;
	bool lost;

	void move(char **map, int max_x, int max_y, char order)
	{
		switch(order)
		{
			case 'R':
				dir = dir % 4 + 1;
				break;
			case 'L':
				dir = dir % 4 - 1;
				break;
			case 'F':
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
					if(!map[max_y - pos_y - 1][pos_x] & (1 << dir))
					{
						lost = true;
						map[max_y - pos_y - 1][pos_x] &= (1 << dir);
						pos_x = new_x;
						pos_y = new_y;
					}
				}
				else
				{
					pos_x = new_x;
					pos_y = new_y;
				}
		}
	}
};

int main()
{
	int max_x, max_y;
	cin>>max_x>>max_y;

	char map[max_x][max_y];

	for(int i = 0; i < max_x; i++)
		for(int j = 0; j < max_y; j++)
			map[i][j] = 0;
		
	return 0;
}
