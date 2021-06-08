#include <iostream>
#include <queue>

class Node
{
public:
    int data;
    Node *right, *left;
};

void insert(Node *&root, int insert_data)
{
    if(root == NULL)
    {
        Node* new_node = new Node();
        new_node->data = insert_data;
        new_node->left = new_node->right = NULL;
        root = new_node;
        return;
    }
    else if(insert_data <= root->data) insert(root->left, insert_data);
    else insert(root->right, insert_data);
}

Node* find_min(Node* root)
{
    if(root == NULL) return NULL;
    else if(root->left == NULL) return root;
    return find_min(root->left);
}

Node* find_max(Node* root)
{
    if(root == NULL) return NULL;
    else if(root->right == NULL) return root;
    return find_max(root->right);
}

void delete_data(Node *&root, int value)
{
    if(value < root->data) delete_data(root->left, value);
    else if(value > root->data) delete_data(root->right, value);
    else //The data to be deleted is found
    {
        if(root->left == NULL && root->right == NULL) //0 child
        {
            delete root;
            root = NULL;
        }
        else if(root->left == NULL) //1 child
        {
            Node* temp = root;
            root = root->right;
            delete temp;   
        }
        else if(root->right == NULL) //1 child
        {
            Node* temp = root;
            root = root->left;
            delete temp;
        }
        else //2 children
        {
            Node* temp = find_min(root->right);
            root->data = temp->data;
            delete_data(root->right, temp->data);
        }
    }
}

Node* search(Node *root, int key)
{
    if(root == NULL) return NULL;
    else if(key == root->data) return root;
    else if(key > root->data) return search(root->right, key);
    else return search(root->left, key);
}

int maxValue(Node *root)
{
    if(root == NULL) return -1;
    else if(root->right == NULL) return root->data;
    return maxValue(root->right);
}

int minValue(Node *root)
{
    if(root == NULL) return -1;
    else if(root->left == NULL) return root->data;
    return minValue(root->left);
}

int height(Node* root)
{
    if(root == NULL) return 1; //because if there is only one node, then -1+1 == 0, i.e, height of the binary tree.
    return std::max(height(root->left), height(root->right)) + 1;
}

void level_order(Node* root) //breadth first traversal
{
    if(!root) std::cout << "\n\nTree is empty!\n";

    std::cout << "\n\nLevel Order Traversal:\n";
    std::queue <Node*> adr;
    adr.push(root);
    while(!adr.empty())
    {
        Node* current = adr.front();
        adr.pop();
        if(current->left != NULL) adr.push(current->left);
        if(current->right != NULL) adr.push(current->right);
        std::cout << current->data << " ";
    }
}

void in_order(Node* root) //left, root, right
{
    if(root == NULL) return;

    in_order(root->left);
    std::cout << root->data << " ";
    in_order(root->right);
}

void pre_order(Node* root) //root, left, right
{
    if(root == NULL) return;

    std::cout << root->data << " ";
    pre_order(root->left);
    pre_order(root->right);
}

void post_order(Node* root) //left, right, root
{
    if(root == NULL) return;

    post_order(root->left);
    post_order(root->right);
    std::cout << root->data << " ";
}

bool is_subtree_lesser(Node* root, int value)
{
    if(root == NULL) return true;

    if(root->data <= value &&
        is_subtree_lesser(root->left, value) &&
        is_subtree_lesser(root->right, value)
        ) return true;
    else return false;
}

bool is_subtree_greater(Node* root, int value)
{
    if(root == NULL) return true;

    if(root->data > value &&
        is_subtree_greater(root->left, value) &&
        is_subtree_greater(root->right, value)
        ) return true;
    else return false;
}

bool isBST(Node* root) //O(n^2), n->no.of nodes
{
    if(root == NULL) return true;
    if(is_subtree_lesser(root->left, root->data) &&
        is_subtree_greater(root->right, root->data) &&
        isBST(root->left) &&
        isBST(root->right)
    ) return true;
    else return false;
}

