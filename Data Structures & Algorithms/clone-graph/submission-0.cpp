class Solution {
public:
    unordered_map<Node*, Node*> visited;   
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;

        if(visited.count(node)) return visited[node];   

        Node* nn = new Node(node->val);
        visited[node] = nn;   

        for(Node* neigh : node->neighbors){
            nn->neighbors.push_back(cloneGraph(neigh));   
        }
        return nn;
    }
};