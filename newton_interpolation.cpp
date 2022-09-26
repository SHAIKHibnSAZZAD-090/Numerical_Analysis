#include <bits/stdc++.h>
using namespace std;
float u_forward(float u, int n)
{
	float temp = u;
	for (int i = 1; i < n; i++)
		temp = temp * (u - i);
	return temp;
}
float u_backward(float u, int n)
{
	float temp = u;
	for (int i = 1; i < n; i++)
		temp = temp * (u + i);
	return temp;
}
int fact(int n)
{
	int f = 1;
	for (int i = 2; i <= n; i++)
		f *= i;
	return f;
}

int main()
{
    cout<<"Enter the number of iteration:";
	int n ,i,j;
	cin>>n;
	float x[n],y[n][n];
	for(i=0;i<n;i++){
        cin>>x[i]>>y[i][0];
	}

	float x1[n];

	float y1[n][n];
	for(i=0;i<n;i++){
        x1[i]=x[i];
        y1[i][0]=y[i][0];
	}
	cout<<"X\t"<<"Y"<<endl;
	cout<<"_____________"<<endl;
	for(int i=0;i<n;i++)
    {
        cout<<x[i]<<"\t"<<y[i][0]<<endl;
    }
    cout<<endl;
     float value1;
     cout<<"Input the desire value of x:";
	cin>>value1;
    while(1){
    int flag;
    cout<<"Press between 1 for Forward,2 for backward and 3 for exit"<<endl;
    cin>>flag;


if(flag==1){


  cout<<"_________Forward________"<<endl;

	for (i = 1; i < n; i++) {
		for (j = 0; j < n - i; j++)
			y[j][i] = y[j + 1][i - 1] - y[j][i - 1];
	}


	for (int i = 0; i < n; i++) {
		cout << setw(6) << x[i]
			<< "\t";
		for (int j = 0; j < n - i; j++)
			cout << setw(4) << y[i][j]
				<< "\t";
		cout << endl;
	}




	float sum = y[0][0];
	float u = (value1 - x[0]) / (x[1] - x[0]);
	for (int i = 1; i < n; i++) {
		sum = sum + (u_forward(u, i) * y[0][i]) /
								fact(i);
	}

	cout << "\n Value at " << value1 << " is "<< sum << endl;

}
else if(flag==2)
{
   cout<<"_______backward______"<<endl;
	float value2=value1;


	 for ( i = 1; i < n; i++) {
        for ( j = n - 1; j >= i; j--)
            y1[j][i] = y1[j][i - 1] - y1[j - 1][i - 1];
    }
     for ( i = 0; i < n; i++) {
        for ( j = 0; j <= i; j++)
            cout << setw(4) << y1[i][j]
                 << "\t";
        cout << endl;
    }


    float sum2 = y1[n - 1][0];
    float u2 = (value2 - x1[n - 1]) / (x1[1] - x1[0]);
    for (i = 1; i < n; i++) {
        sum2 = sum2 + (u_backward(u2, i) * y1[n - 1][i]) /
                                     fact(i);
    }

    cout << "\n Value at " << value2 << " is "<< sum2 << endl;
}
else
    break;
    }
	return 0;
}


