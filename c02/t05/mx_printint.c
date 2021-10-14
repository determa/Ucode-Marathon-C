#include <unistd.h>

void mx_printint(int n){
	if(n != 0) {
		char v[20];
		int i = 0;
		long val = n;
		if(val < 0) {
			write(1, "-", 1);
			val = -val;
		}
	
		while(val != 0) {
			 v[i++] = val % 10 + '0';
			 val /= 10;
		}
	
		for(int j = i - 1; j >= 0; j--)
			write(1, &v[j], 1);
	} 
	else 
		write(1, "0", 1);
}

