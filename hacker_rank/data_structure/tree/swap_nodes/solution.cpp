#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
    public:
    Node* left;
    Node* right;
    int data;

    Node(int d) {
        data=d;
        left=NULL;
        right=NULL;
    }
};

void saveNode(Node* root, vector<int>& v) {
    if(root->left != NULL)
        saveNode(root->left, v);
    v.push_back(root->data);
    if(root->right != NULL)
        saveNode(root->right, v);
}

void printNode(Node* root) {
    if(root->left != NULL)
        printNode(root->left);
    cout<<root->data<<" ";
    if(root->right != NULL)
        printNode(root->right);
}

 void swapNode(Node*& root, int k, int c) {
    if(c%k==0){
        Node* temp = root->left;
        root->left=root->right;
        root->right=temp;
    }
    
    if(root->left != NULL)
        swapNode(root->left, k, c+1);
    if(root->right != NULL)
        swapNode(root->right, k, c+1);
}

vector<vector<int>> solve(vector<vector<int>> indexes, vector<int> queries) {
    int in=indexes.size();
    int qn=queries.size();
    vector<vector<int>> ans(qn);
    queue<Node*> q;
    Node* root=(Node*)new Node(1);
    q.push(root);

    for(int i=0; i<in; ++i) {
        Node* curr=q.front(); q.pop();
        if(indexes[i][0]==-1) {
            curr->left = NULL;
        } else {
            // create new node with indexes[i][0]
            Node* n=new Node(indexes[i][0]);
            // add to left of curr node
            curr->left=n;
            // push curr->left to queue
            q.push(n);
        }
        if(indexes[i][1]==-1) {
            curr->right=NULL;
        } else {
            // create new node with indexes[i][1]
            Node* n=new Node(indexes[i][1]);
            // add to right of curr node
            curr->right=n;
            // push curr->right to queue
            q.push(n);
        }
    }

    for(int i=0; i<qn; ++i){
        swapNode(root, queries[i], 1);
        saveNode(root, ans[i]);
    }

    return ans;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, qn;
    cin>>n;

    vector<vector<int>> idx(n);
    for(int i=0; i<n; ++i){
        idx[i].resize(2);
        cin>>idx[i][0]>>idx[i][1];
    }

    cin>>qn;
    vector<int> q(qn);
    for(int i=0; i<qn; ++i)
        cin>>q[i];

    vector<vector<int>> ans=solve(idx, q);
    for(auto es: ans) {
        for(int e: es)
            cout<<e<<" ";
        cout<<endl<<endl;
    }

    return 0;
}
