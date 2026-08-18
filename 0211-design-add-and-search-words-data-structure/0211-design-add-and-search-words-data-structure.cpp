class WordDictionary {
public:
    struct Node {
        Node* child[26];
        bool isEnd;

        Node() {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
        }
    };

    Node* root;

    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* curr = root;

        for (char c : word) {
            int index = c - 'a';

            if (curr->child[index] == nullptr)
                curr->child[index] = new Node();

            curr = curr->child[index];
        }

        curr->isEnd = true;
    }

    bool searchHelper(Node* curr, string& word, int pos) {
        if (pos == word.size())
            return curr->isEnd;

        char c = word[pos];

        // '.' can represent any character
        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (curr->child[i] != nullptr &&
                    searchHelper(curr->child[i], word, pos + 1)) {
                    return true;
                }
            }
            return false;
        }

        int index = c - 'a';

        if (curr->child[index] == nullptr)
            return false;

        return searchHelper(curr->child[index], word, pos + 1);
    }

    bool search(string word) {
        return searchHelper(root, word, 0);
    }
};