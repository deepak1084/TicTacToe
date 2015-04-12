#include <iostream>
#include<string>
#include<vector>
using namespace std;

int check(int ar[][3])
{
    int f=1;
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    if(ar[i][j]==0)
    f=0;
    if(f==1)
    return -1;
    for(int i=0;i<3;i++)
    {
            int s=0;

            for(int j=0;j<3;j++)
            s=s+ar[i][j];
            if(ar[i][0]==ar[i][1]&&ar[i][1]==ar[i][2]) {

            if(s==3) {

            return 1;
            }
            if(s==6) {

            return 2;
            }
            }
            }
            for(int i=0;i<3;i++)
            {
            int s=0;
            for(int j=0;j<3;j++)
            s=s+ar[j][i];
            if(ar[0][i]==ar[1][i]&&ar[1][i]==ar[2][i]) {
            if(s==3) {

            return 1;
            }
            if(s==6) {
     //       cout<<"Com";
            return 2;
            }
            }
            }
            if(ar[0][0]==1&&ar[1][1]==1&&ar[2][2]==1)
            {
  //                                           cout<<"plyer";
                                             return 1;
                                             }

            if(ar[0][0]==2&&ar[1][1]==2&&ar[2][2]==2)
            {
    //                                         cout<<"com";
                                             return 2;
                                             }

            if(ar[2][0]==1&&ar[1][1]==1&&ar[0][2]==1)
            {
      //                                       cout<<"plyer";
                                             return 1;
                                             }

            if(ar[2][0]==2&&ar[1][1]==2&&ar[0][2]==2)
            {
        //                                     cout<<"com";
                                             return 2;
                                             }
                                             return 0;
    }
    void dis(int ar[][3])
    {
         for(int i=0;i<3;i++)
    {
         cout<<"\t|";
            for(int j=0;j<3;j++)
            {
                    if(ar[i][j]==1)
                    cout<<"0 |";
                    else if(ar[i][j]==2)
                    cout<<"X |";
                    else
                    cout<<"  |";

    }
    cout<<"\n";
    cout<<"\t----------";
    cout<<"\n";
    }
}
int f(int ar[][3])
{
     int f=1;
     for(int i=0;i<3;i++)
     {
             for(int j=0;j<3;j++)
             {
                     if(ar[i][j]==0)
                     f=0;
             }
     }
     if(f==1){
                     cout<<"Draw\n";
                     return 1;
     }
     return 0;
}
int  inp(int ar[][3],int *p,int *q)
{
     int temp[3][3];

     int pp,qq,pr[3][3]={0};
     for(int i=0;i<3;i++) {
             for(int j=0;j<3;j++) {

      for(int k=0;k<3;k++) {
                             for(int w=0;w<3;w++) {
                                     temp[k][w]=ar[k][w];
                             }
                     }
                       if(ar[i][j]==0) {
                     temp[i][j]=2;
                     if(check(temp)==2)
                     {
                     *p=i;
                     *q=j;
                     return 1;
                     }
                     }}}
     for(int i=0;i<3;i++) {
             for(int j=0;j<3;j++) {
                     for(int k=0;k<3;k++) {
                             for(int w=0;w<3;w++) {
                                     temp[k][w]=ar[k][w];
                             }
                     }
                     if(ar[i][j]==0) {
                     temp[i][j]=1;
                     if(f(ar))
                     return 0;
                     if(check(temp)==2) {
                     *p=i;
                     *q=j;
                     return 1;
                     }
                     if(check(temp)==-1) {
                     *p=i;
                     *q=j;
                     return 0;
                     }
                     if(check(temp)==1) {
                     *p=i;
                     *q=j;
                     return 1;
                     }
                     pr[i][j] = inp(temp,&pp,&qq);
                     }
             }
}
     int h=0;
     for(int i=0;i<3;i++)
     {
             for(int j=0;j<3;j++)
             {
                     if(h < pr[i][j] && ar[i][j]==0){
                     h=pr[i][j];
                     pp=i;
                     qq=j;
                     }
                     }
     *p=pp;
     *q=qq;
}

}


int main()
{
cout<< "Welcome to the Medium Diffulty Level Tic Tac Toe (using Graph concepts DFS CPP project!\n" ;
   int ar[3][3]={0};
    cout<<"Enter the position in index form like 1,1 represent the first left box and\n 3,3 represent the last right block\n";
    int i,j,p,q;
    int t=1;
    while(1) {
             cout<<"Enter Index positions\n";
    cin>>i>>j;
    ar[i-1][j-1]=1;
    cout<<"\nDisplaying Checker Box\n";
    dis(ar);

    if(check(ar)==1) {
                  cout<<"Player Wins ,Gud Work..:)";
    break;
}

    if(check(ar)==2) {
                  cout<<"Com Wins :( \n Better Luck next time you can beat computer as it is Medium Difficulty Level ";
    break;
}
    if(f(ar)) {
              cout<<"\nSorry No one Wins.\nBetter Luck next time you can beat computer as it is Medium Difficulty Level\n";
    break;
    }
    inp(ar,&p,&q);
    ar[p][q]=2;
    cout<<"\n";
    cout<<"\nDisplaying Checker Box\n";
    dis(ar);

    if(check(ar)==1) {
                  cout<<"Player Wins :)";
    break;
}

    if(check(ar)==2) {
                  cout<<"Com Wins :( \n Better Luck next time you can beat computer as it is Medium Difficulty Level ";
    break;
}

    if(f(ar)) {
              cout<<"No one Wins";
    break;
}
}
return 0;
}
