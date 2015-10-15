#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
    map<UndirectedGraphNode *, UndirectedGraphNode *> copyMap;
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) return NULL;
        return dfs(node);
    }

    UndirectedGraphNode* dfs(UndirectedGraphNode *node) {
        UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
        copyMap[node] = new_node;
        for (auto u : node->neighbors) {
            if (copyMap[u]) {
                new_node->neighbors.push_back(copyMap[u]);
            }
            else {
                new_node->neighbors.push_back(dfs(u));
            }
        }
        return new_node;
    }

    void printGraph(UndirectedGraphNode *node) {
        map<UndirectedGraphNode *, bool> visited;
        printHelper(visited, node);
        printf("\n");
    }

    void printHelper(map<UndirectedGraphNode *, bool> &visited, UndirectedGraphNode *node) {
        if (node == NULL) return;
        if (visited[node]) return;

        printf("%d", node->label);
        for (auto u : node->neighbors) {
            printf(",%d", u->label);
        }
        printf("#");
        visited[node] = true;

        for (auto u : node->neighbors) {
            printHelper(visited, u);
        }
    }
};

int main() {

    UndirectedGraphNode *zero = new UndirectedGraphNode(0);
    UndirectedGraphNode *one = new UndirectedGraphNode(1);
    UndirectedGraphNode *two = new UndirectedGraphNode(2);

    zero->neighbors = { one, two };
    one->neighbors = { two };
    two->neighbors = { two };

    Solution s;
    printf(" Graph: ");
    s.printGraph(zero);

    UndirectedGraphNode *cloned = s.cloneGraph(zero);

    printf("Cloend: ");
    s.printGraph(cloned);

    return 0;
}
