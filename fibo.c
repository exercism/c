#include<stsio.h>
#include<conio.h>
int main()
{
  int a=0;
  int b= 1;
  int n;
  print("\n%d\t%d",a,b);
  print("Enter numbers of terms");
  scanf("%d", &n);
  int i =1
  while(i<=n-2)
  {
    a=b;
    b=a+b;
    print("\t%d",b);
    i++;
  }
  return 0;
}
