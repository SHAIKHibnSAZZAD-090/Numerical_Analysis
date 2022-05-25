///x^3-6x+11x-6=0
#include<bits/stdc++.h>
using namespace std;
double A1[101];
double A2[101];
double DIV[101];

double find_B(int n)
{
    double sum=0.0;

    for(int i=1;i<n;i++){
        sum = sum + (1.0*A1[i]*A2[n-i]);
        }

    return sum;
}
void div()
{
    cout<<"\nStep\t DIV"<<endl;
    cout<<"___________________"<<endl;
    for(int i=1;i<90;i++){
        DIV[i]=(A2[i]/(1.0*A2[i+1]));
    }
}

int main()
{
    double x,a,b,c,d;
    double fx;

    cout<<"Enter Co-efficient of x^3 : ";
    cin>>a;
    cout<<"Enter Co-efficient of x^2 : ";
    cin>>b;
    cout<<"Enter Co-efficient of x : ";
    cin>>c;
    cout<<"Enter Constant term:";
    cin>>d;

    A1[1]= c/(-d);
    A1[2]= b/(-d);
    A1[3]= a/(-d);

    A2[1]=1;

    for(int i=2;i<90;i++){
        A2[i]=find_B(i);
    }

    div();
    int i;

    for(i=1;i<=40;i++){
        if(fabs(DIV[i]-DIV[i+1])>0.0005 && DIV[i+1]){
            cout<<"\n"<<i<<"\t "<<DIV[i]<<endl;
        }
        else
            break;
    }

    cout<<"Root of the equation : ";
    cout<<setprecision(5)<<"\t"<<DIV[i]<<endl;


    return 0;

}
