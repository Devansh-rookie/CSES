#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set> // Using set for automatic sorting and uniqueness
#include <algorithm>

// Using namespace as shown in the provided images
using namespace std;

// This is the struct definition from your images.
// Note: The comments mention uppercase, but the problem examples use lowercase.
// The provided solution works correctly for either, as long as the input is consistent.
struct InputData {
    int rows;
    int cols;
    vector<vector<char>> board; // Uppercase characters A-Z
    int num_words;
    vector<string> words;       // Uppercase words
};

// This is the input reading function from your images.
InputData read_input() {
    InputData data;
    cin >> data.rows >> data.cols;
    data.board.assign(data.rows, vector<char>(data.cols));
    for (int i = 0; i < data.rows; ++i) {
        for (int j = 0; j < data.cols; ++j) {
            cin >> data.board[i][j];
        }
    }
    cin >> data.num_words;
    data.words.resize(data.num_words);
    for (int i = 0; i < data.num_words; ++i) cin >> data.words[i];
    return data;
}

// TrieNode structure to build the prefix tree
struct TrieNode {
    std::unordered_map<char, TrieNode*> children;
    std::string word = ""; // Stores the complete word if this node is an endpoint

    // Destructor to free memory
    ~TrieNode() {
        for (auto& pair : children) {
            delete pair.second;
        }
    }
};

// Depth-First Search function to explore the board
void dfs(int r, int c, const std::vector<std::vector<char>>& board, std::vector<std::vector<bool>>& visited, TrieNode* node, std::set<std::string>& found_words) {
    int rows = board.size();
    int cols = board[0].size();

    if (r < 0 || r >= rows || c < 0 || c >= cols || visited[r][c]) {
        return;
    }

    char ch = board[r][c];

    if (node->children.find(ch) == node->children.end()) {
        return;
    }

    node = node->children[ch];

    if (!node->word.empty()) {
        found_words.insert(node->word);
        node->word = "";
    }

    visited[r][c] = true;

    int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int i = 0; i < 8; ++i) {
        dfs(r + dr[i], c + dc[i], board, visited, node, found_words);
    }

    visited[r][c] = false;
}


// The solution is placed inside this function as required.
void solve_problem(const InputData& data) {
    TrieNode* root = new TrieNode();
    for (const std::string& w : data.words) {
        TrieNode* node = root;
        for (char ch : w) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->word = w;
    }

    std::set<std::string> found_words;
    int rows = data.rows;
    int cols = data.cols;

    if (rows == 0 || cols == 0) {
        std::cout << 0 << std::endl;
        delete root;
        return;
    }

    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            dfs(i, j, data.board, visited, root, found_words);
        }
    }

    if (found_words.empty()) {
        std::cout << 0 << std::endl;
    } else {
        std::cout << found_words.size() << std::endl;
        for (const std::string& word : found_words) {
            std::cout << word << std::endl;
        }
    }

    delete root;
}


// This is the main function from your images.
int main() {
    // Optional: Add for faster I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    InputData input_data = read_input();
    solve_problem(input_data);
    return 0;
}
