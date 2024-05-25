#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
using namespace std;

struct node {
    string data;
    int weight_of_word;
    struct node* right;
    struct node* left;
};

int word_count = 0; // Global variable to keep track of the number of words

int calculate_word_weight(const string& word) {
    int weight = 0;
    for (char c : word) {
        weight += int(c) * int(c); // Add the ASCII value of each character
    }
    return weight;
}

struct node* node_creation(int w, string d) {
    struct node* temp = new node;
    temp->data = d;
    temp->weight_of_word = w;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* root, int key, string word) {
    if (root == NULL) {
        word_count++; // Increment word count when a new node is created
        return node_creation(key, word);
    }

    if (root->data == word) {
        cout << "Word \"" << word << "\" already exists in the dictionary." << endl;
        return root;
    }

    if (root->weight_of_word > key) {
        root->left = insert(root->left, key, word);
    } else {
        root->right = insert(root->right, key, word);
    }

    return root;
}

void inorder_traversal(struct node* root) {
    if (root == NULL) {
        return;
    } else {
        inorder_traversal(root->left);
        cout << root->data << " ";
        inorder_traversal(root->right);
    }
}

void spell_corrector(struct node* root, string str22) {
    if (root == NULL) {
        return;
    }

    string fin = root->data;
    int hit = 0;

    if (abs((int)fin.size() - (int)str22.size()) <= 2) {
        for (size_t o = 0; o < min(fin.size(), str22.size()); o++) {
            if (fin[o] == str22[o]) {
                hit++;
            }
        }
    }

    int hitrate = ((hit * 100) / str22.size());
    if (hitrate >= 50) {
        cout << fin << endl;
    }

    spell_corrector(root->left, str22);
    spell_corrector(root->right, str22);
}

void search(struct node* root, int ww, string str) {
    struct node* temp = root;
    bool found = false;

    while (root != NULL) {
        if (root->data == str) {
            found = true;
            break;
        } else if (root->weight_of_word < ww) {
            root = root->right;
        } else {
            root = root->left;
        }
    }

    if (found) {
        cout << str << " Found in Dictionary";
    } else {
        cout << str << " Not Found in Dictionary\n\nSuggested Words\n\n";
        spell_corrector(temp, str);
    }
}

int main() {
    struct node* root = NULL;
    int opt = 0;

    while (opt != 5) {
        cout << "\nMENU:\n";
        cout << "1) Insert from dictionary\n";
        cout << "2) Insert a word\n";
        cout << "3) Search a word\n";
        cout << "4) Show all words\n";
        cout << "5) Exit\n";
        cout << "Choose an option: ";
        cin >> opt;

        if (opt == 1) {
            ifstream file("dictionary.txt");
            if (!file.is_open()) {
                cout << "Error opening file!" << endl;
                return 1;
            }

            string word;
            while (file >> word) {
                int weight = calculate_word_weight(word);
                root = insert(root, weight, word);
            }
            file.close();
            cout << "Words inserted from dictionary. Total words: " << word_count << endl;
        } else if (opt == 2) {
            string new_word;
            cout << "Enter the word to insert: ";
            cin >> new_word;
            int weight = calculate_word_weight(new_word);
            root = insert(root, weight, new_word);

            // Add the word to the dictionary file
            ofstream dictFile("dictionary.txt", ios::app);
            if (dictFile.is_open()) {
                dictFile <<  "\n"<<new_word;  // Ensure each word is inserted on a new line
                dictFile.close();
                cout << "Word \"" << new_word << "\" inserted into the dictionary and BST." << endl;
                cout << "Total words: " << word_count << endl;
            } else {
                cout << "Error opening dictionary file for writing!" << endl;
            }
        } else if (opt == 3) {
            string search_word;
            cout << "Enter a word to search: ";
            cin >> search_word;
            int search_word_weight = calculate_word_weight(search_word);
            search(root, search_word_weight, search_word);
        } else if (opt == 4) {
            cout << "Inorder traversal of the BST: ";
            inorder_traversal(root);
            cout << endl;
            cout << "Total words: " << word_count << endl; // Display total word count
        } else if (opt == 5) {
            cout << "Exiting program...\n";
        } else {
            cout << "Invalid option! Please choose again.\n";
        }
    }

    return 0;
}

