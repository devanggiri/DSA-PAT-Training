/*take input in the form of level order traversal
input:
first line array size
array elements
output:
print the level order traversal of the tree
*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void levelOrder(Node *root)
{
    if (root == NULL)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *temp = q.front();
        cout << temp->data << " ";
        q.pop();
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }
}

Node *buildTree(int arr[], int n, int i)
{
    if (i >= n)
        return NULL;
    Node *root = newNode(arr[i]);
    root->left = buildTree(arr, n, 2 * i + 1);
    root->right = buildTree(arr, n, 2 * i + 2);
    return root;
}

int main()
{
    int n;
    cout<<"Enter size: ";
    cin >> n;
    int arr[n];
    cout<<"Elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    Node *root = buildTree(arr, n, 0);
    cout<<"Level order traversal of tree: ";
    levelOrder(root);
    return 0;
}

/*get right view of binary tree.
Input: [1,2,3,null,5,null,4]
Output: [1,3,4]
*/

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insertLevelOrder(const std::vector<int>& arr, int i) {
    TreeNode* root = nullptr;
    if (i < arr.size() && arr[i] != -1) {
        root = new TreeNode(arr[i]);
        root->left = insertLevelOrder(arr, 2 * i + 1);
        root->right = insertLevelOrder(arr, 2 * i + 2);
    }
    return root;
}

std::vector<int> rightView(TreeNode* root) {
    std::vector<int> result;
    if (!root) return result;
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; ++i) {
            TreeNode* node = q.front();
            q.pop();
            if (i == n - 1) {
                result.push_back(node->val); // last node at the current level
            }
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return result;
}

