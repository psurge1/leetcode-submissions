/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // level order traversal (BFS), 2 queues
        // add node to a queue
        // pop node, add all its children to another queue
        // set node's next to front of first queue
        // continue popping from first queue until its empty
        // populate first queue with second queue's nodes, clear second queue
        if (!root)
            return nullptr;
        
        deque<Node*> nodes;
        deque<Node*> children;

        nodes.push_back(root);
        Node* node;
        while (!nodes.empty()) {
            while (!nodes.empty()) {
                node = nodes.front();
                nodes.pop_front();
                if (node->left)
                    children.push_back(node->left);
                if (node->right)
                    children.push_back(node->right);
                if (!nodes.empty()) {
                    node->next = nodes.front();
                }
            }

            for (auto& child : children) {
                nodes.push_back(child);
            }
            children.clear();
        }
        return root;
    }
};
