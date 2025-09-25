#include <bits/stdc++.h>
using namespace std;

class Codec {
public:
  string serialize(TreeNode *root) {
    ostringstream out;
    serializeHelp(root, out);
    return out.str();
  }
  TreeNode *deserialize(string data) {
    istringstream in(data);
    return deserailizeHelp(in);
  }
  void serializeHelp(TreeNode *root, ostringstream &out) {
    if (root == nullptr) {
      out << "N ";
      return;
    }
    out << root->val << " ";
    serializeHelp(root->left, out);
    serializeHelp(root->right, out);
  }

  TreeNode *deserailizeHelp(istringstream &in) {
    string val;
    in >> val;
    if (val == "N")
      return nullptr;
    TreeNode *root = new TreeNode(stoi(val));
    root->left = deserailizeHelp(in);
    root->right = deserailizeHelp(in);
    return root;
  }
};
