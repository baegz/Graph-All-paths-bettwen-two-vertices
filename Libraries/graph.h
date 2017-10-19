#ifndef GRAPH_MATRIX_H
#define GRAPH_MATRIX_H

class Graph{
	protected:
		int numVertex;
		int maxVertex;
		Vertex *vertices;
		int **matAdj;
		
	public:
		Graph(){ Graph(1); }
		
		Graph(int max){
			maxVertex = max;
			numVertex = 0;
			vertices = new Vertex[max];
			matAdj = new int*[max];
			for(int i=0;i<max;i++){
				matAdj[i] = new int[max];
				for(int j=0;j<max;j++) matAdj[i][j] = 0;
			}
		}
		
		int getMaxVertex(){	return this->maxVertex;	}
		
		int getNumVertex(){	return this->numVertex;	}
		
		void setNumVertex(int n){ numVertex = n; }
		
		void newVertex(string name){
			if(numOfVertex(name) < 0){
				Vertex v = Vertex(name,numVertex);
				vertices[numVertex++]=v;
			}else{
				cout<<"The vertex exist!\n";
			}
		}
		
		int numOfVertex(string name){
			for(int i = 0;i < numVertex;i++)
				if(vertices[i].similar(name))
					return i;
			return -1;
		}
		
		int newArc(string a, string b,int n){
			int va= numOfVertex(a);
			int vb = numOfVertex(b);
			if(va<0 || vb<0) cout<<"This vertex don't exist!";
			else matAdj[va][vb]=n;
		}
		
		void newArc(int a,int b, int n){
			if(a < 0 || b < 0 || a > numVertex || b > numVertex)
				cout<<"This vertex don't exist!";
			else matAdj[a][b]=n;
		}
		
		bool adjacent(string a, string b){
			if(numOfVertex(a) < 0 || numOfVertex(b) < 0) return false;
			else return matAdj[numOfVertex(a)][numOfVertex(b)] >= 1;
		}
		
		bool adjacent(int a, int b){
			if(a < 0 || b < 0 || a > numVertex || b > numVertex) return false;
			else return matAdj[a][b]>=1;
		}
		
		int getValue(string a, string b){
			int va = numOfVertex(a);
			int vb = numOfVertex(b);
			
			if(va < 0 || vb < 0){
				cout<<"This vertex don't exist";
				return false;
			}else{
				return matAdj[va][vb];
			}
		}
		
		int getValue(int a, int b){
			if(a < 0 || b < 0 || a > numVertex || b >= numVertex){
				return -1;
			}else{
				return matAdj[a][b];
			}
		}
		
		void setValue(int a, int b, int v){
			if(a < 0 || b < 0 || a > numVertex || b >= numVertex){
				cout<<"This vertex don't exist";
			}else{
				matAdj[a][b]=v;
			}
		}
		
		void setValue(string a, string b, int v){
			int va = numOfVertex(a);
			int vb = numOfVertex(b);
			if(va < 0 || vb < 0 || va > numVertex || vb >= numVertex){
				cout<<"This vertex don't exist";
			}else{
				matAdj[va][vb]=v;
			}
		}
		
		Vertex getVertex(int va){
			if(va < 0 || va >= numVertex){
				cout<<"This vertex don't exist";
			}else{
				return vertices[va];
			}
		}
		
		void setVertex(Vertex v, int va){
			if(va < 0 || va >= numVertex){
				cout<<"This vertex don't exist";
			}else{
				vertices[va]=v;
			}
		}
		
		void printVertices(){
			cout<<"Vertices: {";
			for(int i = 0;i < numVertex;i++){
				cout<<vertices[i].getName();
				if(i != numVertex-1)
					cout<<",";
			}
			cout<<"}\n\n";
		}
		
		void printMatAdj(){
			for(int i = 0;i < numVertex;i++){
				for(int j=0;j<numVertex;j++){
					cout<<"[";
					if(matAdj[i][j]==0){
						cout<<setfill(' ')<<setw(3)<<" ";
					}else{
						cout<<setfill(' ')<<setw(3)<<matAdj[i][j];
					}
					cout<<"]";
				}
				cout<<endl;
			}
		}
		
		bool exist(vector<string> path, string a){
			for(vector<string>::iterator it = path.begin(); it != path.end();it++)
				if(*it == a) return true;
			return false;
		}
		
		int getWeight(vector<string> path, string a){
			int weight=0;
			path.push_back(a);
			for(int i = 0;i < path.size()-1;i++)
				weight += getValue(path[i],path[i+1]);
			return weight;
		}
		
		void findAllPaths(string a, string b, vector<string> path){
			if(!exist(path,a)){
				path.push_back(a);
				int n = this->numOfVertex(a);
				for(int i = 0;i < numVertex;i++)
					if(adjacent(n,i)){
						if(vertices[i].getName() == b){
							for(vector<string>::iterator it = path.begin(); it != path.end();it++)
								cout<<*it<<"->";
							cout<<b<<" (weight: "<<getWeight(path,b)<<")\n";
						}else findAllPaths(vertices[i].getName(),b,path);
					}
			}
		}
		
		void allPaths(string a, string b){
			if(numOfVertex(a) > -1 && numOfVertex(b) > -1){
				vector<string> path;
				cout<<"\nShowing all paths from \""<<a<<"\" to \""<<b<<"\"...\n";
				findAllPaths(a,b,path);
			}
		}
};

#endif
