/*
// < simulated annealing >
// p = e^(-(E2-E1)/kT)
// if( p>rand() ) : new state
 */
#include <stdio.h>
#include <algorithm>
#include <time.h>
#include <math.h>
using namespace std;
int n;
struct state
{
    char str[33][33];
    int cnt[33];
    int res()
    {
        int res = 0;
        for(int i = 0;i<n;i++)
            res += min(cnt[i],n-cnt[i]);
        return  res;
    }
}old,neew;

void change()
{
    neew = old;
    int i = rand()%n;
    for(int j = 0;j<n;j++)
    {
        if(neew.str[j][i] == 'T')
        {
            neew.cnt[j]--;
            neew.str[j][i] = 'H';
        }
        else
        {
            neew.cnt[j]++;
            neew.str[j][i] = 'T';
        }
    }
}
int main()
{
    srand(10000000004);
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
    {
        scanf("%s",old.str[i]);
        for(int j = 0;j<n;j++)
            if(old.str[i][j] == 'T')
                old.cnt[i]++;
    }
    double temp = 1;
    for(int i = 0;i<3000000;i++)
    {
        change();
        if(old.res() - neew.res()>log(rand()%100000/1e5)*1.7863*temp)
            old = neew;
        temp *= 0.9999;
    }
    printf("%d\n",old.res());

}
