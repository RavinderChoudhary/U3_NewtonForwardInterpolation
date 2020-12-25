#include<stdio.h>
#include<math.h>
int fact(int);

int main()
{
    #ifndef ONLINE_JUDGE 
      freopen("input.txt", "r", stdin); 
      freopen("output.txt", "w", stdout); 
    #endif 
float arr[10][11],x,h,p,y,px=1;
int i,j,n,ch=30;
scanf("%d",&n);

for(i=0;i<n;i++)
{ 
scanf("%f",&arr[i][0]);
scanf("%f",&arr[i][1]);
}

//Forming difference table.
for(j=2;j<=n;j++)
for(i=0;i<n-1;i++)
arr[i][j]=arr[i+1][j-1]-arr[i][j-1];

//Printing table
printf("\n Forward Difference table is:-");
printf("\n\tx\tY");
for(i=0;i<=n-2;i++)
printf("\t%c^%dY",ch,i+1);
for(i=0;i<n;i++)
{printf("\n");
for(j=0;j<n+1-i;j++)
{printf("\t%.5f",arr[i][j]);
}
}

//Take the value of x for f(x)
scanf("%f",&x);
//Calculate the value of f(x) for x
h=arr[1][0]-arr[0][0];
p=(x-arr[0][0])/h;
y=arr[0][1];
for(i=1;i<n;i++)
{ px=px*(p-(i-1));
y=y+(arr[0][i+1]*px)/fact(i);
}
printf("\nthe value of function at x=%f is %f",x,y);
}
int fact(int n)
{ int i,f=1;
for(i=1;i<=n;i++)
f=f*i;
return f;
}

/*
n = 6
x , y
1.5 3.375   
2 7 
2.5 13.625  
3 24    
3.5 38.875  
4 59
x0
2.75
*/