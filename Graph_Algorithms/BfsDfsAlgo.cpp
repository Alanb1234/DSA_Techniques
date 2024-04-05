#include <iostream>
#include <vector>
#include <queue>


/*
The Breadth-First Search (BFS) algorithm is a fundamental algorithm for traversing 
or searching tree or graph data structures. It explores the neighbor nodes at the 
present depth prior to moving on to the nodes at the next depth level.
*/

/*
You need two data structures: one to represent the graph and another to implement 
the queue mechanism that BFS relies on for traversing the graph level by level.
*/

struct TreeNode {
    char value;
    std::vector<TreeNode*> children;
    
    TreeNode(char val) : value(val) {}
    
    // Function to add a child node to this node
    void addChild(TreeNode* child) {
        children.push_back(child);
    }
};


// Function to print the tree using BFS
void printTreeBFS(TreeNode* root) {
    if (!root) return;

    std::queue<TreeNode*> queue;
    queue.push(root);

    while (!queue.empty()) {
        TreeNode* current = queue.front();
        queue.pop();

        std::cout << current->value << " ";

        for (TreeNode* child : current->children) {
            queue.push(child);
        }
    }
    std::cout << std::endl;
}

// Function to print the tree in a depth-first manner
void printTreeDFS(TreeNode* root) {
    if (!root) return;

    // Print the current node's value
    std::cout << root->value << " ";

    // Recursively print each of the child nodes
    for (TreeNode* child : root->children) {
        printTreeDFS(child);
    }
}


int main(){

    // Create nodes
    TreeNode* root = new TreeNode('A');
    TreeNode* child1 = new TreeNode('B');
    TreeNode* child2 = new TreeNode('C');
    TreeNode* child3 = new TreeNode('D');
    TreeNode* child4 = new TreeNode('E');
    TreeNode* child5 = new TreeNode('F');
    TreeNode* child6 = new TreeNode('G');
    TreeNode* child7 = new TreeNode('H');
    TreeNode* child8 = new TreeNode('I');
    TreeNode* child9 = new TreeNode('J');
    TreeNode* child10 = new TreeNode('K');
    TreeNode* child11 = new TreeNode('L');
    TreeNode* child12 = new TreeNode('M');

    // Manually construct the tree
    root->addChild(child1);
    root->addChild(child2);
    root->addChild(child3);
    root->addChild(child4);
    child1->addChild(child5);
    child5->addChild(child8);
    child8->addChild(child11);

    child1->addChild(child6);
    child6->addChild(child9);
    child9->addChild(child12);

    child3->addChild(child7);
    child7->addChild(child10);

    // Print the tree using BFS
    std::cout << "BFS Tree Traversal: ";
    printTreeBFS(root);

    // Print the tree using DFS
    std::cout << "DFS Tree Traversal: ";
    printTreeDFS(root);

    

    


    return 0;

}
