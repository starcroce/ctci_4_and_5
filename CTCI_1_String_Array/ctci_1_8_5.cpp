bool isRotation(string s1, string s2){
	if(s1.length() != s2.length()){
		return false;
	}
	string s = s1 + s2;
	return isSubstring(s, s2);
}