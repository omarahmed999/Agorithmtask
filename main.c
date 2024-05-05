#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n; scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int count1 = 0 , count2 = 0,dom = arr[0] ;

    for(int i=0;i<n;i++){
            int e = arr[i];
            count1=0;
        for(int j=0;j<n;j++){
            if(arr[j]==e) count1++;
        }
    if(count2<count1){
            count2 = count1;
            dom = arr[i];
        }
    }
//    printf("%d\n",count2);
//    printf("%d\n",dom);
if(count2 <= n/2) printf("-1");
else{
    for(int i=0;i<n;i++){
        if(arr[i]==dom) printf("%d ",i);
    }
}
    return 0;
}
