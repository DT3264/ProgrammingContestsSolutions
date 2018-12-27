#include<stdio.h>
struct server{
    int recieved, lost, total;
}servers[2];
int main(){
    int n, i;
    int server, recieved, lost;
    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%d %d %d", &server, &recieved, &lost);
        servers[server-1].recieved+=recieved;
        servers[server-1].lost+=lost;
        servers[server-1].total+=recieved+lost;
    }
    for(i=0; i<2; i++){
        printf("%s\n", (servers[i].recieved>=servers[i].total/2 ? "LIVE" : "DEAD"));
    }
    return 0;
}
