/*
Some where in MissionRnD world ,there is a large plot of empty Rectangular land ,divided into Blocks of
equal size . A Land of N Blocks at length and M Blocks at Breadth will have total of N x M Blocks .

Each Block has a pillar of Height H .[0 <= H <=100000] .A Pillar is said to be a Leader if there are no more
neighbouring pillars (East ,West ,Noth and South) whose height is greater than current one .
And excatly opposite ,A pillar is said to be a Looser if there are no more neighbouring pillars
whose height is less than the current pillar height

If a block has 0 specified ,It has No pillar and No person can be on that block.In the below example
1,2,4... are heights of pillars at that block.Do not consider 0 while calculating Leaders or Loosers .
Example :

1 2 0 1 0
0 0 0 9 0
0 0 0 8 0
0 1 4 6 5
0 0 2 3 4

Here a[0][1] ie 2 ,and a[1][3] ie 9 are leaders ,as all their neighbouring elements are less or equal than it .
Here a[0][0] ie 1 ,and a[0][3] ie 1 and a[3][1] ie 1 and a[4][2] ie 2 are Loose Pillars ,as all their
neighbouring pillars height are greater or equal than it .

Now there is a child who likes to jump from one pillar to another ,He starts at a looser Pillar and jumps to
a nearby pillar (4 Directions) ,if the nearby pillar height is "strictly greater" than curernt pillar height .
So he can jump from 1 to 3 ,or 3 to 7 but not 4 to 1 and 5 to 5 .[all these are heights]
He continues jumping until he reaches a LeaderPillar .

As he likes jumping ,He would like to know the Path which starts at a Looser Pillar and ends at a Leader Pillar
that involves maximum jumps ,Can you help the child solve his Task ?

In the above example :
1-2 Path , requires only 1 jump
1-4-6-8-9 requires 4 jumps
2-3-4-5-6-8-9 requires 6 jumps
1-9 requires only 1 jump.
So in the above example you need to return [2,3,4,5,6,8,9] and copy 6 in jumps_count

Input :
A 2D Array (passed as Single pointer,First element Address) ,N (number of Cols), M(number of rows),
jumps_count (Pointer to an Integer)
Output :
Return the Max Jumps path  ,and copy number of max jumps into jumps_count .

Constraints :
0<=N<=10000
0<=M<=10000
Note : If there is no such path ,Copy 0 in jumps_count and return NULL,(Same for Invalid Inputs too)
Examples :
-----
2 1 7
3 0 4   ->Max Path : [1,2,3,5,6] ,jumps_count =4 [Here both 4's are looser elements]
5 6 4
--------
5 8 9 10
4 3 1 0
3 0 0 3   ->Max Path is [1,2,3,4,5,8,9,10] , jumps_count =8
2 1 1 1
---------
0 0 0
0 4 0  ->Max Path is [4] ,jumps_count=0;
0 0 0
Note : There will be only One Maximum Jumps path .[If there are multiple ,Return any 1 path]
*/
#include <stdlib.h>
#include <stdio.h>



