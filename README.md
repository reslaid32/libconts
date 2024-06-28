# libconts
**Library of data structures and containers in `C` language**

## Structures
  1. [Hashmap](libconts/hashmap/hashmap.h)
  - Key-value storage, the principle of operation of a hashmap involves using a hash function to convert keys into array indices (hashes), where values are stored. Its core principle ensures fast data access by quickly searching based on the key's hash and minimizing collisions (instances where different keys hash to the same index).
  2. [Vector](libconts/vector/vector.h)
  - Dynamic array, the principle of operation of a vector involves storing elements in contiguous memory with dynamic resizing as needed, ensuring efficient element access and fast insertion/deletion at the end of the data structure.
 3. [Linked-List](libconts/list/linked.h)
 - Linked lists: Node-based storage, the principle of operation of a linked list involves storing elements as nodes where each node contains data and a reference (or pointer) to the next node, allowing dynamic allocation and efficient insertion/deletion operations.
 4. [Doubly-Linked-List](libconts/list/doubly_linked.h)
 - Bidirectional nodes, the principle of operation of a doubly linked list involves storing elements as nodes where each node contains data and references (or pointers) to both the next and previous nodes, allowing bidirectional traversal and efficient insertion/deletion operations.
 5. [Stack](libconts/stack/stack.h)
 - Last in, first out, the stack operates based on the Last In, First Out (LIFO) principle, where items are added and removed from one end of the data structure only.
 6. [Queue](libconts/queue/queue.h)
 - First In, First Out, the queue operates based on the First In, First Out (FIFO) principle, where items are added to the back and removed from the front of the data structure.
 7. [Deque](libconts/deque/deque.h)
 - Deque operates bidirectionally, the deque (double-ended queue) operates similarly to both a stack and a queue, allowing insertion and deletion of elements from both ends of the structure. It supports operations like push/pop at both front and back ends efficiently. 
 8. [Set](libconts/set/set.h)
 - Unique elements, a set stores unique elements and supports operations like insertion, deletion, and membership testing efficiently.
 9. [BinaryTree](libconts/binary/tree.h)
 - Hierarchical data structure, a binary tree organizes data in nodes where each node has at most two children: a left child and a right child. Nodes are arranged such that elements smaller than the parent are to the left, and elements larger are to the right. This structure facilitates efficient searching, insertion, and deletion operations.
