#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
using u128 = __uint128_t;

#define endl    			"\n"
#define nl  					cout << endl;

#define pp 						pop_back
#define pb 						push_back
#define vin 					vector<int>
#define all(v)				v.begin(), v.end()
#define print(v)	 		for(auto &i : v)cout << i <<" "; cout << endl;
#define mprint(mp) 		for(auto &i : mp)cout << i.first <<" " << i.second << endl;

#define _log2(n)    	63 - __builtin_clzll(n)
#define pop_count(n)	__builtin_popcountll(n)

ofstream err("output.error");
#ifdef DEBUG
	#define clog err
#else 
	#define clog if(0)cerr
#endif
template<class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator<<(ostream& out, const Con& v) {
	out <<"";
	for(auto &i : v){
		out <<" " << i;
	}
	return out << "\n";
}

const int INF = 1e18;
const int M = 1e9 + 7;
const int N = 2e5 + 10;



void solve(){

}

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int test = 1;
	cin >> test;
	for(int i = 1; i <= test; i++){
		solve();
	}
}
