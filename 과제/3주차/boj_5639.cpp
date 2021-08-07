#include <iostream>
#include <vector>
 
using namespace std;
 
struct Node{
    int left=0;
    int right=0;
};
 
Node tree[1000001];
 
void insert(int p, int data){
    if(p<data){
        if(tree[p].right == 0) tree[p].right = data;
        else insert(tree[p].right, data);
    }
    else {
        if(tree[p].left == 0) tree[p].left = data;
        else insert(tree[p].left, data);
    }
}
 
void post_order(int p){
    
    if(p != 0){
        post_order(tree[p].left);
        post_order(tree[p].right);
        cout << p << "\n";
    }
}
 
int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int root;
    cin >> root;
    
    int num;
    while(cin >> num){
        insert(root, num);
    }
    
    post_order(root);
}
 
