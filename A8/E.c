#include<stdio.h>
#include<stdlib.h>

int len(char * s){
    int len=0;
    
    while(s[len] != '\0'){
        len++;
    }
    return len;
}
long long arrayToLongLong(char *s) {
    long long result = 0;
    int i = 0;

    // Handle negative sign if present
    int sign = 1;
    if (s[0] == '-') {
        sign = -1;
        i = 1;
    }

    // Iterate through the array and construct the number
    while (s[i] != '\0') {
        result = result * 10 + (s[i] - '0');
        i++;
    }

    return result * sign;
}
void removeLeadingZeroes(char *s) {
    int original = len(s);
    int i = 0;
    while(s[i] == '0') {
        i++;
    }

    // Copy non-zero characters to the beginning of the s array
    for(int j = 0; j < original - i; j++) {
        s[j] = s[i + j];
    }

    // Add null terminator at the end of the modified string
    s[original - i] = '\0';
}

void removeOneDigit(char *s) {
    int original = len(s);
    char new[original - 1];

    // Determine which digit to remove based on comparison
    int removeIndex;
    if (s[0] > s[1]) {
        // If the most significant digit is greater, remove it
        removeIndex = 0;
    } else {
        // Otherwise, remove the second most significant digit
        removeIndex = 1;
    }

    // Copy remaining digits to the new array
    int newIndex = 0;
    for (int i = 0; i < original; i++) {
        if (i != removeIndex) {
            new[newIndex++] = s[i];
        }
    }

    // Add null terminator at the end of the modified string
    new[original - 1] = '\0';

    // Copy the modified string back to the original array
    for (int i = 0; i < original; i++) {
        s[i] = new[i];
    }
}


int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    char s[n+1];
    scanf("%s",s);
    char scopy[n+1];
    for(int i=0;i<n+1;i++){
        scopy[i]=s[i];
    }
    while(k--){
        removeOneDigit(s);
        removeLeadingZeroes(s);
    }
    long long  n1=arrayToLongLong(scopy);
    long long n2=arrayToLongLong(s);
    printf("%lld\n",(long long)(n1-n2));
    return 0;
}