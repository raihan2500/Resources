#define db(val) #val": " << (val)
#define print_op(...) ostream& operator<<(ostream& out, const __VA_ARGS__& u)
#define CONCAT_(x, y) x##y
#define CONCAT(x, y) CONCAT_(x, y)
#   define clog cerr << setw(__db_level * 2) << setfill(' ') << "" << setw(0)
#   define DB() debug_block CONCAT(dbbl, __LINE__)
    int __db_level = 0;
    struct debug_block {
        debug_block() { clog << "{" << endl; ++__db_level; }
        ~debug_block() { --__db_level; clog << "}" << endl; }
    };


//Vector
ostream& operator<<(ostream& out, const vector<int>& v) {
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


//Set
ostream& operator<<(ostream& out, const set<int>& s) {
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


//Multiset
ostream& operator<<(ostream& out, const multiset<int>& s) {
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


template<class U, class V> print_op(pair<U, V>) {
    return out << u.first << ", " << u.second << endl;
}

template<class Con, class = decltype(begin(declval<Con>()))>
typename enable_if<!is_same<Con, string>::value, ostream&>::type
operator<<(ostream& out, const Con& con) { 
    out <<"\n";
    for (auto beg = con.begin(), it = beg; it != con.end(); ++it)
        out << (it == beg ? "" : "") << *it;
    return out << "";
}


template<size_t i, class T> ostream& print_tuple_utils(ostream& out, const T& tup) {
    if constexpr(i == tuple_size<T>::value) return out << ")"; 
    else return print_tuple_utils<i + 1, T>(out << (i ? ", " : "(") << get<i>(tup), tup); 
}
template<class ...U> print_op(tuple<U...>) {
    return print_tuple_utils<0, tuple<U...>>(out, u);
}
