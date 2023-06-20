#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

template <class G> class CNode {
public:
    typedef typename G::n N;
    typedef typename G::Edge Edge;

    N value;
    bool paso;
    vector<Edge*> edges;
    CNode(int v = 0, vector<Edge*> e = {}, bool p = 0) : value(v), edges(e), paso(p) {}
};

template <class G> class CEdge {
public:
    typedef typename G::e E;
    typedef typename G::Node Node;

    E value;
    Node* nodes[2];
    bool dir;
    CEdge(int v = 0, Node* a = nullptr, Node* b = nullptr, bool d = 0) {
        value = v;
        d = dir;
        nodes[0] = a;
        nodes[1] = b;
    }
};

template <class N, class E> class CGraph {
public:
    typedef N n;
    typedef E e;
    typedef CGraph<N, E> G;
    typedef CNode<G> Node;
    typedef CEdge<G> Edge;

    bool InsertNode(N v);
    bool InsertEdge(Node* a, Node* b, E e, bool dir);
    bool RemoveEdge(Node* a, Node* b, E e);
    bool RemoveNode(N v);

    vector<Node*> nodes = {};
};

template <class N, class E> bool CGraph<N, E>::InsertNode(N v) {
    Node* a = new Node(v);
    nodes.push_back(a);
    return 0;
}

template <class N, class E>
bool CGraph<N, E>::InsertEdge(Node* a, Node* b, E e, bool dir) {
    Edge* edge = new Edge(e, a, b, dir);
    a->edges.push_back(edge);
    return 0;
}

template <class N, class E>
bool CGraph<N, E>::RemoveEdge(Node* a, Node* b, E e) {
    return 0;
}

template <class N, class E> bool CGraph<N, E>::RemoveNode(N v) { return 0; }

struct Coord {
    float x, y;
};

class CCharGraph : public CGraph<char, int> {};

class CCoordGraph : public CGraph<Coord, int> {};

class CintGraph : public CGraph<int, int> {};

template<class C>
void Floyd(vector<vector<int>> &D, int n, C Grafo) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
          for(int k = 0; k < Grafo.nodes[i]->edges.size(); k++){
            if(Grafo.nodes[i]->edges[k]->nodes[1]->value == j){
              D[i][j] = Grafo.nodes[i]->edges[k]->value;
              break;
            }
            else{
              D[i][j] = INF;
            }
          }
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++) 
            {
                if (D[i][k] + D[k][j] < D[i][j]) 
                {
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }
}

int main() {
    CintGraph Grafo;
    int n = 5;
    Grafo.InsertNode(0);
    Grafo.InsertNode(1);
    Grafo.InsertNode(2);
    Grafo.InsertNode(3);
    Grafo.InsertNode(4);
    Grafo.InsertEdge(Grafo.nodes[0], Grafo.nodes[1], 2, 0);
    Grafo.InsertEdge(Grafo.nodes[0], Grafo.nodes[4], 4, 0);
    Grafo.InsertEdge(Grafo.nodes[1], Grafo.nodes[2], 3, 0);
    Grafo.InsertEdge(Grafo.nodes[2], Grafo.nodes[3], 5, 0);
    Grafo.InsertEdge(Grafo.nodes[2], Grafo.nodes[4], 1, 0);
    Grafo.InsertEdge(Grafo.nodes[3], Grafo.nodes[0], 8, 0);
    Grafo.InsertEdge(Grafo.nodes[4], Grafo.nodes[3], 7, 0);
    vector<vector<int>> D(n);
    for (int i = 0; i < n; i++) {
        D[i].resize(n);
    }
    Floyd<CintGraph>(D, n, Grafo);
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
        cout << D[i][j] << " ";
      }
      cout << endl;
    }
}
