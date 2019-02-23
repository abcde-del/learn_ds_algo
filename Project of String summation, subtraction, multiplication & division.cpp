#include<bits/stdc++.h>
using namespace std;
vector<int>k;
long long int remaind = 0;
string sum(string a, string b)
{
    k.clear();
    string s;
    int c, d, e, l1, l2;
    l1=a.size();
    l2=b.size();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if(l1>=l2){
        int  c=0;
        for(int i=0; i<l1; i++){
            if(i>l2-1){
                d=a[i]-'0' + c;
                c=d/10;
                e=d%10;
                k.push_back(e);
            }
            else{
                d=a[i]-'0' + b[i]-'0'+c;
                c=d/10;
                e=d%10;
                k.push_back(e);
            }
        }
        if(c>0){
            k.push_back(c);
        }
        reverse(k.begin(), k.end());
        stringstream ss;
        copy(k.begin(), k.end(), ostream_iterator<int>(ss));
        s = ss.str();
        return s;
    }

    else{
        int  c=0;
        for(int i=0; i<l2; i++){
            if(i>l1-1){
                d=b[i]-'0' + c;
                c=d/10;
                e=d%10;
                k.push_back(e);
            }
            else{
                d=b[i]-'0' + a[i]-'0'+c;
                c=d/10;
                e=d%10;
                k.push_back(e);
            }
        }
        if(c>0){
            k.push_back(c);
        }
        reverse(k.begin(), k.end());
        stringstream ss;
        copy(k.begin(), k.end(), ostream_iterator<int>(ss));
        s = ss.str();
        return s;
    }

}

int big(string a, string b){
    int l1, l2;
    l1=a.size();
    l2=b.size();
    int c=0;
    for(int i=0; i<l1; i++){
        if((a[i]-'0')>(b[i]-'0')){
            return 1;
            c=1;
            break;
        }
        else if((a[i]-'0')<(b[i]-'0')){
            return 0;
            c=1;
            break;
        }
    }
    if(c==0){
        return 1;
    }
}

string subs(string a, string b)
{
    string s;
    int l1, l2;
    l1=a.size();
    l2=b.size();
    k.clear();
    int c=0, d, e, t=big(a, b);
    if(l1>l2){
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for(int i=0; i<l1; i++){
            if(i>l2-1){
                if((a[i]-'0') - c < 0){
                    e=(a[i]-'0')+10-c;
                    c=1;
                    k.push_back(e);
                }
                else{
                    e=(a[i]-'0') -c;
                    c=0;
                    k.push_back(e);
                }
            }
            else{
                if((a[i]-'0') - c <(b[i]-'0')){
                    d=(a[i]-'0')+10-c;
                    c=1;
                    e=d - (b[i]-'0');
                    k.push_back(e);
                }
                else{
                    e=(a[i]-'0') - c - (b[i]-'0');
                    k.push_back(e);
                    c=0;
                }
            }
        }
        reverse(k.begin(), k.end());
        stringstream ss;
        copy(k.begin(), k.end(), ostream_iterator<int>(ss));
        s = ss.str();
        return s;
    }

    else if((l1==l2) && t){
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for(int i=0; i<l1; i++){
                if((a[i]-'0') - c < (b[i]-'0')){
                    d=(a[i]-'0')+10-c;
                    c=1;
                    e=d - (b[i]-'0');
                    k.push_back(e);
                }
                else{
                    e=(a[i]-'0') - c - (b[i]-'0');
                    k.push_back(e);
                    c=0;
                }
        }
        reverse(k.begin(), k.end());
        stringstream ss;
        copy(k.begin(), k.end(), ostream_iterator<int>(ss));
        s = ss.str();
        return s;
    }

    else if(l1==l2){
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for(int i=0; i<l1; i++){
                if((b[i]-'0') - c < (a[i]-'0')){
                    d=(b[i]-'0')+10-c;
                    c=1;
                    e=d - (a[i]-'0');
                    k.push_back(e);
                }
                else{
                    e=(b[i]-'0') - c - (a[i]-'0');
                    k.push_back(e);
                    c=0;
                }
        }
        cout<<'-';
        reverse(k.begin(), k.end());
        stringstream ss;
        copy(k.begin(), k.end(), ostream_iterator<int>(ss));
        s = ss.str();
        return s;
    }

    else{
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for(int i=0; i<l2; i++){
            if(i>l1-1){
                if((b[i]-'0') - c < 0){
                    e=(b[i]-'0')+10-c;
                    c=1;
                    k.push_back(e);
                }
                else{
                    e=(b[i]-'0') -c;
                    c=0;
                    k.push_back(e);
                }
            }
            else{
                if((b[i]-'0') - c <(a[i]-'0')){
                    d=(b[i]-'0')+10-c;
                    c=1;
                    e=d - (a[i]-'0');
                    k.push_back(e);
                }
                else{
                    e=(b[i]-'0') - c - (a[i]-'0');
                    k.push_back(e);
                    c=0;
                }
            }
        }
        cout<<'-';
        reverse(k.begin(), k.end());
        stringstream ss;
        copy(k.begin(), k.end(), ostream_iterator<int>(ss));
        s = ss.str();
        return s;
    }
}

