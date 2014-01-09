bool visited[num];
queue<int> q;

void init(){
	for(int i=0; i<num; i++){
		visited[i] = false;
	}
}

bool isRoute(int src, int dst){
	q.push(src);
	visited[src] = true;
	while(!q.isEmpty()){
		int tmp = q.front();
		q.pop();
		if(tmp == dst)
			return true;
		for(int i=0; i<n; i++){
			if(visited[i]){
				q.push(i);
				visited[i] = true
			}
		}
	}
	return false;
}