bool isBST2(Node* root, int min_value, int max_value) //O(n)
{
    if(root == NULL) return true;
    if(root->data > min_value &&
        root->data < max_value &&
        isBST2(root->left, min_value, root->data) &&
        isBST2(root->right, root->data, max_value)
    ) return true;
    else return false;
}

bool isBST3(Node *root) //O(n)
{
    if(!root) return true;
    
    if((root->left && root->data < root->left->data) ||
        (root->right && root->data >= root->right->data)
    ) return false;
    if(isBST3(root->left) && isBST3(root->right)) return true;
    return false;
}

Node* inorderSuccessor(Node* root, int value)
{
    Node* current = search(root, value);
    if(current == NULL) return NULL;
    //If right subtree is present
    if(current->right != NULL) return find_min(current->right);
    //If right subtree not present
    else
    {
        Node* successor = NULL;
        Node* ancestor = root;
        while(ancestor != current)
        {
            if(current->data < ancestor->data)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else ancestor = ancestor->right;
        }
        return successor;
    }
}

void inorderPredecessor_Util(Node* root, int key, Node *&pred)
{
    if(!root) return;

    //If left subtree is present
    if(root->data == key && root->left){
        pred = find_max(root->left);
        return;
    }
    if(key > root->data){
        pred = root;
        inorderPredecessor_Util(root->right, key, pred);
    } else inorderPredecessor_Util(root->left, key, pred);
    /*
    For finding successor along with predecessor -
    1. pass an extra parameter 'Node *succ'
    2. add an extra if condition after checking left subtree. This'll check for
    right subtree's presence.
        if(root->data == key && root->right) {
            succ = find_min(root->right);
            return;
        }
    3. Change the else condition to -
        else {
            succ = root;
            inorderPredecessor_Util(root->left, key, pred, succ)
        }
    */
}

Node* inorderPredecessor(Node *root, int key)
{
    if(!root) return NULL;

    Node *pred = NULL;
    inorderPredecessor_Util(root, key, pred);
    return pred;
}

int main()
{
    Node *root = NULL;

    insert(root, 15); //here, root becomes the address of the node whose data is 15
    insert(root, 10); //added to left of 15
    insert(root, 20); //added to right of 15 
    insert(root, 25); //added to right of 20
    insert(root, 8); //added to left of 10
    insert(root, 12); //added to right of 10

    std::cout << search(root, 8) << std::endl; //address of 8
    std::cout << search(root, 12) << std::endl; //address of 12
    std::cout << search(root, 188) << std::endl; //0 ---> number not found

    std::cout << minValue(root) << std::endl; //8
    std::cout << maxValue(root) << std::endl; //25

    std::cout << height(root) << std::endl; //2

    level_order(root); //15 10 20 8 12 25
    std::cout << "\n\nPre Order Traversal:\n"; pre_order(root); //15 10 8 12 20 25
    std::cout << "\n\nIn Order Traversal:\n"; in_order(root); //8 10 12 15 20 25
    std::cout << "\n\nPost Order Traversal:\n"; post_order(root); //8 12 10 25 20 15

    std::cout << "\n\n" <<  isBST(root) << std::endl; //1...O(n^2) --- n->no.of nodes

    delete_data(root, 15); //15 got deleted from the tree
    std::cout << "\n15 got deleted. Remaining numbers are: ";
    in_order(root); //8 10 12 20 25 
    printf("\n"); 

    std::cout << isBST(root) << std::endl; //1...O(n^2), where n->no.of nodes
    std::cout << isBST2(root, INT32_MIN, INT32_MAX); //1...O(n)
    std::cout << "\nIS BST: " << isBST3(root); //1...O(n^2), where n->no.of nodes

    std::cout << "\nInorder successor of 12: "<< inorderSuccessor(root, 12)->data;//20
    std::cout << "\nInorder predecessor of 12: " << inorderPredecessor(root, 12)->data; //10

    return 0;
}