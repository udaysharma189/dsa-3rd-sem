
#include <iostream>
using namespace std;

struct Node {
    Node* children[26];
    bool end;
    
    Node() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        end = false;
    }
};

struct Trie {
    Node* root;

    Trie() {
        root = new Node();
    }

    // Insert word
    void insert(string word) {
        Node* temp = root;

        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';

            if (temp->children[index] == NULL) {
                temp->children[index] = new Node();
            }

            temp = temp->children[index];
        }

        temp->end = true;
    }

    // Search word
    bool search(string word) {
        Node* temp = root;

        for (int i = 0; i < word.length(); i++) {
            int index = word[i] - 'a';

            if (temp->children[index] == NULL) {
                return false;
            }

            temp = temp->children[index];
        }

        return temp->end;
    }
};

int main() {
    Trie t;

    t.insert("apple");
    t.insert("app");
    t.insert("bat");

    cout << t.search("apple") << endl;
    cout << t.search("app") << endl;
    cout << t.search("bat") << endl;
    cout << t.search("ball") << endl;

    return 0;
}
