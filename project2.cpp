#include<bits/stdc++.h>
using namespace std;
void print(int **grid,int N)
{
    cout << "\t\t\t\t\t------------------------------------------------------" << endl;
      for(int i=0;i<N;i++)
           {
               cout << "\t\t\t\t\t" ;
             for(int j=0;j<N;j++)
             {
                 if(grid[i][j]!=-1)
                 cout<< " |" << grid[i][j] << "| " << " ";
                 else
                 cout<< " | | " << " ";
             }
             cout << endl;
             cout << "\t\t\t\t\t------------------------------------------------------" << endl;
          }
}
bool isSmallGrid(int **grid,int row,int col,int num)
{
    int rowfac=row-(row%3);
    int colfac=col-(col%3);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(grid[i+rowfac][j+colfac]==num)
            {
                return false;
            }
        }
    }
    return true;
}
bool isCol(int **grid,int col,int num,int N)
{
    for(int i=0;i<N;i++)
    {
        if(grid[i][col]==num)
            return false;
    }
    return true;
}
bool isRow(int **grid,int row,int num,int N)
{
    for(int i=0;i<N;i++)
    {
        if(grid[row][i]==num)
            return false;
    }
    return true;
}
bool isSafe(int **grid,int row ,int col,int num,int N)
{
    if(N==10)
    {
    if(isRow(grid,row,num,N) && isCol(grid,col,num,N))
     {
        return true;
     }
    }
    else if(N==9)
    {
        if(isSmallGrid(grid,row,col,num) && isRow(grid,row,num,N) && isCol(grid,col,num,N))
        {
            return true;
        }
    }
    return false;
}
bool findEmptyLocation(int **grid,int &row , int &col,int N)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
           if(grid[i][j]==-1)
           {
               row=i;
               col=j;
           return true;
           }
        }
    }
    return false;
}
bool isGrid(int **grid,int N)
{
        int row,col;
           if(!findEmptyLocation(grid,row,col,N))
            {
               return true;
            }
    for(int i=1;i<=N;i++)
    {
        if(isSafe(grid,row,col,i,N))
        {
            grid[row][col]=i;
           if(isGrid(grid,N))
           {
               return true;
           }
            grid[row][col]=-1;
        }
    }
    return false;
}

