#include <iostream>

using namespace std;

int main()
{
    int n = 7;
    
    for(int i=0; i<n;i++)
        cout<<'*';
    cout<<endl;
        
    int n1 = (n/2);
    for(int i = 1;i<=n1;i++){
        for(int j = 1; j<=n1-i+1;j++)
            cout<<'*';
        for(int l = 1; l<=2*i-1;l++)
            cout<<' ';
        for(int k = 1; k<=n1-i+1;k++)
            cout<<'*';
        cout<<endl;
    }
    for(int i = n1-1;i>=1;i--){
        for(int j = 1; j<=n1-i+1;j++)
            cout<<'*';
        for(int l = 1; l<=2*i-1;l++)
            cout<<' ';
        for(int k = 1; k<=n1-i+1;k++)
            cout<<'*';
        cout<<endl;
    }
    
    for(int i = 0; i < n; i++)
        cout<<'*';

    return 0;
}
