#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 9 ;
int n , m , start[N] , en[N] ;
int main()
{
    freopen("trash.inp" , "r" , stdin) ;
    cin >> n >> m ;
    for(int i = 1 ; i <= n ; i++)
        cin >> start[i] ;
    for(int i = 1 ; i <= m ; i++)
        cin >> en[i] ;
    map<long long , int > mp ;
    for(int i = 1 ; i <= n ; i++ )
    {
        for(int j = 1 ; j <= m ; j ++ )
        {
            mp[en[j] - start[i]]++;
        }
    }
    int Max = 0 , id = 0 ;
    for(auto t : mp)
    {
        cout << t.second << ' ' << t.first << endl;
        if(t.second > Max)
           {
             id = t.first ;
             Max = t.second ;
           }
        else if(t.second == Max)
        {
            if(id > t.first)
            id = t.first;
        }
    }
    cout << Max  << ' ' << id  ;
}