void hint(int **grid,int row,int col)
{
    int num=grid[row][col];
    vector <string> v = {"THIS IS THE SMALLEST POSITIVE NUMBER","THIS NUMBER IS THE GCD OF ANY TWO PRIME NUMBERS","THIS NUMBER IS THE ONLY EVEN PRIME NUMBER","THIS NUMBER'S SQUARE IS 9","THIS NUMBER IS THE SQUARE OF ONLY EVEN PRIME NUMBER","LCM OF THIS NUMBER AND 3 IS 15","THIS NUMBER IS 2*3=","THIS NUMBER IS THE LARGEST SINGLE DIGIT PRIME NUMBER","THIS NUMBER IS THE CUBE OF THE ONLY EVEN PRIME NUMBER","THIS NUMBER IS THE SQUARE OF FIRST ODD PRIME NUMBER"};
    cout << "\t\t\t\t\t HINT:  "<< v[num] << endl;
}
bool inputnum(int **grid1s,int **gridsoln,int N)
{
           int row,col;
           if(!findEmptyLocation(grid1s,row,col,N))
            {
               return true;
            }
            cout << "\t\t\t\t\t ENTER THE NUMBER YOU FIND SUITABLE AT THE INDEX [" << row+1 << "," << col+1 << "] " <<endl;
            cout << "\t\t\t\t\t ENTER -1 FOR HINTS" << endl;
            int temp;
            cin>>temp;
            if(temp==-1)
            {
                hint(gridsoln,row,col);
                int n;
                cin>>n;
                if(n==gridsoln[row][col])
               {
                grid1s[row][col]=n;
               }
                else
               {
                cout << "\t\t\t\t\t\t INCORRECT ANSWER !!!!! " << endl;
                cout << "\t\t\t\t\t\t TRY AGAIN....." << endl;
                inputnum(grid1s,gridsoln,N);
               }
            }
            else if(temp==gridsoln[row][col])
            {
                grid1s[row][col]=temp;
            }
            else
            {
                cout << "\t\t\t\t\t\t INCORRECT ANSWER !!!!! " << endl;
                cout << "\t\t\t\t\t\t TRY AGAIN....." << endl;
                inputnum(grid1s,gridsoln,N);
            }
            return false;
}
 void enternumber(int **grid,int **gridsoln,int N)
 {
     int **grid1s=new int*[N];
     for(int i=0;i<N;i++)
     {
         grid1s[i]=new int[N];
         for(int j=0;j<N;j++)
         {
           grid1s[i][j]=grid[i][j];
         }
     }
            print(grid1s,N);
            bool flag=inputnum(grid1s,gridsoln,N);
            if(!flag)
            enternumber(grid1s,gridsoln,N);
            else
            {
                cout << "\t\t\t\t\t YOU HAVE COMPLETED THE GRID!!CONGRATULATIONS!!!..." << endl;
            }
}
void play(int N)
{
    int **grid1=new int*[N];
     for(int i=0;i<N;i++)
     {
         grid1[i]=new int[N];
     }
    if(N==9)
    {
    int grid[N][N]={{9, -1 ,-1, -1 ,2 ,-1 ,7, 5 ,-1 },{6 ,-1 ,-1 ,-1, 5, -1, -1, 4, -1 },{-1, 2, -1, 4, -1, -1, -1, -1, -1 },{2, -1 ,8 ,-1,-1,-1, -1 ,-1 ,-1 },{-1 ,7, -1, 5, -1, 9, -1, 6, -1 },{-1 ,-1, -1, -1 ,-1 ,-1, 4 ,-1 ,1 },{-1, 1 ,-1,-1, -1, 5, -1, 8 ,-1},{-1, 9, -1, -1, 7, -1, -1, -1, 4 },{-1, 8 ,2 ,-1,4 ,-1,-1 ,-1, 6}};

     for(int i=0;i<N;i++)
     {
         for(int j=0;j<N;j++)
         {
           grid1[i][j]=grid[i][j];
         }
     }
    }
    else if(N==10)
    {
        int grid[N][N]={{0 ,-1, 2, -1, 4, -1, 6, -1, 8, -1},{1 ,-1 ,3 ,-1 ,5 ,-1, 7, -1 ,9 ,-1},{2 ,-1, 4, -1, 6 ,-1, 8 ,-1, 0, -1},{3 ,-1 ,5 ,-1, 7, -1 ,9 ,-1 ,1 ,-1 },{4 ,-1, 6 ,-1 ,8, -1 ,0 ,-1 ,2, -1 },{5 ,-1 ,7 ,-1 ,9 ,-1 ,1, -1 ,3, -1 },{6 ,-1, 8, -1 ,0 ,-1 ,2, -1, 4 ,-1},{7 ,-1, 9 ,-1 ,1 ,-1 ,3, -1 ,5 ,-1},{8 ,-1 ,0 ,-1, 2, -1 ,4 ,-1, 6, -1},{9 ,-1, 1, -1 ,3, -1, 5, -1, 7 ,-1}};

     for(int i=0;i<N;i++)
     {
         for(int j=0;j<N;j++)
         {
           grid1[i][j]=grid[i][j];
         }
     }
    }
      int **gridsoln=new int*[N];
     for(int i=0;i<N;i++)
     {
         gridsoln[i]=new int[N];
         for(int j=0;j<N;j++)
         {
           gridsoln[i][j]=grid1[i][j];
         }
     }
     bool flag=isGrid(gridsoln,N);
     enternumber(grid1,gridsoln,N);
}
void normalsudoku(int N)
{
    cout << "\t\t\t\t\t WHAT WOULD YOU LIKE TO PREFER " << endl;
    cout << "\t\t\t\t\t     [p]PLAY THE SUDOKU" << endl;
    cout << "\t\t\t\t\t     [s]GET THE SOLUTION OF A GRID" << endl;
    char ch;
    cin>>ch;
    if(ch=='p' || ch=='P')
    {
        play(N);
    }
    else if(ch=='s'|| ch=='S')
    {
    cout << "\t\t\t\t\t ENTER THE GRID " << endl;
         int **grid=new int*[N];
         for(int i=0;i<N;i++)
          {
            grid[i]=new int[N];
            for(int j=0;j<N;j++)
            {
              cin >> grid[i][j];
            }
          }
    bool flag =isGrid(grid,N);
    if(flag)
    {
         system("pause");
         cout << "\t\t\t\t\t A SOLUTION FOR THIS GRID IS POSSIBLE" << endl;
         system("pause");
         print(grid,N);
    }
    else
     {
        cout << "\t\t\t\t\t A SOLUTION FOR THIS GRID IS NOT POSSIBLE" << endl;
     }
    }
    else
    {
        cout << "\t\t\t\t\t  WRONG CHOICE!!! TRY AGAIN" << endl;
        normalsudoku(9);
    }
}
bool isoddevenGrid(int **grid,int N);
bool evencheck(int **grid,int row,int col,int N)
{
           for(int i=0;i<N;i=i+2)
             {
              if(isSafe(grid,row,col,i,N))
              {
                 grid[row][col]=i;
                 if(isoddevenGrid(grid,N))
                       {
                          return true;
                       }
               grid[row][col]=-1;
                  }
             }
       return false;
}
bool oddcheck(int **grid,int row,int col,int N)
{
         for(int i=1;i<N;i=i+2)
             {
              if(isSafe(grid,row,col,i,N))
                  {
                 grid[row][col]=i;
                 if(isoddevenGrid(grid,N))
                       {
                          return true;
                       }
               grid[row][col]=-1;
                  }
              }
        return false;
}
bool isoddevenGrid(int **grid,int N)
{
        int row,col;
           if(!findEmptyLocation(grid,row,col,N))
            {
               return true;
            }
            bool flag=true;
             if((row+col)%2==0)
               {
                   flag=evencheck(grid,row,col,N);
               }
               else
               {
                   flag=oddcheck(grid,row,col,N);
               }
    return flag;
}
void oddevensudoku(int N)
{
    cout << "\t\t\t\t\t WHAT WOULD YOU LIKE TO PREFER " << endl;
    cout << "\t\t\t\t\t     [p]PLAY THE SUDOKU" << endl;
    cout << "\t\t\t\t\t     [s]GET THE SOLUTION OF A GRID" << endl;
    char ch;
    cin>>ch;

    if(ch=='p' || ch=='P')
    {
        play(10);
    }
    else if(ch=='s'|| ch=='S')
    {
    cout << "\t\t\t\t\t ENTER THE GRID" << endl;
         int **grid=new int*[N];
         for(int i=0;i<N;i++)
          {
              grid[i]=new int[N];
            for(int j=0;j<N;j++)
            {
              cin >> grid[i][j];
            }
          }

    bool flag =isoddevenGrid(grid,N);
    if(flag)
    {
        cout << "\t\t\t\t\t A SOLUTION FOR THIS IS POSSIBLE" << endl;
        system("pause");
        print(grid,N);
    }
    else
    {
        cout << "\t\t\t\t\t A SOLUTION FOR THIS GRID IS NOT POSSIBLE" << endl;
     }
    }
     else
    {
        cout << "\t\t\t\t\t WRONG CHOICE!! TRY AGAIN." << endl;
        oddevensudoku(10);
    }
}
void start()
{
     cout << "\t\t\t\t\t WHICH TYPE OF SUDOKU WOULD YOU PREFER " << endl;
       cout << "\t\t\t\t\t 1.NORMAL SUDOKU " << endl;
       cout << "\t\t\t\t\t 2.ODD/EVEN SUDOKU " << endl;
       int n;
       cin>>n;
       if(n==1)
       {
           normalsudoku(9);
       }
       else if(n==2)
       {
           oddevensudoku(10);
       }
       else
       {
           cout << "\t\t\t\t\t WRONG CHOICE!!!.ENTER YOUR CHOICE AGAIN." << endl;
           start();
       }
}
int main()
{
       cout << "\t\t\t\t\t\t SUDOKU SOLVER " << endl;
       //system("pause");
       start();

}
