#include <stdio.h>

char a[9];
char b[9];
char c[9];

int main(){
    scanf("%s %s",a,b);
    //第1 2 3 4位是阶码
    int jiema1=0,jiema2=0;
    for(int i=1;i<5;i++){
        jiema1=(a[i]-'0')+jiema1*2;//存进去的是字符，无法直接加减
    }
    for(int j=1;j<5;j++){
        jiema2=(b[j]-'0')+jiema2*2;//存进去的是字符，无法直接加减
    }
    int jiema;
    int jiemacha;
    if(jiema1>jiema2){
        jiema=jiema1;
        jiemacha=jiema1-jiema2;
    }
    else{
        jiema=jiema2;
        jiemacha=jiema2-jiema1;
    } 
    int weishu1=0,weishu2=0;
    for(int i=5;i<8;i++){
        weishu1=(a[i]-'0')+weishu1*2;
    }
    for(int j=5;j<8;j++){
        weishu2=(b[j]-'0')+weishu2*2;
    }
    weishu1=8+weishu1;//补1
    weishu2=8+weishu2;
    weishu1=weishu1>>(jiema-jiema1);
    weishu2=weishu2>>(jiema-jiema2);
    int weishu=weishu1+weishu2;
    while(weishu>=16){
        weishu = weishu >> 1;
        jiema++;
    }
    for(int k=7;k>4;k--){
        c[k]=(weishu%2) ? '1' : '0';
        weishu=weishu/2;
    }
    for(int q=4;q>0;q--){
        c[q]=(jiema%2) ? '1' : '0';
        jiema=jiema/2;
    }
    c[0]='0';
    c[8]='\0';
    printf("%s",c);
    return 0;
}