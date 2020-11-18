# Cpp tricks inspired from Python
1. [Range fn in Cpp inspired from Python](http://shishtpal.blogspot.com/2015/01/range-function-in-c-inspired-from-python.html#:~:text=range()%20function%20in%20C%2B%2B%20%3A%20Inspired%20from%20Python,-%23%20What%20is%20range&text=%23%20A%20sequence%20of%20numbers%20from,\)%2C%20and%20optional%20step%20parameter.&text=%23%20You%20are%20not%20limited%20to,float%20(%20*%20)%20data%20type.)
# Complexity

## 1. Sorting Algo  
![](Quick_References/Sorting_Complexity.PNG)  

# Important Algorithms

## 1. String Matching
  
  #### A) KPM Algorithm
          -> Worst Case : O(N)
   [Youtube](https://www.youtube.com/watch?v=V5-7GzOfADQ)
   [GFG](https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/)

## 2. Tree
        -> If there are N nodes
             ==> N-1 edges only!
  #### A) Transveral
          1. LNR - Inorder
          2. NLR - Preorder == DFS
          3. LRN - Postorder
          4. Level Order Transversal == BFS
          
          ==> No need to use DFS or BFS here in tree!
   [Tree Transverals](https://www.geeksforgeeks.org/tree-traversals-inorder-preorder-and-postorder/)  
   [Level Order Transversal](https://www.geeksforgeeks.org/level-order-tree-traversal/)

## 3. Graph  [Code](https://github.com/AbhinavKoul/Coding_Questions_Solutions/blob/b91ac7d86a5f4872668b5f3b49d6eeb925c24b94/Implementations/Graphs/GRAPH(better%20implementation).cpp)
      
      -> Unweighted Graph -> Directly use the code given above
      -> Weighted Graph -> Can use a 
      
      1) Constructor     
      
      v<int> weights = {0,5,4,3,2,1};
      struct ListNode 
      {
         int val;
         ListNode *next;     
         ListNode(int x) : val(weights[x]), next(nullptr) {}

      };
      
      2) PAIR
  [Pair Usage](https://www.geeksforgeeks.org/graph-implementation-using-stl-for-competitive-programming-set-2-weighted-graph/)
  
  #### A) DFS  [Code](https://github.com/AbhinavKoul/Coding_Questions_Solutions/blob/b91ac7d86a5f4872668b5f3b49d6eeb925c24b94/Implementations/Graphs/GRAPH(better%20implementation).cpp#L47)
          -> Worst Case : O(|V|+|E|)  
          1. Connected graph  
          2. There is an edge case for unconnected graph ==> NEED TO run DFS from all unvisited nodes after a initial DFS. 
   1. [GFG](https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/)  
   
          -> APPLICATIONS
          1. For a weighted graph, DFS traversal of the graph produces the minimum spanning tree and all pair shortest path tree
          2. Detecting cycle in a graph
          3. Path Finding
          4. Topological Sorting
          5. test if a graph is bipartite
          6. Finding Strongly Connected Components
          7. Solving puzzles with only one solution
   2. [DFS-APPLICATIONS](https://www.geeksforgeeks.org/applications-of-depth-first-search/)  
   3. [Detect Cycles in Directed](https://www.geeksforgeeks.org/detect-cycle-in-a-graph/)
   4. [Detect Cycles in Undirected](https://www.geeksforgeeks.org/detect-cycle-undirected-graph/)
   5. [Strongly Connected Componants using DFS](https://www.geeksforgeeks.org/strongly-connected-components/)
   6. [BEST - CLSR - Strongly connected comp](https://www.personal.kent.edu/~rmuhamma/Algorithms/MyAlgorithms/GraphAlgor/strongComponent.htm)
     
   5. [QUESTIONS](https://www.geeksforgeeks.org/tag/dfs/)
    
  #### A) BFS
   [GFG]()
  #### A) DIJKSTRA STL
   [GFG- Priority Queue](https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-priority_queue-stl/)  
   [GFG-Sets](https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-using-set-in-stl/)  
  #### A) KRUSKAL STL
   [GFG](https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-using-stl-in-c/)  
  #### A) PRISM STL
   [GFG](https://www.geeksforgeeks.org/prims-algorithm-using-priority_queue-stl/)  
# Overloading Output,Input,Equal => LIST vs VECTOR vs Dqueue [link](http://www.yolinux.com/TUTORIALS/LinuxTutorialC++STL.html#LIST)
