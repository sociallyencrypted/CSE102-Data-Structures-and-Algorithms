#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct MinHeapNode
{
    char data;
    int freq;
    int encode;
    int encSize;
    struct MinHeapNode *left, *right;
} MHNode;

typedef struct MinHeap
{
    int size;
    int capacity;
    MHNode **array;
} MH;

MHNode *genNode(char data, int freq)
{
    MHNode *node = (MHNode *)malloc(sizeof(MHNode));
    node->data = data;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

MHNode *genNodeAlt(char data)
{
    MHNode *node = (MHNode *)malloc(sizeof(MHNode));
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    return node;
}

int isPatta(MHNode *node)
{
    if (node->left == NULL)
    {
        if (node->right == NULL)
        {
            return 1;
        }
    }
    return 0;
}

void minHeapify(MH *mhp, int id)
{
    int smolest = id;
    int right = 2 * id + 2;
    int left = 2 * id + 1;
    if (right < mhp->size && mhp->array[right]->freq < mhp->array[smolest]->freq)
    {
        smolest = right;
    }
    if (left < mhp->size && mhp->array[left]->freq < mhp->array[smolest]->freq)
    {
        smolest = left;
    }
    if (smolest != id)
    {
        MHNode *abhi = mhp->array[smolest];
        mhp->array[smolest] = mhp->array[id];
        mhp->array[id] = abhi;
        minHeapify(mhp, smolest);
    }
}

MHNode *extractMin(MH *mhp)
{
    if (mhp->size == 0)
        return NULL;
    MHNode *node = mhp->array[0];
    mhp->array[0] = mhp->array[mhp->size - 1];
    mhp->size--;
    minHeapify(mhp, 0);
    return node;
}

int isEkSizeKa(MH *mhp)
{
    if (mhp->size == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

MH *buildMH(char data[], int freq[], int size, int capacity, MHNode **MHNarr)
{
    MH *hp = (MH *)malloc(sizeof(MH));
    hp->size = 0;
    hp->capacity = capacity;
    hp->array = (MHNode **)malloc(hp->capacity * sizeof(MHNode *));
    for (int i = 0; i < size; i++)
    {
        MHNode *node = genNode(data[i], freq[i]);
        hp->array[hp->size++] = node;
        MHNarr[i] = node;
    }
    for (int i = (hp->size - 1) / 2; i >= 0; i--)
    {
        minHeapify(hp, i);
    }
    return hp;
}

void insertNode(MH *mhp, MHNode *node)
{
    if (mhp->size == mhp->capacity)
    {
        return;
    }
    mhp->array[mhp->size] = node;
    mhp->size++;
    int id = mhp->size - 1;
    while (id > 0 && mhp->array[id]->freq < mhp->array[(id - 1) / 2]->freq)
    {
        MHNode *temp = mhp->array[id];
        mhp->array[id] = mhp->array[(id - 1) / 2];
        mhp->array[(id - 1) / 2] = temp;
        id = (id - 1) / 2;
    }
}

void printMH(MH *mhp)
{
    for (int i = 0; i < mhp->size; i++)
    {
        printf("%c:%d ", mhp->array[i]->data, mhp->array[i]->freq);
    }
    printf("\n");
}

int joinArray(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum *= 10;
        sum += arr[i];
    }
    return sum;
}

void printBuff(MHNode *jadi, int arr[], int curr, FILE *out)
{
    if (jadi->left != NULL)
    {
        arr[curr] = 0;
        printBuff(jadi->left, arr, curr + 1, out);
    }
    if (jadi->right != NULL)
    {
        arr[curr] = 1;
        printBuff(jadi->right, arr, curr + 1, out);
    }
    if (isPatta(jadi))
    {
        jadi->encode = joinArray(arr, curr);
        jadi->encSize = curr;
        fprintf(out, "%c: %d\n", jadi->data, jadi->encode);
        printf("%c: %d\n", jadi->data, jadi->encode);
    }
}
// turning water into wine, your mother into mine

void sastaDecode(FILE *in, FILE *out)
{
    // char[] ans = "";
    // struct MinHeapNode *curr = jadi;
    // for (int i = 0; i < s.size(); i++)
    // {
    //     if (s[i] == '0')
    //         curr = curr->left;
    //     else
    //         curr = curr->right;

    //     if (curr->left == NULL and curr->right == NULL)
    //     {
    //         printf("%c", curr->data);
    //         curr = jadi;
    //     }
    // }
    int size;
    size = fgetc(in) - '0';
    char data[size];
    MHNode **MHNarr = (MHNode **)malloc(size * sizeof(MHNode *));
    MHNode *jadi = genNodeAlt('\\');
    fgetc(in); // for eol after size mehul pls don't forget this again
    for (int i = 0; i < size; i++)
    {
        data[i] = fgetc(in);
        fgetc(in);
        fgetc(in);
        char c;
        MHNode *curr = jadi;
        while ((c = fgetc(in)) != '\n')
        {
            if (c == '0')
            {
                if (curr->left == NULL)
                {
                    MHNode *new = genNodeAlt('\\');
                    curr = curr->left = new;
                }
                else
                {
                    curr = curr->left;
                }
            }
            else
            {
                if (curr->right == NULL)
                {
                    MHNode *new = genNodeAlt('\\');
                    curr = curr->right = new;
                }
                else
                {
                    curr = curr->right;
                }
            }
        }
        curr->data = data[i];
        // printf("NEWS %d: %c %c\n", i, curr->data, data[i]);
    }
    // printBuff(jadi, (int *)malloc(size * sizeof(int)), 0, out);
    char digit;
    MHNode *curr = jadi;
    while ((digit = fgetc(in)) != EOF)
    {
        if (digit == '0')
        {
            if (isPatta(curr->left))
            {
                fprintf(out, "%c", curr->left->data);
                curr = jadi;
            }
            else
            {
                curr = curr->left;
            }
        }
        if (digit == '1')
        {
            if (isPatta(curr->right))
            {
                fprintf(out, "%c", curr->right->data);
                curr = jadi;
            }
            else
            {
                curr = curr->right;
            }
        }
    }
}
// bhai itna lmaba assignment 2 percent weightage ke liye kyun bhai kyun rula rahe ho

void encode(FILE *in, FILE *out)
{
    int freqi[256] = {0};
    char ch;
    int size = 0;
    while ((ch = fgetc(in)) != EOF)
    {
        if (freqi[(int)ch] == 0)
        {
            size++;
        }
        freqi[(int)ch]++;
    }
    fprintf(out, "%d\n", size);
    char arr[size];
    int freq[size];
    int j = 0;
    for (int i = 0; i < 256; i++)
    {
        if (freqi[i] != 0)
        {
            // printf("%d here", i);
            arr[j] = (char)i;
            freq[j] = freqi[i];
            j++;
        }
    }
    MHNode **nodeArr = (MHNode **)malloc(size * sizeof(MHNode *));
    MH *mhp = buildMH(arr, freq, size, 255, nodeArr);
    printMH(mhp);
    MHNode *left, *right, *top;
    while (!isEkSizeKa(mhp))
    {
        left = extractMin(mhp);
        right = extractMin(mhp);
        top = genNode('\\', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertNode(mhp, top);
        // printf("extracted node freq: %c %d %c %d\n", left->data, left->freq, right->data, right->freq);
        // printf("inserted node freq: %d\n", top->freq);
    }
    MHNode *jadi = extractMin(mhp);
    int arrz[255];
    printBuff(jadi, arrz, 0, out);
    char c;
    rewind(in);
    char buf[8];
    int counter = 0;
    while ((c = fgetc(in)) != EOF)
    {
        for (int i = 0; i < size; i++)
        {
            if (c == nodeArr[i]->data)
            {
                // counter += nodeArr[i]->encSize;
                // if (counter >= 8)
                // {
                // }
                fprintf(out, "%d", nodeArr[i]->encode);
                break;
            }
        }
    }
}

int main()
{
    char finname[128];
    char foutname[128];
    printf("Enter input file name: ");
    scanf("%s", finname);
    FILE *fin = fopen(finname, "rb");
    printf("Enter output file name: ");
    scanf("%s", foutname);
    FILE *fout = fopen(foutname, "wb");
    if (fin == NULL)
    {
        printf("Error: File not found!");
        return 0;
    }
    if (fout == NULL)
    {
        printf("Error: File not found!");
        return 0;
    }
    int choice;
    printf("Enter mode (0 for compression, 1 for decompression): ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 0:
        encode(fin, fout);
        break;

    case 1:
        sastaDecode(fin, fout);
        break;
    }
}
