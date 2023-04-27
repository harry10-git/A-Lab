#include<stdio.h>
#include<stdlib.h>
#define MAX_HT 100

typedef struct minHeapNode {
    char data;
    unsigned freq;
    struct minHeapNode *left, *right; 
} minHeapNode;

typedef struct minHeap {
    unsigned size;
    unsigned cap;
    struct minHeapNode** arr;
} minHeap;

minHeapNode* createNode(char data, unsigned freq){
    minHeapNode* newnode = (minHeapNode*)malloc(sizeof(minHeapNode));
    newnode->data = data;
    newnode->freq = freq;
    newnode->left = newnode->right = NULL;
    return newnode;
}

minHeap* createMinHeap(unsigned cap){
    minHeap* minheap = (minHeap*)malloc(sizeof(minHeap));
    minheap->size = 0;
    minheap->cap = cap;
    minheap->arr = (minHeapNode**)malloc(sizeof(minHeapNode*) * minheap->cap);
    return minheap;
}

void swapMinNode(minHeapNode** a,minHeapNode** b){
    minHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(minHeap* minheap, int i){
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
  
    if (left < minheap->size && minheap->arr[left]->freq < minheap->arr[smallest]->freq){
        smallest = left;
    }
    
    if (right < minheap->size && minheap->arr[right]->freq < minheap->arr[smallest]->freq){
        smallest = right;
    }

    if (smallest != i){
       
        swapMinNode(&minheap->arr[smallest],&minheap->arr[i]);
        minHeapify(minheap,smallest);
    }
}

int isSizeOne(minHeap* minheap){
    return (minheap->size == 1);
}

minHeapNode* extractMin(minHeap* minheap){
    minHeapNode*  temp = minheap->arr[0];
    minheap->arr[0] = minheap->arr[minheap->size - 1];
    --minheap->size;
    minHeapify(minheap,0);
    return temp;
}



void insertMinHeap(minHeap* minheap, minHeapNode* minheapnode){
    ++minheap->size;
    int i = minheap->size - 1;
    while (i && minheapnode->freq < minheap->arr[(i- 1) / 2]->freq){
        minheap->arr[i] = minheap->arr[(i - 1)/2];
        i = (i - 1) / 2;
    }
    minheap->arr[i] = minheapnode;
}

void buildMinHeap(minHeap* minheap){
    int n = minheap->size - 1;
    int i;
    //build min heap
    for(i = (i - 1) / 2; i >= n; --i){
        minHeapify(minheap,i);
    }
}

void display(int arr[], int n){
    for (int i = 0; i < n; i++){
        printf(" %d ",arr[i]);
    }
    printf("\n");
}

int isLeaf(minHeapNode* root){
    return !(root->left) && !(root->right);
}

minHeap* createAndBuildMinHeap(char data[], int freq[], int size){
    minHeap* minheap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minheap->arr[i] = createNode(data[i],freq[i]);

    minheap->size = size;
    buildMinHeap(minheap);
    return minheap;       
}

//The function that builds Huffman tree
minHeapNode* buildHuffmanTree(char data[], int freq[], int size){
    minHeapNode *left, *right, *top;  
    //step1:Create a minheap of capacity equal to size
    minHeap* minheap = createAndBuildMinHeap(data,freq,size);

    // Iterate while size of heap doesn't become 1
    while (!isSizeOne(minheap)){
    //step2: Extract 2 min heap freq items from min heap 
        left = extractMin(minheap);
        right = extractMin(minheap);
    /*Step 3: Create a new internal node with freq equal to the sum of the 
    the 2 nodes frequencies. 
    
    Make the 2 extracted node as left and right of this new
    node.Add this node to the min heap.
    
    $ is a special value for internal nodes
    */
        top = createNode('$',left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertMinHeap(minheap,top);
    }
    return extractMin(minheap);
}

// Prints huffman codes from the root of Huffman Tree.
// It uses arr[] to store codes
void printCodes(minHeapNode* root, int arr[], int top){
    //checks if the left child of root exists or not
    if (root->left){
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right){
        arr[top] = 1;
        printCodes(root->right,arr, top + 1);
    }

    if (isLeaf(root)){
        printf(" %c: ", root->data);
        display(arr,top);
    }
}

void HuffmanCode(char data[], int freq[], int size){
    minHeapNode* root = buildHuffmanTree(data,freq,size);
    int arr[MAX_HT], top = 0;
    printCodes(root, arr, top);
}

int main(){
    int n;
    char arr[40];
    int freq[40];
    printf("Enter the number of elements:\n");
    scanf("%d",&n);
    printf("Enter %d characters and their frequencies:\n",n);
    for (int i = 0; i < n; i++){
        scanf(" %c %d",&arr[i],&freq[i]);
    }

    HuffmanCode(arr,freq,n);
    return 0;
}