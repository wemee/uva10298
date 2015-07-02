#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define _SIZE_ 168

int prime[168] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};

int search(int n, int left, int right){
    int mid;
    
    if (left>right) return right;
    
    mid=left+right/2;
    if (prime[mid]==n) return mid;
    if (prime[mid]>n) return search(n, left, mid-1);
    return search(n, mid+1, right);
}

int check(const char *s1, const char *s2){
    return strcmp(s1, s2) ? 0: 1;
}

int split_and_check(char *str, int size, int len){
    int left=0;
    static char s1[500000], s2[500000];
    while (left+size<len) {
        strncpy(s1, str+left, size);
        strncpy(s2, str+left+size, size);
        if (!check(s1, s2)) return 0;
        left += size;
    }
    return len/size;
}

int main() {
    char *str=malloc(1000000*sizeof(char)), ch;
    int len, sq, prime_idx, i, n;
    while (scanf("%s", str)!=EOF) {
        if (str[0]=='.') break;
        
        len = (int)strlen(str);
        if (len==1) {
            printf("1\n");
            continue;
        }
        
        ch = str[0];
        if ((int)strspn(str, &ch)==len) {
            printf("%d\n", len);
            continue;
        }
        
        n = 0;
        sq=(int)sqrt(len);
        prime_idx = search(sq, 0, _SIZE_);
        for (i=0; i<=prime_idx; i++) {
            n = split_and_check(str, prime[prime_idx], len);
            if(n>0) break;
        }
        printf("%d\n", n>0 ? n:1);
    }
    free(str);
    return 0;
}
