#include <algorithm>
#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

template <class G> class CNode {
public:
  typedef typename G::n N;
  typedef typename G::Edge Edge;
  typedef typename G::Node Node;

  N value;
  bool paso;
  vector<Edge *> edges;
  Node *parent;
  CNode(int v = 0, vector<Edge *> e = {}, bool p = 0)
      : value(v), edges(e), paso(p) {}
};

template <class G> class CEdge {
public:
  typedef typename G::e E;
  typedef typename G::Node Node;

  E value;
  Node *nodes[2];
  bool dir;
  bool a_pase;
  CEdge(int v = 0, Node *a = nullptr, Node *b = nullptr, bool d = 0,
        bool ap = 0) {
    value = v;
    dir = d;
    a_pase = ap;
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
  bool Ciclo(Edge *A);

  vector<Node *> nodes = {};
  vector<Edge *> aristas = {};
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
  aristas.push_back(edge1);
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

template <class N, class E>
bool CGraph<N, E>::Ciclo(Edge *A) {
  deque<Edge *> verificador;
  verificador.push_back(A);
  while(!verificador.empty()){
    for(auto it = (*verificador.begin())->nodes[1]->edges.begin(); it < (*verificador.begin())->nodes[1]->edges.end();it++){
      if((*it)->nodes[1]->value == (*verificador.begin())->nodes[0]->value){
        continue;
      }
      if((*it)->nodes[1]->value == A->nodes[0]->value && (*it)->a_pase){
        return 1;
      }
      if((*it)->a_pase){
        verificador.push_back((*it));
      }
    }
    verificador.pop_front();
  }
  return 0;
}


template <class d> void kruskal(d C, vector<typename d::Edge *> &t) {
  vector<typename d::Edge *> A = C.aristas;
  sort(A.begin(), A.end(), [](typename d::Edge *p1, typename d::Edge *p2) {
    if (p1->value == p2->value) {
      return p1->nodes[0]->value < p2->nodes[0]->value;
    }
    return p1->value < p2->value;
  });
  for (auto it = A.begin(); it != A.end(); it++) {
    bool p = C.Ciclo((*it));
    if (!p) {
      t.push_back(*it);
      (*it)->a_pase = 1;
      for(auto i = (*it)->nodes[1]->edges.begin(); i < (*it)->nodes[1]->edges.end(); i++){
        if((*i)->nodes[1]->value == (*it)->nodes[0]->value){
          (*i)->a_pase = 1;
        }
      }
    }
  }
}

int main() {
  CintGraph C;
  /*C.InsertNode(1);
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
  C.InsertEdge(C.nodes[5], C.nodes[6], 53, 0);*/
  C.InsertNode(1);
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
  C.InsertEdge(C.nodes[4], C.nodes[6], 9, 0);
  vector<CintGraph::Edge *> T;
  kruskal<CintGraph>(C, T);
  cout << "Resultados: " << endl;
  for (auto it = T.begin(); it < T.end(); it++) {
    cout << (*it)->nodes[0]->value << "->" << (*it)->nodes[1]->value << " = "
         << (*it)->value << endl;
  }
}
