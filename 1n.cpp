

// inser ito linear array

#include<bits/stdc++.h>
using namespace std;
// array insert
void okk()
{

    int LA[7]={5,10,15,20,25};
    
    int N=5,k=3,item=100;
    
    int J=N;
    while(J>=k)
    {
        LA[J+1]=LA[J];
        J=J-1;
    }
    LA[k]=item;
    N=N+1;

    cout<<"item insert"<<endl;
    int i;
    for(i=0; i<N; i++)
    {   
        
        cout<<LA[i]<<" "<<endl;;
       
        
    }

}
 //array delete


 void wow()
 {
    int la[7]={5,10,15,20,25},n=5,k=3, item;
  

    item=la[k];
    int j;
    for(j=k; j<n-1; j++)
    {
        la[j]=la[j+1];
    }
    n=n-1;

    cout<<"item deleted"<<endl;
    int i;
    for(i=0; i<n; i++)
    {
        cout<<la[i]<<" "<<endl;
    }

 }




int main()
{
    okk();
    wow();
    return 0;
}



