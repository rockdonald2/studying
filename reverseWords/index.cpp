string reverseWords(string s) {
    stringstream stream(s);
    
    string rStr{};
    string tmpStr{};
    
    while (stream >> tmpStr) {
        if (!rStr.length()) {
            rStr = tmpStr;
        } else {
            rStr = tmpStr + ' ' + rStr;
        }
    }
    
    return rStr;
}