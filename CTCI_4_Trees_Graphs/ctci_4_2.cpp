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
		// after pop from queue, the visiting is finished
		if(tmp == dst)
			return true;
		for(int i=0; i<n; i++){
			// visit neighbors with false visited state
			if(visited[i] == false){
				q.push(i);
				visited[i] = true
			}
		}
	}
	return false;
}