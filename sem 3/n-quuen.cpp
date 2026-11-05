#include <iostream>
using namespace std;
#define N 4
int col[N+1],rd[2*N-1],ld[2*N-1],board[N+1];
bool queen(int i)
{
    for(int j=1;j<=N;j++)
    {
        if(col[j]==0 && rd[i+j-1]==0 && ld[i+N-j]==0)
        {
            board[i]=j;
            // col[j]=rd[i+j-1]=ld[i+N-j]=1;
            col[j]=1;
            rd[i+j-1]=1;
            ld[i+N-j]=1;    
            if(i==N)
                return true;
            else if(queen(i+1)==true)
            {
                return true;
            }
            board[i]=0;
            col[j]=0;
            rd[i+j-1]=0;
            ld[i+N-j]=0;             
        }
    }
    return false;
}
int main()
{
   int i=1;
   queen(i);
   for(int j=1;j<=N;j++) 
   {
        // cout<<" "<<board[i];
        cout<<" "<<board[j];
   }                                                                                                                                                                                               
   return 0;

}
//.............................................................................N-Queen's problem..