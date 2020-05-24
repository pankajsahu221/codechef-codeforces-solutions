This code is taken from MathProgrammer(github).
Thanks for his code.
/*
Build a segment trees. The leaves are the elements themselves. Each level we do either OR or XOR on the children nodes.

If there are an even number of levels, the first operation is XOR ... Else it is OR.

To do an update, we must trace a path from the root to the leaf. This is O(n), where n is the number of levels. 
Or O(log n), if n is the number of elements.
*/

int tree[3*MAX_SIZE];
int element[MAX_SIZE];

int perform(int a, int operation, int b)
{
    switch(operation)
    {
        case OR  :  return (a|b);
        case XOR :  return (a^b);
    }
}

int other(int operation)
{
    return (operation^1);
}

void build(int node, int start, int end, int operation)
{
    if(start == end)
    {
        tree[node] = element[start];
        return;
    }

    int mid = (start + end)/2;

    build(2*node, start, mid, other(operation));
    build(2*node + 1, mid + 1, end, other(operation));

    tree[node] = perform(tree[2*node], operation, tree[2*node + 1]);
}

void update(int node, int start, int end, int index, int value, int operation)
{
    if(start == end)
    {
        tree[node] = element[index] = value;
        return;
    }

    int mid = (start + end)/2;

    if(index >= start && index <= mid)
    {
        update(2*node, start, mid, index, value, other(operation));
    }
    else if(index > mid && index <= end)
    {
        update(2*node + 1, mid + 1, end, index, value, other(operation));
    }

    tree[node] = perform(tree[2*node], operation, tree[2*node + 1]);
}

int main()
{
    int n, no_of_queries;
    scanf("%d %d", &n, &no_of_queries);

    int no_of_elements = (1 << n);
    for(int i = 1; i <= no_of_elements; i++)
        scanf("%d", &element[i]);

    int first_operation = (n%2 == 0 ? XOR : OR);
    build(1, 1, no_of_elements, first_operation);

    while(no_of_queries--)
    {
        int index, value;
        scanf("%d %d", &index, &value);

        update(1, 1, no_of_elements, index, value, first_operation);
        printf("%d\n", tree[1]);
    }
    return 0;
}
