#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


/**********************************************************************************
                                 1 BUBBLE SORT                                                      
**********************************************************************************/

void bubble_sort()
{
	int i, n,temp,j,arr[100];
	printf("\nEnter the number of elements: ");
	scanf("%d",&n);
	printf("\nEnter %d elements: ", n);
	for(i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
		
	}
	
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n-i-1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	printf("\n_____Sorted elements_____\n");
	for(i=0; i<n; i++)
	{
		printf("%d\t", arr[i]);
	}
}

/*********************************************************************************
                                   2 INSERTION SORT                                                      
**********************************************************************************/

void insertion_sort(int arr[], int n)
{
	int i, j, temp;
	for(i=1; i<n; i++)
	{
		temp = arr[i];
		j = i-1;
		while((temp < arr[j]) && (j>=0))
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
}

void insert_fun()
{
	int arr[100], i, n;
	printf("\nEnter the number of elements: ");
	scanf("%d",&n);
	printf("\nEnter %d elements: ", n);
	for(i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	
	insertion_sort(arr,n);
	printf("\n_____Sorted elements_____\n");
		for(i=0; i<n; i++)
	{
		printf("%d\t", arr[i]);
	}
}

/**********************************************************************************
                                3  SELECTION SORT                                                      
**********************************************************************************/

int sel_smallest(int arr[], int k, int n)
{
	int pos = k, small=arr[k],i;
	for(i=k+1; i<n; i++)
	{
		if(arr[i] < small)
		{
			small = arr[i];
			pos = i;
		}
	}
	return pos;	
}

void selection_sort(int arr[],int n)
{
	int k, pos, temp;
	for(k=0; k<n; k++)
	{
		pos = sel_smallest(arr, k, n);
		temp = arr[k];
		arr[k] = arr[pos];
		arr[pos] = temp;		
	}
}

void select_fun()
{
	int arr[100], i, n;
    printf("\nEnter the number of elements: ");
	scanf("%d",&n);
	printf("\nEnter %d elements: ", n);
	for(i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	
	selection_sort(arr,n);
	printf("\n_____Sorted elements_____\n");
		for(i=0; i<n; i++)
	{
		printf("%d\t", arr[i]);
	}
}


/*********************************************************************************
                              4  MERGE SORT                                                      
**********************************************************************************/


void merge(int arr[], int beg, int mid, int end)
{
	int i=beg, j=mid+1, index=beg, temp[100], k;
	while((i<=mid) && (j<=end))
	{
		if(arr[i] < arr[j])
		{
			temp[index] = arr[i];
			i++;
		}
		
		else
		{
			temp[index] = arr[j];
			j++;
		}
		index++;
	}
	if(i>mid)
	{
		while(j<=end)
		{
			temp[index] = arr[j];
			j++;
			index++;
		}
	}
	else
	{
		while(i<=mid)
		{
			temp[index] = arr[i];
			i++;
			index++;
		}
	}
	for(k=beg; k<index; k++)
	{
		arr[k] = temp[k];
	}
}

void merge_sort(int arr[], int beg, int end)
{
	int mid;
	if(beg < end)
	{
		mid = (beg+end)/2;
		merge_sort(arr, beg, mid);
		merge_sort(arr, mid+1, end);
		merge(arr, beg, mid, end);
		
	}
}

void merge_fun()
{
	int arr[100], i, n;
	printf("\nEnter the number of elements: ");
	scanf("%d",&n);
	printf("\nEnter %d elements: ", n);
	for(i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	
	merge_sort(arr, 0, n-1);
	printf("\n_____Sorted elements_____\n");
	for(i=0; i<n; i++)
	{
		printf("%d\t", arr[i]);
    } 
}


/*********************************************************************************
                               5 QUICK SORT                                                      
**********************************************************************************/


int quick(int a[], int beg, int end)
{
	int left, right, temp, loc, flag;
	loc = left = beg;
	right = end;
	flag = 0;
	while(flag!= 1)
	{
		while((a[loc]<=a[right]) && (loc!=right))
		right--;
		
		if(loc==right)
		{
			flag = 1;
		}
		else if(a[loc]>a[right])
		{
			temp = a[loc];
			a[loc] = a[right];
			a[right] = temp;
			loc = right;
		}
		
		if(flag!=1)
		{
			while((a[loc]>=a[left]) && (loc!=left))
			left++;
			if(loc == left)
			flag = 1;
			else if(a[loc]<a[left])
			{
				temp = a[loc];
				a[loc] = a[left];
				a[left] = temp;
				loc = left;
			}
		}
	}
	return loc;
}

void quick_sort(int a[], int beg, int end)
{
	int loc;
	if(beg<end)
	{
		loc = quick(a, beg, end);
		quick_sort(a, beg, loc-1);
		quick_sort(a, loc+1, end);
	}
}

int quick_fun()
{
	int arr[100], i, n;
	printf("\nEnter the number of elements: ");
	scanf("%d",&n);
	printf("\nEnter %d elements: ", n);
	for(i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	quick_sort(arr, 0, n-1);
	printf("\n_____Sorted elements_____\n");
	for(i=0; i<n; i++)
	{
		printf("%d\t", arr[i]);
    } 
}


/*********************************************************************************
                               6 RADIX SORT                                                      
**********************************************************************************/


int radix_largest(int arr[], int n)
{
	int large = arr[0], i;
	for(i=1; i<n; i++)
	{
		if(arr[i]>large)
		large = arr[i];
	}
	return large;
}

void radix_sort(int arr[], int n)
{
	int bucket[100][100], bucket_count[100];
	int i, j, k, remainder, nop=0, divisor=1, large, pass;
	large = radix_largest(arr,n);
	
	while(large>0)
	{
		nop++;
		large/=100;
	}
	for(pass=0; pass<nop; pass++)
	{
		for(i=0;i<100;i++)
		bucket_count[i] = 0;
		for(i=0;i<n;i++)
		{
			//sort the number according to the digit at PASSth place
			remainder = (arr[i]/divisor)%100;
			bucket[remainder][bucket_count[remainder]] = arr[i];
			bucket_count[remainder] += 1;
		}
		//collect the numbers after PASS pass
		i=0;
		for(k=0;k<100;k++)
		{
			for(j=0;j<bucket_count[k];j++)
			{
				arr[i] = bucket[k][j];
				i++;
			}
		}
		divisor *= 100;
	}
}

void radix_fun()
{
	int arr[100], i, n;
	printf("\nEnter the number of elements: ");
	scanf("%d",&n);
	printf("\nEnter %d elements: ", n);
	for(i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	radix_sort(arr, n);
	printf("\n_____Sorted elements_____\n");
	for(i=0; i<n; i++)
	{
		printf("%d\t", arr[i]);
    } 	
}


/*********************************************************************************
                               7 SHELL SORT                                                      
**********************************************************************************/

void shell_fun()
{
	int arr[100];
	int i, j, n, flag=1,gap_size, temp;
	printf("\nEnter the number of elements: ");
	scanf("%d",&n);
	printf("\nEnter %d elements: ", n);
	for(i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}
	gap_size = n;
	while(flag == 1 || gap_size>1)
	{
		flag=0;
		gap_size = (gap_size+1)/2;
		for(i=0; i<(n-gap_size); i++)
		{
			if(arr[i+gap_size]<arr[i])
			{
				temp = arr[i+gap_size];
				arr[i+gap_size]=arr[i];
				arr[i]=temp;
				flag=0;
			}
		}
	}
	printf("\n_____Sorted elements_____\n");
	for(i=0; i<n; i++)
	{
		printf("%d\t", arr[i]);
    }
}


/*********************************************************************************
                               MAIN FUNCTION                                                     
**********************************************************************************/


void main()
{
	int ch;
	printf("\n***********************************************************************************\n");
	printf("                               SORTING ALGORITHMS                                      \n");
	printf("***********************************************************************************\n");
	while(1)
	{
		printf("\n_____MAIN MENU_____\n");
		printf("1.Bubble sort\n2.Insertion sort\n3.Selection sort\n4.Merge sort\n5.Quick sort\n6.Radix sort\n7.Shell sort\n8.Exit\n");
		printf("\nEnter the choice: ");
		scanf("%d",&ch);
		printf("\n");
		
		switch (ch)
		{
			case 1:printf("******************************  BUBBLE SORT  ****************************************\n");
			       bubble_sort();
			       printf("\n\n*************************************************************************************\n");
			       break;
			       
			case 2:printf("******************************  INSERTION SORT  ****************************************\n");
			       insert_fun();
			       printf("\n\n*************************************************************************************\n");
			       break;
			       
			case 3:printf("*****************************  SELECTION SORT  **************************************\n");
			       select_fun();
			       printf("\n\n*************************************************************************************\n");
			       break;
			       
			case 4:printf("*******************************  MERGE SORT  ****************************************\n");
			       merge_fun();
			       printf("\n\n*************************************************************************************\n");
			       break;
			       
			case 5:printf("*******************************  QUICK SORT  ****************************************\n");
			       quick_fun();
			       printf("\n\n*************************************************************************************\n");
			       break;
			       
			case 6:printf("*******************************  RADIX SORT  ****************************************\n");
			       radix_fun();
			       printf("\n\n*************************************************************************************\n");
			       break;
			       
			case 7:printf("*******************************  SHELL SORT  ****************************************\n");
			       shell_fun();
			       printf("\n\n*************************************************************************************\n");
			       break;
			       
			case 8:exit(0);
			       break;
			    
			default: printf("Invalid choice!!, Try again\n");
			printf("\n\n*************************************************************************************\n");
		}		
	}
}
