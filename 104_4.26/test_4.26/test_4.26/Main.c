#define _CRT_SECURE_NO_WARNINGS



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//两个有序int数组合并为一个有序int数组


void Merge_sorted_arrays(int *nums1,int *nums2,int* destination,int len1,int len2)
{
	assert(nums1&&nums2&&destination);
	assert(len1>0&&len2>0);
	int z=0,i=0,j=0;
	int destlen = len1 + len2;

	while (i<len1&&j<len2)
	{
		
			if (nums1[i] < nums2[j])
			{
				destination[z++] = nums1[i++];
			}
			else
			{
				destination[z++] = nums2[j++];
			
			}
			
		
	}


	if (i < len1)
		{
		memcpy(destination + z, nums1 + i, (size_t)((len1 - i) * 4));
		
		/*for (; i < len1; i++,z++)
		{
			destination[z] = nums1[i];
		}*/
		}
	else if (j < len2)
		{
		memcpy(destination + z, nums2 + j, (size_t)((len2 - j) * 4));
		/*for (; j < len2; j++, z++)
		{
			destination[z] = nums2[j];
		}*/
		}
}


int main()
{

	int n, m;
	int i = 0,j=0,z=0;
	scanf("%d %d", &n, &m);
	
	int *nums1=malloc(sizeof(int) * n);
	int *nums2= malloc(sizeof(int) * m);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &nums1[i]);
	}
	for (i = 0; i < m; i++)
	{
		scanf("%d", &nums2[i]);
	}


	int *newnums=malloc(sizeof(int) * (n + m));
	int len = n + m;


	Merge_sorted_arrays(nums1, nums2, newnums, n, m);


	//i = 0;
	//
	//while (z<len)
	//{


	//	
	//	if (i < n && j < m)
	//	{

	//		if (nums1[i] < nums2[j])
	//		{
	//			newnums[z] = nums1[i];
	//			i++;
	//			z++;
	//		}
	//		else if (nums1[i] > nums2[j])
	//		{
	//			newnums[z] = nums2[j];
	//			j++;
	//			z++;
	//		}
	//		else
	//		{
	//			newnums[z] = nums1[i];
	//			z++;
	//			i++;
	//			newnums[z] = nums2[j];
	//			z++;
	//			j++;
	//		}
	//	}




	//	else if(i < n)
	//	{
	//		memcpy(newnums + z, nums1 + i, (n  - i)*4);
	//		z = len;
	//	}
	//	else if (j < m)
	//	{
	//		memcpy(newnums + z, nums2 + j, (m  - j) * 4);
	//		z = len;
	//	}

	//}





	for (i = 0; i < len; i++)
	{
		printf("%d ", newnums[i]);
	}
	free(nums1);
	free(nums2);
	free(newnums);
	return 0;
}