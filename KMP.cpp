#include <stdio.h>

#define M 9
#define N 5
#define letter 4
#define flow 65

char* pat = "AABCAABCA";
char* txt = "BCAAB";
int dp[N][26];

int search(){
	int next = 0;
	for(int i = 0; i < M; i++){
		next = dp[next][pat[i] - flow];
		if(next == N)
			return i - N + 1;
	}
	
	return -1;
}

void make_dp(){
	int X = 0;
	
	// initialize the pd matrix
	for(int i = 0; i < M; i ++){
		for(int j = 0; j < N; j++){
			dp[i][j] = 0;
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < letter; j++){
			if( (j) == (txt[i] - flow) )
				dp[i][j] = i + 1;
			else
				dp[i][j] = dp[X][j];
		}
		
		X = dp[X][txt[i] - flow];
	}
}

int main(){
	make_dp();
	
	for(int i = 0; i < N; i ++){
		for(int j = 0; j < letter; j++){
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}
	
	int res = search();
	printf("\ninex of start is %d\n", res);
	
	return 0;
}
