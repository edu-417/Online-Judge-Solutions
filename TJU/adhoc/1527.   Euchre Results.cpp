#include<cstdio>
int loss[3],win[3];
bool doit(){
    for(int i=0;i<3;++i)scanf("%d%d",loss+i,win+i);
    bool end=true;
    for(int i=0;i<3;++i)if(loss[i]!=0 || win[i]!=0)end=false;
    if(end)return false;
    int losses=0,wins=0;
    for(int i=0;i<3;++i)losses+=loss[i],wins+=win[i];
    int a=(losses+loss[0]+win[0]+wins)/2;
    int b=a;
    printf("Anna's won-loss record is %d-%d.\n",a-losses,b-wins);
    return true;
    }
int main(){
    while(1)if(!doit())break;
    }
