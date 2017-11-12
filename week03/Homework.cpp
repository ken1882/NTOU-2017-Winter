#include <cstdio>

int main(int argc, char** argv){
    int n;
    scanf("%d", &n);
    while(n--){
        int hr, mi, sec;
        scanf("%d:%d:%d", &hr, &mi, &sec);
        if(hr >= 12){
            if(hr > 12)hr = hr % 12;
            printf("%02d:%02d:%02d p.m.\n", hr, mi ,sec);
        }
        else{
            if(!hr)hr = 12;
            printf("%02d:%02d:%02d a.m.\n", hr, mi ,sec);
        }
    }
    return 0;
}
