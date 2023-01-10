/*
#########################################
# Program to calculate the determinant  #
# of a 3x3 matrix			#
#					#
# Input:				#
# 	9 elements for each position in #
# 	a 3x3 array			#
# Returns:				#
# 	the determinant of the matrix	#
#					#
#########################################
*/

#include <stdio.h>
int main(){
	printf("21CS8109\tAyush Anand\n");
	printf("Let's calculate the determinant of a 3x3 matrix\n");
	printf("Input the matrix at (i-j) position\n");

	int arr[3][3];
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			printf("%d-%d:\t", i,j);
			scanf("%d", &arr[i][j]);
		}
	}
	int ans = arr[0][0]*(arr[1][1]*arr[2][2]-arr[1][2]*arr[2][1])
			- arr[0][1]*(arr[1][0]*arr[2][2]-arr[1][2]*arr[2][0])
			+ arr[0][2]*(arr[1][0]*arr[2][1]-arr[1][1]*arr[2][0]);
	printf("determinant is: %d\n", ans);
	return 1;
}
