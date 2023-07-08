#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define ll long long

vector<int> restar(vector<int> w, vector<int> x){
    int tamw = w.size(), tamx = x.size();
    int suma = 0;
    bool negativo = false;
    vector<int> resp;
    for(int i = 0; i < tamw; i++){
        suma += w[i] * pow(10,(tamw-(i+1)));
    }
    for(int i = 0; i < tamx; i++){
        suma -= x[i] * pow(10,(tamw-(i+1)));
    }
    while(suma != 0){
        int part = suma%10;
        suma /= 10;
        resp.insert(resp.begin(),part);
    }
    return resp;
}

ll sumar(int w, int x){
    return w+x;
}

ll Mult10(ll m, int n){
    ll multi = pow(10,n)*m;
    return multi;
}

ll MultBasica(vector<int> u, vector<int> v){
    ll num = 0;
    ll res= 0;
    int un = u.size(), vn = v.size();
    for(int i = 0; i < un; i++){
        num += u[i]*pow(10,(un-(i+1)));
    }
    for(int i = 0; i < vn; i++){
        res += num*pow(10,(vn-(i+1)))*v[i];
    }
    return res;
}

ll Mult(vector<int> u, vector<int> v, int n, int base){
    if(n == base){
        return MultBasica(u,v);
    }
    int m = n/2;
    ll m1,m2,m3;
    vector<int> w(u.begin(),u.begin()+m);
    vector<int> x(u.begin()+m,u.end());
    vector<int> y(v.begin(),v.begin()+m);
    vector<int> z(v.begin()+m,v.end());
    m1 = Mult(w,y,m,base);
    m2 = Mult(x,z,m,base);
    vector <int> mi =restar(w,x);
    vector<int> sus = restar(z,y);
    m3 = Mult(mi,sus,m,base);
    return sumar(sumar(Mult10(m1,n),Mult10(sumar(sumar(m1,m2),m3),m)),m2);
}

int main()
{
    vector<int> u = {1,2,3,4};
    vector<int> v = {1,5};
    int un = u.size();
    int vn = v.size();
    int n = min(un,vn);
    ll r = Mult(u,v,n,2);
    cout << r << endl;
    return 0;
}