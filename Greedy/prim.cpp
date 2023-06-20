#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

template <class G> class CNode {
public:
  typedef typename G::n N;
  typedef typename G::Edge Edge;

  N value;
  bool paso;
  list<Edge *> edges;
  CNode(int v = 0, list<Edge *> e = {}, bool p = 0) : value(v), edges(e), paso(p) {}
};

template <class G> class CEdge {
public:
  typedef typename G::e E;
  typedef typename G::Node Node;

  E value;
  Node *nodes[2];
  bool dir;
  CEdge(int v = 0, Node *a = nullptr, Node *b = nullptr, bool d = 0) {
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
  bool InsertEdge(Node *a, Node *b, E e, bool dir);
  bool RemoveEdge(Node *a, Node *b, E e);
  bool RemoveNode(N v);

  vector<Node *> nodes = {};
};

template <class N, class E> bool CGraph<N, E>::InsertNode(N v) {
  Node *a = new Node(v);
  nodes.push_back(a);
  return 0;
}

template <class N, class E>
bool CGraph<N, E>::InsertEdge(Node *a, Node *b, E e, bool dir) {
  Edge *edge1 = new Edge(e, a, b, dir);
  Edge *edge2 = new Edge(e, b, a, dir);
  a->edges.push_back(edge1);
  b->edges.push_back(edge2);
  return 0;
}

template <class N, class E>
bool CGraph<N, E>::RemoveEdge(Node *a, Node *b, E e) {
  return 0;
}

template <class N, class E> bool CGraph<N, E>::RemoveNode(N v) { return 0; }

struct Coord {
  float x, y;
};

class CCharGraph : public CGraph<char, int> {};

class CCoordGraph : public CGraph<Coord, int> {};

class CintGraph : public CGraph<int, int> {};


template<class d>
void Prim(d C, vector<typename d::Edge *> &t){
  vector<typename d::Node *>  nodos = C.nodes;
  vector<typename d::Node *> U;
  U.push_back(*(C.nodes.begin()));
  while(U.size() != nodos.size()){
    typename d::Edge * menor_arista =  nullptr;
    vector<typename d::Edge *> aristas_m = {};
    for(auto it = U.begin(); it < U.end(); it++){
      vector<typename d::Edge *> temp((*it)->edges.begin(), (*it)->edges.end());
      sort(temp.begin(), temp.end(), [](typename d::Edge *a, typename d::Edge *b) {
        return a->value > b->value;
      });
      for (auto i = temp.begin(); i != temp.end(); i++) {
        if (!((*i)->nodes[1]->paso)) {
          aristas_m.push_back(*i);
          continue;
        }
      }
    }
    sort(aristas_m.begin(), aristas_m.end(), [](typename d::Edge *a, typename d::Edge *b) {
        return a->value > b->value;
      });
    for (auto i = aristas_m.begin(); i != aristas_m.end(); i++) {
        if (!((*i)->nodes[1]->paso)) {
          menor_arista = *i;
          continue;
        }
      }
    t.push_back(menor_arista);
    U.push_back((menor_arista)->nodes[1]);
    (menor_arista)->nodes[0]->paso = 1;
    (menor_arista)->nodes[1]->paso = 1;
  }
}

int main() {
  CintGraph C;
  C.InsertNode(1);
  C.InsertNode(2);
  C.InsertNode(3);
  C.InsertNode(4);
  C.InsertNode(5);
  C.InsertNode(6);
  C.InsertNode(7);
  C.InsertEdge(C.nodes[0], C.nodes[1], 11, 0);
  C.InsertEdge(C.nodes[0], C.nodes[2], 8, 0);
  C.InsertEdge(C.nodes[0], C.nodes[3], 40, 0);
  C.InsertEdge(C.nodes[1], C.nodes[4], 46, 0);
  C.InsertEdge(C.nodes[1], C.nodes[2], 3, 0);
  C.InsertEdge(C.nodes[2], C.nodes[3], 29, 0);
  C.InsertEdge(C.nodes[2], C.nodes[5], 31, 0);
  C.InsertEdge(C.nodes[4], C.nodes[5], 40, 0);
  C.InsertEdge(C.nodes[3], C.nodes[5], 17, 0);
  C.InsertEdge(C.nodes[4], C.nodes[6], 15, 0);
  C.InsertEdge(C.nodes[5], C.nodes[6], 53, 0);
  /*C.InsertNode(1);
  C.InsertNode(2);
  C.InsertNode(3);
  C.InsertNode(4);
  C.InsertNode(5);
  C.InsertNode(6);
  C.InsertNode(7);
  C.InsertEdge(C.nodes[0], C.nodes[1], 7, 0);
  C.InsertEdge(C.nodes[0], C.nodes[3], 5, 0);
  C.InsertEdge(C.nodes[1], C.nodes[2], 8, 0);
  C.InsertEdge(C.nodes[1], C.nodes[3], 9, 0);
  C.InsertEdge(C.nodes[3], C.nodes[4], 15, 0);
  C.InsertEdge(C.nodes[1], C.nodes[4], 7, 0);
  C.InsertEdge(C.nodes[2], C.nodes[4], 5, 0);
  C.InsertEdge(C.nodes[3], C.nodes[5], 6, 0);
  C.InsertEdge(C.nodes[5], C.nodes[4], 8, 0);
  C.InsertEdge(C.nodes[5], C.nodes[6], 11, 0);
  C.InsertEdge(C.nodes[4], C.nodes[6], 9, 0);*/
  vector<CintGraph::Edge *> T;
  Prim<CintGraph>(C, T);
  for(auto it = T.begin(); it < T.end();it++){
    cout << (*it)->nodes[0]->value << "->" << (*it)->nodes[1]->value << " = " << (*it)->value<< endl;
  }
}