string multi(string a, string b)
{
    int e, f, g, c, l1, l2;
    l1=a.size();
    l2=b.size();
    vector<int>m;
    string s;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    if(l1>=l2){
        string n = "0";
        for(int i=0; i<l2; i++){
            c=0;
            m.clear();
            for(int j=0; j<l1; j++){
                f=((b[i]-'0')*(a[j]-'0'))+c;
                e=f%10;
                c=e/10;
                m.push_back(e);
            }
            if(c!=0) m.push_back(c);
            reverse(m.begin(), m.end());
            if(i>0){
                for(int l=1; l<=i; l++) m.push_back(0);
            }
            stringstream ss;
            copy(m.begin(), m.end(), ostream_iterator<int>(ss));
            s = ss.str();
            //cout<<s<<endl;
            s = sum(s, n);
            n = s;
        }
        return s;
    }
    else{
        string n = "0";
        for(int i=0; i<l1; i++){
            c=0;
            m.clear();
            for(int j=0; j<l2; j++){
                f=((a[i]-'0')*(b[j]-'0'))+c;
                e=f%10;
                c=e/10;
                m.push_back(e);
            }
            if(c!=0) m.push_back(c);
            reverse(m.begin(), m.end());
            if(i>0){
                for(int l=1; l<=i; l++) m.push_back(0);
            }
            stringstream ss;
            copy(m.begin(), m.end(), ostream_iterator<int>(ss));
            s = ss.str();
            //cout<<s<<endl;
            s = sum(s, n);
            n = s;
        }
        return s;
    }
}

string divis(string a, long long int b)
{
    int l1 = a.size();
    string s;
        long long int indx = 0, d=a[indx]-'0', e, c=0;
        while(d<b){
            d=d*10 + a[++indx]-'0';
            remaind = d%b;
        }
        while(l1>indx){
            c = 1;
            e = d/b;
            k.push_back(e);
            remaind = d%b;
            d=(d%b)*10 + a[++indx]-'0';
        }

        if(l1==0){
            k.push_back(0);
        }
        else if(c==0){
            k.push_back(0);
        }
        stringstream ss;
        copy(k.begin(), k.end(), ostream_iterator<int>(ss));
        s = ss.str();
        return s;
}

int main()
{
    while(1){
        string s;
        cout<<"Press q for exit and else for calculation"<<endl;
        char ch;
        cin>>ch;
        if(ch == 'q') break;
        string a, b;
        int c, l1, l2;
        char t;
        cout << "First Number is  : ";
        cin>>a;
        cout << "Second Number is  : ";
        cin>>b;
        cout<< "Value of Sign : ";
        cin>>t;

        if(t=='+'){
            s=sum(a, b);
            for(int g=0; g<s.size(); g++){
                cout<<s[g]-'0';
            }
            cout<<endl;
        }

        else if(t=='-'){
            int f=0;
            s=subs(a, b);
            for(int g=0; g<s.size(); g++){
                if(s[g]== '0' && f==0){
                    continue;
                }
                else{
                    f=1;
                    cout<<s[g]-'0';
                }
            }
            if(f==0) cout<<0;
            cout<<endl;
        }

        if(t=='*'){
            s=multi(a, b);
            for(int g=0; g<s.size(); g++){
                cout<<s[g]-'0';
            }
            cout<<endl;
        }

        if(t=='/'){
            cout<<"We(those who aren't topcoder like me) cannot divide a large int stored as a string with another large int stored as a string,"<<endl<<"But we can divide a large int stored as a string with another large int not stored as a string"<<endl;
            cout<<"Input a large number as a divisor"<<endl;
            long long int lnum;
            cin>>lnum;
            if(lnum==0) cout<<"Not Possible because it would be infinity"<<endl;
            s=divis(a, lnum);
            cout<<"Quotient : ";
            for(int g=0; g<s.size(); g++){
                cout<<s[g]-'0';
            }
            cout<<endl;
            cout<<"Remainder : "<<remaind<<endl;
        }
    }

return 0;
}
