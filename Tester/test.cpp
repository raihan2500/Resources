#include<bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
const int N = 2e5 + 10;

const string loc = "/home/raihan/Downloads/tests/";

bool comp(string fileA, string fileB){
    ifstream a(fileA), b(fileB);
    string a_line, b_line;
    while(getline(a, a_line)){
        if(!(getline(b, b_line)) or a_line != b_line){
            return false;
        }
    }
    return true;
}

int32_t main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n; 
    system("g++ solution.cpp -o run");

    for(int i = 1; i <= n; i++){
        string input = loc + to_string(i) + ".in";
        string output = loc + to_string(i) + ".out";


        auto start_code = chrono::high_resolution_clock::now();

        string compile_command = "./run<" + input + ">solution.out";
        system(compile_command.c_str());

        auto end_code = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(end_code - start_code);
        
        
        if(comp(output, "solution.out"))cout << "Accepted  ";
        else cout << "Wrong answer on test case " << i << "  ";
        cout << duration.count() << " ms\n";
        cout.flush();
    }
    system("rm run && rm solution.out && rm solution");
}