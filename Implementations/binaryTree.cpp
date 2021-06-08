#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>

class Node
{
public:
    int data;
    Node *left, *right;
};

Node* createNode(int data)
{
    Node* new_node = new Node();
    new_node->data = data;
    new_node->left = new_node->right = NULL;
    return new_node;
}

void insert(Node *&root, int data)
{
    if(!root)
    {
        root = createNode(data);
        return;   
    }

    std::queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        Node *current = q.front();
        q.pop();

        if(!current->left)
        {
            current->left = createNode(data);
            return;
        } else q.push(current->left);

        if(!current->right)
        {
            current->right = createNode(data);
            return;
        } else q.push(current->right);
    }
}

void level_order(Node* root)
{
    if(!root) std::cout << "Tree is empty!";

    std::cout << "\nLevel Order Traversal:\n";
    std::queue <Node*> q;
    q.push(root);
    while(!q.empty())
    {
        Node* current = q.front();
        q.pop();
        if(current->left) q.push(current->left);
        if(current->right) q.push(current->right);
        std::cout << current->data << "\t";
    }
}

void reverse_level_order(Node* root)
{
    if(!root){
        std::cout << "\nTree is empty!\n";
        return;
    }

    std::cout << "\n\nReverse_Level order traversal:\n";
    std::stack <Node*> s;
    std::queue <Node*> q;
    q.push(root);
    while(!q.empty()){
        Node *curr = q.front();
        q.pop();
        s.push(curr);
        if(curr->right) q.push(curr->right);
        if(curr->left) q.push(curr->left);
    }

    while(!s.empty()){
        std::cout << s.top()->data << "\t";
        s.pop();
    }
}

void inOrder(Node *root) //left, root, right
{
    if(!root){
        std::cout << "\n\nTree is empty!\n";
        return;
    }

    std::cout << "\n\nIn Order Traversal:\n";
    std::stack <Node*> s;
    Node *curr = root; 
    while (!s.empty() || curr) {
        while(curr) {
            s.push(curr);
            curr = curr->left;
        }
        std::cout << s.top()->data << "\t";
        curr = s.top()->right;
        s.pop();
    }
}

void preOrder(Node *root) //root, left, right
{
    if(!root) std::cout << "\n\nTree is empty!\n";

    std::cout << "\n\nPre Order Traversal:\n";
    std::stack <Node*> s;
    s.push(root);
    while(!s.empty()) {
        Node *curr = s.top();
        s.pop();
        std::cout << curr->data << "\t";
        if(curr->right) s.push(curr->right);
        if(curr->left) s.push(curr->left);
    }
}

void postOrder(Node *root) //left, right, root -------- two stacks iterative method
{
    if(!root) std::cout << "Tree is empty!";

    std::cout << "\n\nPost Order Traversal:\n";
    std::stack <Node*> s1, s2;
    s1.push(root);
    while (!s1.empty()) {
        Node* current = s1.top();
        s1.pop();
        s2.push(current);
        if(current->left) s1.push(current->left);
        if(current->right) s1.push(current->right);
    }

    while (!s2.empty()) {
        std::cout << s2.top()->data << "\t";
        s2.pop();
    }
}

void deleteNode(Node *&root, int del_data)
{
    if(!root){
        std::cout << "\nTree is empty!";
        return;
    }
    if(root->data == del_data && !root->left && !root->right){
        delete(root);
        root = NULL;
        return;
    }
    Node *del_node = NULL, *parent = NULL, *current = root;
    std::queue<Node*> q;    
    q.push(root);
    while(!q.empty())
    {
        current = q.front();
        q.pop();

        if(current->data == del_data) del_node = current;      
        if(current->left){
            parent = current;
            q.push(current->left);
        }
        if(current->right){
            parent = current;
            q.push(current->right);   
        }
    }

    if(!del_node){
        std::cout << "\n\nDATA NOT FOUND!\n\n";
        return;
    }
    std::swap(current->data, del_node->data);
    delete(current);
    if(parent->right) parent->right = NULL;
    else parent->left = NULL;
    std::cout << "\n\n\' " << del_data <<  " \' was deleted.\n";
}

