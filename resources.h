#include<bits/stdc++.h>
using namespace std;

//using u128 = __uint128_t;
#define int                 long long

#define endl                "\n"
#define yes                 cout<<"YES\n"
#define no                  cout<<"NO\n"
#define nl                  cout<<"\n"
#define cnl                 clog<<"\n"

#define lin(n)              int n;cin>>n;
#define pr                  pair<int, int>
#define vin                 vector<int>
#define pp                  pop_back()
#define pb(n)               push_back(n)
#define ppfr(v)             v.erase(v.begin());
#define all(x)              x.begin(),x.end()

#define forn(i,n)           for(int i = 0; i < n; i++)
#define Forn(i,n)           for(int i = 1; i <= n; i++)
#define rforn(i,n)          for(int i = n - 1; i >= 0; i--)
#define print(arr)          for(auto x: arr)cout<<x<<" ";nl;
#define mprint(mp)          for(auto a : mp)cout<<a.first<<" "<<a.second<<endl;
                            
mt19937                     rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng(x,y)            uniform_int_distribution<int>(x,y)(rng)

namespace Pollard{
    #define int long long
    mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
    const int N = 1e6 + 100;
    bool isPrime[N]; int hp[N];
    vector<int> primes;

    void init(){
        memset(isPrime, 1, sizeof(isPrime));
        isPrime[0] = isPrime[1] = 0;

        for(int i = 2; i < N; i++){
            if(isPrime[i]){
                hp[i] = i;
                for(int j = i + i; j < N; j += i){
                    isPrime[j] = 0;
                    hp[j] = i;
                }
            }
        }
        for(int i = 2; i < N; i++){
            if(isPrime[i]){
                primes.push_back(i);
            }
        }
    }
    
    int binExp(int a, int b, int M = 1e9 + 7){
        int ans = 1;    a %= M;
        
        while(b > 0){
            if(b & 1)ans = ((__uint128_t)(ans % M) * (a % M)) % M;
            b >>= 1;
            a = ((__uint128_t)(a % M) * (a % M)) % M;
        }
        return ans;
    }

    //Miller Rabin primality test
    bool is_composite(int n, int a, int d, int p){
        int x = binExp(a, d, n);
        if(x == 1 or x == n - 1)return false;
    
        for(int i = 0; i < p - 1; i++){
            x = (__uint128_t)x * x % n;
            if(x == n - 1)return false;
        }
    
        return true;
    }
    
    bool miller_rabin(int n, int iter = 5){
        if(n < 4)return n == 2 || n == 3;
        
        int p = 0, d = n - 1;
        while((d & 1) == 0){
            d >>= 1;
            p++;
        }
    
        for(int i = 0; i < iter; i++){
            int a = 2 + rnd() % (n - 3);
            if(is_composite(n, a, d, p))return false;
        }
    
        return true;
    }
    
    //Pollard rho
    int func(int x, int c, int mod){
        return ((__uint128_t) x * x % mod + c) % mod;
    }    

    int rho(int n){
        int c = 1 + rnd() % (n - 2);
        int x =  2 + rnd() % (n - 2);
        int y = x, d = 1;

        while(d == 1){
            x = func(x, c, n);
            y = func(func(y, c, n), c, n);
            d = __gcd(abs(x - y), n);
        }
        return d;
    }

    vector<int> factorize(int n){
        if(n == 1)return {1};
        if(miller_rabin(n))return {n};
        vector<int> factors, temp;
        
        if(n < N){
            while(n > 1){
                int pm = hp[n];
                while(n % pm == 0){
                    factors.push_back(pm);
                    n /= pm;
                }
            }
            return factors;
        }

        int x = rho(n);
        factors = factorize(x);
        temp = factorize(n / x);
        factors.insert(factors.end(), temp.begin(), temp.end());
        return factors;
    }

    void allDivsGen(int ind, int curVal, vector<pair<int, int>> &pmFact, set<int> &ans){
        if(pmFact[ind].first == -1){
            ans.insert(curVal);
            return;
        }
        for(int i = 0; i <= pmFact[ind].second; i++){
            allDivsGen(ind + 1, curVal, pmFact, ans);
            curVal *= pmFact[ind].first;
        }
    }

    set<int> allDivisors(int n){
        set<int> ans;
        vector<pair<int, int>> prime_factors;
        vector<int> fact = factorize(n);
        unordered_map<int, int> mp;
        for(auto i : fact)mp[i]++;
        for(auto i : mp)prime_factors.push_back({i.first, i.second});
        prime_factors.push_back({-1, -1});
        allDivsGen(0, 1, prime_factors, ans);
        return ans;
    }
}

class SeiveAlgo{
    private:
        //Variables
        int N = 1e6, factors_size,  num_cnt = 0, dp_cnt = 0;
        vector<int> lp;
        vector<bool>isPrime;
        set<int> divisors;
        struct grp{int pm, cnt;};
        vector<grp>factors;

    public:
        vector<int>primes;

        SeiveAlgo(int n = 1e6){
            N = n + 100;
            lp = vector<int> (N);
            isPrime = vector<bool> (N);
            generatePrimes();
        }

        vector<int> primeFactors(int n){
            vector<int> v;
            factors.clear();
            while(n > 1){
                int pm = lp[n], cnt = 0;
                while(n % pm == 0){
                    v.push_back(pm);
                    n /= pm;
                    cnt++;
                }
                factors.push_back({pm, cnt});
            }
            return v;
        }

        //All the divisors of a number
        set<int> allDivisors(int n){
            primeFactors(n);
            factors_size = factors.size();
            divisors.clear();
            allDivisorsGenerator(0, 1);
            return divisors;
        }

    private:
        //Segment Seive
        vector<int> segSeive(int l, int r){
            if(l > r)swap(l, r);
            int n = r - l + 1;
            vector<bool>isPrime(n + 1);
            vector<int>segPrimes;

            for(int i = 0; primes[i] * primes[i] <= r; i++){
                int st = ceil(l * 1.0 / primes[i]) * primes[i];
                for(int j = st; j <= r; j += primes[i]){
                    if(j == primes[i])continue;
                    isPrime[j - l] = true;
                }
            }
            
            for(int i = 0; i < n; i++){
                if(!isPrime[i]){
                    if(i + l > 1){
                        segPrimes.push_back(i + l);
                    }
                }
            }
            return segPrimes;
        }

    private:
        void allDivisorsGenerator(int currIndex, int currDivisor){
            dp_cnt++;
            if(currIndex == factors_size){
                num_cnt++;
                divisors.insert(currDivisor);
                return;
            }
            for(int i = 0; i <= factors[currIndex].cnt; i++){
                allDivisorsGenerator(currIndex + 1, currDivisor);
                currDivisor *= factors[currIndex].pm;
            }
        }

        void generatePrimes(){
            isPrime[0] = isPrime[1] = true;
            for(int i = 2; i < N; i++){
                if(!isPrime[i]){
                    lp[i] = i;
                    for(int j = i + i; j < N; j += i){
                        isPrime[j] = true;
                        if(lp[j] == 0)lp[j] = i;
                    }
                }
            }
            for(int i = 2; i < N; i++){
                if(!isPrime[i])primes.push_back(i);
            }
        }
};


