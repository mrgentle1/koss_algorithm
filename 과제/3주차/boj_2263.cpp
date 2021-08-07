#include <iostream> 
#define max 100001 
using namespace std; 
int n; 
int temp[max], inOrder[max], postOrder[max]; 
void PreOrder(int inStart, int inEnd, int postStart, int postEnd)
{ 
    if(inStart > inEnd || postStart > postEnd) 
        return;
    printf("%d ", postOrder[postEnd]);
    int r = temp[postOrder[postEnd]]; 
    PreOrder(inStart, r-1, postStart, postStart+r-inStart-1); 
    PreOrder(r+1, inEnd, postStart+r-inStart, postEnd-1); 
} 
int main(){ 
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
        scanf("%d", &inOrder[i]);
    for (int i = 0; i < n; i++) 
        scanf("%d", &postOrder[i]);
    for (int i = 0; i < n; i++) 
        temp[inOrder[i]] = i; 
    PreOrder(0, n-1, 0, n-1); 
}
