#include<iostream>

using namespace std;

#define max2(a,b) (a>b ? a : b)

//Longest common subsequence
//LCS(i,j) = if a[i]==b[j] then 1+LCS(i-1,j-1)
//			else 	max(LCS(i-1,j),LCS(i,j-1))
int LCS_recursive(char *a, char *b, int higha, int highb){
	if(higha < 0 || highb < 0){
		return 0;
	}
	if(a[higha] == b[highb]){
		return 1 + LCS_recursive(a,b,higha-1,highb-1);
	}
	else{
		return max2(LCS_recursive(a,b,higha-1,highb),LCS_recursive(a,b,higha,highb-1));
	}
}


int LCS_TDM(char *a, char *b, int higha, int highb,int **mem){
	if(higha < 0 || highb < 0){
		return 0;
	}
	if(a[higha] == b[highb]){
		if(higha == 0){
			mem[0][0] = 1;
			return mem[0][0];
		}
		if(mem[higha][highb] == -1){
			mem[higha][highb] = 1 + LCS_TDM(a,b,higha-1,highb-1,mem);
		}
		return mem[higha][highb];
	}
	else{
		if(higha == 0 || highb == 0){
			mem[0][0] = 1;
			return mem[0][0];
		}
		if(mem[higha][highb] == -1){
			mem[higha][highb] = max2(LCS_TDM(a,b,higha-1,highb,mem),LCS_TDM(a,b,higha,highb-1,mem));
		}
		return mem[higha][highb];
	}
}

int LCS_TDMCaller(char *a, char *b, int lena, int lenb){
	int **mem = (int **)malloc(lena*sizeof(int *));
	for(int i=0; i<lena; i++){
		mem[i] = (int *)malloc(lenb * sizeof(int));
		fill(mem[i],mem[i]+lenb,-1);
	}
	return LCS_TDM(a,b,lena-1,lenb-1,mem);
}