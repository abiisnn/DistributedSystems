#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
int main(){
	srand(time(NULL));
	char *str = NULL;
	int tam = 0;
	int n = 175760;
	//cin  >> n;
	for(int i =0; i < n; i++){
		tam+=4;
		str= (char *) realloc(str,tam);
		//tam+=4;
		char aux[5];
		for(int j =0; j < 3; j++){
			aux[j] = (char)((rand()%26)+'A');
		}
		aux[3] = ' ';
		aux[4] = '\0';
		
		memcpy(str+tam-4,aux,4);
	}
	//printf("%s",str);
	char ipn[] = "IPN";
	int cont =0;
	for(int i =0; i < tam-3; i++){
		int flag = 1;
		for(int j =0; j < 3; j++){
			if(ipn[j] != str[i+j]){
				flag = 0;
				break;
			}
		}
		if(flag == 1) cont++;
	}
	printf("%d",cont);
	return 0;
}

