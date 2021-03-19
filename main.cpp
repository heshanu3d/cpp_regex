//
// Created by hs-s1 on 2021/3/19.
//

#include <iostream>
#include <regex>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    std::array re = {std::regex("/opt/app/1-(\\d+).*"), std::regex(".*-b (\\d+).*")};

    string str = "/opt/app/1-9/";
//    string str = ".locate -a s -b 10 -s 2";
    string slotNum;

    auto it = std::find_if(re.begin(), re.end(), [str, &slotNum](std::regex r) {
        std::smatch res;
        bool flag = std::regex_match(str, res, r) && res.size() > 1;
        if (flag) {
            slotNum = res[1];
        }
        return flag;
    });
    if (it != re.end()) {
        cout << "slotNum: " << slotNum << endl;
    }
    else {
        cout << "Not Match!";
    }
}