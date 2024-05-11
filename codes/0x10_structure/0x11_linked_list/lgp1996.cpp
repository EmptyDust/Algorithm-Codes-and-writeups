#include <bits/stdc++.h>
using namespace std;

typedef struct num23{
    int num;
    struct num23*next;
}NUM;

int main(){
    NUM* head = new NUM();
    NUM* tmp=head;
    int n,k;
    cin>>n>>k;

    for(int i=1;i<=n;++i)
    {
        tmp->next=new NUM();
        tmp->next->num=i;
        tmp=tmp->next;
    }
    tmp->next=head->next;

    tmp=head;
    while(tmp!=tmp->next)
    {
        for(int j=1;j<k;++j)
            tmp=tmp->next;
        NUM* t=tmp->next;
        tmp->next=t->next;
        cout<<t->num<<' ';
        free(t);
    }
    cout<<tmp->num;

    return 0;
}