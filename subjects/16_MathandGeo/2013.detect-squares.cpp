class DetectSquares {
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        squares[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int result = 0;
        int x = point[0];
        int y = point[1];
        for(auto it_x = squares.begin(); it_x != squares.end(); it_x++) {
            int sq_x = it_x->first;
            for(auto it_y = it_x->second.begin(); it_y != it_x->second.end(); it_y++) {
                int sq_y = it_y->first;
                int sq_count = it_y->second;

                if (abs(sq_x - x) == 0 || abs(sq_x - x) != abs(sq_y - y)) {
                    continue;
                }
                
                result += squares[sq_x][sq_y] * squares[x][sq_y] * squares[sq_x][y];
            }
        }

        return result;
        
    }
private:
    unordered_map<int, unordered_map<int, int>> squares; 
};
/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */