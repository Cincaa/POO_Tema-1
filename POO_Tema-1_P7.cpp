#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Multimi
{
private:
    vector <int> V;

public:
    Multimi();
    Multimi(int v);
    void transformare();
    void show();
    vector <int> get_V()
    {
        return V;
    }
    Multimi operator +(Multimi B);
    Multimi operator *(Multimi B);
    Multimi operator -(Multimi B);
    friend ostream& operator << (ostream &output, const Multimi &obj);
    friend istream& operator >> (istream &input, Multimi &obj);
};

istream& operator >> (istream &input, Multimi &obj)
{
        int x;
        input>>x;
        obj.V.push_back(x);
    return input;
}
ostream &operator <<(ostream &output, const Multimi &obj)
{
    cout<<'{';
    for(int i=0;i<obj.V.size();i++)
        output<<obj.V[i]<<", ";
    output<<"\b\b}\n";
    return output;
}

Multimi::Multimi(int v)
    {
        V.clear();
        int x;
        for(int i=0;i<v;i++){
            cin>>x;
            V.push_back(x);
        }
    }
Multimi::Multimi()
    {
        (*this).V.clear();
    }
void Multimi::transformare()
{
    for(int i=0;i<V.size();i++)
        for(int j=i+1;j<V.size();j++)
            if(V[i]==V[j]){
                V.erase(V.begin()+j);
                j--;
            }
}

void Multimi::show()
{
    for(int i=0;i<this->V.size();i++)
        cout<<this->V[i]<<' ';
    cout<<'\n';
}

Multimi Multimi:: operator +(Multimi B)
{
    Multimi C;
    sort(V.begin(),V.end());
    sort(B.V.begin(),B.V.end());
    int i=0,j=0;
    while(i<V.size() && j<B.V.size())
        if(V[i]<B.V[j]){
            C.V.push_back(V[i]);
            i++;
        }
        else
            if(V[i]>B.V[j])
            {
                C.V.push_back(B.V[j]);
                j++;
            }
            else
            {
                C.V.push_back(B.V[j]);
                j++;i++;
            }
    while(i<V.size()){
         C.V.push_back(V[i]);
            i++;
    }
    while(j<B.V.size()){
        C.V.push_back(B.V[j]);
            j++;
    }
    return C;
}

Multimi Multimi:: operator *(Multimi B)
{
    Multimi C;
    sort(V.begin(),V.end());
    sort(B.V.begin(),B.V.end());
    for(int i=0;i<V.size();i++)
        for(int j=0;j<B.V.size();j++)
            if(V[i]==B.V[j])
                C.V.push_back(V[i]);
    return C;
}

Multimi Multimi:: operator -(Multimi B)
{
    Multimi C;
    sort(V.begin(),V.end());
    sort(B.V.begin(),B.V.end());
    for(int i=0;i<V.size();i++){
        int ok=0;
        for(int j=0;j<B.V.size();j++)
            if(V[i]==B.V[j])
                ok=1;
        if(ok==0)
            C.V.push_back(V[i]);
    }
    return C;
}

class Pereche
{
    int a,b;
public:
    void set_a(int q){a=q; }
    void set_b(int q){b=q; }
    friend class MultPereche;
    friend ostream& operator << (ostream &output, const Pereche &obj);
    friend istream& operator >> (istream &input, Pereche &obj);
};

ostream& operator << (ostream &output, const Pereche &obj)
{
    output<<'('<<obj.a<<','<<obj.b<<"), ";

    return output;
}

istream& operator >> (istream &input, Pereche &obj)
{
    input>>obj.a>>obj.b;

    return input;
}
class MultPereche
{
    vector <Pereche> V;
public:
    MultPereche produs(Multimi x, Multimi y);
    void show();
    friend ostream& operator << (ostream &output, const MultPereche &obj);
    friend istream& operator >> (istream &input, MultPereche &obj);
};

istream& operator >> (istream &input, MultPereche &obj)
{
    int m,n;
    Pereche x;
        input>>m>>n;
        x.set_a(m);
        x.set_b(n);
        obj.V.push_back(x);
    return input;
}
ostream& operator << (ostream &output, const MultPereche &obj)
{
    output<<'{';
    for(int i=0;i<obj.V.size();i++)
        output<<obj.V[i];
    output<<"\b\b}\n";

    return output;
}
MultPereche MultPereche:: produs(Multimi x, Multimi y)
{
    MultPereche C;
    Pereche c;
    for(int i=0;i<x.get_V().size();i++)
        for(int j=0;j<y.get_V().size();j++){
            c.a=x.get_V()[i];
            c.b=y.get_V()[j];
            C.V.push_back(c);
        }

    return C;
}

void MultPereche:: show()
{
    cout<<"\n{";
    for(int i=0;i<V.size();i++)
        cout<<'('<<V[i].a<<','<<V[i].b<<"), ";
    cout<<"\b\b}\n";
}
int main()
{

    cout<<"MENIU"<<endl;
    cout<<"1.Citire A\n";
    cout<<"2.Citire B\n";
    cout<<"3.Transformare A\n";
    cout<<"4.Transformare B\n";
    cout<<"5.A U B\n";
    cout<<"6.A intersectat B\n";
    cout<<"7.A - B\n";
    cout<<"8.Citire preche (a,b)\n";
    cout<<"9.Citire multimi de perchechi (a,b)\n";
    cout<<"10.Afisare multimea A\n";
    cout<<"11.Afisare multimea B\n";
    cout<<"12.Afisare pereche (a,b)\n";
    cout<<"13.Afisare multime de pechechi\n";
    cout<<"14.Produs cartezian AxB\n";
    cout<<"0.Exit\n";

    Multimi A;
    Multimi B;
    MultPereche M;
    MultPereche D;
    Pereche P;
    int n;
    int x=1;

    while(x)
    {
        cin>>x;
        switch(x)
        {
            case 1: cout<<"\nNr. de elemente din A este: "; cin>>n;  for(int i=1;i<=n;i++) cin>>A; break;
            case 2: cout<<"\nNr. de elemente din B este: "; cin>>n;  for(int i=1;i<=n;i++) cin>>B; break;
            case 3: A.transformare(); break;
            case 4: B.transformare(); break;
            case 5: cout<<A+B; break;
            case 6: cout<<A*B; break;
            case 7: cout<<A-B; break;
            case 8: cin>>P; break;
            case 9: cout<<"Nr de perechi este: "; cin>>n; for(int i=1;i<=n;i++) cin>>M; break;
            case 10: cout<<A; break;
            case 11: cout<<B; break;
            case 12: cout<<P<<"\b\b\n"; break;
            case 13: cout<<M; break;
            case 14: D=D.produs(A,B);cout<<D; break;
            case 0: x=0; break;
        }
        if(x)
            cout<<"Noua comanda este: ";
    }
    return 0;

}
