#include <stdio.h>
#include <stdlib.h>
int main()
{
int x; scanf("%d",&x);
int arr[x];
int freq[100000]={0};
for(int i=0;i<x;i++){
scanf("%d",&arr[i]);
freq[arr[i]]++;
}
int maxe = arr[0] , maxx = 0;
for(int i=0;i<x;i++){
if(maxx<freq[arr[i]]){
maxx = freq[arr[i]];
maxe = arr[i];
}
}
if(maxx<=(x/2))
printf("-1");
else{
for(int i=0;i<x;i++){
if(arr[i]==maxe){
printf("%d ",i);
}
}
}
return 0;
}