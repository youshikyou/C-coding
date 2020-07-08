
# include <stdio.h>
# include <string.h>
void get_next(char *T, int * next) {
	int i = 1;
	int j = 0;
	next[1] = 0;
	while (i < T[0])  //if T starts from index 0, index 0 is not the length, it should be strlen(T)
	{
		
		if (j == 0 || T[i] == T[j])  //if T starts from index 0, index 0 is not the length, it should be T[i-1]= T[j-1]
		{ 
			i++;
			j++;
			next[i] = j;
		}
		else
			j = next[j];

	}
}

int KMP(char * S, char *T, int pos) {
	int next[255];
	int i = pos;
	int j = 1;
	get_next(T, next);
	while (i <= S[0] && j <= T[0]) //if T and S start from index 0, index 0 is not the length, it should be i<=strlen(S) && j<=strlen(T),
	{
		if (S[i] == T[j] || j == 0) //if T and S start from index 0, index 0 is not the length, it should be S[i-1]= T[j-1]
		{
			i++;
			j++;
		}
		else
			j = next[j];
	}

	if (j > T[0]) {
		return i - T[0];
	}
	else
		return 0;
}

int main() {
	char S[255] = " ababcabcacbab";
	S[0] = 13;
	char T[255] = " abcac";
	T[0] = 5;
	int i = KMP(S,T,1);
	printf("%d", i);
	return 0;
}
