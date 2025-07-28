#ifdef int 
#else 
    #define int32_t long long
#endif
//Main function *must be signed if int not defined (signed main(){})


#ifdef SUBLIME
    #ifdef apnd
        //Append hote thakbe output.error file a    
        ofstream err("output.error", ios::app);
    #else
        ofstream err("output.error");
    #endif    

    #define cerr err
#endif

#define cnl  clog << '\n'
#define db(val) #val": " << (val)
#define print_op(...) ostream& operator<<(ostream& out, const __VA_ARGS__& u)
#define CONCAT_(x, y) x##y

#define space setw(__db_level * 2) << setfill(' ') << "" << setw(0)

#define CONCAT(x, y) CONCAT_(x, y)
#define clog cerr << space 

#define NB debug_block CONCAT(debug_block_level, __LINE__)
int __db_level = 0;
struct debug_block {
    debug_block() { clog << "{" <<  endl; ++__db_level; }
    ~debug_block() { --__db_level; clog << "}" << endl; }
};


namespace Segment{
    /**************************VECTOR******************************************/
    ostream& operator<<(ostream& out, const vector<int>& v) {
        for(auto it : v)out << it <<" ";
        return out << endl;
    }
    ostream& operator<<(ostream& out, const vector<char>& v) {
        for(auto it : v)out << it <<" ";
        return out << endl;
    }
    ostream& operator<<(ostream& out, const vector<int32_t>& v) {
        for(auto it : v)out << it <<" ";
        return out << endl;
    }
    ostream& operator<<(ostream& out, const vector<double>& v) {
        for(auto it : v)out << it <<" ";
        return out << endl;
    }
    ostream& operator<<(ostream& out, const vector<string>& v) {
        for(auto it : v)out << it <<" ";
        return out << endl;
    }


    /**************************SET******************************************/
    ostream& operator<<(ostream& out, const set<int>& s) {
        for(auto it : s)out << it <<" ";
        return out << endl;
    }
    ostream& operator<<(ostream& out, const set<int32_t>& s) {
        for(auto it : s)out << it <<" ";
        return out << endl;
    }
    ostream& operator<<(ostream& out, const set<char>& s) {
        for(auto it : s)out << it <<" ";
        return out << endl;
    }
    ostream& operator<<(ostream& out, const set<double>& s) {
        for(auto it : s)out << it <<" ";
        return out << endl;
    }
    ostream& operator<<(ostream& out, const set<string>& s) {
        for(auto it : s)out << it <<" ";
        return out << endl;
    }


    /**************************UNORDERED_SET******************************************/
    ostream& operator<<(ostream& out, const unordered_set<int>& s) {
        for(auto it : s)out << it <<" ";
        return out << endl;
    }
    ostream& operator<<(ostream& out, const unordered_set<int32_t>& s) {
        for(auto it : s)out << it <<" ";
        return out << endl;
    }
    ostream& operator<<(ostream& out, const unordered_set<char>& s) {
        for(auto it : s)out << it <<" ";
        return out << endl;
    }
    ostream& operator<<(ostream& out, const unordered_set<double>& s) {
        for(auto it : s)out << it <<" ";
        return out << endl; 
    }
    ostream& operator<<(ostream& out, const unordered_set<string>& s) {
        for(auto it : s)out << it <<" ";
        return out << endl;
    }


    /**************************MULTISET******************************************/
    ostream& operator<<(ostream& out, const multiset<int>& s) {
        for(auto it : s)out << it <<" ";
        return out << endl;
    }
    ostream& operator<<(ostream& out, const multiset<int32_t>& s) {
        for(auto it : s)out << it <<" ";
        return out << endl;
    }
    ostream& operator<<(ostream& out, const multiset<char>& s) {
        for(auto it : s)out << it <<" ";
        return out << endl;
    }
    ostream& operator<<(ostream& out, const multiset<double>& s) {
        for(auto it : s)out << it <<" ";
        return out << endl; 
    }
    ostream& operator<<(ostream& out, const multiset<string>& s) {
        for(auto it : s)out << it <<" ";
        return out << endl;
    }


    /**************************UNORDERED_MULTISET******************************************/
    ostream& operator<<(ostream& out, const unordered_multiset<int>& s) {
        for(auto it : s)out << it <<" ";
        return out << endl;
    }
    ostream& operator<<(ostream& out, const unordered_multiset<int32_t>& s) {
        for(auto it : s)out << it <<" ";
        return out << endl;
    }
    ostream& operator<<(ostream& out, const unordered_multiset<char>& s) {
        for(auto it : s)out << it <<" ";
        return out << endl;
    }
    ostream& operator<<(ostream& out, const unordered_multiset<double>& s) {
        for(auto it : s)out << it <<" ";
        return out << endl; 
    }
    ostream& operator<<(ostream& out, const unordered_multiset<string>& s) {
        for(auto it : s)out << it <<" ";
        return out << endl;
    }

    /**************************ORDERED_SET******************************************/
    #ifdef ORDERED_SET_ON
        ostream& operator<<(ostream& out, const ordered_set<int>& s) {
            for(auto it : s)out << it <<" ";
            return out << endl;
        }
        ostream& operator<<(ostream& out, const ordered_set<int32_t>& s) {
            for(auto it : s)out << it <<" ";
            return out << endl;
        }
        ostream& operator<<(ostream& out, const ordered_set<char>& s) {
            for(auto it : s)out << it <<" ";
            return out << endl;
        }
        ostream& operator<<(ostream& out, const ordered_set<double>& s) {
            for(auto it : s)out << it <<" ";
            return out << endl; 
        }
        ostream& operator<<(ostream& out, const ordered_set<string>& s) {
            for(auto it : s)out << it <<" ";
            return out << endl;
        }

    #endif
};
using namespace Segment;




template<class U, class V> print_op(pair<U, V>) {
    return out << u.first << ", " << u.second << endl;
}

template<class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator<<(ostream& out, const Con& con) { 
    out << '\n';
    for (auto beg = con.begin(), it = beg; it != con.end(); ++it){
        out << space << *it;
    }
    return out;
}


template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")"; 
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup); 
}
template<class ...U> print_op(tuple<U...>) {
    return print_tuple_utils<0, tuple<U...>>(out, u);
}