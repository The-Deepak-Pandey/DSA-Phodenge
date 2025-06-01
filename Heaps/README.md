I used 1 based indexing here for heaps

What is says is that if index of `root=i` then index of `leftChild=2*i` and index of `rightChild=2*i+1`. And `parent=i/2`

In heaps concepts we think of heap as a tree but originally we operate in arrays, since it is a complete tree finding indexes with respect to nodes is not a problem.

### Max Heap

Parent's nodeValue > Child's nodeValue

### Min Heap

Parent's nodeValue < Child's nodeValue


### Inserting a Node

1. **Insert the Node at the End**: Add the new node at the end of the heap (array representation).

2. **Heapify-Up (Bubble-Up)**: Compare the newly added node with its parent. If the heap property is violated:
    - For Max Heap: Swap the node with its parent if the node's value is greater than the parent's value.
    - For Min Heap: Swap the node with its parent if the node's value is less than the parent's value.

3. **Repeat Until Heap Property is Restored**: Continue the process until the node is in the correct position and the heap property is satisfied.

4. **Stop When Root is Reached**: If the node reaches the root and the heap property is still satisfied, stop the process.

### Deleting a Node

1. **Replace the Node to be Deleted**: Replace the node to be deleted with the last node in the heap (array representation).

2. **Remove the Last Node**: Remove the last node from the heap.

3. **Heapify-Down (Bubble-Down)**: Compare the replaced node with its children. If the heap property is violated:
    - For Max Heap: Swap the node with the larger child if the node's value is less than the larger child's value.
    - For Min Heap: Swap the node with the smaller child if the node's value is greater than the smaller child's value.

4. **Repeat Until Heap Property is Restored**: Continue the process until the node is in the correct position and the heap property is satisfied.

5. **Stop When Leaf Node is Reached**: If the node becomes a leaf and the heap property is still satisfied, stop the process.

### Heapify Algorithm

### Heapify Algorithm with Build Heap

#### Heapify
Heapify is a process to maintain the heap property for a node and its descendants. It ensures that the subtree rooted at the node satisfies the heap property.

1. **Start with a Node**: Select a node in the heap (array representation).

2. **Compare with Children**:
    - For Max Heap: Find the largest value among the node and its children.
    - For Min Heap: Find the smallest value among the node and its children.

3. **Swap if Necessary**: If the node's value violates the heap property, swap it with the child having the largest (Max Heap) or smallest (Min Heap) value.

4. **Repeat Recursively**: Perform heapify on the affected child node until the heap property is restored.

#### Build Heap
Building a heap involves converting an unsorted array into a valid heap.

1. **Start from the Last Non-Leaf Node**: The last non-leaf node is at index \(  n/2 +1 \) (1-based indexing).

2. **Perform Heapify**: Apply the heapify algorithm to each node from the last non-leaf node up to the root.

3. **Result**: After heapifying all nodes, the array represents a valid heap.

#### Time Complexity:
- **Heapify**: \(O(\log n)\) for a single node.
- **Build Heap**: \(O(n)\) for all nodes.

#### Example:
Given an array `[4, 10, 3, 5, 1]`, build a max heap:
1. Start heapify from index \( \lfloor n/2 \rfloor \).
2. Apply heapify recursively to ensure the heap property.
3. Resulting max heap: `[10, 5, 3, 4, 1]`.

### Heap Sort

Heap Sort is a comparison-based sorting algorithm that uses the properties of a heap to sort elements.

1. **Build a Max Heap**: Convert the array into a max heap. This ensures the largest element is at the root.

2. **Extract the Root**: Swap the root (largest element) with the last element in the heap. Reduce the heap size by one.

3. **Heapify the Root**: Restore the heap property by performing heapify-down on the root.

4. **Repeat Until Sorted**: Continue extracting the root and heapifying until the heap size becomes 1.


### Time Complexity:
- **Building the Heap**: \(O(n)\)
- **Heapify Operations**: \(O(\log n)\) for each of the \(n\) elements.
- **Overall**: \(O(n \log n)\)

### Space Complexity:
- **In-Place Sorting**: \(O(1)\)

## Using Priority Queue

### Max - Heap

1. **Initialization**: `priority_queue<int> maxHeap;`
2. **Insertion**: `maxHeap.push(value);`
3. **Peek (Access the largest element)**: `maxHeap.top();`
4. **Deletion (Remove the largest element)**: `maxHeap.pop();`

### Min - Heap

1. **Initialization**: `priority_queue<int, vector<int>, greater<int>> minHeap;`
2. **Insertion**: `minHeap.push(value);`
3. **Peek (Access the smallest element)**: `minHeap.top();`
4. **Deletion (Remove the smallest element)**: `minHeap.pop();`