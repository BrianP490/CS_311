// =========================================================
//HW#: HW4 BST
//Your name: Brian Perez
//CS311
//Complier:  g++
//File type: header file binstree.h
//================================================================

// tree element type is int for now
typedef int elem_t;   // elem_t is hidden from the client

// definition of what a Vertex is - also hidden from the client
struct Vertex
{
  Vertex *Up;  // points to the parent node
  Vertex *Left;
  elem_t  Elem;
  Vertex *Right;
  int Height;  // for EC
  int Balance;  // for EC
};

// this is set up to be inherited by another class
class BST
{
    public:

    // constructor  initializes Root
    BST::BST();

    // destructor must completely destroy the tree
    BST::~BST();

    // PURPOSE: Does Post Order traversal of the tree and deletes each vertex
    // PARAM:   V is a pointer to the vertex to be deleted
    void BST::dtraverse(Vertex *V);  // recursive post order traversal


    // PURPOSE: Show vertices in IN order traversal from the Root
    void BST::Display();

    // PURPOSE: Does IN order traversal from V recursively
    // PARAM: V is te pointer to the vertex to visit right now
    // For non EC, the height and balance will always be 0 
    void BST::INorderTraversal(Vertex *V);

    // PURPOSE: Searches for an element in PRE-order traversal
    // This is the same as Depth First Traversal
    bool BST::Search(elem_t K);

    // PURPOSE: Does PRE order search from V recursively
    // PARAM: V is the pointer to the vertex to be visited now
    //        K is what we are looking for
    bool BST::PREorderSearch(Vertex *V, elem_t K);

    // ------ The following are for adding and deleting vertices -----


    // PURPOSE: Adds a vertex to the binary search tree for a new element 
    // PARAM: the new element E
    // ALGORITHM: We will do this iteratively (not recursively)
    // to demonstrate the algorithm that is in the notes
    //    - smaller than the current -> go to the left
    //    - bigger than the current  -> go to the right
    //    - cannot go any further    -> add it there
    void BST::InsertVertex(elem_t E);


    // PURPOSE: Deletes a vertex that has E as its element.
    // PARAM: element E to be removed
    // ALGORITHM: First we must find the vertex then call Remove 
    void BST::DeleteVertex(elem_t E);


    // PURPOSE: Removes vertex pointed to by V
    // PARAM: V and its parent  pointer P
    // Case 1: it is a leaf, delete it
    // Case 2: it has just one child, bypass it
    // Case 3: it has two children, replace it with the max of the left subtree
    void BST::remove(Vertex *V, Vertex *P);

    // PURPOSE: Finds the Maximum element in the left sub-tree of V
    // and also deletes that vertex
    elem_t BST::findMax(Vertex *V);
};
