#include<iostream>
#include<windows.h>

using namespace std;

//Interface
const unsigned int row=34;
const unsigned int col=60;
const float delay=0.2; //in seconds
const char live='O';
const char dead='_';

//Functions
void insert_arr(int[row][col]);
int neighbours(int[row][col],int,int);
void exchange(int[row][col],int[row][col]);
void input();

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	getchar();			//Hold for an enter key press
	input();			//include line only if you want input from file
	
	int world[row][col];
	int nextG[row][col];
	
	insert_arr(world);
	int k=0;
	
	while(1)
	{
		cout<<"generation( "<<++k<<" )\n\n";
		if(k%2==1)
		{
			exchange(world,nextG);
			Sleep(delay*1000);
			system("CLS");
		}
		else
		{
			exchange(nextG,world);
			Sleep(delay*1000);
			system("CLS");
		}
	}
	return 0;
}

void insert_arr(int arr[row][col])	//Takes in input for the array
{
	for(int i=0;i<row;i++)
		for(int j=0;j<col;j++)
			cin>>arr[i][j];
}

int neighbours(int arr[row][col],int i,int j)		//Counts the number of neighbours around a cell
{
	if(i==0||j==0||i==row-1||j==col-1)
		return 0;
	
	int count=0;
	
	//sides
	if(arr[i+1][j])
		count++;
	if(arr[i][j+1])
		count++;
	if(arr[i-1][j])
		count++;
	if(arr[i][j-1])
		count++;
	
	if(count>=4)
		return count;
		
	//diagonals
	if(arr[i+1][j+1])
		count++;
	if(arr[i-1][j-1]&&count<4)
		count++;
	if(arr[i-1][j+1]&&count<4)
		count++;
	if(arr[i+1][j-1]&&count<4)
		count++;
	
	return count;
}

void exchange(int a[row][col],int b[row][col])	//does the main calculation for the game
{
	for(int i=0;i<row;i++)
	{
		cout<<"\t";
		for(int j=0;j<col;j++)
		{
		
			if(a[i][j])
				cout<<live<<" ";
			else
				cout<<dead<<" ";
				
			int alive=neighbours(a,i,j);
			
			if(a[i][j]&&(alive<2||alive>3))
			{
				b[i][j]=0;
				continue;
			}
			else if(!a[i][j]&&alive==3)
			{
				b[i][j]=1;
				continue;
			}
			
			b[i][j]=a[i][j];
		}
		cout<<endl;
	}
}

void input()		
{
	#ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
	#endif
}

/*
Rudrashish Das
9th May 2021
*/
