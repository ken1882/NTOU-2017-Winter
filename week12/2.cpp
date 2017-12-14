#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Profile{
    string name, id, email;
    int age;

    Profile(string n, string i, int a, string m){
        name = n; id = i; age = a; email = m;
    }
};

bool sort_profile_by_id(Profile a, Profile b){
    return a.id < b.id;
}

int main(){
    int cas;
    while(cin >> cas){
        vector<Profile> data;
        for(int c=0;c<cas;c++){
            string n,i,m;
            int a;
            cin >> n >> i >> a >> m;
            Profile p(n,i,a,m);
            data.push_back(p);
        }
        sort(data.begin(), data.end(), sort_profile_by_id);
        for(auto p:data){
            cout << p.name << ' ' << p.id << ' ' << p.age << ' ' << p.email << '\n';
        }
    }
    return 0;
}
