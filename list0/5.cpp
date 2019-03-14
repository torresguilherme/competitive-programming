// UVa 151
#include <iostream>
#include <cstdio>
using namespace std;

bool was_all_blacked_out(bool *regions, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(regions[i] == false)
            return false;
    }

    return true;
}

int min_m(int n)
{
    for(int i = 1; i <= __INT_MAX__; i++)
    {
        int current = 0;
        bool regions[n];
        for(int j = 0; j < n; j++)
        {
            regions[j] = false;
        }
        regions[0] = true;
        while(!was_all_blacked_out(regions, n))
        {
            int leaps_left = i;
            while(leaps_left)
            {
                current++;
                current %= n;
                if(regions[current] == false)
                {
                    leaps_left--;
                }
            }
            regions[current] = true;
        }
        if(current == 12)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int n;
    scanf("%d", &n);
    while(n)
    {
        int m = min_m(n);
        cout<<m<<endl;
        scanf("%d", &n);
    }

    return 0;
}