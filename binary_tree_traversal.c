#include <stdio.h>
#include <stdlib.h>

// முனை வரையறை (Node Structure)
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// புதிய முனை உருவாக்கும் செயல்பாடு
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// போஸ்ட் ஆர்டரில் இடது முனைகளை எண்ணும் செயல்பாடு
int countLeftNodesPostOrder(struct Node* root) {
    if (root == NULL) {
        return 0;
    }

    // இடது சப்ட்ரீக்கு செல்
    int leftCount = countLeftNodesPostOrder(root->left);
    
    // வலது சப்ட்ரீக்கு செல்
    int rightCount = countLeftNodesPostOrder(root->right);

    // ரூட் செயல்பாடு: தற்போதைய முனையின் இடது குழந்தை இருக்கிறதா?
    int currentNodeCount = 0;
    if (root->left != NULL) {
        currentNodeCount = 1; // இடது குழந்தை இருக்கிறது, அது ஒரு இடது முனை
    }

    // மொத்தம் = இடது சப்ட்ரீ + வலது சப்ட்ரீ + தற்போதைய முனையில் கண்ட இடது முனை
    return leftCount + rightCount + currentNodeCount;
}

// முக்கிய செயல்பாடு
int main() {
    /* மாதிரி மரம்:
           1
         /   \
        2     3
       / \   /
      4   5 6
     /
    7
    */
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->left->left->left = createNode(7);

    int count = countLeftNodesPostOrder(root);
    printf("இடது முனைகளின் எண்ணிக்கை (Post Order): %d\n", count);
    // Output: 4 
    // இடது முனைகள்: 2, 4, 6, 7

    return 0;
}