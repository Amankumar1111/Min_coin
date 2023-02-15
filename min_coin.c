#include<stdio.h>
#include<limits.h>
// m is size of coins array (number of different coins)
int BtCoins(int coins[], int m, int V)
{
// base case
if (V == 0) return 0;

// Initialize result
int res = INT_MAX;

// Try every coin that has smaller value than V
for (int i=0; i<m; i++)
{
	if (coins[i] <= V)
	{
		int sub_res = BtCoins(coins, m, V-coins[i]);

		// Check for INT_MAX to avoid overflow and see if
		// result can minimized
		if (sub_res != INT_MAX && sub_res + 1 < res)
			res = sub_res + 1;
	}
}
return res;
}

int usCoins(int coins[], int m, int V)
{
// base case
if (V == 0) return 0;

// Initialize result
int res = INT_MAX;

// Try every coin that has smaller value than V
for (int i=0; i<m; i++)
{
	if (coins[i] <= V)
	{
		int sub_res = usCoins(coins, m, V-coins[i]);

		// Check for INT_MAX to avoid overflow and see if
		// result can minimized
		if (sub_res != INT_MAX && sub_res + 1 < res)
			res = sub_res + 1;
	}
}
return res;
}

int nkCoins(int coins[], int m, int V)
{
// base case
if (V == 0) return 0;

// Initialize result
int res = INT_MAX;

// Try every coin that has smaller value than V
for (int i=0; i<m; i++)
{
	if (coins[i] <= V)
	{
		int sub_res = nkCoins(coins, m, V-coins[i]);

		// Check for INT_MAX to avoid overflow and see if
		// result can minimized
		if (sub_res != INT_MAX && sub_res + 1 < res)
			res = sub_res + 1;
	}
}
return res;
}
// Driver program to test above function
int main()
{
	int Btcoins[] = {1,2,5,10,20,50};//use for British coin
	int uscoins[]={1,5,10,25};//use for US coin
	int nkcoins[]={1,5,10,20};//use for Norwegian Krone coin
	int m = sizeof(Btcoins)/sizeof(Btcoins[0]);
	int n = sizeof(uscoins)/sizeof(uscoins[0]);
	int o = sizeof(nkcoins)/sizeof(nkcoins[0]);
	int Value,choice=0;
printf("_______*******________\n");
printf("1:British Pound \n");
printf("2:US Dollar \n");
printf("3:Norwegian Krone \n");
printf("_______*******________\n");
printf("Enter the value of whose you want to convert \n");
scanf("%d",&Value);
printf("Enter the choice  :\n");
scanf("%d",&choice);
switch(choice)
{
	case 1:printf("Minimum coins required is %d",BtCoins(Btcoins, m, Value));
	break;
	case 2:printf("Minimum coins required is %d",usCoins(uscoins, n, Value));
	break;
	case 3:printf("Minimum coins required is %d",nkCoins(nkcoins, o, Value));
	break;
	default:printf("wrong choice");
}
	return 0;
}

