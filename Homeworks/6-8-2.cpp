#include <stdio.h>
#include <algorithm>

int compare(int now[10],int a[10],int b[10],int digit,int ts,int num[10][10]){
    bool flag=false;
    for(int i=0;i<ts;i++){
        int tmpa=0,tmpb=0;
        for(int k=0;k<digit;k++){
            for(int j=0;j<digit;j++){
                if(now[j]==num[i][k]){
                    tmpb++;
                };
            }
            if(now[k]==num[i][k]){
                tmpa++;
            }
        }
        tmpb-=tmpa;
        if(tmpa==a[i] && tmpb==b[i]){
            flag=true;
        }else{
            flag=false;
            break;
        }
    }
    if(flag==true){
        //for(int i=0;i<10;i++)printf("%d",now[i]);
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int cases;
    scanf("%d",&cases);
    while(cases--){
        long long int count=0;
        int table[10]={9,8,7,6,5,4,3,2,1,0};
        int ts,digit,tmp,i;
        int num[10][10]={0},a[10]={0},b[10]={0};
        scanf("%d%d",&ts,&digit);
        for(i=0;i<ts;i++){
            scanf("%d%d%d",&tmp,&a[i],&b[i]);
            for(int k=digit-1;k>=0;k--){
                num[i][k]=tmp%10;
                tmp/=10;
            }
        }
        while(table[0]!=0){
              if(compare(table,a,b,digit,ts,num)){
                  count++;
              }
              std::prev_permutation(table,table+10);
        }
        for(int i=2;i<=10-digit;i++){
            count/=i;
        }
            printf("%lld\n",count);
    }
    return 0;
}
