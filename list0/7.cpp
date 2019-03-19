// UVa 220
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int number_of_games;
    cin>>number_of_games;

    while(number_of_games--)
    {
        char map[8][8];
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                scanf(" %c", &map[i][j]);
            }
        }

        char command = 0;
        while(command != 'Q')
        {
            scanf(" %c", &command);
            switch (command)
            {
                case 'M': // make move
                    break;
                
                case 'L': // list legal moves
                    break;
            
                default:
                    break;
            }
        }

        cout<<endl;
    }

    return 0;
}