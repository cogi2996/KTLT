void 2TO1 (int m,int n,int a[])
{
    int b[100];
    int temp = 0 ;
    for(int i = 0;i<m;i++)
    {
        for(int j  = 0;j<n;j++)
        {
            a[i][j]  = b[temp++];
        }
    }
    
}