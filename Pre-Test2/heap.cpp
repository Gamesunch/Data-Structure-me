#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class graph{
	public:
		int edges[100][100];
		int vertex;
		
		graph(int n){
			vertex = n;
			for(int i = 0;i<n;i++){
				for(int j = 0;j<n;j++){
					edges[i][j] = 0;
				}
			}
		}
		
		void addEdges(int v1,int v2,int w){
			edges[v1][v2] = w;
		}
		
		void BFS(int start){
			bool visited[100] = {false};
			
			queue<int> q;
			q.push(start);
			visited[start] = true;
			
			while(!q.empty()){
				int current = q.front();
				q.pop();
				cout<<current<<" ";
				
				for(int i = 0;i<vertex;i++){
					if(edges[current][i] != 0 && !visited[i]){
						q.push(i);
						visited[i] = true;
					}
				}
			}
			
			cout<<endl;
		}
		
		void DFS(int start){
			bool visited[100] = {false};
			
			stack<int> s;
			s.push(start);
			
			while(!s.empty()){
				int current = s.top();
				s.pop();
				
				if(!visited[current]){
					cout<<current<<" ";
					visited[current] = true;
				}
				
				for(int i = vertex - 1;i>= 0;i--){
					if(edges[current][i] != 0 && !visited[i]){
						s.push(i);
					}
				}
			}
			
			cout<<endl;
		}
};

int main(){
	int n;
	cin>>n;
	
	graph g(n);
	
	int v1,v2,w,s;
	char c;
	
	while(true){
		cin>>c;
		if(c == 'e'){
			cin>>v1>>v2>>w;
			g.addEdges(v1,v2,w);
		}
		else if(c == 's'){
			while(true){
				cin>>c;
				if(c == 'd'){
					cin >> s;
					g.DFS(s);
				}
				else if(c == 'b'){
					cin >> s;
					g.BFS(s);
				}
				else if(c == 'q'){
					return 0;
				}
			}
		}
		else if(c == 'q'){
			return 0;
		}
	}
}

/*
6
e 0 1 1
e 1 0 1
e 0 2 1
e 2 0 1
e 1 2 1
e 2 1 1
e 2 5 1
e 5 2 1
e 2 4 1
e 4 2 1
e 2 3 1
e 3 2 1
e 3 4 1
e 4 3 1
e 5 4 1
e 4 5 1
s
d 2
d 0
d 5
d 3
b 1
b 0
b 5
q
*/
