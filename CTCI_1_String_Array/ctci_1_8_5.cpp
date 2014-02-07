bool isRotation(string s1, string s2){
	if(s1.length() != s2.length()){
		return false;
	}
	// stupid error!!!
	// s1: abc, s2: cab, s1+s1: abcabc
	string s = s1 + s1;
	return isSubstring(s, s2);
}