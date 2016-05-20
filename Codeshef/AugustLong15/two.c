#include <stdio.h>
#include <string.h>
int main(){
	unsigned int T;
	char l1[200000+1];
	char l2[200000+1];
	scanf("%d",&T);
	unsigned int i;
	unsigned int s1,s2;
	unsigned int pos[2];
	int ans;

	while(T--){
		unsigned int change=0;
		
		scanf("%s",l1);
		scanf("%s",l2);
		
		i=0;
		
		s1=strlen(l1)-1;

		pos[0]=0;
		pos[1]=0;
		// 0 for l1 and 1 for l2

		ans = 1; // 1 for True

		
		if (l1[i] == '.') {
			pos[0]=i;
			pos[1]=0;
		}
		else if (l2[i] == '.')	{
			pos[0]=i;
			pos[1]=1;
		}	
		else{
			ans=0;
		}

		// if (ans!=0 && l1[s1]=='#' && l2[s1]=='#'){
		// 	ans=0;
		// }

		if (ans == 1){
			while(i<s1) {
				
				if(pos[1]==0) {

					if (i+1<=s1 && l1[i+1]=='.'){
						i+=1;
						pos[0]=i;
					}
					else if (i<=s1 && l2[i]=='.'){
						pos[0]=i;
						pos[1]=1;
						change+=1;
						l1[i]='#';
					}
					else if (i+1<=s1 && l2[i+1]=='.'){
						i+=1;
						pos[0]=i;
						pos[1]=1;
						change+=1;
					}
					else {
						// if (i!=s1 || i!=s2){
								ans=0;
								break;
							// }
					}
				}
				else if (pos[1]==1) {
					if (i+1<=s1 && l2[i+1]=='.'){
						i+=1;
						pos[0]=i;
					}
					else if (i<=s1 && l1[i]=='.'){
						pos[0]=i;
						pos[1]=0;
						change+=1;
						l2[i]='#';
					}
					else if (i+1<=s1 && l1[i+1]=='.'){
						i+=1;
						pos[0]=i;
						pos[1]=0;
						change+=1;
					}
					else {
						// if (i!=s1 || i!=s2){
								ans=0;
								break;
							// }
					}
				}
			}
		}

		if (ans==1){
			if (pos[1]==1 && pos[0]==s1){
				if (l2[pos[0]]=='.') {
					ans=1;
				}
				// else if(l1[i]=='.'){
				// 	change+=1;
				// 	ans=1;
				// }
				else{
					ans=0;
				}
			}
			
			if (pos[1]==0 && pos[0]==s1){
				if (l1[pos[0]]=='.'){
					ans=1;
				}
				// else if(l2[i]=='.'){
				// 	change+=1;
				// 	ans=1;
				// }
				else{
					ans=0;
				}
			}
		}

		if(ans==1)
			printf("%s\n%d\n","Yes",change);
		else
			printf("%s\n","No");
		// c=getchar_unlocked();
	}
	return 0;
}