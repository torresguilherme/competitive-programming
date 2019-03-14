// UVa 119
#include <iostream>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

int main()
{
    bool first_time = true;
    int people_count;
    while(scanf("%d", &people_count) != EOF)
    {
        if(!first_time)
        {
            cout<<endl;
        }
        first_time = false;
        map<string, int> people;
        string people_array[people_count];
        for(int i = 0; i < people_count; i++)
        {
            cin>>people_array[i];
            people.insert(pair<string, int>(people_array[i], 0));
        }

        for(int i = 0; i < people_count; i++)
        {
            string giver;
            int total;
            int receivers;
            cin>>giver>>total>>receivers;
            for(int j = 0; j < receivers; j++)
            {
                string receiver;
                cin>>receiver;
                people[receiver] += total / receivers;
                people[giver] -= total / receivers;
            }
        }

        for(int i = 0; i < people_count; i++)
        {
            cout<<people_array[i]<<' '<<people[people_array[i]]<<endl;
        }
    }

    return 0;
}