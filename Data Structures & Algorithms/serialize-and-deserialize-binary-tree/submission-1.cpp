class Codec {
public:

    // Serialize
    string serialize(TreeNode* root) {
        string result;
        serializeHelper(root, result);
        return result;
    }

    void serializeHelper(TreeNode* root, string& result) {
        if (root == nullptr) {
            result += "#,";
            return;
        }

        result += to_string(root->val) + ",";

        serializeHelper(root->left, result);
        serializeHelper(root->right, result);
    }

    // Deserialize
    TreeNode* deserialize(string data) {
        int index = 0;
        return deserializeHelper(data, index);
    }

    TreeNode* deserializeHelper(string& data, int& index) {

        // Find next comma
        int comma = data.find(',', index);

        string value = data.substr(index, comma - index);
        index = comma + 1;

        if (value == "#") {
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(value));

        root->left = deserializeHelper(data, index);
        root->right = deserializeHelper(data, index);

        return root;
    }
};
