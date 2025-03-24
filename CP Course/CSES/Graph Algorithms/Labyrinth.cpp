#include <iostream>
using namespace std;

struct Node{
    int x,y;
    Node *next;
    Node(int x, int y):x(x),y(y){}
};

struct Queue{
    Node *head;
    Node *tail;
    Queue():head(nullptr),tail(nullptr){}
    void push(Node *node){
        if(head==nullptr){
            head=node;
            tail=node;
        }else{
            tail->next=node;
            tail=node;
        }
    }
    Node* pop(){
        if(head==nullptr){
            return nullptr;
        }else{
            Node *temp=head;
            head=head->next;
            return temp;
        }
    }
    bool empty(){
        return head==nullptr;
    }
};


bool vaildPush(int i, int j, int M, int N, Queue * q, int **arr, int x, int y){
    if(i>0&&i<M&&j>0&&j<N){{
        if(arr[i][j]=='.'){
            q->push(new Node(i,j));
            arr[i][j] = x*N + y;
            return false;
        }else if(arr[i][j]=='B'){
            q->push(new Node(i,j));
            return true;
        }
   
    }

    }
}
int main() {
    int M,N;
    cin>>M>>N;

    int **arr = new int*[M];
    for (int i = 0; i < M; i++) {
        arr[i] = new int[N];
    }

    for(int i=0;i<M;i++) for(int j=0;j<N;j++) cin>>arr[i][j];

    int iA=0,jA=0;
    for(int i=0;i<M;i++) for(int j=0;j<N;j++){
        if(arr[i][j]=='A'){
            iA=i;
            jA=j;
            break;
        }
    }
    
    Queue q;
    q.push(new Node(iA,jA));

    while(!q.empty()){
        Node *p = q.pop();
        int i=p->x;
        int j=p->y;

        if(vaildPush(i-1, j, M, N, &q, arr, i, j)){break;};
        if(vaildPush(i+1, j, M, N, &q, arr, i, j)){break;};
        if(vaildPush(i, j-1, M, N, &q, arr, i, j)){break;};
        if(vaildPush(i, j+1, M, N, &q, arr, i, j)){break;};
    }

    if(q.empty()){

        cout<<"NO";
    }else{
        Node *p = q.pop();
        int i=p->x;
        int j=p->y;

        // trace path

    }
   


    for (int i = 0; i < M; i++) {
        delete[] arr[i];
    }
    
    delete[] arr;

    return 0;
}