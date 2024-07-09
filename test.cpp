#include <iostream>

using namespace std;

#define MAX_VTXS 9
#define PUSH 1
#define POP 2

class Queue {
private:
    int front;
    int rear;
    int lastOp;
    int data[MAX_VTXS];
public:
    Queue() {
        front = 0;
        rear = 0;
        lastOp = 0;
    }
    ~Queue() {}
    int isEmpty() {
        if (front == rear && lastOp != PUSH) {
            return 1;
        } else return 0;
    }
    bool isFull() {
        if (front == rear && lastOp == PUSH) return 1;
        else return 0;
    }
    void enqueue(int i) {
        if (!isFull()) {
            rear = (rear + 1) % MAX_VTXS;
            this->data[rear] = i;
            lastOp = PUSH;
        }
    }
    int dequeue() {
        if (!isEmpty()) {
            lastOp = POP;
            front = (front + 1) % MAX_VTXS;
            return data[front];
        }
        return 0;
    }
    void printQ() {
        int numberOfQ;
        numberOfQ = rear > front ? rear - front : (rear + MAX_VTXS) - front;
        int index = front + 1;
        for (int i = 0; i < numberOfQ; i++) {
            cout << data[(index + i) % MAX_VTXS] << " ";
        }
        cout << endl;
    }
};

class Node {
protected:
    int id;
    Node* link;
public:
    Node(int i, Node* l = nullptr) {
        id = i;
        link = l;
    }
    ~Node() { if (link != nullptr) delete link; }
    int getId() { return id; }
    Node* getLink() { return link; }
    void setLink(Node* l) { link = l; }
};

class AdjListGraph {
protected:
    int size;
    char vertices[MAX_VTXS];
    Node* adj[MAX_VTXS];
    bool visited[MAX_VTXS];
public:
    AdjListGraph() { size = 0; }
    ~AdjListGraph() { reset(); }
    void reset() {
        for (int i = 0; i < size; i++) {
            if (adj[i] != nullptr) delete adj[i];
        }
    }
    void insertVertex(char val) {
        if (!isFull()) {
            vertices[size] = val;
            adj[size++] = nullptr;
        } else cout << "error, isFull" << endl;
    }
    char getVertex(int v) { return vertices[v]; }
    void insertEdge(int u, int v) {
        adj[u] = new Node(v, adj[u]);
        adj[v] = new Node(u, adj[v]);
    }
    Node* adjacent(int v) { return adj[v]; }
    bool isFull() { return size >= MAX_VTXS; }
    bool isEmpty() { return size == 0; }
    bool isLinked(int u, int v) {
        Node* temp = adj[u];
        while (temp != nullptr) {
            if (temp->getId() == v) {
                return true;
            }
            temp = temp->getLink();
        }
        return false;
    }
    void BFS(int v) {
        resetVisited();
        visited[v] = true;
        cout << getVertex(v) << " ";
        Queue q;
        q.enqueue(v);
        while (!q.isEmpty()) {
            int u = q.dequeue();
            Node* temp = adj[u];
            while (temp != nullptr) {
                int w = temp->getId();
                if (!visited[w]) {
                    visited[w] = true;
                    cout << getVertex(w) << " ";
                    q.enqueue(w);
                }
                temp = temp->getLink();
            }
        }
    }
    void resetVisited() {
        for (int i = 0; i < size; i++) {
            visited[i] = false;
        }
    }
};

int main() {
    AdjListGraph g;
    g.insertVertex('A');
    g.insertVertex('B');
    g.insertVertex('C');
    g.insertVertex('D');
    g.insertVertex('E');
    g.insertVertex('F');
    g.insertVertex('G');
    g.insertVertex('H');
    g.insertVertex('I');

    g.insertEdge(0, 1); // A-B
    g.insertEdge(0, 2); // A-C
    g.insertEdge(0, 3); // A-D
    g.insertEdge(1, 4); // B-E
    g.insertEdge(2, 5); // C-F
    g.insertEdge(3, 7); // D-H
    g.insertEdge(4, 5); // E-F 
    g.insertEdge(4, 6); // E-G
    g.insertEdge(5, 7); // F-H
    g.insertEdge(6, 8); // G-I
    g.insertEdge(7, 8); // H-I

    cout << "BFS: ";
    g.resetVisited();
    g.BFS(0);
    cout << endl;

    return 0;
}


/*


int main() {
    AdjListGraph g;
    g.insertVertex('A'); // 0
    g.insertVertex('B'); // 1
    g.insertVertex('C'); // 2
    g.insertVertex('D'); // 3
    g.insertVertex('E'); // 4
    g.insertVertex('F'); // 5
    g.insertVertex('G'); // 6
    g.insertVertex('H'); // 7
    g.insertVertex('I'); // 8

    g.insertEdge(0, 1); // A-B
    g.insertEdge(0, 2); // A-C
    g.insertEdge(0, 3); // A-D
    g.insertEdge(1, 4); // B-E
    g.insertEdge(2, 5); // C-F
    g.insertEdge(3, 7); // D-H
    g.insertEdge(4, 5); // E-F 
    g.insertEdge(4, 6); // E-G
    g.insertEdge(5, 7); // F-H
    g.insertEdge(6, 8); // G-I
    g.insertEdge(7, 8); // H-I

    cout << "BFS: ";
    g.BFS(0);
    cout << endl;

    return 0;
}


*/