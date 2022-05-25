#include<bits/stdc++.h>
using namespace std;
double arr1[100];
double arr2[100];
double Div[100];

double find_b(int n)
{
    double sum=0.0;
    for(int i=1;i<n;i++)
    {
        sum=sum+(1.0*arr1[i]*arr2[n-i]);
    }
    return sum;
}
void div()
{
    cout<<"\n\tDIV\n"<<endl;
    for(int i=1;i<100;i++)
    {
        Div[i]=(arr2[i]/(1.0*arr2[i+1]));
    }
    cout<<"\n";
}
int main()
{
    double x,a,b,c,d;
    double fx;
    cout<<"equation type: ax^3+bx^2+cx+d "<<endl;
    cout<<"Equation's Co-efficients: "<<endl;
    cout<<"inter x^3 co-efficient:";
    cin>>a;
     cout<<"inter x^2 co-efficient:";
     cin>>b;
      cout<<"inter x^1 co-efficient:";
      cin>>c;
       cout<<"inter constant co-efficient:";
       cin>>d;
       arr1[1]=c/(-d);
       arr1[2]=b/(-d);
       arr1[3]=a/(-d);
        arr2[1]=1;

        for(int i=2;i<100;i++)
        {
            arr2[i]=find_b(i);
        }
        div();
        int i;
        for(int i=1;i<=100;i++)
        {
            if(fabs(Div[i]-Div[i+1])>.005 && Div[i+1])
            {
                cout<<endl;
                cout<<i<<" "<<Div[i]<<endl;
                cout<<"__________________"<<endl;

            }
            else
            break;
        }
        cout<<"\nRoot is: ";
        cout<<fixed<<setprecision(4)<<Div[9]<<endl;



}
