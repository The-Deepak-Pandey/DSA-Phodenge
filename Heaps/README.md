I used 1 based indexing here for heaps

What is says is that if index of `root=i` then index of `leftChild=2*i` and index of `rightChild=2*i+1`. And `parent=i/2`

In heaps concepts we think of heap as a tree but originally we operate in arrays, since it is a complete tree finding indexes with respect to nodes is not a problem.

### Max Heap

Parent's nodeValue > Child's nodeValue

### Min Heap

Parent's nodeValue < Child's nodeValue