int search(Node *root, int key) //using preorder
{
    if(!root) return 0;
    if(root->data == key) return 1;

    int found = search(root->left, key); //left subtree check
    if(found) return 1;

    found = search(root->right, key); // right subtree check
    return found;
}

int height(Node *root)
{
    if (!root) return 0;  
    
    // compute the depth of each subtree
    int lDepth = height(root->left);  
    int rDepth = height(root->right);  
    
    // use the larger one  
    return std::max(lDepth, rDepth) + 1;
}

//Diameter (sometimes called width) - It is the number of nodes on the longest path between two end nodes.
int diameter(Node *root) //O(n^2) -> because for every node we are calculating height
{
    if(!root) return 0;
    return std::max(height(root->left) + height(root->right) + 1, 
                    std::max(diameter(root->left), diameter(root->right)));
}

int diameter2(Node* root, int &height) //O(n) - because height is calculated in the same recursion, hence less time than above function
{
    if(!root) return 0;

    int lh = 0, rh = 0;
    int lDiameter = diameter2(root->left, lh);
    int rDiameter = diameter2(root->right, rh);
    height = std::max(lh, rh) + 1;
    return std::max(lh+rh+1, std::max(lDiameter, rDiameter));
}

int diameter3_heightFunc(Node *root, int &ans)
{
    if (!root) return 0;  
    
    int lDepth = diameter3_heightFunc(root->left, ans);  
    int rDepth = diameter3_heightFunc(root->right, ans);  
    ans = std::max(ans, 1 + lDepth + rDepth); //just compare the ans with the path length of every node and update it
    return std::max(lDepth, rDepth) + 1;
}

int diameter3(Node *root) // O(3)
{
    if(!root) return 0;
    int ans = INT32_MIN;
    int height = diameter3_heightFunc(root, ans);
    return ans;
}

void createMirrorTree(Node *root1, Node *&root2)
{
    if(!root1) return;

    root2 = createNode(root1->data);
    createMirrorTree(root1->right, root2->left);
    createMirrorTree(root1->left, root2->right);
}

int maxValue(Node *root)
{
    if(!root) return INT32_MIN;
    return std::max(root->data, std::max(maxValue(root->left), maxValue(root->right)));
}

int minValue(Node *root)
{
    if(!root) return INT32_MAX;
    return std::min(root->data, std::min(minValue(root->left), minValue(root->right)));
}

/*
An empty tree is height-balanced. A non-empty binary tree T is balanced if:
1) Left subtree of T is balanced
2) Right subtree of T is balanced
3) The difference between heights of left subtree and right subtree is not more than 1.
*/
bool isBalanced(Node *root)
{
    if(!root) return true;

    int lHeight = height(root->left), rHeight = height(root->right);
    if(abs(lHeight - rHeight) <= 1 && isBalanced(root->left) 
        && isBalanced(root->right)) return true;
    return false;
}

void leafPaths_Util(Node *root, std::vector<int> v)
{
    if(!root) return;
    if(!root->right && !root->left){
        v.push_back(root->data);
        std::cout << "\n";
        for(int i=0; i<v.size(); i++) std::cout << v[i] << "\t";
        return;
    }
    v.push_back(root->data);
    leafPaths_Util(root->left, v);
    leafPaths_Util(root->right, v);
}

void leafPaths(Node *root)
{
    if(!root){
        std::cout << "\n\nTree is empty!";
        return;
    }
    std::vector<int> v;
    leafPaths_Util(root, v);
}

void leafPaths2_Util(Node *root, int path[], int pathLen) 
{ 
    if (!root) return; 
    path[pathLen++] = root->data;  
    if (!root->left && !root->right){
        std::cout << "\n";
        for(int i=0; i<pathLen; i++) std::cout << path[i] << "\t";
    } else { 
        leafPaths2_Util(root->left, path, pathLen); 
        leafPaths2_Util(root->right, path, pathLen); 
    }
}

