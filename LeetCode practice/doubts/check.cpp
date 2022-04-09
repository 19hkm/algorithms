#include<bits/stdc++.h>
using namespace std;

#define loopi(i,a,b) for(int i=a; i<b; i++)
#define PB push_back
#define MP make_pair
#define F first
#define S second

class Node {
    public: 
    int val;
    Node* next;
    Node(int val){
        this.val = val;
        this.next = NULL;
    }
};

public Node* prepareNode(vector<int> v){
    Node* dummyNode = new Node(-1);
    Node* head = dummyNode;
    for(auto val: v){
        head->next = new Node(val);
        head = head->next;
    }
    return dummyNode->next;
}

public void printNodes(Node* head){
    while(head) 
        cout<<head->val<<" ";
    cout<<endl;
}

int main(){
    Node* head = prepareNode({1,2,3,4});
    printNodes();
    return 0;
}