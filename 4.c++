   #include <iostream>
   #include <sstream>
   #include <queue>
   using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
public:
    // Encodes a tree to a single string
    string serialize(TreeNode* root) {
        if (!root) return "null";

        stringstream ss;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                ss << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            } else {
                ss << "null ";
            }
        }

        return ss.str();
    }

    // Decodes your encoded data to tree
    TreeNode* deserialize(string data) {
        if (data == "null") return nullptr;

        stringstream ss(data);
        string str;
        ss >> str;

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (!(ss >> str)) break;
            if (str != "null") {
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }

            if (!(ss >> str)) break;
            if (str != "null") {
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }

        return root;
    }
};

// Helper function to print the tree (Level Order)
void printTree(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node) {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        } else {
            cout << "null ";
        }
    }
    cout << endl;
}

int main() {
    // Creating a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Codec ser, deser;
    string serializedTree = ser.serialize(root);
    cout << "Serialized Tree: " << serializedTree << endl;

    TreeNode* deserializedTree = deser.deserialize(serializedTree);
    cout << "Deserialized Tree: ";
    printTree(deserializedTree);

    return 0;
}