/*
Some where in MissionRnD world ,there is a large plot of empty Rectangular land ,divided into Blocks of
equal size . A Land of N Blocks at length and M Blocks at Breadth will have total of N x M Blocks .

Each Block has a pillar of Height H .[0 <= H <=100000] .A Pillar is said to be a Leader if there are no more
neighbouring pillars (East ,West ,Noth and South) whose height is greater than current one .
And excatly opposite ,A pillar is said to be a Looser if there are no more neighbouring pillars
whose height is less than the current pillar height

If a block has 0 specified ,It has No pillar and No person can be on that block.In the below example
1,2,4... are heights of pillars at that block.Do not consider 0 while calculating Leaders or Loosers .
Example :

1 2 0 1 0
0 0 0 9 0
0 0 0 8 0
0 1 4 6 5
0 0 2 3 4

Here a[0][1] ie 2 ,and a[1][3] ie 9 are leaders ,as all their neighbouring elements are less or equal than it .
Here a[0][0] ie 1 ,and a[0][3] ie 1 and a[3][1] ie 1 and a[4][2] ie 2 are Loose Pillars ,as all their
neighbouring pillars height are greater or equal than it .

Now there is a child who likes to jump from one pillar to another ,He starts at a looser Pillar and jumps to
a nearby pillar (4 Directions) ,if the nearby pillar height is "strictly greater" than curernt pillar height .
So he can jump from 1 to 3 ,or 3 to 7 but not 4 to 1 and 5 to 5 .[all these are heights]
He continues jumping until he reaches a LeaderPillar .

As he likes jumping ,He would like to know the Path which starts at a Looser Pillar and ends at a Leader Pillar
that involves maximum jumps ,Can you help the child solve his Task ?

In the above example :
1-2 Path , requires only 1 jump
1-4-6-8-9 requires 4 jumps
2-3-4-5-6-8-9 requires 6 jumps
1-9 requires only 1 jump.
So in the above example you need to return [2,3,4,5,6,8,9] and copy 6 in jumps_count

Input :
A 2D Array (passed as Single pointer,First element Address) ,N (number of Cols), M(number of rows),
jumps_count (Pointer to an Integer)
Output :
Return the Max Jumps path  ,and copy number of max jumps into jumps_count .

Constraints :
0<=N<=10000
0<=M<=10000
Note : If there is no such path ,Copy 0 in jumps_count and return NULL,(Same for Invalid Inputs too)
Examples :
-----
2 1 7
3 0 4   ->Max Path : [1,2,3,5,6] ,jumps_count =4 [Here both 4's are looser elements]
5 6 4
--------
5 8 9 10
4 3 1 0
3 0 0 3   ->Max Path is [1,2,3,4,5,8,9,10] , jumps_count =8
2 1 1 1
---------
0 0 0
0 4 0  ->Max Path is [4] ,jumps_count=0;
0 0 0
Note : There will be only One Maximum Jumps path .[If there are multiple ,Return any 1 path]
*/
#include <stdlib.h>
#include <stdio.h>
int check(int **arr, int rows, int cols, int i, int j)
{
	
	if (i < 0 || j < 0 || i >= rows || j >= cols) 
		return 0;
	int a,b;
	a = b = 0;
	if (i < rows - 1 && j>0 && j<cols - 1)
	{
		if (arr[i][j] == arr[i][j + 1] && arr[i][j] < arr[i][j - 1] && arr[i][j] == arr[i + 1][j])
			return 1;
	}
	if (i - 1 >= 0)
	{
		if (arr[i - 1][j] == 0)
		{
			a++, b++;
		}
		else if (arr[i - 1][j] > arr[i][j])
			a++;
		else
			b++;
	}
	else
	{
		a++, b++;
	}
	if (j - 1 >= 0)
	{
		if (arr[i][j - 1] == 0)
		{
			a++, b++;
		}
		else if (arr[i][j - 1] > arr[i][j])
			a++;
		else
			b++;
	}
	else
	{
		a++;
		b++;
	}
	if (i + 1 < rows)
	{
		if (arr[i + 1][j] == 0) 
		{
			a++, b++;
		}
		else if (arr[i + 1][j] > arr[i][j]) 
			a++;
		else 
			b++;
	}
	else
	{
		a++, b++;
	}
	if (j + 1 < cols)
	{
		if (arr[i][j + 1] == 0)
		{
			a++, b++;
		}
		else if (arr[i][j + 1] > arr[i][j])
			a++;
		else
			b++;
	}
	else
	{
		a++, b++;
	}
	if (a == 4) 
		return 1;
	else if (b == 4) 
		return 2;
	else 
		return 3;

}
int pillar_rec(int **board, int rows, int cols, int* path1, int* path2, int i, int j, int* l1, int l, int n)
{
	int r,k;
	r = check(board, rows, cols, i, j);
	if (r == 0)
		return 0;
	if ((r == 1 && n == 0) || ((board[i][j]>n && r==3)))
	{
		n = board[i][j];
		path2[l++] = n;
		k = pillar_rec(board, rows, cols, path1, path2, i - 1, j, l1, l, n);
		n = board[i][j];
		k = pillar_rec(board, rows, cols, path1, path2, i, j - 1, l1, l, n);
		n = board[i][j];
		k = pillar_rec(board, rows, cols, path1, path2, i, j + 1, l1, l, n);
		n = board[i][j];
		k = pillar_rec(board, rows, cols, path1, path2, i + 1, j, l1, l, n);
	}
	else if (r == 2)
	{
		path2[l] = board[i][j];
		l++;
		if (*l1 < l)
		{
			for ( k = 0; k < l; k++)
			{
				path1[k] = path2[k];
			}
			*l1 = l;
		}
	}
	return 0;
}
int * pillars_max_jumps(int *blocks, int n, int m, int *jumps_count){
	if (blocks == NULL || n <= 0 || m <= 0)
	{
		*jumps_count = 0;
		return NULL;
	}
	else
	{
		int i, j,k=0,chk = 0, num,l1,l2,ret;
		int ** arr = (int**)malloc(sizeof(int*)*n); 
		l1 = l2 = 0;
		for (i = 0; i < n; i++)
		{

			arr[i] = (int*)malloc(m*sizeof(int));
		}
		for (i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				arr[i][j] = blocks[k++];
			}
		}
		int * path1 = (int*)malloc(sizeof(int)*(m*n));
		int * path2 = (int*)malloc(sizeof(int)*(m*n));
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (arr[i][j])
				{
					chk = check(arr, n, m, i, j);
					if (chk == 1)
					{
						num = 0;
						ret = pillar_rec(arr, n, m, path1, path2, i, j, &l1, l2, num);
					}

				}
			}
		}

		if (l1 == 0)
		{
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					if (arr[i][j] != 0)
					{
						chk = check(arr, m, n, i, j);
						if (chk == 2)
						{
							path1[0] = arr[i][j];
							*jumps_count = 0;
							return path1;
						}
					}
					else
					{
						return NULL;
					}
				}
			}
			*jumps_count = 0;
			return NULL;
		}
		int *result = (int*)malloc(sizeof(int)*l1);
		*jumps_count = l1 - 1;
		for (i = 0; i < l1; i++)
			result[i] = path1[i];

		return result;
	}
}