
// MaxHeapify(A, i)
// 1. l = Left(i)
// 2. r = Right(i)
// 3. if i is a leaf, then return
// 4. if i has one child, then swap with the child
// 5. if i has two children, then swap with the larger child
// 6. if either child is larger than i, then swap with the larger child
// 7. MaxHeapify(A, l)
// 8. MaxHeapify(A, r)

// MaxHeapify function
void MaxHeapify(int A[], int i, int n)
{
    int l, r, largest;
    l = Left(i);
    r = Right(i);
    if (l <= n && A[l] > A[i])
        largest = l;
    else
        largest = i;
    if (r <= n && A[r] > A[largest])
        largest = r;
    if (largest != i)
    {
        swap(&A[i], &A[largest]);
        MaxHeapify(A, largest, n);
    }
}

MinHeapify(int A[], int i, int n)
{
    int l, r, smallest;
    l = Left(i);
    r = Right(i);
    if (l <= n && A[l] < A[i])
        smallest = l;
    else
        smallest = i;
    if (r <= n && A[r] < A[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&A[i], &A[smallest]);
        MinHeapify(A, smallest, n);
    }
}


