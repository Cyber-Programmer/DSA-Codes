#include <iostream>

using namespace std;

// Structure to represent a node in the linked list
struct Node {
    int vertex;
    Node* next;
};

// Function to create a new node in the linked list
Node* newNode(int vertex) {
    Node* temp = new Node;
    temp->vertex = vertex;
    temp->next = nullptr;
    return temp;
}

// Function to add an edge to the adjacency list represented by a linked list
void addEdge(Node* adjList[], int source, int destination) {
    Node* newnode = newNode(destination);
    newnode->next = adjList[source]; // Add the new node to the head of the list for source vertex
    adjList[source] = newnode;
}

// Function to perform DFS traversal of a graph
void DFS(Node* adjList[], int startVertex, bool visited[]) {
    visited[startVertex] = true;
    cout << startVertex << " ";

    // Recur for all the adjacent vertices of the current vertex
    for (Node* neighbor = adjList[startVertex]; neighbor != nullptr; neighbor = neighbor->next) {
        if (!visited[neighbor->vertex]) {
            DFS(adjList, neighbor->vertex, visited);
        }
    }
}

// Function to display the menu
void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Add an edge\n";
    cout << "2. Perform DFS traversal\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    // Create an array of pointers to Node to represent adjacency list
    Node* adjList[numVertices];
    for (int i = 0; i < numVertices; ++i) {
        adjList[i] = nullptr;
    }

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                int source, destination;
                cout << "Enter the source vertex: ";
                cin >> source;
                cout << "Enter the destination vertex: ";
                cin >> destination;
                addEdge(adjList, source, destination);
                cout << "Edge added from " << source << " to " << destination << ".\n";
                break;
            }
            case 2: {
                int startVertex;
                cout << "Enter the starting vertex for DFS traversal: ";
                cin >> startVertex;

                // Create a visited array to keep track of visited vertices
                bool visited[numVertices];
                for (int i = 0; i < numVertices; ++i) {
                    visited[i] = false;
                }

                cout << "DFS Traversal (starting from vertex " << startVertex << "): ";
                DFS(adjList, startVertex, visited);
                cout << endl;
                break;
            }
            case 3: {
                cout << "Exiting...\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    } while (choice != 3);

    // Clean up dynamically allocated memory
    for (int i = 0; i < numVertices; ++i) {
        Node* current = adjList[i];
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    return 0;
}

