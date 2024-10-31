#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Comparator for priority queue (min-heap)
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Function to build the Huffman tree
Node* buildHuffmanTree(const std::unordered_map<char, int>& freq) {
    std::priority_queue<Node*, std::vector<Node*>, Compare> pq;
    for (const auto& p : freq) {
        pq.push(new Node(p.first, p.second));
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* newNode = new Node('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }

    return pq.top();
}

// Function to generate Huffman codes from the Huffman tree
void generateHuffmanCodes(Node* root, const std::string& str, std::unordered_map<char, std::string>& huffmanCode) {
    if (!root) return;

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    generateHuffmanCodes(root->left, str + "0", huffmanCode);
    generateHuffmanCodes(root->right, str + "1", huffmanCode);
}

// Function to deallocate memory
void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int shkwjks() {
    std::string text = "Raja";
    std::unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    Node* root = buildHuffmanTree(freq);
    std::unordered_map<char, std::string> huffmanCode;
    generateHuffmanCodes(root, "", huffmanCode);

    std::cout << "Huffman Codes:\n";
    for (const auto& p : huffmanCode) {
        std::cout << p.first << ": " << p.second << "\n";
    }

    std::cout << "\nOriginal text: " << text << "\n";
    std::cout << "Encoded text: ";
    for (char ch : text) {
        std::cout << huffmanCode[ch];
    }
    std::cout << std::endl;

    deleteTree(root); // Clean up memory
    return 0;
}