void leafPaths2(Node *root)  
{ 
    if(!root){
        std::cout << "\n\nTree is empty!";
        return;
    }
    int path[1000]; 
    leafPaths2_Util(root, path, 0); 
} 

void spiralLevelOrder(Node *root)
{
    std::cout << "\n\nSpiral Level Order:\n";
    std::stack<Node*> s1;
    std::stack<Node*> s2;
    
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()) {
            std::cout << s1.top()->data << "\t";
            if(s1.top()->right) s2.push(s1.top()->right);
            if(s1.top()->left) s2.push(s1.top()->left);
            s1.pop();
        }
        
        while(!s2.empty()) {
            std::cout << s2.top()->data << "\t";
            if(s2.top()->left) s1.push(s2.top()->left);
            if(s2.top()->right) s1.push(s2.top()->right);
            s2.pop();
        }
    }
}

Node* treeFromString(std::string str)
{
    Node *root = createNode(str[0] - '0');
    std::stack<Node*> s;
    s.push(root);
    int i = 1;
    bool popped = false;

    while(!s.empty() && i < str.length()){
        //There is no need to put !s.empty() but just in case, if GOD's angry (-_-).
        if(str[i] == '('){                                     
            if(!popped){
                s.top()->left = createNode(str[++i] - '0');
                s.push(s.top()->left);
            } else {
                s.top()->right = createNode(str[++i] - '0');
                s.push(s.top()->right);
            }
            popped = false;
        } else if(str[i] == ')') {
            s.pop();
            popped = true;
        }
        i++;
    }
    s.pop(); //popping the root
    return root;
}

int main()
{
    Node* root = NULL;
    insert(root, 15); //root node is 15
    insert(root, 10); //added to left of 15
    insert(root, 20); //added to right of 15 
    insert(root, 25); //added to left of 10
    insert(root, 8); //added to right of 10
    insert(root, 12); //added to left of 20

    level_order(root); //15, 10, 20, 25, 8, 12
    deleteNode(root, 25); //'12' replaces '25'
    level_order(root); //15, 10, 20, 12, 8
    reverse_level_order(root); //12, 8, 10, 20, 15

    inOrder(root); //12, 10, 8, 15, 20
    preOrder(root); //15, 10, 12, 8, 20
    postOrder(root); //12, 8, 10, 20, 15
    spiralLevelOrder(root); //15, 10, 20, 8, 12

    std::cout << "\n\nHeight of the tree: " << height(root); //3
    std::cout << "\n\nDiameter of the tree [O(n^2)]: " << diameter(root); //4
    
    int height = 0;
    std::cout << "\n\nDiameter of the tree [O(n)]: " << diameter2(root, height); //4
    std::cout << "\n\nDiameter of the tree [O(n) Method2]: " << diameter3(root); //4
    std::cout << "\n\nSearched numbers found or not: " << search(root, 12) << ", " << search(root, 22); //1, 0
    std::cout << "\n\nIs balanced or not: " << isBalanced(root); //1
    std::cout << "\n\nMax value in the tree: " << maxValue(root); //20
    std::cout << "\n\nMin value in the tree: " << minValue(root); //8
    std::cout << "\n\nAll root-to-leaf paths: "; leafPaths(root);
    std::cout << "\n\nAll root-to-leaf paths [method 2]: "; leafPaths2(root);

    std::string str = "4(2(3)(1))(6(5))";
    std::cout << "\n\n-----Test Root Preorder-----";
    Node* test_root = treeFromString(str);
    preOrder(test_root); 

    Node *mirror_root = NULL;
    createMirrorTree(root, mirror_root);
    std::cout << "\n\n------Traversals for Mirror Tree------";
    level_order(mirror_root); //15, 20, 10, 8, 12
    inOrder(mirror_root); //20, 15, 8, 10, 12
    preOrder(mirror_root); //15, 20, 10, 8, 12
    postOrder(mirror_root); //20, 8, 12, 10, 15
    

    return 0;
}