void printVector(const std::vector<int>& vec) {
    for (int val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

std::vector<int> getInput() {
    std::vector<int> input;
    std::string line;
    std::cout << "Enter the elements of the binary tree (enter -1 for null nodes): ";
    std::getline(std::cin, line);
    std::istringstream iss(line);
    int number;
    while (iss >> number) {
        input.push_back(number);
    }
    return input;
}

int main() {
    std::vector<int> input = getInput();
    TreeNode* root = insertLevelOrder(input, 0);
    std::vector<int> result = rightView(root);
    std::cout << "Right view of the binary tree: ";
    printVector(result);
    return 0;
}

/*count number of nodes present in binary tree*/

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insertLevelOrder(const std::vector<int>& arr, int i) {
    TreeNode* root = nullptr;
    if (i < arr.size() && arr[i] != -1) {
        root = new TreeNode(arr[i]);
        root->left = insertLevelOrder(arr, 2 * i + 1);
        root->right = insertLevelOrder(arr, 2 * i + 2);
    }
    return root;
}

int countNodes(TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

std::vector<int> getInput() {
    std::vector<int> input;
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    int number;
    while (iss >> number) {
        input.push_back(number);
    }
    return input;
}

int main() {
    std::vector<int> input = getInput();
    TreeNode* root = insertLevelOrder(input, 0);
    int result = countNodes(root);
    std::cout << result << std::endl;
    return 0;
}

/*print pre order traversal of tree*/

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insertLevelOrder(const std::vector<int>& arr, int i) {
    TreeNode* root = nullptr;
    if (i < arr.size() && arr[i] != -1) {
        root = new TreeNode(arr[i]);
        root->left = insertLevelOrder(arr, 2 * i + 1);
        root->right = insertLevelOrder(arr, 2 * i + 2);
    }
    return root;
}

void preOrder(TreeNode* root) {
    if (!root) return;
    std::cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

std::vector<int> getInput() {
    std::vector<int> input;
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    int number;
    while (iss >> number) {
        input.push_back(number);
    }
    return input;
}

int main() {
    std::vector<int> input = getInput();
    TreeNode* root = insertLevelOrder(input, 0);
    preOrder(root);
    return 0;
}

/*Given Binary tree Please find the diamater of that tree
Input 0
2 4 5 6 -1 -1 7 20 30 80 90 -1 -1 8 -1 -1 9 -1 -1 -1 -1 -1 -1
Sample Output 0
8
Sample Input 1
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 1
4
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(const std::vector<int>& values) {
    if (values.empty() || values[0] == -1) return nullptr;
    TreeNode* root = new TreeNode(values[0]);
    std::queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < values.size()) {
        TreeNode* current = q.front();
        q.pop();
        if (values[i] != -1) {
            current->left = new TreeNode(values[i]);
            q.push(current->left);
        }
        i++;
        if (i >= values.size()) break;
        if (values[i] != -1) {
            current->right = new TreeNode(values[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

int height(TreeNode* root, int &diameter) {
    if (root == nullptr) return 0;
    int leftHeight = height(root->left, diameter);
    int rightHeight = height(root->right, diameter);
    diameter = std::max(diameter, leftHeight + rightHeight);
    return 1 + std::max(leftHeight, rightHeight);
}

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    height(root, diameter);
    return diameter;
}

std::vector<int> getInput() {
    std::vector<int> input;
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    int number; 
    while (iss >> number) {
        input.push_back(number);
    }
    return input;
}

int main() {
    std::vector<int> input = getInput();
    TreeNode* root = buildTree(input);
    int diameter = diameterOfBinaryTree(root);
    std::cout << diameter << std::endl;
    return 0;
}
/*Given two positive integer arrays nums and numsDivide. You can delete any number of elements from num.
Return the minimum number of deletion such that smallest elements in nums divides all the elements of numsDivide. 
If this is not possible return -1.
Input:
5
2 3 2 4 3
5
9 6 9 3 15
Output:
2*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int gcdArray(const vector<int>& nums) {
    return accumulate(nums.begin(), nums.end(), nums[0], gcd);
}

int minDeletions(vector<int>& nums, const vector<int>& numsDivide) {
    int g = gcdArray(numsDivide);
    
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
        if (g % nums[i] == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int n, m;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    cin >> m;
    vector<int> numsDivide(m);
    for (int i = 0; i < m; ++i) {
        cin >> numsDivide[i];
    }
    int result = minDeletions(nums, numsDivide);
    cout << result << endl;
    return 0;
}

/*given a string containing digits from 2-9 inclusive, return all possible letter combinations that 
the number could represent. a mapping of digits to letter combination like a telephone is taken. 
1 does not map to anything.
2->abc
3->def
4->ghi
5->jkl
6->mno
7->pqrs
8->tuv
9->wxyz
input:
23
output:
ad ae af bd be bf cd ce cf*/

#include <iostream>
#include <vector>
#include<algorithm>
#include <string>
using namespace std;

vector<string> letterCombinations(string digits) {
    vector<string> result;
    if (digits.empty()) return result;
    vector<string> mapping = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    result.push_back("");
    for (char digit : digits) {
        vector<string> temp;
        for (char ch : mapping[digit - '2']) {
            for (string str : result) {
                temp.push_back(str + ch);
            }
        }
        result = temp;
    }
    
    sort(result.begin(),result.end());
    return result;
}

int main() {
    string digits;
    cin >> digits;
    vector<string> result = letterCombinations(digits);
    for (string str : result) {
        cout << str << " ";
    }
    cout << endl;
    return 0;
}

/*you get n letters in a string as input. you have to print n! lines showing a valid permutation 
of the input string and output should be sorted in lexicorgraphically order
Input:
bob
Output:
bbo
bbo
bob
bob
obb
obb*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void permute(string str, int l, int r, vector<string>& result) {
    if (l == r) {
        result.push_back(str);
    } else {
        for (int i = l; i <= r; ++i) {
            swap(str[l], str[i]);
            permute(str, l + 1, r, result);
            swap(str[l], str[i]);
        }
    }
}

vector<string> permutations(string str) {
    vector<string> result;
    permute(str, 0, str.size() - 1, result);
    sort(result.begin(), result.end());
    return result;
}

int main() {
    string str;
    cin >> str;
    vector<string> result = permutations(str);
    for (string str : result) {
        cout << str << endl;
    }
    return 0;
}

/*print distinct sorted permutations with duplicates allowed in input
Input:
BAC
Output:
ABC ACB BAC BCA CAB CBA
Input:
AAB
Output:
AAB ABA BAA*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void permute(string str, int l, int r, vector<string>& result) {
    if (l == r) {
        result.push_back(str);
    } else {
        for (int i = l; i <= r; ++i) {
            if (i != l && str[i] == str[l]) continue;
            swap(str[l], str[i]);
            permute(str, l + 1, r, result);
        }
    }
}

vector<string> permutations(string str) {
    vector<string> result;
    sort(str.begin(), str.end());
    permute(str, 0, str.size() - 1, result);
    return result;
}

int main() {
    string str;
    cin >> str;
    vector<string> result = permutations(str);
    for (string str : result) {
        cout << str << " ";
    }
    cout << endl;
    return 0;
}

/*take n as input showing size of matrix nxn. then take matrix input and convert it into a sudoku and print in output
input:
9
3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0 
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0
output:
3 1 6 5 7 8 4 9 2
5 2 9 1 3 4 7 6 8
4 8 7 6 2 9 5 3 1
2 6 3 4 1 5 9 8 7
9 7 4 8 6 3 1 2 5
8 5 1 7 9 2 6 4 3
1 3 8 9 4 7 2 5 6
6 9 2 3 5 1 8 7 4
7 4 5 2 8 6 3 1 9
hackerrank: sudoku solver*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int num) {
    for (int i = 0; i < 9; ++i) {
        if (board[row][i] == num) return false;
        if (board[i][col] == num) return false;
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num) return false;
    }
    return true;
}

bool solveSudoku(vector<vector<int>>& board) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] == 0) {
                for (int num = 1; num <= 9; ++num) {
                    if (isSafe(board, i, j, num)) {
                        board[i][j] = num;
                        if (solveSudoku(board)) return true;
                        board[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    vector<vector<int>> board(9, vector<int>(9));
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> board[i][j];
        }
    }
    solveSudoku(board);
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

/*find the length of the longest substring without repeating characters from a string*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.size();
    int result = 0;
    unordered_map<char, int> map;
    for (int i = 0, j = 0; j < n; ++j) {
        if (map.find(s[j]) != map.end()) {
            i = max(i, map[s[j]]);
        }
        result = max(result, j - i + 1);
        map[s[j]] = j + 1;
    }
    return result;
}

int main() {
    string s;
    cin >> s;
    int result = lengthOfLongestSubstring(s);
    cout << result << endl;
    return 0;
}