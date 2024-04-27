class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, string> romans;
        romans[1] = "I";
        romans[5] = "V";
        romans[10] = "X";
        romans[50] = "L";
        romans[100] = "C";
        romans[500] = "D";
        romans[1000] = "M";

        vector<string> converted;
        int target = num;
        for(int i = 0; i < 4; i++) {
            if(target == 0) {
                break;
            }
            string rom;
            int digit = target % 10;
            if(digit == 4 || digit == 9) {
                rom.append(romans[pow(10, i)]);
                rom.append(romans[(digit+1) * pow(10, i)]);
            }
            else if(digit > 5){
                rom.append(romans[5 * pow(10, i)]);
                for(int j = 0; j < digit-5; j++) {
                    rom.append(romans[pow(10, i)]);
                }
            }
            else if(digit == 5) {
                rom.append(romans[5* pow(10, i)]);
            }
            else{
                for(int j = 0; j < digit; j++) {
                    rom.append(romans[pow(10, i)]);
                }
            }
            converted.push_back(rom);
            target /= 10;
        }

        string result;
        for(int i = converted.size() - 1; i > -1; i--) {
            if(!converted[i].empty()) {
                for(char ch : converted[i]) {
                    result+= ch;
                }
            }
        }
        return result;
    }
};