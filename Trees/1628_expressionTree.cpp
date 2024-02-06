// https://leetcode.com/problems/design-an-expression-tree-with-evaluate-function/description/

/**
 * This is the interface for the expression tree Node.
 * You should not remove it, and you can define some classes to implement it.
 */

class Node {
public:
    virtual ~Node () {};
    virtual int evaluate() const = 0;
protected:
};

class ExpNode : public Node {
 public:
  ExpNode(const string& val, ExpNode* left, ExpNode* right)
      : val(val), left(left), right(right) {}

  int evaluate() const override {
    return left == nullptr && right == nullptr
               ? stoi(val)
               : op.at(val)(left->evaluate(), right->evaluate());
  }

 private:
  static const inline unordered_map<string, function<long(long, long)>> op{
      {"+", std::plus<long>()},
      {"-", std::minus<long>()},
      {"*", std::multiplies<long>()},
      {"/", std::divides<long>()}};
  const string val;
  const ExpNode* const left;
  const ExpNode* const right;
};

/**
 * This is the TreeBuilder class.
 * You can treat it as the driver code that takes the postinfix input 
 * and returns the expression tree represnting it as a Node.
 */

class TreeBuilder {
public:
    Node* buildTree(vector<string>& postfix) {
        stack<ExpNode*> nodes;

        for(int i = 0; i < postfix.size(); i++){
            string currChar = postfix[i];
            if (currChar != "+" && currChar != "-" && currChar != "*" && currChar != "/") {
                ExpNode* newNode = new ExpNode(currChar, NULL, NULL);
                nodes.push(newNode);
            } else {
                ExpNode* right = nodes.top();
                nodes.pop();
                ExpNode* left = nodes.top();
                nodes.pop();
                ExpNode* newNode = new ExpNode(currChar, left, right);
                nodes.push(newNode);
            }
        }

        return nodes.top();
    }
};
