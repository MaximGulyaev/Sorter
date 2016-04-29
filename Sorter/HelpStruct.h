template<typename T>
struct TCompare {
	bool operator()(const T& a, const T& b){
		return (a < b);
	}
};